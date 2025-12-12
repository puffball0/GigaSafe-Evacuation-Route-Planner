import React from 'react';
import type { Floor, GraphData, VisualizationData } from '../types';
import './VisualizationStatus.css';

interface VisualizationStatusProps {
  floor: Floor;
  selectedNode: number | null;
  visualizationData: VisualizationData | null;
  graphData: GraphData | null;
  currentStep: number;
  isPlaying: boolean;
  onStepChange: (step: number) => void;
  onPlayPause: () => void;
  algorithm: string;
}

const VisualizationStatus: React.FC<VisualizationStatusProps> = ({
  floor,
  selectedNode,
  visualizationData,
  graphData,
  currentStep,
  isPlaying,
  onStepChange,
  onPlayPause,
  algorithm
}) => {
  const getNodeName = (nodeId: number): string => {
    if (!graphData) return nodeId.toString();
    const node = graphData.nodes.find(n => n.id === nodeId);
    return node ? node.name : `Node ${nodeId}`;
  };

  const getAlgorithmDisplayName = (algo: string): string => {
    const names: Record<string, string> = {
      dijkstra: "Dijkstra",
      astar: "A*",
      bfs: "BFS",
      dfs: "DFS"
    };
    return names[algo] || algo.toUpperCase();
  };

  // Get current state message
  const getCurrentStateMessage = (): string => {
    if (!visualizationData || !visualizationData.states || currentStep < 0 || currentStep >= visualizationData.states.length) {
      return "No active state";
    }
    return visualizationData.states[currentStep].message;
  };

  // Get queue/stack state
  const getQueueState = (): number[] => {
    if (!visualizationData || !visualizationData.states || currentStep < 0 || currentStep >= visualizationData.states.length) {
      return [];
    }
    return visualizationData.states[currentStep].queueState;
  };

  return (
    <div className="visualization-status-section">
      <h3>Visualization Status</h3>

      <div className="status-box">
        <p>
          <span>Floor:</span>
          <strong>{floor.name}</strong>
        </p>
        <p>
          <span>Algorithm:</span>
          <strong className="algorithm-badge">{getAlgorithmDisplayName(algorithm)}</strong>
        </p>
        <p>
          <span>Starting Location:</span>
          {selectedNode ? (
            <strong className="selected">{getNodeName(selectedNode)} ✓</strong>
          ) : (
            <span className="not-selected">Not selected</span>
          )}
        </p>
        <p>
          <span>Route Status:</span>
          {visualizationData ? (
            <strong className="computed">Computed ✓</strong>
          ) : (
            <span className="not-computed">Not computed</span>
          )}
        </p>
      </div>

      {visualizationData && (
        <>
          {/* Current State Message */}
          <div className="current-state-message">
            <div className="state-label">Current Step:</div>
            <div className="state-text">{getCurrentStateMessage()}</div>
          </div>

          {/* Queue/Stack State */}
          {getQueueState().length > 0 && (
            <div className="queue-state">
              <div className="queue-label">
                {algorithm === 'bfs' ? 'Queue:' : algorithm === 'dfs' ? 'Stack:' : 'Priority Queue:'}
              </div>
              <div className="queue-items">
                {getQueueState().map((nodeId, idx) => (
                  <span key={idx} className="queue-item">
                    {nodeId}
                  </span>
                ))}
              </div>
            </div>
          )}

          {/* Playback Controls */}
          <div className="playback-controls">
            <button onClick={onPlayPause} className="play-button">
              {isPlaying ? '⏸️ Pause' : '▶️ Play'}
            </button>

            <div className="step-info">
              Step {currentStep + 1} of {visualizationData.states?.length || 0}
            </div>
          </div>

          {/* Step Slider */}
          <div className="step-slider">
            <input
              type="range"
              min="0"
              max={(visualizationData.states?.length || 1) - 1}
              value={currentStep}
              onChange={(e) => onStepChange(parseInt(e.target.value))}
              className="slider"
            />
            <div className="slider-labels">
              <span>Start</span>
              <span>End</span>
            </div>
          </div>

          {/* Statistics */}
          <div className="stats-box">
            <div className="stat-item">
              <span>Nodes Explored:</span>
              <strong>{visualizationData.states?.[currentStep]?.visitedNodes.length || 0}</strong>
            </div>
            <div className="stat-item">
              <span>Total Steps:</span>
              <strong>{visualizationData.states?.length || 0}</strong>
            </div>
            {visualizationData.states && currentStep === visualizationData.states.length - 1 && (
              <>
                <div className="stat-item">
                  <span>Path Length:</span>
                  <strong>{visualizationData.path.length} nodes</strong>
                </div>
                <div className="stat-item">
                  <span>Distance:</span>
                  <strong>
                    {algorithm === 'bfs'
                      ? `${visualizationData.distance} hops`
                      : `${visualizationData.distance.toFixed(2)} units`}
                  </strong>
                </div>
              </>
            )}
          </div>
        </>
      )}
    </div>
  );
};

export default VisualizationStatus;