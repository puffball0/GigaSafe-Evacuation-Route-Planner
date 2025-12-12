import React, { useRef, useEffect, useState } from 'react';
import type { Floor, GraphData, Node, VisualizationData } from '../types';
import { findNearestNode } from '../api/backendApi';
import './PlannerMapViewer.css';

interface PlannerMapViewerProps {
  floor: Floor | null;
  graphData: GraphData | null;
  selectedNode: Node | null;
  evacuationRoute: VisualizationData | null;
  onNodeSelect: (node: Node) => void;
  loading: boolean;
}

const PlannerMapViewer: React.FC<PlannerMapViewerProps> = ({
  floor,
  graphData,
  selectedNode,
  evacuationRoute,
  onNodeSelect,
  loading
}) => {
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const [mapImage, setMapImage] = useState<HTMLImageElement | null>(null);
  const [hoveredNode, setHoveredNode] = useState<Node | null>(null);
  const [mousePos, setMousePos] = useState<{ x: number; y: number }>({ x: 0, y: 0 });
  const [cursorCoords, setCursorCoords] = useState<{ x: number; y: number } | null>(null);

  // Load floor map image
  useEffect(() => {
    if (!floor) return;

    const img = new Image();
    const floorMaps: { [key: number]: string } = {
      1: '/maps/mezzaninefloor.jpg',
      2: '/maps/lowergroundfloor.jpg',
      3: '/maps/groundfloor.jpg',
      4: '/maps/firstfloor.jpg',
      5: '/maps/secondfloor.jpg',
      6: '/maps/2Afloor.jpg'
    };

    img.src = floorMaps[floor.id] || '';
    img.onload = () => setMapImage(img);
    img.onerror = () => console.error('Failed to load map image');
  }, [floor]);

  // Draw canvas
  useEffect(() => {
    if (!canvasRef.current || !mapImage || !graphData) return;

    const canvas = canvasRef.current;
    const ctx = canvas.getContext('2d');
    if (!ctx) return;

    const width = canvas.width;
    const height = canvas.height;

    // Clear canvas
    ctx.clearRect(0, 0, width, height);

    // Draw map image
    ctx.drawImage(mapImage, 0, 0, width, height);

    // Draw evacuation route path
    if (evacuationRoute) {
      const path = evacuationRoute.path;

      // Draw route line
      ctx.strokeStyle = '#ef4444';
      ctx.lineWidth = 6;
      ctx.lineCap = 'round';
      ctx.lineJoin = 'round';

      // Add glow effect
      ctx.shadowColor = '#ef4444';
      ctx.shadowBlur = 15;

      ctx.beginPath();
      for (let i = 0; i < path.length; i++) {
        const node = graphData.nodes.find(n => n.id === path[i]);
        if (!node) continue;

        if (i === 0) {
          ctx.moveTo(node.x, node.y);
        } else {
          ctx.lineTo(node.x, node.y);
        }
      }
      ctx.stroke();
      ctx.shadowBlur = 0;

      // Draw direction arrows on path
      ctx.fillStyle = '#ef4444';
      for (let i = 0; i < path.length - 1; i++) {
        const fromNode = graphData.nodes.find(n => n.id === path[i]);
        const toNode = graphData.nodes.find(n => n.id === path[i + 1]);
        if (!fromNode || !toNode) continue;

        const midX = (fromNode.x + toNode.x) / 2;
        const midY = (fromNode.y + toNode.y) / 2;
        const angle = Math.atan2(toNode.y - fromNode.y, toNode.x - fromNode.x);

        ctx.save();
        ctx.translate(midX, midY);
        ctx.rotate(angle);
        ctx.beginPath();
        ctx.moveTo(-8, -8);
        ctx.lineTo(8, 0);
        ctx.lineTo(-8, 8);
        ctx.closePath();
        ctx.fill();
        ctx.restore();
      }
    }

    // Draw nodes
    graphData.nodes.forEach(node => {
      if (node.isExit) {
        // Draw exit nodes
        ctx.fillStyle = '#22c55e';
        ctx.strokeStyle = '#16a34a';
        ctx.lineWidth = 3;

        ctx.beginPath();
        ctx.arc(node.x, node.y, 12, 0, Math.PI * 2);
        ctx.fill();
        ctx.stroke();

        // Exit label
        ctx.fillStyle = 'white';
        ctx.font = 'bold 10px sans-serif';
        ctx.textAlign = 'center';
        ctx.fillText('EXIT', node.x, node.y - 18);
      } else if (node.type === 'shop') {
        // Draw shop nodes (only if not in route or selected)
        const isInRoute = evacuationRoute?.path.includes(node.id);
        const isSelected = selectedNode?.id === node.id;

        if (!isInRoute && !isSelected) {
          ctx.fillStyle = '#3b82f6';
          ctx.strokeStyle = '#2563eb';
          ctx.lineWidth = 2;

          ctx.beginPath();
          ctx.arc(node.x, node.y, 8, 0, Math.PI * 2);
          ctx.fill();
          ctx.stroke();
        }
      }
    });

    // Highlight selected node
    if (selectedNode) {
      ctx.fillStyle = '#f59e0b';
      ctx.strokeStyle = '#d97706';
      ctx.lineWidth = 4;
      ctx.shadowColor = '#f59e0b';
      ctx.shadowBlur = 15;

      ctx.beginPath();
      ctx.arc(selectedNode.x, selectedNode.y, 14, 0, Math.PI * 2);
      ctx.fill();
      ctx.stroke();
      ctx.shadowBlur = 0;

      // Selected node label
      ctx.fillStyle = 'white';
      ctx.font = 'bold 11px sans-serif';
      ctx.textAlign = 'center';
      ctx.fillText(selectedNode.name, selectedNode.x, selectedNode.y - 20);
    }

    // Highlight hovered node
    if (hoveredNode && hoveredNode.id !== selectedNode?.id) {
      ctx.strokeStyle = '#60a5fa';
      ctx.lineWidth = 3;
      ctx.shadowColor = '#60a5fa';
      ctx.shadowBlur = 10;

      const radius = hoveredNode.isExit ? 12 : 10;
      ctx.beginPath();
      ctx.arc(hoveredNode.x, hoveredNode.y, radius, 0, Math.PI * 2);
      ctx.stroke();
      ctx.shadowBlur = 0;
    }

  }, [mapImage, graphData, selectedNode, evacuationRoute, hoveredNode]);

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
    const clickedNode = findNearestNode(x, y, graphData.nodes);

    if (clickedNode) {
      onNodeSelect(clickedNode);
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
    setCursorCoords({ x: Math.round(x), y: Math.round(y) });

    // Find hovered node
    let hovered: Node | null = null;
    for (const node of graphData.nodes) {
      if (node.isExit) continue;

      const dx = node.x - x;
      const dy = node.y - y;
      const radius = 15;

      if (Math.sqrt(dx * dx + dy * dy) < radius) {
        hovered = node;
        break;
      }
    }

    setHoveredNode(hovered);
    canvas.style.cursor = hovered ? 'pointer' : 'crosshair';
  };

  const handleMouseLeave = () => {
    setCursorCoords(null);
    setHoveredNode(null);
  };

  return (
    <div className="planner-map-container">
      {loading ? (
        <div className="loading-overlay">
          <div className="spinner"></div>
          <p>Loading map...</p>
        </div>
      ) : !floor || !graphData ? (
        <div className="empty-state">
          <p>No floor selected</p>
        </div>
      ) : (
        <>
          <canvas
            ref={canvasRef}
            width={1400}
            height={600}
            onClick={handleCanvasClick}
            onMouseMove={handleMouseMove}
            onMouseLeave={handleMouseLeave}
            className="planner-canvas"
          />

          {cursorCoords && (
            <div
              className="coords-tooltip"
              style={{
                left: mousePos.x + 15,
                top: mousePos.y + 15
              }}
            >
              X: {cursorCoords.x}, Y: {cursorCoords.y}
            </div>
          )}

          {hoveredNode && (
            <div
              className="node-tooltip"
              style={{
                left: mousePos.x + 15,
                top: mousePos.y + 15
              }}
            >
              <div className="tooltip-title">{hoveredNode.name}</div>
              <div className="tooltip-details">
                <span>Type: {hoveredNode.type}</span>
                <span>Click to select</span>
              </div>
            </div>
          )}

          <div className="map-legend">
            <div className="legend-item">
              <div className="legend-icon shop-icon"></div>
              <span>Shops</span>
            </div>
            <div className="legend-item">
              <div className="legend-icon exit-icon"></div>
              <span>Emergency Exits</span>
            </div>
            <div className="legend-item">
              <div className="legend-icon selected-icon"></div>
              <span>Your Location</span>
            </div>
            <div className="legend-item">
              <div className="legend-line route-line"></div>
              <span>Evacuation Route</span>
            </div>
          </div>
        </>
      )}
    </div>
  );
};

export default PlannerMapViewer;