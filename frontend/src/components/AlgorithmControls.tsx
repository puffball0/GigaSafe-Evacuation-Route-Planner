import React from 'react';
import type { GraphData } from '../types';
import './AlgorithmControls.css';

interface AlgorithmControlsProps {
  selectedNode: number | null;
  algorithm: string;
  onAlgorithmChange: (algorithm: string) => void;
  onCompute: () => void;
  onReset: () => void;
  isComputing: boolean;
  hasVisualization: boolean;
  graphData: GraphData | null;
  onNodeSelect: (nodeId: number) => void;
}

const AlgorithmControls: React.FC<AlgorithmControlsProps> = ({
  selectedNode,
  algorithm,
  onAlgorithmChange,
  onCompute,
  onReset,
  isComputing,
  hasVisualization,
  graphData,
  onNodeSelect
}) => {
  const shopNodes = graphData?.nodes.filter(n => n.type === 'shop' && !n.isExit) || [];

  return (
    <div className="algorithm-controls-section">
      <h3>Algorithm Controls</h3>

      {/* Node Selection Dropdown */}
      <div className="control-group">
        <label htmlFor="node-select">Select Starting Location</label>
        <select
          id="node-select"
          value={selectedNode || ''}
          onChange={(e) => onNodeSelect(parseInt(e.target.value))}
          className="node-select"
        >
          <option value="">-- Select a store --</option>
          {shopNodes.map(node => (
            <option key={node.id} value={node.id}>
              {node.name} (ID: {node.id})
            </option>
          ))}
        </select>
      </div>

      {/* Algorithm Selection */}
      <div className="control-group">
        <label htmlFor="algo-select">Algorithm</label>
        <select
          id="algo-select"
          value={algorithm}
          onChange={(e) => onAlgorithmChange(e.target.value)}
          className="algo-select"
        >
          <option value="dijkstra">Dijkstra's Algorithm</option>
          <option value="astar">A* Algorithm</option>
          <option value="bfs">BFS (Breadth-First Search)</option>
          <option value="dfs">DFS (Depth-First Search)</option>
        </select>
      </div>

      {/* Algorithm Description */}
      <div className="algorithm-description">
        {algorithm === 'dijkstra' && (
          <p><strong>Dijkstra:</strong> Finds shortest path based on actual distances. Guarantees optimal path but slower.</p>
        )}
        {algorithm === 'astar' && (
          <p><strong>A*:</strong> Uses heuristics for faster search. Good for known exit locations with position data.</p>
        )}
        {algorithm === 'bfs' && (
          <p><strong>BFS:</strong> Explores level by level. Finds shortest path in terms of number of hops (not distance).</p>
        )}
        {algorithm === 'dfs' && (
          <p><strong>DFS:</strong> Explores depth-first. May find longer paths but explores thoroughly. Not optimal for distance.</p>
        )}
      </div>

      {/* Compute Button */}
      <button
        onClick={onCompute}
        disabled={!selectedNode || isComputing}
        className="compute-button"
      >
        {isComputing ? (
          <>
            <span className="spinner-small"></span>
            Computing...
          </>
        ) : (
          <>🔥 Compute Evacuation Route</>
        )}
      </button>

      {/* Reset Button */}
      {hasVisualization && (
        <button onClick={onReset} className="reset-button">
          Reset Visualization
        </button>
      )}
    </div>
  );
};

export default AlgorithmControls;