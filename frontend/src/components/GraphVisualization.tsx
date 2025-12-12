import React, { useRef, useEffect, useState } from 'react';
import type { GraphData, VisualizationData, Node, AlgorithmState } from '../types';
import './GraphVisualization.css';

interface GraphVisualizationProps {
  graphData: GraphData | null;
  selectedNode: number | null;
  visualizationData: VisualizationData | null;
  currentStep: number;
  onNodeSelect: (nodeId: number) => void;
  loading: boolean;
}

const GraphVisualization: React.FC<GraphVisualizationProps> = ({
  graphData,
  selectedNode,
  visualizationData,
  currentStep,
  onNodeSelect,
  loading
}) => {
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const [hoveredNode, setHoveredNode] = useState<number | null>(null);
  const [mousePos, setMousePos] = useState<{ x: number; y: number }>({ x: 0, y: 0 });

  useEffect(() => {
    if (!canvasRef.current || !graphData || loading) return;

    const canvas = canvasRef.current;
    const ctx = canvas.getContext('2d');
    if (!ctx) return;

    const width = canvas.width;
    const height = canvas.height;

    // Clear canvas
    ctx.clearRect(0, 0, width, height);

    // Draw grid
    ctx.strokeStyle = 'rgba(255, 255, 255, 0.03)';
    ctx.lineWidth = 1;
    for (let x = 0; x < width; x += 50) {
      ctx.beginPath();
      ctx.moveTo(x, 0);
      ctx.lineTo(x, height);
      ctx.stroke();
    }
    for (let y = 0; y < height; y += 50) {
      ctx.beginPath();
      ctx.moveTo(0, y);
      ctx.lineTo(width, y);
      ctx.stroke();
    }

    // Get current algorithm state
    const currentState: AlgorithmState | null = visualizationData && visualizationData.states && currentStep >= 0 && currentStep < visualizationData.states.length
      ? visualizationData.states[currentStep]
      : null;

    // Draw all edges (default color)
    ctx.strokeStyle = '#3f3f46';
    ctx.lineWidth = 2;
    graphData.edges.forEach(edge => {
      const fromNode = graphData.nodes.find(n => n.id === edge.from);
      const toNode = graphData.nodes.find(n => n.id === edge.to);
      if (fromNode && toNode) {
        ctx.beginPath();
        ctx.moveTo(fromNode.x, fromNode.y);
        ctx.lineTo(toNode.x, toNode.y);
        ctx.stroke();
      }
    });

    // Highlight active edge (currently exploring)
    if (currentState && currentState.activeEdge[0] !== -1 && currentState.activeEdge[1] !== -1) {
      const fromNode = graphData.nodes.find(n => n.id === currentState.activeEdge[0]);
      const toNode = graphData.nodes.find(n => n.id === currentState.activeEdge[1]);

      if (fromNode && toNode) {
        ctx.strokeStyle = '#f59e0b';  // Orange for active edge
        ctx.lineWidth = 5;
        ctx.beginPath();
        ctx.moveTo(fromNode.x, fromNode.y);
        ctx.lineTo(toNode.x, toNode.y);
        ctx.stroke();

        // Glow effect
        ctx.shadowColor = '#f59e0b';
        ctx.shadowBlur = 15;
        ctx.stroke();
        ctx.shadowBlur = 0;
      }
    }

    // Highlight visited edges (all edges between visited nodes)
    if (currentState && currentState.visitedNodes.length > 0) {
      ctx.strokeStyle = '#a855f7';  // Purple for visited edges
      ctx.lineWidth = 3;

      graphData.edges.forEach(edge => {
        const isFromVisited = currentState.visitedNodes.includes(edge.from);
        const isToVisited = currentState.visitedNodes.includes(edge.to);

        if (isFromVisited && isToVisited) {
          const fromNode = graphData.nodes.find(n => n.id === edge.from);
          const toNode = graphData.nodes.find(n => n.id === edge.to);

          if (fromNode && toNode) {
            ctx.beginPath();
            ctx.moveTo(fromNode.x, fromNode.y);
            ctx.lineTo(toNode.x, toNode.y);
            ctx.stroke();
          }
        }
      });
    }

    // Highlight final path (only at the last step)
    if (visualizationData && visualizationData.states && currentStep === visualizationData.states.length - 1) {
      ctx.strokeStyle = '#ef4444';  // Red for final path
      ctx.lineWidth = 5;

      for (let i = 0; i < visualizationData.path.length - 1; i++) {
        const fromNode = graphData.nodes.find(n => n.id === visualizationData.path[i]);
        const toNode = graphData.nodes.find(n => n.id === visualizationData.path[i + 1]);

        if (fromNode && toNode) {
          ctx.beginPath();
          ctx.moveTo(fromNode.x, fromNode.y);
          ctx.lineTo(toNode.x, toNode.y);
          ctx.stroke();

          // Glow effect
          ctx.shadowColor = '#ef4444';
          ctx.shadowBlur = 15;
          ctx.stroke();
          ctx.shadowBlur = 0;
        }
      }
    }

    // Draw nodes
    graphData.nodes.forEach(node => {
      let fillColor = '#18181b';     // Default: dark
      let borderColor = '#71717a';   // Default: gray
      let radius = 8;
      let borderWidth = 2;

      // Base node type colors
      if (node.isExit) {
        fillColor = '#22c55e';         // Green for exits
        borderColor = '#16a34a';
        radius = 12;
      } else if (node.type === 'shop') {
        fillColor = '#3b82f6';         // Blue for shops
        borderColor = '#2563eb';
        radius = 10;
      } else if (node.type === 'corridor') {
        fillColor = '#6b7280';         // Gray for corridors
        borderColor = '#4b5563';
        radius = 6;
      }

      // State-based coloring
      if (currentState) {
        // Unvisited nodes override removed to preserve base colors as per user request


        // Visited nodes (Purple)
        if (currentState.visitedNodes.includes(node.id)) {
          fillColor = '#a855f7';
          borderColor = '#9333ea';
          borderWidth = 3;
        }

        // Currently exploring node (yellow)
        if (node.id === currentState.exploringNode && currentState.exploringNode !== -1) {
          fillColor = '#fbbf24';
          borderColor = '#f59e0b';
          radius += 3;
          borderWidth = 4;

          // Pulse effect
          ctx.shadowColor = '#fbbf24';
          ctx.shadowBlur = 20;
        }

        // Current node being processed (orange with strong glow)
        if (node.id === currentState.currentNode && currentState.currentNode !== -1) {
          fillColor = '#f59e0b';
          borderColor = '#d97706';
          radius += 4;
          borderWidth = 5;

          // Strong pulse effect
          ctx.shadowColor = '#f59e0b';
          ctx.shadowBlur = 25;
        }

        // Final path nodes at completion
        if (visualizationData && visualizationData.states && currentStep === visualizationData.states.length - 1) {
          if (visualizationData.path.includes(node.id)) {
            borderColor = '#ef4444';
            borderWidth = 4;
          }
        }
      }

      // Highlight selected node
      if (node.id === selectedNode) {
        borderColor = '#ef4444';
        borderWidth = 4;
        radius += 2;
      }

      // Highlight hovered node
      if (hoveredNode === node.id) {
        radius += 2;
        ctx.shadowColor = borderColor;
        ctx.shadowBlur = 10;
      }

      // Draw node
      ctx.lineWidth = borderWidth;
      ctx.beginPath();
      ctx.arc(node.x, node.y, radius, 0, Math.PI * 2);
      ctx.fillStyle = fillColor;
      ctx.fill();
      ctx.strokeStyle = borderColor;
      ctx.stroke();
      ctx.shadowBlur = 0;

      // Draw node labels for shops and exits
      if (node.type === 'shop' || node.isExit) {
        ctx.fillStyle = 'white';
        ctx.font = 'bold 10px sans-serif';
        ctx.textAlign = 'center';
        ctx.fillText(node.id.toString(), node.x, node.y - radius - 5);
      }
    });
  }, [graphData, selectedNode, visualizationData, currentStep, loading, hoveredNode]);

  const handleCanvasClick = (e: React.MouseEvent<HTMLCanvasElement>) => {
    if (!graphData) return;

    const canvas = canvasRef.current;
    if (!canvas) return;

    const rect = canvas.getBoundingClientRect();
    const scaleX = canvas.width / rect.width;
    const scaleY = canvas.height / rect.height;

    const x = (e.clientX - rect.left) * scaleX;
    const y = (e.clientY - rect.top) * scaleY;

    // Find clicked node
    const clickedNode = graphData.nodes.find(node => {
      const dx = node.x - x;
      const dy = node.y - y;
      const radius = node.isExit ? 12 : node.type === 'shop' ? 10 : 6;
      return Math.sqrt(dx * dx + dy * dy) < radius + 5;
    });

    if (clickedNode && !clickedNode.isExit) {
      onNodeSelect(clickedNode.id);
    }
  };

  const handleMouseMove = (e: React.MouseEvent<HTMLCanvasElement>) => {
    if (!graphData) return;

    const canvas = canvasRef.current;
    if (!canvas) return;

    const rect = canvas.getBoundingClientRect();
    const scaleX = canvas.width / rect.width;
    const scaleY = canvas.height / rect.height;

    const x = (e.clientX - rect.left) * scaleX;
    const y = (e.clientY - rect.top) * scaleY;

    setMousePos({ x: e.clientX, y: e.clientY }); // Keep tooltip usage of screen coords

    // Find hovered node
    const hovered = graphData.nodes.find(node => {
      const dx = node.x - x;
      const dy = node.y - y;
      const radius = node.isExit ? 12 : node.type === 'shop' ? 10 : 6;
      return Math.sqrt(dx * dx + dy * dy) < radius + 5;
    });

    setHoveredNode(hovered ? hovered.id : null);
    canvas.style.cursor = hovered && !hovered.isExit ? 'pointer' : 'default';
  };

  const getNodeInfo = (): Node | null => {
    if (!hoveredNode || !graphData) return null;
    return graphData.nodes.find(n => n.id === hoveredNode) || null;
  };

  const nodeInfo = getNodeInfo();

  return (
    <div className="graph-visualization-container">
      {loading ? (
        <div className="loading-overlay">
          <div className="spinner"></div>
          <p>Loading graph...</p>
        </div>
      ) : !graphData ? (
        <div className="empty-state">
          <p>No graph data available</p>
        </div>
      ) : (
        <>
          <canvas
            ref={canvasRef}
            width={1400}
            height={600}
            onClick={handleCanvasClick}
            onMouseMove={handleMouseMove}
            className="graph-canvas"
          />
          {nodeInfo && (
            <div
              className="node-tooltip"
              style={{
                left: mousePos.x + 15,
                top: mousePos.y + 15
              }}
            >
              <div className="tooltip-title">{nodeInfo.name}</div>
              <div className="tooltip-details">
                <span>ID: {nodeInfo.id}</span>
                <span>Type: {nodeInfo.type}</span>
                <span>Position: ({nodeInfo.x}, {nodeInfo.y})</span>
              </div>
            </div>
          )}
          <div className="graph-legend">
            <div className="legend-item">
              <div className="legend-icon" style={{ background: '#f3f4f6', borderColor: '#d1d5db', border: '2px solid' }}></div>
              <span>Unvisited</span>
            </div>
            <div className="legend-item">
              <div className="legend-icon" style={{ background: '#fbbf24', borderColor: '#f59e0b', border: '2px solid' }}></div>
              <span>Exploring</span>
            </div>
            <div className="legend-item">
              <div className="legend-icon current-icon"></div>
              <span>Current</span>
            </div>
            <div className="legend-item">
              <div className="legend-icon" style={{ background: '#a855f7', borderColor: '#9333ea', border: '2px solid' }}></div>
              <span>Visited</span>
            </div>
            <div className="legend-item">
              <div className="legend-icon exit-icon"></div>
              <span>Exit</span>
            </div>
            <div className="legend-item">
              <div className="legend-line" style={{ background: '#f59e0b', width: '32px', height: '4px', borderRadius: '2px' }}></div>
              <span>Active Edge</span>
            </div>
            <div className="legend-item">
              <div className="legend-line" style={{ background: '#a855f7', width: '32px', height: '4px', borderRadius: '2px' }}></div>
              <span>Visited Edges</span>
            </div>
            <div className="legend-item">
              <div className="legend-line final-line"></div>
              <span>Final Path</span>
            </div>
          </div>
        </>
      )}
    </div>
  );
};

export default GraphVisualization;