import React, { useState, useEffect } from 'react';
import FloorSelector from '../components/FloorSelector';
import PlannerMapViewer from '../components/PlannerMapViewer';
import type { Floor, GraphData, Node, VisualizationData } from '../types';
import { fetchFloors, fetchGraphData, computeRoute } from '../api/backendApi';
import './PlannerPage.css';

interface PlannerPageProps {
  onBack: () => void;
}

const PlannerPage: React.FC<PlannerPageProps> = ({ onBack }) => {
  const [floors, setFloors] = useState<Floor[]>([]);
  const [selectedFloor, setSelectedFloor] = useState<Floor | null>(null);
  const [graphData, setGraphData] = useState<GraphData | null>(null);
  const [selectedNode, setSelectedNode] = useState<Node | null>(null);
  const [evacuationRoute, setEvacuationRoute] = useState<VisualizationData | null>(null);
  const [isComputing, setIsComputing] = useState(false);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<string | null>(null);

  // Load floors on mount
  useEffect(() => {
    const loadFloors = async () => {
      try {
        setLoading(true);
        const floorsData = await fetchFloors();
        setFloors(floorsData);
        if (floorsData.length > 0) {
          setSelectedFloor(floorsData[0]);
        }
      } catch (err) {
        setError('Failed to load floors');
        console.error(err);
      } finally {
        setLoading(false);
      }
    };

    loadFloors();
  }, []);

  // Load graph data when floor changes
  useEffect(() => {
    if (!selectedFloor) return;

    const loadGraphData = async () => {
      try {
        setLoading(true);
        setError(null);
        const data = await fetchGraphData(selectedFloor.id);
        setGraphData(data);
        setSelectedNode(null);
        setEvacuationRoute(null);
      } catch (err) {
        setError('Failed to load floor data');
        console.error(err);
      } finally {
        setLoading(false);
      }
    };

    loadGraphData();
  }, [selectedFloor]);

  const handleSelectFloor = (floor: Floor) => {
    setSelectedFloor(floor);
    setSelectedNode(null);
    setEvacuationRoute(null);
  };

  const handleNodeSelect = (node: Node) => {
    setSelectedNode(node);
    setEvacuationRoute(null);
  };

  const handleEvacuate = async () => {
    if (!selectedFloor || !selectedNode) return;

    try {
      setIsComputing(true);
      setError(null);
      const route = await computeRoute(selectedFloor.id, selectedNode.id);
      setEvacuationRoute(route);
    } catch (err) {
      setError('Failed to compute evacuation route');
      console.error(err);
    } finally {
      setIsComputing(false);
    }
  };

  const handleReset = () => {
    setSelectedNode(null);
    setEvacuationRoute(null);
  };

  const getInstructions = (): string[] => {
    if (!evacuationRoute || !graphData) return [];

    const instructions: string[] = [];
    const path = evacuationRoute.path;

    for (let i = 0; i < path.length; i++) {
      const node = graphData.nodes.find(n => n.id === path[i]);
      if (!node) continue;

      if (i === 0) {
        instructions.push(`Start from ${node.name}`);
      } else if (i === path.length - 1) {
        instructions.push(`Exit through ${node.name}`);
      } else {
        const prevNode = graphData.nodes.find(n => n.id === path[i - 1]);
        if (prevNode) {
          const distance = Math.sqrt(
            Math.pow(node.x - prevNode.x, 2) + Math.pow(node.y - prevNode.y, 2)
          ).toFixed(1);
          instructions.push(`Proceed to ${node.name} (${distance}m)`);
        }
      }
    }

    instructions.push(`Total distance: ${evacuationRoute.distance.toFixed(1)}m`);

    return instructions;
  };

  const shopNodes = graphData?.nodes.filter(n => n.type === 'shop' && !n.isExit) || [];

  return (
    <div className="evacuation-planner">
      <div className="planner-header">
        <button className="back-button" onClick={onBack}>
          ← Back to Home
        </button>
        <h2>GigaSafe Evacuation Planner</h2>
      </div>

      <div className="planner-container">
        <aside className="sidebar">
          <FloorSelector
            floors={floors}
            selectedFloor={selectedFloor}
            onSelectFloor={handleSelectFloor}
            loading={loading}
          />

          {selectedFloor && (
            <div className="evacuation-section">
              <h3>Your Location</h3>
              
              <div className="location-selector">
                <label htmlFor="store-select">Select Store:</label>
                <select
                  id="store-select"
                  value={selectedNode?.id || ''}
                  onChange={(e) => {
                    const nodeId = parseInt(e.target.value);
                    const node = shopNodes.find(n => n.id === nodeId);
                    if (node) handleNodeSelect(node);
                  }}
                  className="store-dropdown"
                >
                  <option value="">-- Select a store --</option>
                  {shopNodes.map(node => (
                    <option key={node.id} value={node.id}>
                      {node.name}
                    </option>
                  ))}
                </select>
              </div>

              <div className="status-box">
                <p>
                  <span>Floor:</span> {selectedFloor.name}
                </p>
                <p>
                  <span>Location:</span>{' '}
                  <span className={selectedNode ? 'selected' : 'not-selected'}>
                    {selectedNode ? `${selectedNode.name} ✓` : 'Not selected'}
                  </span>
                </p>
                <p>
                  <span>Route:</span>{' '}
                  <span className={evacuationRoute ? 'computed' : 'not-computed'}>
                    {evacuationRoute ? 'Computed ✓' : 'Not computed'}
                  </span>
                </p>
              </div>

              <button
                className="evacuate-button"
                onClick={handleEvacuate}
                disabled={!selectedNode || isComputing}
              >
                {isComputing ? 'Computing Route...' : '🔥 Compute Evacuation Route'}
              </button>

              {evacuationRoute && (
                <button className="reset-button" onClick={handleReset}>
                  Reset Route
                </button>
              )}
            </div>
          )}

          {error && (
            <div className="error-message">
              {error}
            </div>
          )}
        </aside>

        <main className="planner-main">
          <div className="route-section">
            <h3>{evacuationRoute ? 'Your Evacuation Route' : 'Select Your Location'}</h3>
            <p className="instruction">
              {evacuationRoute 
                ? 'Follow the highlighted path to the nearest exit' 
                : 'Click on the map or use the dropdown to select your location'}
            </p>
            
            <PlannerMapViewer
              floor={selectedFloor}
              graphData={graphData}
              selectedNode={selectedNode}
              evacuationRoute={evacuationRoute}
              onNodeSelect={handleNodeSelect}
              loading={loading}
            />

            {evacuationRoute && (
              <div className="instructions-panel">
                <h4>Evacuation Instructions</h4>
                <ol className="instructions-list">
                  {getInstructions().map((instruction, idx) => (
                    <li key={idx}>{instruction}</li>
                  ))}
                </ol>
              </div>
            )}
          </div>
        </main>
      </div>
    </div>
  );
};

export default PlannerPage;