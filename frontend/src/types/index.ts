
// // =====================
// // Floor Types
// // =====================
// export interface Floor {
//   id: number;
//   name: string;
//   floorNumber: number | string;
// }

// // =====================
// // Node Types
// // =====================
// export interface Node {
//   id: number;
//   name: string;
//   type: 'shop' | 'corridor' | 'exit' | 'stairs';
//   x: number;
//   y: number;
//   floor: number;
//   isExit: boolean;
// }

// // =====================
// // Edge Types
// // =====================
// export interface Edge {
//   from: number;
//   to: number;
//   distance: number;
//   type: string;
// }

// // =====================
// // Graph Data
// // =====================
// export interface GraphData {
//   floorId: number;
//   nodes: Node[];
//   edges: Edge[];
// }

// // =====================
// // Algorithm State (Step-by-Step Visualization)
// // =====================
// export interface AlgorithmState {
//   currentNode: number;                 // Node being processed
//   exploringNode: number;               // Node being explored
//   activeEdge: [number, number];        // Current edge being checked
//   queueState: number[];                // Queue or stack contents
//   visitedNodes: number[];              // All visited nodes
//   message: string;                     // Description of step
// }

// // =====================
// // Visualization Data
// // =====================
// export interface VisualizationData {
//   startNodeId: number;
//   exitId: number;
//   distance: number;
//   path: number[];
//   algorithm: string;

//   // From version 1
//   states?: AlgorithmState[];

//   // From version 2
//   visitedOrder?: number[];
//   exploredEdges?: Array<{ from: number; to: number }>;

//   floorId?: number;
// }

// // =====================
// // Location Type (Planner)
// // =====================
// export interface Location {
//   x: number;
//   y: number;
//   nodeId?: number;
// }

// // =====================
// // Evacuation Route (Planner)
// // =====================
// export interface EvacuationRoute {
//   path: number[];
//   distance: number;
//   exitId: number;
//   instructions: string[];
// }

// // =====================
// // Page Types
// // =====================
// export type Page = 'home' | 'visualization' | 'planner' | 'hashmap';

// // =====================
// // HashMap Visualization Types
// // =====================
// export interface HashMapState {
//   stepId: number;
//   description: string;
//   currentBucketIndex: number;
//   insertedNodeId: number;
//   insertedNodeName: string;
//   isCollision: boolean;
//   chainState: number[]; // List of Node IDs in the chain
// }

// export interface HashMapData {
//   steps: HashMapState[];
// }






// =====================
// Floor Types (Used by both)
// =====================
export interface Floor {
  id: number;
  name: string;
  floorNumber: string | number;
}

// =====================
// Node & Graph Types (Used by VisualizationStatus)
// =====================
export interface Node {
  id: number;
  name: string;
  type: 'shop' | 'corridor' | 'exit' | 'stairs';
  x: number;
  y: number;
  floor: number;
  isExit: boolean;
}

export interface Edge {
  from: number;
  to: number;
  distance: number;
  type: string;
}

export interface GraphData {
  floorId: number;
  nodes: Node[];
  edges: Edge[];
}

// =====================
// Algorithm State (Used by VisualizationStatus)
// =====================
export interface AlgorithmState {
  currentNodeId: number;
  distance: number;
  queueState: number[];                // Queue or stack contents (IDs)
  visitedNodes: number[];              // All visited nodes (IDs)
  message: string;                     // Description of step
}

// =====================
// Visualization Data (Used by VisualizationStatus)
// =====================
export interface VisualizationData {
  startNodeId: number;
  exitId: number;
  distance: number;
  path: number[];
  algorithm: string;
  states?: AlgorithmState[]; // Used by VisualizationStatus
  floorId?: number;
}

// =====================
// HashMap Visualization Types
// =====================

/**
 * NEW: ChainNode interface used to represent a node in the hash map's linked list chain.
 */
export interface ChainNode {
  id: number;
  name: string;
}

/**
 * UPDATED: HashMapState now uses ChainNode[] for the chainState.
 */
export interface HashMapState {
  stepId: number;
  description: string;
  currentBucketIndex: number;
  insertedNodeId: number;
  insertedNodeName: string;
  isCollision: boolean;
  chainState: ChainNode[]; // CORRECTED: Now expects array of objects
}

export interface HashMapData {
  floorId: number;
  bucketCount: number;
  steps: HashMapState[];
}

// =====================
// Other Types (for completeness)
// =====================
export type Page = 'home' | 'visualization' | 'planner' | 'hashmap';

export interface Location {
  x: number;
  y: number;
  nodeId?: number;
}