import React, { useState, useEffect, useCallback, useMemo } from 'react';
import FloorSelector from '../components/FloorSelector';
import { visualizeHashMap } from '../api/backendApi';
import type { Floor, HashMapData, HashMapState } from '../types';
import './HashMap.css';
import '../pages/VisualizationPage.css';

interface ChainNode {
    id: number;
    name: string;
}

interface HashMapPageProps {
    onBack: () => void;
}

const HashMapPage: React.FC<HashMapPageProps> = ({ onBack }) => {
    const [floors] = useState<Floor[]>([
        { id: 1, name: 'Mezzanine Floor', floorNumber: 'Mezzanine' },
        { id: 2, name: 'Lower Ground Floor', floorNumber: 'Lower Ground' },
        { id: 3, name: 'Ground Floor', floorNumber: 0 },
        { id: 4, name: 'First Floor', floorNumber: 1 },
        { id: 5, name: 'Second Floor', floorNumber: 2 },
        { id: 6, name: '2A Floor', floorNumber: '2A' }
    ]);

    const [selectedFloor, setSelectedFloor] = useState<Floor>(floors[4]);
    const [hashMapData, setHashMapData] = useState<HashMapData | null>(null);
    const [currentStepIndex, setCurrentStepIndex] = useState<number>(0);
    const [isPlaying, setIsPlaying] = useState<boolean>(false);
    const [loading, setLoading] = useState<boolean>(false);
    const [error, setError] = useState<string | null>(null);

    // Search state
    const [searchQuery, setSearchQuery] = useState<string>('');
    const [searchResult, setSearchResult] = useState<{
        found: boolean;
        comparisons: number;
        bucketIndex: number | null;
        nodeId?: number;
        nodeName?: string;
        searchTime: number;
    } | null>(null);
    const [isSearching, setIsSearching] = useState<boolean>(false);

    const currentStep: HashMapState | null = hashMapData?.steps[currentStepIndex] || null;

    const fetchHashMapData = useCallback(async (floorId: number) => {
        setLoading(true);
        setError(null);
        setHashMapData(null);
        setCurrentStepIndex(0);
        setIsPlaying(false);
        setSearchResult(null);
        setIsSearching(false);
        setSearchQuery('');
        try {
            const data = await visualizeHashMap(floorId);
            setHashMapData(data);
        } catch (err) {
            setError('Failed to fetch HashMap visualization data. Check backend status or console for details.');
            console.error(err);
        } finally {
            setLoading(false);
        }
    }, []);

    useEffect(() => {
        fetchHashMapData(selectedFloor.id);
    }, [selectedFloor, fetchHashMapData]);

    const nodeMap = useMemo(() => {
        if (!hashMapData) return new Map<number, string>();
        const map = new Map<number, string>();
        hashMapData.steps.forEach(step => {
            if (step.insertedNodeId != null) {
                map.set(step.insertedNodeId, step.insertedNodeName);
            }
        });
        return map;
    }, [hashMapData]);

    const nodeNames = useMemo(() => {
        if (!hashMapData) return new Set<string>();
        return new Set(hashMapData.steps.map(s => s.insertedNodeName));
    }, [hashMapData]);

    const handleNext = () => {
        if (hashMapData && currentStepIndex < hashMapData.steps.length - 1) {
            setCurrentStepIndex(prev => prev + 1);
        } else {
            setIsPlaying(false);
        }
    };

    const handlePrev = () => {
        if (currentStepIndex > 0) {
            setCurrentStepIndex(prev => prev - 1);
        }
    };

    const handlePlayPause = () => {
        setIsPlaying(prev => !prev);
    };

    const handleSliderChange = (event: React.ChangeEvent<HTMLInputElement>) => {
        const index = parseInt(event.target.value);
        setCurrentStepIndex(index);
        setIsPlaying(false);
    };

    useEffect(() => {
        let interval: NodeJS.Timeout | null = null;
        if (isPlaying && hashMapData && currentStepIndex < hashMapData.steps.length - 1) {
            interval = setInterval(handleNext, 900);
        } else if (isPlaying && hashMapData && currentStepIndex === hashMapData.steps.length - 1) {
            setIsPlaying(false);
        }

        return () => {
            if (interval) clearInterval(interval);
        };
    }, [isPlaying, currentStepIndex, hashMapData]);

    const bucketCount = hashMapData?.bucketCount || 10;
    const buckets = Array.from({ length: bucketCount }, (_, i) => i);
    const totalSteps = hashMapData?.steps.length || 0;

    const bucketChains = useMemo(() => {
        const chains: ChainNode[][] = Array.from({ length: bucketCount }, () => []);
        if (!hashMapData) return chains;

        for (let i = 0; i <= currentStepIndex && i < hashMapData.steps.length; i++) {
            const step = hashMapData.steps[i];

            // Backend now returns chainState as array of objects {id, name}
            if (Array.isArray(step.chainState) && typeof step.currentBucketIndex === 'number') {
                try {
                    // Check if it's the new format (objects) or old format (numbers - though we changed backend)
                    // Safe cast to any to check structure
                    const rawChain = step.chainState as any[];
                    if (rawChain.length > 0 && typeof rawChain[0] === 'object') {
                        chains[step.currentBucketIndex] = rawChain.map((node: any) => ({
                            id: node.id,
                            name: node.name
                        }));
                    } else {
                        // Fallback for number[] if somehow mixed (shouldn't happen with new backend)
                        chains[step.currentBucketIndex] = (rawChain as number[]).map(id => ({
                            id,
                            name: nodeMap.get(id) || `Node ${id}`
                        }));
                    }
                } catch {
                    // ignore malformed chainState
                }
            }
            // Handle single insertions if chainState is empty/missing but node inserted
            else if (step.insertedNodeId != null && typeof step.currentBucketIndex === 'number') {
                const id = step.insertedNodeId;
                const name = step.insertedNodeName || nodeMap.get(id) || `Node ${id}`;
                // Add to front if not exists
                const existing = chains[step.currentBucketIndex];
                if (!existing.some(n => n.id === id)) {
                    chains[step.currentBucketIndex] = [{ id, name }, ...existing];
                }
            }
        }
        return chains;
    }, [hashMapData, currentStepIndex, bucketCount, nodeMap]);

    const chainNodesForBucket = (bIndex: number): ChainNode[] => {
        return bucketChains[bIndex] || [];
    };

    const vizContainerRef = React.useRef<HTMLDivElement>(null);

    // Auto-scroll to active bucket
    useEffect(() => {
        if (!hashMapData || !currentStep || !vizContainerRef.current) return;

        let targetIndex = -1;
        if (typeof currentStep.currentBucketIndex === 'number') {
            targetIndex = currentStep.currentBucketIndex;
        }

        if (targetIndex !== -1) {
            // Find the bucket element
            const bucketElement = vizContainerRef.current.querySelector(`[aria-label="Bucket ${targetIndex}"]`) as HTMLElement;
            if (bucketElement) {
                // Scroll into view
                bucketElement.scrollIntoView({ behavior: 'smooth', block: 'nearest', inline: 'center' });
            }
        }
    }, [currentStepIndex, hashMapData, currentStep]);


    const calculateSearchTime = (comparisons: number): number => {
        const hashTime = 50;
        const comparisonTime = comparisons * 100;
        const memoryAccessTime = (comparisons + 1) * 10;
        return hashTime + comparisonTime + memoryAccessTime;
    };

    const performSearch = (query: string) => {
        if (!hashMapData || !query.trim()) return;

        setIsSearching(true);
        let comparisons = 0;
        let found = false;
        let foundNodeId: number | undefined;
        let foundNodeName: string | undefined;
        let targetBucket: number | null = null;

        const parsedQuery = query.trim();
        const asNumber = Number(parsedQuery);
        const isNumericSearch = !isNaN(asNumber) && parsedQuery === asNumber.toString();

        let targetId: number | null = null;

        // Step 1: Resolve Target ID and Bucket
        if (isNumericSearch) {
            // For numeric search, we assume the user entered an ID.
            targetId = asNumber;
        } else {
            // For string search, we first look up the ID associated with this name.
            // This is crucial because our hash function is id % m.
            // We can use nodeMap to find the ID.
            // Since nodeMap is ID -> Name, we iterate.
            for (const [id, name] of nodeMap.entries()) {
                if (name.toLowerCase() === parsedQuery.toLowerCase()) {
                    targetId = id;
                    break;
                }
            }
        }

        // If we found an ID (either direct input or resolved from name), calculate bucket
        if (targetId !== null) {
            targetBucket = targetId % bucketCount;
        } else {
            // If we couldn't resolve a name to an ID, we can't efficiently find the bucket 
            // with the hash function id % m. We might default to a naive hash 
            // or just say not found immediately, but let's try the naive string hash 
            // just in case they are searching for something hypothetically (though it won't be in the map)
            // Actually, for this visualization, "Not Found" is the correct result if name doesn't exist.
            // But let's check one bucket just to show the visualization "searching".
            let hash = 0;
            for (let i = 0; i < parsedQuery.length; i++) {
                hash = ((hash << 5) - hash) + parsedQuery.charCodeAt(i);
                hash = hash & hash;
            }
            targetBucket = Math.abs(hash) % bucketCount;
        }

        // Step 2: Search in that bucket
        const chainIds = bucketChains[targetBucket] || [];

        for (let i = 0; i < chainIds.length; i++) {
            const node = chainIds[i]; // node is {id, name} object now or number?? 
            // Wait, bucketChains is ChainNode[][]. So 'node' is {id, name}.
            const nodeId = node.id;
            const nodeName = node.name;
            comparisons++;

            let match = false;
            // Compare against resolved target ID if we have one
            if (targetId !== null) {
                match = (nodeId === targetId);
            }
            // Fallback: compare name/string if we somehow didn't resolve ID (shouldn't happen for valid nodes)
            else if (!isNumericSearch) {
                match = nodeName.toLowerCase() === parsedQuery.toLowerCase();
            }

            if (match) {
                found = true;
                foundNodeId = nodeId;
                foundNodeName = nodeName;
                break;
            }
        }

        // Auto-scroll to search result bucket if found, or the checked bucket if not found
        if (targetBucket !== null && vizContainerRef.current) {
            const bucketElement = vizContainerRef.current.querySelector(`[aria-label="Bucket ${targetBucket}"]`) as HTMLElement;
            if (bucketElement) {
                bucketElement.scrollIntoView({ behavior: 'smooth', block: 'nearest', inline: 'center' });
            }
        }

        const searchTime = calculateSearchTime(comparisons);

        setSearchResult({
            found,
            comparisons,
            bucketIndex: targetBucket,
            nodeId: foundNodeId,
            nodeName: foundNodeName,
            searchTime
        });
        setIsSearching(false);
    };

    const handleSearchSubmit = (e: React.FormEvent) => {
        e.preventDefault();
        if (searchQuery.trim()) {
            performSearch(searchQuery.trim());
        }
    };

    if (loading) return <div className="visualization-page"><div className="viz-header"><button className="back-button" onClick={onBack}>← Back</button></div><div className="viz-container">Loading HashMap data...</div></div>;
    if (error) return <div className="visualization-page"><div className="viz-header"><button className="back-button" onClick={onBack}>← Back</button></div><div className="viz-container"><div className="error-message">{error}</div></div></div>;

    if (!hashMapData || totalSteps === 0) {
        return (
            <div className="visualization-page">
                <div className="viz-header">
                    <button className="back-button" onClick={onBack}>← Back to Visualizations</button>
                    <h2>🔑 HashMap Visualization (Chaining) - {selectedFloor.name}</h2>
                </div>

                <div className="viz-container">
                    <div className="viz-sidebar">
                        <FloorSelector
                            floors={floors}
                            selectedFloor={selectedFloor}
                            onSelectFloor={setSelectedFloor}
                            loading={loading}
                        />
                    </div>

                    <div className="viz-main">
                        <div className="error-message">Visualization data is not available for this floor, or the backend returned no steps.</div>
                    </div>
                </div>
            </div>
        );
    }

    return (
        <div className="visualization-page">
            <div className="viz-header">
                <button className="back-button" onClick={onBack}>← Back to Visualizations</button>
                <h2>🔑 HashMap Visualization (Chaining) - {selectedFloor.name}</h2>
            </div>

            <div className="viz-container">
                <aside className="viz-sidebar" style={{ width: '320px', minWidth: '320px' }}>
                    <FloorSelector
                        floors={floors}
                        selectedFloor={selectedFloor}
                        onSelectFloor={setSelectedFloor}
                        loading={loading}
                    />

                    {/* Search Section */}
                    <div className="path-info">
                        <h4 className="flex items-center gap-2">
                            <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
                                <path fillRule="evenodd" d="M8 4a4 4 0 100 8 4 4 0 000-8zM2 8a6 6 0 1110.89 3.476l4.817 4.817a1 1 0 01-1.414 1.414l-4.816-4.816A6 6 0 012 8z" clipRule="evenodd" />
                            </svg>
                            Search Node
                        </h4>
                        <form onSubmit={handleSearchSubmit} style={{ marginBottom: '1rem' }}>
                            <div style={{ display: 'flex', gap: '0.5rem', marginBottom: '0.5rem' }}>
                                <input
                                    type="text"
                                    placeholder="Enter ID or name..."
                                    value={searchQuery}
                                    onChange={(e) => setSearchQuery(e.target.value)}
                                    style={{
                                        flex: 1,
                                        padding: '0.5rem 0.75rem',
                                        borderRadius: '6px',
                                        border: '1px solid oklch(0.22 0 0)',
                                        background: 'oklch(0.15 0 0)',
                                        color: 'white',
                                        fontSize: '0.9rem'
                                    }}
                                />
                                <button
                                    type="submit"
                                    disabled={isSearching || !searchQuery.trim()}
                                    className="flex items-center justify-center"
                                    style={{
                                        padding: '0.5rem',
                                        width: '42px',
                                        borderRadius: '6px',
                                        background: 'linear-gradient(135deg, oklch(0.65 0.22 264.376) 0%, oklch(0.6 0.2 270) 100%)',
                                        color: 'white',
                                        border: 'none',
                                        cursor: isSearching ? 'not-allowed' : 'pointer',
                                        opacity: isSearching ? 0.6 : 1
                                    }}
                                >
                                    {isSearching ? (
                                        <svg className="animate-spin h-5 w-5 text-white" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
                                            <circle className="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" strokeWidth="4"></circle>
                                            <path className="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4zm2 5.291A7.962 7.962 0 014 12H0c0 3.042 1.135 5.824 3 7.938l3-2.647z"></path>
                                        </svg>
                                    ) : (
                                        <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
                                            <path fillRule="evenodd" d="M8 4a4 4 0 100 8 4 4 0 000-8zM2 8a6 6 0 1110.89 3.476l4.817 4.817a1 1 0 01-1.414 1.414l-4.816-4.816A6 6 0 012 8z" clipRule="evenodd" />
                                        </svg>
                                    )}
                                </button>
                            </div>
                        </form>

                        {searchResult && (
                            <div style={{
                                background: 'oklch(0.15 0 0)',
                                borderRadius: '8px',
                                padding: '1rem',
                                border: '1px solid oklch(0.22 0 0)',
                                fontSize: '0.9rem'
                            }}>
                                <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', marginBottom: '0.75rem' }}>
                                    <span style={{ fontWeight: 700, color: 'white', fontSize: '1rem' }}>Search Result</span>
                                    <span style={{
                                        padding: '0.25rem 0.75rem',
                                        borderRadius: '12px',
                                        background: searchResult.found
                                            ? 'rgba(34, 197, 94, 0.2)'
                                            : 'rgba(239, 68, 68, 0.2)',
                                        color: searchResult.found ? '#4ade80' : '#f87171',
                                        fontWeight: 700,
                                        fontSize: '0.85rem',
                                        display: 'flex',
                                        alignItems: 'center',
                                        gap: '0.25rem'
                                    }}>
                                        {searchResult.found ? (
                                            <>
                                                <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                                    <path fillRule="evenodd" d="M16.707 5.293a1 1 0 010 1.414l-8 8a1 1 0 01-1.414 0l-4-4a1 1 0 011.414-1.414L8 12.586l7.293-7.293a1 1 0 011.414 0z" clipRule="evenodd" />
                                                </svg>
                                                Found
                                            </>
                                        ) : (
                                            <>
                                                <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                                    <path fillRule="evenodd" d="M4.293 4.293a1 1 0 011.414 0L10 8.586l4.293-4.293a1 1 0 111.414 1.414L11.414 10l4.293 4.293a1 1 0 01-1.414 1.414L10 11.414l-4.293 4.293a1 1 0 01-1.414-1.414L8.586 10 4.293 5.707a1 1 0 010-1.414z" clipRule="evenodd" />
                                                </svg>
                                                Not Found
                                            </>
                                        )}
                                    </span>
                                </div>

                                <div style={{ color: 'oklch(0.75 0 0)' }}>
                                    <div style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem', alignItems: 'center' }}>
                                        <span className="flex items-center gap-1">
                                            <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                                <path d="M2 11a1 1 0 011-1h2a1 1 0 011 1v5a1 1 0 01-1 1H3a1 1 0 01-1-1v-5zM8 7a1 1 0 011-1h2a1 1 0 011 1v9a1 1 0 01-1 1H9a1 1 0 01-1-1V7zM14 4a1 1 0 011-1h2a1 1 0 011 1v12a1 1 0 01-1 1h-2a1 1 0 01-1-1V4z" />
                                            </svg>
                                            Bucket:
                                        </span>
                                        <span style={{ fontWeight: 700, color: 'white', fontSize: '1.1rem' }}>{searchResult.bucketIndex}</span>
                                    </div>
                                    <div style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem', alignItems: 'center' }}>
                                        <span className="flex items-center gap-1">
                                            <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                                <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zm1-11a1 1 0 10-2 0v3.586L7.707 9.293a1 1 0 00-1.414 1.414l3 3a1 1 0 001.414 0l3-3a1 1 0 00-1.414-1.414L11 10.586V7z" clipRule="evenodd" />
                                            </svg>
                                            Comparisons:
                                        </span>
                                        <span style={{ fontWeight: 700, color: 'white', fontSize: '1.1rem' }}>{searchResult.comparisons}</span>
                                    </div>
                                    <div style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem', alignItems: 'center' }}>
                                        <span className="flex items-center gap-1">
                                            <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                                <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zm1-12a1 1 0 10-2 0v4a1 1 0 00.293.707l2.828 2.829a1 1 0 101.415-1.415L11 9.586V6z" clipRule="evenodd" />
                                            </svg>
                                            Lookup Time:
                                        </span>
                                        <span style={{ fontWeight: 700, color: '#60a5fa', fontSize: '1.1rem' }}>{searchResult.searchTime}ms</span>
                                    </div>
                                    {searchResult.found && searchResult.nodeName && (
                                        <div style={{
                                            marginTop: '0.75rem',
                                            padding: '0.75rem',
                                            borderRadius: '6px',
                                            background: 'rgba(34, 197, 94, 0.1)',
                                            border: '1px solid rgba(34, 197, 94, 0.3)'
                                        }}>
                                            <div style={{ fontWeight: 600, color: '#4ade80', marginBottom: '0.25rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
                                                <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                                    <path fillRule="evenodd" d="M16.707 5.293a1 1 0 010 1.414l-8 8a1 1 0 01-1.414 0l-4-4a1 1 0 011.414-1.414L8 12.586l7.293-7.293a1 1 0 011.414 0z" clipRule="evenodd" />
                                                </svg>
                                                Found Node:
                                            </div>
                                            <div style={{ fontSize: '0.95rem', color: 'white' }}>{searchResult.nodeName}</div>
                                            <div style={{ fontSize: '0.85rem', color: 'oklch(0.75 0 0)' }}>ID: {searchResult.nodeId}</div>
                                        </div>
                                    )}
                                </div>
                            </div>
                        )}
                    </div>

                    <div className="path-info">
                        <h4 className="flex items-center gap-2">
                            <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
                                <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zM9.555 7.168A1 1 0 008 8v4a1 1 0 001.555.832l3-2a1 1 0 000-1.664l-3-2z" clipRule="evenodd" />
                            </svg>
                            Controls
                        </h4>
                        <div style={{ display: 'flex', gap: '0.5rem', marginBottom: '0.75rem', flexWrap: 'wrap' }}>
                            <button
                                onClick={handlePrev}
                                disabled={currentStepIndex === 0}
                                className="flex items-center justify-center gap-2"
                                style={{
                                    flex: 1,
                                    minWidth: '80px',
                                    padding: '0.5rem 0.75rem',
                                    borderRadius: '6px',
                                    background: 'linear-gradient(135deg, oklch(0.15 0 0), oklch(0.17 0 0))',
                                    color: 'white',
                                    border: '1px solid oklch(0.22 0 0)',
                                    cursor: currentStepIndex === 0 ? 'not-allowed' : 'pointer',
                                    opacity: currentStepIndex === 0 ? 0.5 : 1
                                }}
                            >
                                <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                    <path fillRule="evenodd" d="M12.707 5.293a1 1 0 010 1.414L9.414 10l3.293 3.293a1 1 0 01-1.414 1.414l-4-4a1 1 0 010-1.414l4-4a1 1 0 011.414 0z" clipRule="evenodd" />
                                </svg>
                                Prev
                            </button>
                            <button
                                onClick={handlePlayPause}
                                disabled={!hashMapData}
                                className="flex items-center justify-center gap-2"
                                style={{
                                    flex: 1,
                                    minWidth: '80px',
                                    padding: '0.5rem 0.75rem',
                                    borderRadius: '6px',
                                    background: 'linear-gradient(135deg, oklch(0.65 0.22 264.376) 0%, oklch(0.6 0.2 270) 100%)',
                                    color: 'white',
                                    border: 'none',
                                    cursor: !hashMapData ? 'not-allowed' : 'pointer',
                                    opacity: !hashMapData ? 0.5 : 1
                                }}
                            >
                                {isPlaying ? (
                                    <>
                                        <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                            <path fillRule="evenodd" d="M18 10a8 8 0 11-16 0 8 8 0 0116 0zM7 8a1 1 0 012 0v4a1 1 0 11-2 0V8zm5-1a1 1 0 00-1 1v4a1 1 0 102 0V8a1 1 0 00-1-1z" clipRule="evenodd" />
                                        </svg>
                                        Pause
                                    </>
                                ) : (
                                    <>
                                        <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                            <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zM9.555 7.168A1 1 0 008 8v4a1 1 0 001.555.832l3-2a1 1 0 000-1.664l-3-2z" clipRule="evenodd" />
                                        </svg>
                                        Play
                                    </>
                                )}
                            </button>
                            <button
                                onClick={handleNext}
                                disabled={!hashMapData || currentStepIndex === totalSteps - 1}
                                className="flex items-center justify-center gap-2"
                                style={{
                                    flex: 1,
                                    minWidth: '80px',
                                    padding: '0.5rem 0.75rem',
                                    borderRadius: '6px',
                                    background: 'linear-gradient(135deg, oklch(0.15 0 0), oklch(0.17 0 0))',
                                    color: 'white',
                                    border: '1px solid oklch(0.22 0 0)',
                                    cursor: (!hashMapData || currentStepIndex === totalSteps - 1) ? 'not-allowed' : 'pointer',
                                    opacity: (!hashMapData || currentStepIndex === totalSteps - 1) ? 0.5 : 1
                                }}
                            >
                                Next
                                <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                    <path fillRule="evenodd" d="M7.293 14.707a1 1 0 010-1.414L10.586 10 7.293 6.707a1 1 0 011.414-1.414l4 4a1 1 0 010 1.414l-4 4a1 1 0 01-1.414 0z" clipRule="evenodd" />
                                </svg>
                            </button>
                        </div>

                        <div style={{ marginBottom: '0.75rem' }}>
                            <input
                                type="range"
                                min={0}
                                max={totalSteps - 1}
                                value={currentStepIndex}
                                onChange={handleSliderChange}
                                style={{ width: '100%' }}
                            />
                        </div>

                        <p style={{ margin: 0, fontSize: '0.95rem', textAlign: 'center' }}>
                            Step <strong>{currentStepIndex + 1}</strong> of <strong>{totalSteps}</strong>
                        </p>
                    </div>

                    <div className="path-info">
                        <h4 className="flex items-center gap-2">
                            <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
                                <path fillRule="evenodd" d="M5 9V7a5 5 0 0110 0v2a2 2 0 012 2v5a2 2 0 01-2 2H5a2 2 0 01-2-2v-5a2 2 0 012-2zm8-2v2H7V7a3 3 0 016 0z" clipRule="evenodd" />
                            </svg>
                            Insertion Sequence
                        </h4>
                        <div className="path-nodes" style={{ marginTop: '0.75rem' }}>
                            {hashMapData.steps.slice(0, currentStepIndex + 1).map((s, idx) => (
                                <div
                                    key={`${s.insertedNodeId ?? idx}-${idx}`}
                                    className={`path-node ${idx === currentStepIndex ? 'exit-node' : ''}`}
                                    title={s.insertedNodeName ? `${s.insertedNodeName} (id:${s.insertedNodeId})` : `id:${s.insertedNodeId}`}
                                    style={{ fontSize: '0.9rem', padding: '0.5rem 0.75rem' }}
                                >
                                    {s.insertedNodeName ? s.insertedNodeName : `#${s.insertedNodeId}`}
                                </div>
                            ))}

                            {currentStepIndex === 0 && hashMapData.steps.length > 0 && (
                                <div style={{ fontSize: '0.9rem', color: 'var(--muted, #cbd5e1)' }}>No insertions shown yet</div>
                            )}
                        </div>

                        <div style={{ marginTop: '1rem' }}>
                            <p style={{ margin: 0, fontWeight: 700, fontSize: '0.95rem', display: 'flex', alignItems: 'center', gap: '0.5rem' }}>
                                <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                    <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zm1-12a1 1 0 10-2 0v4a1 1 0 00.293.707l2.828 2.829a1 1 0 101.415-1.415L11 9.586V6z" clipRule="evenodd" />
                                </svg>
                                Current Step
                            </p>
                            <p style={{ margin: '0.25rem 0 0 0', fontSize: '0.9rem', color: 'oklch(0.75 0 0)' }}>{currentStep?.description}</p>
                            {currentStep?.insertedNodeName && (
                                <p style={{ margin: '0.25rem 0 0 0', fontSize: '0.9rem' }}>
                                    <strong>Node:</strong> {currentStep.insertedNodeName} (id: {currentStep.insertedNodeId})
                                </p>
                            )}
                            {typeof currentStep?.currentBucketIndex === 'number' && (
                                <p style={{ margin: '0.25rem 0 0 0', fontSize: '0.9rem' }}>
                                    <strong>Bucket:</strong> {currentStep?.currentBucketIndex}
                                </p>
                            )}
                            {currentStep?.isCollision && (
                                <p style={{ margin: '0.25rem 0 0 0', color: '#ff6b6b', fontSize: '0.9rem' }}>
                                    <strong>Collision detected</strong>
                                </p>
                            )}
                        </div>
                    </div>

                    <div className="path-info">
                        <h4 className="flex items-center gap-2">
                            <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
                                <path d="M2 11a1 1 0 011-1h2a1 1 0 011 1v5a1 1 0 01-1 1H3a1 1 0 01-1-1v-5zM8 7a1 1 0 011-1h2a1 1 0 011 1v9a1 1 0 01-1 1H9a1 1 0 01-1-1V7zM14 4a1 1 0 011-1h2a1 1 0 011 1v12a1 1 0 01-1 1h-2a1 1 0 01-1-1V4z" />
                            </svg>
                            Statistics
                        </h4>
                        <div className="path-details" style={{ marginTop: '0.5rem', fontSize: '0.9rem' }}>
                            <p style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem', alignItems: 'center' }}>
                                <span className="flex items-center gap-1">
                                    <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                        <path fillRule="evenodd" d="M10 9a3 3 0 100-6 3 3 0 000 6zm-7 9a7 7 0 1114 0H3z" clipRule="evenodd" />
                                    </svg>
                                    Total Nodes
                                </span>
                                <strong>{nodeNames.size}</strong>
                            </p>
                            <p style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem', alignItems: 'center' }}>
                                <span className="flex items-center gap-1">
                                    <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                        <path fillRule="evenodd" d="M3 4a1 1 0 011-1h12a1 1 0 110 2H4a1 1 0 01-1-1zm0 4a1 1 0 011-1h12a1 1 0 110 2H4a1 1 0 01-1-1zm0 4a1 1 0 011-1h12a1 1 0 110 2H4a1 1 0 01-1-1zm0 4a1 1 0 011-1h12a1 1 0 110 2H4a1 1 0 01-1-1z" clipRule="evenodd" />
                                    </svg>
                                    Total Buckets
                                </span>
                                <strong>{bucketCount}</strong>
                            </p>
                            <p style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem', alignItems: 'center' }}>
                                <span className="flex items-center gap-1">
                                    <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                        <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zM7 9a1 1 0 000 2h6a1 1 0 100-2H7z" clipRule="evenodd" />
                                    </svg>
                                    Collisions
                                </span>
                                <strong>{hashMapData.steps.filter(s => s.isCollision && s.description && s.description.startsWith('Collision detected')).length}</strong>
                            </p>
                            <p style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem', alignItems: 'center' }}>
                                <span className="flex items-center gap-1">
                                    <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                        <path d="M2 11a1 1 0 011-1h2a1 1 0 011 1v5a1 1 0 01-1 1H3a1 1 0 01-1-1v-5zM8 7a1 1 0 011-1h2a1 1 0 011 1v9a1 1 0 01-1 1H9a1 1 0 01-1-1V7zM14 4a1 1 0 011-1h2a1 1 0 011 1v12a1 1 0 01-1 1h-2a1 1 0 01-1-1V4z" />
                                    </svg>
                                    Load Factor
                                </span>
                                <strong>{(nodeNames.size / bucketCount).toFixed(2)}</strong>
                            </p>
                        </div>
                    </div>
                </aside>

                <main className="viz-main">
                    <div className="explanation-box" style={{ marginBottom: '1rem' }}>
                        {currentStep ? (
                            <>
                                <span className="step-number">Step {currentStep.stepId + 1}:</span>
                                <span className="step-description">{currentStep.description}</span>
                                {currentStep.description.startsWith('Computing hash:') && (
                                    <span className="hash-info">
                                        &nbsp;Node <strong>{currentStep.insertedNodeName}</strong> (ID: {currentStep.insertedNodeId}) → bucket <strong>{currentStep.currentBucketIndex}</strong>.
                                    </span>
                                )}
                                {currentStep.isCollision && currentStep.description.startsWith('Collision detected') && (
                                    <span className="collision-info">
                                        &nbsp;Collision at bucket <strong>{currentStep.currentBucketIndex}</strong>.
                                    </span>
                                )}
                            </>
                        ) : (
                            <span>Select a floor to begin the visualization.</span>
                        )}
                    </div>

                    <div className="hashmap-visualization" ref={vizContainerRef} style={{ alignItems: 'flex-end' }}>
                        {buckets.map(index => {
                            const chainToDisplay = chainNodesForBucket(index);
                            const isCurrentBucket = currentStep?.currentBucketIndex === index;
                            const isSearchTargetBucket = searchResult?.bucketIndex === index;

                            return (
                                <div key={index} className="bucket-column" aria-label={`Bucket ${index}`}>
                                    {chainToDisplay.length === 0 && (
                                        <div style={{ minHeight: 40, display: 'flex', alignItems: 'center', color: '#9ca3af' }}>— empty —</div>
                                    )}

                                    {chainToDisplay.map((node, nodeIndex) => {
                                        const lastInsertedThisBucket = (() => {
                                            if (!hashMapData) return null;
                                            for (let i = currentStepIndex; i >= 0; i--) {
                                                const s = hashMapData.steps[i];
                                                if (s.currentBucketIndex === index && s.insertedNodeId != null) return s.insertedNodeId;
                                                if (s.currentBucketIndex === index && Array.isArray(s.chainState)) {
                                                    const snap = s.chainState as unknown as number[];
                                                    return snap.length ? snap[0] : null;
                                                }
                                            }
                                            return null;
                                        })();

                                        const isInsertedNode = node.id === lastInsertedThisBucket && currentStepIndex >= 0;
                                        const isSearchMatch = searchResult?.found && searchResult.nodeId === node.id;

                                        return (
                                            <div
                                                key={node.id}
                                                className={`chain-node ${isInsertedNode ? 'inserted-node' : ''} ${isCurrentBucket ? 'active-chain' : ''} ${isSearchMatch ? 'search-match' : ''}`}
                                                role="listitem"
                                                aria-label={`Node ${node.id}`}
                                            >
                                                <span className="node-id">{node.id}</span>
                                                <span className="node-name">{node.name}</span>
                                                <div className="chain-arrow">↓</div>
                                            </div>
                                        );
                                    })}

                                    <div
                                        className={`bucket-base ${isCurrentBucket ? 'active-bucket' : ''} ${currentStep?.isCollision && isCurrentBucket ? 'collision-bucket' : ''} ${isSearchTargetBucket ? 'search-bucket' : ''}`}
                                        aria-hidden={false}
                                    >
                                        <span className="bucket-number">{index}</span>
                                        <span className="bucket-label">Bucket</span>
                                    </div>
                                </div>
                            );
                        })}
                    </div>
                </main>
            </div>
        </div>
    );
};

export default HashMapPage;