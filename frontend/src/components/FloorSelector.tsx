import React from 'react';
import type { Floor } from '../types';
import './FloorSelector.css';

interface FloorSelectorProps {
  floors: Floor[];
  selectedFloor: Floor | null;
  onSelectFloor: (floor: Floor) => void;
  loading: boolean;
}

const FloorSelector: React.FC<FloorSelectorProps> = ({ 
  floors, 
  selectedFloor, 
  onSelectFloor, 
  loading 
}) => {
  return (
    <div className="floor-selector-section">
      <h3>Select a Floor</h3>
      {loading ? (
        <div className="loading-state">Loading floors...</div>
      ) : (
        <div className="floor-buttons">
          {floors.map(floor => (
            <button
              key={floor.id}
              onClick={() => onSelectFloor(floor)}
              className={`floor-button ${selectedFloor?.id === floor.id ? 'active' : ''}`}
            >
              <div className="floor-name">{floor.name}</div>
              <div className="floor-label">Floor {floor.floorNumber}</div>
            </button>
          ))}
        </div>
      )}
    </div>
  );
};

export default FloorSelector;

