import React, { useState, useEffect } from 'react';
import FloorSelector from '../components/FloorSelector';
import GraphVisualization from '../components/GraphVisualization';
import AlgorithmControls from '../components/AlgorithmControls';
import VisualizationStatus from '../components/VisualizationStatus';
import { fetchGraphData, computeRoute } from '../api/backendApi';
import type { Floor, GraphData, VisualizationData } from '../types';
import './VisualizationPage.css';

interface VisualizationPageProps {
  onBack: () => void;
}

const VisualizationPage: React.FC<VisualizationPageProps> = ({ onBack }) => {
  const [floors] = useState<Floor[]>([
    { id: 1, name: 'Mezzanine Floor', floorNumber: 'Mezzanine' },
    { id: 2, name: 'Lower Ground Floor', floorNumber: 'Lower Ground' },
    { id: 3, name: 'Ground Floor', floorNumber: 0 },
    { id: 4, name: 'First Floor', floorNumber: 1 },
    { id: 5, name: 'Second Floor', floorNumber: 2 },
    { id: 6, name: '2A Floor', floorNumber: '2A' }
  ]);

  const [selectedFloor, setSelectedFloor] = useState<Floor>(floors[4]); // Default: Second Floor
  const [graphData, setGraphData] = useState<GraphData | null>(null);
  const [selectedNode, setSelectedNode] = useState<number | null>(null);
  const [algorithm, setAlgorithm] = useState<string>('dijkstra');
  const [isComputing, setIsComputing] = useState<boolean>(false);
  const [visualizationData, setVisualizationData] = useState<VisualizationData | null>(null);
  const [currentStep, setCurrentStep] = useState<number>(0);
  const [isPlaying, setIsPlaying] = useState<boolean>(false);
  const [loading, setLoading] = useState<boolean>(false);
  const [error, setError] = useState<string | null>(null);

  // Load graph data when floor changes
  useEffect(() => {
    loadGraph();
  }, [selectedFloor]);

  const loadGraph = async () => {
    try {
      setLoading(true);
      setError(null);
      const data = await fetchGraphData(selectedFloor.id);
      setGraphData(data);
      setSelectedNode(null);
      setVisualizationData(null);
      setCurrentStep(0);
    } catch (err) {
      setError('Failed to load graph data');
      console.error(err);
    } finally {
      setLoading(false);
    }
  };

  const handleFloorSelect = (floor: Floor) => {
    setSelectedFloor(floor);
    setSelectedNode(null);
    setVisualizationData(null);
    setCurrentStep(0);
    setIsPlaying(false);
  };

  const handleNodeSelect = (nodeId: number) => {
    if (graphData) {
      const node = graphData.nodes.find(n => n.id === nodeId);
      if (node && !node.isExit) {
        setSelectedNode(nodeId);
        setVisualizationData(null);
        setCurrentStep(0);
        setIsPlaying(false);
      }
    }
  };

  const handleAlgorithmChange = (newAlgorithm: string) => {
    setAlgorithm(newAlgorithm);
    // Reset visualization when algorithm changes
    setVisualizationData(null);
    setCurrentStep(0);
    setIsPlaying(false);
  };

  const handleComputeRoute = async () => {
    if (!selectedNode || !selectedFloor) {
      setError('Please select a starting location');
      return;
    }

    try {
      setIsComputing(true);
      setError(null);
      const result = await computeRoute(selectedFloor.id, selectedNode, algorithm);
      setVisualizationData(result);
      setCurrentStep(0);
      setIsPlaying(false);
    } catch (err) {
      setError(`Failed to compute route using ${algorithm.toUpperCase()}`);
      console.error(err);
    } finally {
      setIsComputing(false);
    }
  };

  const handleReset = () => {
    setSelectedNode(null);
    setVisualizationData(null);
    setCurrentStep(0);
    setIsPlaying(false);
  };

  const handleStepChange = (step: number) => {
    setCurrentStep(step);
    setIsPlaying(false);
  };

  const handlePlayPause = () => {
    setIsPlaying(!isPlaying);
  };

  // Auto-play visualization
  useEffect(() => {
    if (!isPlaying || !visualizationData) return;

    const timer = setInterval(() => {
      if (!visualizationData.states) return;
      setCurrentStep(prev => {
        if (prev >= visualizationData.states!.length - 1) {
          setIsPlaying(false);
          return prev;
        }
        return prev + 1;
      });
    }, 800); // 800ms per step

    return () => clearInterval(timer);
  }, [isPlaying, visualizationData]);

  const getAlgorithmDisplayName = (algo: string): string => {
    const names: Record<string, string> = {
      dijkstra: "Dijkstra's Algorithm",
      astar: "A* Algorithm",
      bfs: "Breadth-First Search",
      dfs: "Depth-First Search"
    };
    return names[algo] || algo.toUpperCase();
  };

  return (
    <div className="visualization-page">
      {/* Header */}
      <div className="viz-header">
        <button className="back-button" onClick={onBack}>
          ← Back to Home
        </button>
        <h2>Algorithm Visualization - Step by Step</h2>
      </div>

      <div className="viz-container">
        {/* Sidebar */}
        <aside className="viz-sidebar">
          <FloorSelector
            floors={floors}
            selectedFloor={selectedFloor}
            onSelectFloor={handleFloorSelect}
            loading={loading}
          />

          <AlgorithmControls
            selectedNode={selectedNode}
            algorithm={algorithm}
            onAlgorithmChange={handleAlgorithmChange}
            onCompute={handleComputeRoute}
            onReset={handleReset}
            isComputing={isComputing}
            hasVisualization={!!visualizationData}
            graphData={graphData}
            onNodeSelect={handleNodeSelect}
          />

          <VisualizationStatus
            floor={selectedFloor}
            selectedNode={selectedNode}
            visualizationData={visualizationData}
            graphData={graphData}
            currentStep={currentStep}
            isPlaying={isPlaying}
            onStepChange={handleStepChange}
            onPlayPause={handlePlayPause}
            algorithm={algorithm}
          />
        </aside>

        {/* Main Content */}
        <main className="viz-main">
          {error && (
            <div className="error-message">
              <span>⚠️</span> {error}
            </div>
          )}

          <div className="graph-section">
            <h3>Graph Visualization</h3>
            <p className="instruction">
              {!selectedNode
                ? 'Click on any store/node on the graph or select from the dropdown'
                : !visualizationData
                  ? 'Click "Compute Route" to start step-by-step visualization'
                  : `Watch ${getAlgorithmDisplayName(algorithm)} explore nodes step by step`}
            </p>

            <GraphVisualization
              graphData={graphData}
              selectedNode={selectedNode}
              visualizationData={visualizationData}
              currentStep={currentStep}
              onNodeSelect={handleNodeSelect}
              loading={loading}
            />
          </div>

          {visualizationData && (
            <div className="path-info">
              <h4>Algorithm Summary</h4>
              <div className="path-details">
                <p>
                  <span>Algorithm:</span> <strong>{getAlgorithmDisplayName(algorithm)}</strong>
                </p>
                <p>
                  <span>Start Node:</span> <strong>{selectedNode}</strong>
                </p>
                <p>
                  <span>Exit Node:</span> <strong>{visualizationData.exitId}</strong>
                </p>
                <p>
                  <span>Total Steps:</span> <strong>{visualizationData.states?.length || 0}</strong>
                </p>
                {visualizationData.states && currentStep === visualizationData.states.length - 1 && (
                  <>
                    <p>
                      <span>Total Distance:</span>{' '}
                      <strong className="distance">
                        {algorithm === 'bfs'
                          ? `${visualizationData.distance} hops`
                          : `${visualizationData.distance.toFixed(2)} units`}
                      </strong>
                    </p>
                    <p>
                      <span>Path Length:</span> <strong>{visualizationData.path.length} nodes</strong>
                    </p>
                  </>
                )}
              </div>

              {visualizationData.states && currentStep === visualizationData.states.length - 1 && (
                <div className="path-sequence">
                  <h5>Final Path:</h5>
                  <div className="path-nodes">
                    {visualizationData.path.map((nodeId, idx) => (
                      <React.Fragment key={nodeId}>
                        <span className={nodeId === visualizationData.exitId ? 'exit-node' : 'path-node'}>
                          {nodeId}
                        </span>
                        {idx < visualizationData.path.length - 1 && <span className="arrow">→</span>}
                      </React.Fragment>
                    ))}
                  </div>
                </div>
              )}
            </div>
          )}
        </main>
      </div>
    </div>
  );
};

export default VisualizationPage;