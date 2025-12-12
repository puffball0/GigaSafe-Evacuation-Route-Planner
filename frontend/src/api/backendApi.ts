// // // Backend API Integration
// // // This file handles all communication with the C++ backend

// // import type { Floor, GraphData, VisualizationData, Node, HashMapData } from '../types';

// // const API_BASE_URL = 'http://localhost:8080/api';

// // /**
// //  * Fetch graph data for a specific floor
// //  */
// // export async function fetchGraphData(floorId: number): Promise<GraphData> {
// //   try {
// //     const response = await fetch(`${API_BASE_URL}/graph/floor/${floorId}`);

// //     if (!response.ok) {
// //       throw new Error(`HTTP error! status: ${response.status}`);
// //     }

// //     const data: GraphData = await response.json();
// //     return data;
// //   } catch (error) {
// //     console.error('Error fetching graph data:', error);
// //     // Return mock data for development
// //     return getMockGraphData(floorId);
// //   }
// // }

// // /**
// //  * Compute evacuation route using backend algorithm
// //  */
// // export async function computeRoute(
// //   floorId: number, 
// //   startNodeId: number, 
// //   algorithm: string = 'dijkstra'
// // ): Promise<VisualizationData> {
// //   try {
// //     const response = await fetch(`${API_BASE_URL}/compute-route`, {
// //       method: 'POST',
// //       headers: {
// //         'Content-Type': 'application/json',
// //       },
// //       body: JSON.stringify({
// //         floorId,
// //         startNodeId,
// //         algorithm
// //       })
// //     });

// //     if (!response.ok) {
// //       throw new Error(`HTTP error! status: ${response.status}`);
// //     }

// //     const data: VisualizationData = await response.json();
// //     return data;
// //   } catch (error) {
// //     console.error('Error computing route:', error);
// //     // Return mock data for development
// //     return getMockRouteData(startNodeId);
// //   }
// // }

// // /**
// //  * Get list of all floors
// //  */
// // export async function fetchFloors(): Promise<Floor[]> {
// //   try {
// //     const response = await fetch(`${API_BASE_URL}/floors`);

// //     if (!response.ok) {
// //       throw new Error(`HTTP error! status: ${response.status}`);
// //     }

// //     const data: Floor[] = await response.json();
// //     return data;
// //   } catch (error) {
// //     console.error('Error fetching floors:', error);
// //     return getMockFloors();
// //   }
// // }

// // // ============ MOCK DATA FOR DEVELOPMENT ============

// // function getMockFloors(): Floor[] {
// //   return [
// //     { id: 1, name: 'Mezzanine Floor', floorNumber: 'Mezzanine' },
// //     { id: 2, name: 'Lower Ground Floor', floorNumber: 'Lower Ground' },
// //     { id: 3, name: 'Ground Floor', floorNumber: 0 },
// //     { id: 4, name: 'First Floor', floorNumber: 1 },
// //     { id: 5, name: 'Second Floor', floorNumber: 2 },
// //     { id: 6, name: '2A Floor', floorNumber: '2A' }
// //   ];
// // }

// // function getMockGraphData(floorId: number): GraphData {
// //   // Mock data based on secondfloor.cpp structure
// //   if (floorId === 5) { // Second Floor
// //     return {
// //       floorId: 5,
// //       nodes: [
// //         // Shops
// //         { id: 401, name: 'KFC', type: 'shop', x: 90, y: 158, floor: 2, isExit: false },
// //         { id: 402, name: 'PIZZA N PASTA', type: 'shop', x: 90, y: 247, floor: 2, isExit: false },
// //         { id: 403, name: 'PAPPASALLIS', type: 'shop', x: 90, y: 267, floor: 2, isExit: false },
// //         { id: 404, name: 'SIMPLY SUFI EXPRESS', type: 'shop', x: 90, y: 298, floor: 2, isExit: false },
// //         { id: 405, name: 'HOWDY', type: 'shop', x: 90, y: 319, floor: 2, isExit: false },
// //         { id: 410, name: 'SPLASH', type: 'shop', x: 258, y: 188, floor: 2, isExit: false },
// //         { id: 411, name: 'CROSSROADS', type: 'shop', x: 295, y: 188, floor: 2, isExit: false },
// //         { id: 415, name: 'MINISO', type: 'shop', x: 420, y: 235, floor: 2, isExit: false },
// //         { id: 421, name: 'FUN CITY', type: 'shop', x: 697, y: 310, floor: 2, isExit: false },
// //         { id: 423, name: 'FANKARE', type: 'shop', x: 835, y: 148, floor: 2, isExit: false },
// //         { id: 440, name: 'CINEPAX', type: 'shop', x: 1240, y: 250, floor: 2, isExit: false },

// //         // Emergency Exits
// //         { id: 444, name: 'Emergency Exit 1', type: 'exit', x: 225, y: 120, floor: 2, isExit: true },
// //         { id: 445, name: 'Emergency Exit 2', type: 'exit', x: 295, y: 120, floor: 2, isExit: true },
// //         { id: 446, name: 'Emergency Exit 3', type: 'exit', x: 447, y: 120, floor: 2, isExit: true },
// //         { id: 447, name: 'Emergency Exit 4', type: 'exit', x: 630, y: 120, floor: 2, isExit: true },
// //         { id: 448, name: 'Emergency Exit 5', type: 'exit', x: 835, y: 120, floor: 2, isExit: true },
// //         { id: 449, name: 'Emergency Exit 6', type: 'exit', x: 1010, y: 120, floor: 2, isExit: true },

// //         // Corridor Junctions
// //         { id: 500, name: 'Top Corridor J1', type: 'corridor', x: 145, y: 188, floor: 2, isExit: false },
// //         { id: 501, name: 'Top Corridor J2', type: 'corridor', x: 240, y: 188, floor: 2, isExit: false },
// //         { id: 502, name: 'Top Corridor J3', type: 'corridor', x: 330, y: 195, floor: 2, isExit: false },
// //         { id: 503, name: 'Top Corridor J4', type: 'corridor', x: 470, y: 205, floor: 2, isExit: false },
// //         { id: 504, name: 'Top Corridor J5', type: 'corridor', x: 590, y: 205, floor: 2, isExit: false },
// //         { id: 505, name: 'Top Corridor J6', type: 'corridor', x: 730, y: 205, floor: 2, isExit: false },
// //         { id: 506, name: 'Top Corridor J7', type: 'corridor', x: 870, y: 195, floor: 2, isExit: false },
// //       ],
// //       edges: [
// //         // Corridor connections
// //         { from: 500, to: 501, distance: 95.0, type: 'walk' },
// //         { from: 501, to: 502, distance: 90.0, type: 'walk' },
// //         { from: 502, to: 503, distance: 140.0, type: 'walk' },
// //         { from: 503, to: 504, distance: 120.0, type: 'walk' },
// //         { from: 504, to: 505, distance: 140.0, type: 'walk' },
// //         { from: 505, to: 506, distance: 140.0, type: 'walk' },

// //         // Shop to corridor connections
// //         { from: 401, to: 500, distance: 55.0, type: 'walk' },
// //         { from: 402, to: 500, distance: 89.0, type: 'walk' },
// //         { from: 410, to: 501, distance: 30.0, type: 'walk' },
// //         { from: 411, to: 501, distance: 30.0, type: 'walk' },
// //         { from: 415, to: 503, distance: 40.0, type: 'walk' },
// //         { from: 421, to: 504, distance: 107.0, type: 'walk' },
// //         { from: 423, to: 506, distance: 50.0, type: 'walk' },

// //         // Exit connections
// //         { from: 444, to: 501, distance: 30.0, type: 'walk' },
// //         { from: 445, to: 502, distance: 30.0, type: 'walk' },
// //         { from: 446, to: 503, distance: 30.0, type: 'walk' },
// //         { from: 447, to: 504, distance: 30.0, type: 'walk' },
// //         { from: 448, to: 506, distance: 30.0, type: 'walk' },
// //       ]
// //     };
// //   }

// //   // Return empty data for other floors
// //   return {
// //     floorId,
// //     nodes: [],
// //     edges: []
// //   };
// // }

// // function getMockRouteData(startNodeId: number): VisualizationData {
// //   // Mock route computation result
// //   return {
// //     startNodeId,
// //     exitId: 444,
// //     distance: 180.5,
// //     visitedOrder: [401, 500, 501, 444],
// //     path: [401, 500, 501, 444],
// //     algorithm: 'dijkstra'
// //   };
// // }

// // export default {
// //   fetchGraphData,
// //   computeRoute,
// //   fetchFloors
// // };


// // Backend API Integration
// // This file handles all communication with the C++ backend




// import type { Floor, GraphData, VisualizationData, Node, HashMapData } from '../types';

// const API_BASE_URL = 'http://localhost:8080/api';

// /**
//  * Fetch graph data for a specific floor
//  */
// export async function fetchGraphData(floorId: number): Promise<GraphData> {
//   try {
//     const response = await fetch(`${API_BASE_URL}/graph/floor/${floorId}`);

//     if (!response.ok) {
//       throw new Error(`HTTP error! status: ${response.status}`);
//     }

//     const data: GraphData = await response.json();
//     return data;
//   } catch (error) {
//     console.error('Error fetching graph data:', error);
//     throw error;
//   }
// }

// /**
//  * Find nearest node to coordinates
//  */
// export function findNearestNode(x: number, y: number, nodes: Node[]): Node | null {
//   let nearest: Node | null = null;
//   let minDistance = Infinity;
//   const searchRadius = 20; // Hitbox radius

//   for (const node of nodes) {
//     const dx = node.x - x;
//     const dy = node.y - y;
//     const distance = Math.sqrt(dx * dx + dy * dy);

//     if (distance < searchRadius && distance < minDistance) {
//       minDistance = distance;
//       nearest = node;
//     }
//   }
//   return nearest;
// }

// /**
//  * Compute evacuation route with full state tracking
//  */
// export async function computeRoute(
//   floorId: number,
//   startNodeId: number,
//   algorithm: string = 'dijkstra'
// ): Promise<VisualizationData> {
//   try {
//     const response = await fetch(`${API_BASE_URL}/compute-route`, {
//       method: 'POST',
//       headers: {
//         'Content-Type': 'application/json',
//       },
//       body: JSON.stringify({
//         floorId,
//         startNodeId,
//         algorithm
//       })
//     });

//     if (!response.ok) {
//       throw new Error(`HTTP error! status: ${response.status}`);
//     }

//     const data: VisualizationData = await response.json();
//     return data;
//   } catch (error) {
//     console.error('Error computing route:', error);
//     throw error;
//   }
// }



// /**
//  * Get list of all floors
//  */
// export async function fetchFloors(): Promise<Floor[]> {
//   try {
//     const response = await fetch(`${API_BASE_URL}/floors`);

//     if (!response.ok) {
//       throw new Error(`HTTP error! status: ${response.status}`);
//     }

//     const data: Floor[] = await response.json();
//     return data;
//   } catch (error) {
//     console.error('Error fetching floors:', error);
//     throw error;
//   }
// }



// /**
//  * Get HashMap visualization steps
//  */
// export async function visualizeHashMap(floorId: number): Promise<HashMapData> {
//   try {
//     const response = await fetch(`${API_BASE_URL}/visualize-hashmap`, {
//       method: 'POST',
//       headers: {
//         'Content-Type': 'application/json',
//       },
//       body: JSON.stringify({ floorId })
//     });

//     if (!response.ok) {
//       throw new Error(`HTTP error! status: ${response.status}`);
//     }

//     const data: HashMapData = await response.json();
//     return data;
//   } catch (error) {
//     console.error('Error fetching hashmap data:', error);
//     throw error;
//   }
// }

// export default {
//   fetchGraphData,
//   computeRoute,
//   fetchFloors,
//   findNearestNode,
//   visualizeHashMap
// };

// Backend API Integration
// This file handles all communication with the C++ backend

import type { Floor, GraphData, VisualizationData, Node, HashMapData } from '../types';

const API_BASE_URL = 'http://localhost:8080/api';

/**
 * Fetch graph data for a specific floor
 */
export async function fetchGraphData(floorId: number): Promise<GraphData> {
  try {
    const response = await fetch(`${API_BASE_URL}/graph/floor/${floorId}`);

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const data: GraphData = await response.json();
    return data;
  } catch (error) {
    console.error('Error fetching graph data:', error);
    throw error;
  }
}

/**
 * Find nearest node to coordinates
 */
export function findNearestNode(x: number, y: number, nodes: Node[]): Node | null {
  let nearest: Node | null = null;
  let minDistance = Infinity;
  const searchRadius = 20; // Hitbox radius

  for (const node of nodes) {
    const dx = node.x - x;
    const dy = node.y - y;
    const distance = Math.sqrt(dx * dx + dy * dy);

    if (distance < searchRadius && distance < minDistance) {
      minDistance = distance;
      nearest = node;
    }
  }
  return nearest;
}

/**
 * Compute evacuation route with full state tracking
 */
export async function computeRoute(
  floorId: number,
  startNodeId: number,
  algorithm: string = 'dijkstra'
): Promise<VisualizationData> {
  try {
    const response = await fetch(`${API_BASE_URL}/compute-route`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({
        floorId,
        startNodeId,
        algorithm
      })
    });

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const data: VisualizationData = await response.json();
    return data;
  } catch (error) {
    console.error('Error computing route:', error);
    throw error;
  }
}


/**
 * Get list of all floors
 */
export async function fetchFloors(): Promise<Floor[]> {
  try {
    const response = await fetch(`${API_BASE_URL}/floors`);

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const data: Floor[] = await response.json();
    return data;
  } catch (error) {
    console.error('Error fetching floors:', error);
    throw error;
  }
}


/**
 * Get HashMap visualization steps
 */
export async function visualizeHashMap(floorId: number): Promise<HashMapData> {
  try {
    const response = await fetch(`${API_BASE_URL}/visualize-hashmap`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ floorId })
    });

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }

    const data: HashMapData = await response.json();
    return data;
  } catch (error) {
    console.error('Error fetching hashmap data:', error);
    throw error;
  }
}

// NOTE: The previous `export default { ... }` block has been REMOVED
// to allow named imports (like `import { findNearestNode } from '...'`) to work correctly.