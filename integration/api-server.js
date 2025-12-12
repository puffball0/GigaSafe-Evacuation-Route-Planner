// // /**
// //  * API Server - Integration Layer between React Frontend and C++ Backend
// //  */

// // const express = require('express');
// // const cors = require('cors');
// // const { spawn } = require('child_process');
// // const path = require('path');

// // const app = express();
// // const PORT = 8080;

// // // Middleware
// // app.use(cors());
// // app.use(express.json());

// // // Path to compiled C++ executable
// // const CPP_EXECUTABLE = `"${path.join(__dirname, '../backend/build/Release/evacuation_system.exe')}"`;

// // /**
// //  * GET /api/graph/floor/:floorId
// //  * Get graph data for a specific floor
// //  */
// // app.get('/api/graph/floor/:floorId', (req, res) => {
// //   const floorId = parseInt(req.params.floorId);

// //   if (isNaN(floorId) || floorId < 1 || floorId > 6) {
// //     return res.status(400).json({ error: 'Invalid floor ID' });
// //   }

// //   const cpp = spawn(CPP_EXECUTABLE, ['--get-graph', floorId.toString()], { shell: true });
// //   let output = '';
// //   let error = '';

// //   cpp.stdout.on('data', (data) => {
// //     output += data.toString();
// //   });

// //   cpp.stderr.on('data', (data) => {
// //     error += data.toString();
// //   });

// //   cpp.on('close', (code) => {
// //     if (code !== 0) {
// //       console.error('C++ Error:', error);
// //       return res.status(500).json({ error: 'Failed to load graph data' });
// //     }

// //     try {
// //       const graphData = JSON.parse(output);
// //       res.json(graphData);
// //     } catch (err) {
// //       console.error('Parse Error:', err);
// //       res.status(500).json({ error: 'Failed to parse graph data' });
// //     }
// //   });
// // });

// // /**
// //  * POST /api/compute-route
// //  * Compute evacuation route with full state tracking
// //  */
// // app.post('/api/compute-route', (req, res) => {
// //   const { floorId, startNodeId, algorithm = 'dijkstra' } = req.body;

// //   if (!floorId || !startNodeId) {
// //     return res.status(400).json({ error: 'Missing required parameters' });
// //   }

// //   console.log(`[API] Received compute-route request: floor=${floorId}, start=${startNodeId}, algo=${algorithm}`);

// //   const cpp = spawn(CPP_EXECUTABLE, [
// //     '--compute-route',
// //     floorId.toString(),
// //     startNodeId.toString(),
// //     algorithm
// //   ], { shell: true });

// //   let output = '';
// //   let error = '';

// //   cpp.stdout.on('data', (data) => {
// //     output += data.toString();
// //   });

// //   cpp.stderr.on('data', (data) => {
// //     error += data.toString();
// //   });

// //   cpp.on('close', (code) => {
// //     if (code !== 0) {
// //       console.error('C++ Error:', error);
// //       return res.status(500).json({ error: 'Failed to compute route' });
// //     }

// //     try {
// //       const result = JSON.parse(output);
// //       result.floorId = floorId;
// //       res.json(result);
// //     } catch (err) {
// //       console.error('Parse Error:', err);
// //       console.error('Output:', output);
// //       res.status(500).json({ error: 'Failed to parse route data' });
// //     }
// //   });
// // });

// // /**
// //  * POST /api/visualize-hashmap
// //  * Visualize HashMap creation for a floor
// //  */
// // app.post('/api/visualize-hashmap', (req, res) => {
// //   const { floorId } = req.body;

// //   if (!floorId) {
// //     return res.status(400).json({ error: 'Missing floor ID' });
// //   }

// //   const cpp = spawn(CPP_EXECUTABLE, [
// //     '--visualize-hashmap',
// //     floorId.toString()
// //   ], { shell: true });

// //   let output = '';
// //   let error = '';

// //   cpp.stdout.on('data', (data) => {
// //     output += data.toString();
// //   });

// //   cpp.stderr.on('data', (data) => {
// //     error += data.toString();
// //   });

// //   cpp.on('close', (code) => {
// //     if (code !== 0) {
// //       console.error('C++ Error:', error);
// //       return res.status(500).json({ error: 'Failed to visualize hashmap' });
// //     }

// //     try {
// //       const result = JSON.parse(output);
// //       res.json(result);
// //     } catch (err) {
// //       console.error('Parse Error:', err);
// //       res.status(500).json({ error: 'Failed to parse hashmap data' });
// //     }
// //   });
// // });

// // /**
// //  * GET /api/floors
// //  * Get list of all available floors
// //  */
// // app.get('/api/floors', (req, res) => {
// //   const floors = [
// //     { id: 1, name: 'Mezzanine Floor', floorNumber: 'Mezzanine' },
// //     { id: 2, name: 'Lower Ground Floor', floorNumber: 'Lower Ground' },
// //     { id: 3, name: 'Ground Floor', floorNumber: 0 },
// //     { id: 4, name: 'First Floor', floorNumber: 1 },
// //     { id: 5, name: 'Second Floor', floorNumber: 2 },
// //     { id: 6, name: '2A Floor', floorNumber: '2A' }
// //   ];
// //   res.json(floors);
// // });

// // /**
// //  * Health check endpoint
// //  */
// // app.get('/api/health', (req, res) => {
// //   res.json({ status: 'OK', message: 'API server is running' });
// // });

// // // Start server
// // app.listen(PORT, () => {
// //   console.log(`API Server running on http://localhost:${PORT}`);
// //   console.log(`C++ Backend executable: ${CPP_EXECUTABLE}`);
// // });




// /**
//  * API Server - Integration Layer between React Frontend and C++ Backend
//  */

// const express = require('express');
// const cors = require('cors');
// const { spawn } = require('child_process');
// const path = require('path');

// const app = express();
// const PORT = 8080;

// // Middleware
// app.use(cors());
// app.use(express.json());

// // Path to compiled C++ executable
// const CPP_EXECUTABLE = `"${path.join(__dirname, '../backend/build/Release/evacuation_system.exe')}"`;

// /**
//  * GET /api/graph/floor/:floorId
//  * Get graph data for a specific floor
//  */
// app.get('/api/graph/floor/:floorId', (req, res) => {
//   const floorId = parseInt(req.params.floorId);

//   if (isNaN(floorId) || floorId < 1 || floorId > 6) {
//     return res.status(400).json({ error: 'Invalid floor ID' });
//   }

//   const cpp = spawn(CPP_EXECUTABLE, ['--get-graph', floorId.toString()], { shell: true });
//   let output = '';
//   let error = '';

//   cpp.stdout.on('data', (data) => {
//     output += data.toString();
//   });

//   cpp.stderr.on('data', (data) => {
//     error += data.toString();
//   });

//   cpp.on('close', (code) => {
//     if (code !== 0) {
//       console.error('C++ Error:', error);
//       return res.status(500).json({ error: 'Failed to fetch graph data' });
//     }

//     try {
//       const result = JSON.parse(output);
//       res.json(result);
//     } catch (err) {
//       console.error('Parse Error:', err);
//       res.status(500).json({ error: 'Failed to parse graph data' });
//     }
//   });
// });

// /**
//  * POST /api/compute-route
//  * Compute evacuation route using backend algorithm
//  */
// app.post('/api/compute-route', (req, res) => {
//   const { floorId, startNodeId, algorithm } = req.body;

//   if (isNaN(floorId) || isNaN(startNodeId) || !algorithm) {
//     return res.status(400).json({ error: 'Missing or invalid parameters' });
//   }

//   // The algorithm argument is required by the C++ backend
//   const algo = algorithm || 'dijkstra';

//   const cpp = spawn(CPP_EXECUTABLE, [
//     '--compute-route',
//     floorId.toString(),
//     startNodeId.toString(),
//     algo
//   ], { shell: true });

//   let output = '';
//   let error = '';

//   cpp.stdout.on('data', (data) => {
//     output += data.toString();
//   });

//   cpp.stderr.on('data', (data) => {
//     error += data.toString();
//   });

//   cpp.on('close', (code) => {
//     if (code !== 0) {
//       console.error('C++ Error:', error);
//       return res.status(500).json({ error: 'Failed to compute route' });
//     }

//     try {
//       const result = JSON.parse(output);
//       res.json(result);
//     } catch (err) {
//       console.error('Parse Error:', err);
//       res.status(500).json({ error: 'Failed to parse route data' });
//     }
//   });
// });


// /**
//  * POST /api/visualize-hashmap
//  * Get HashMap visualization steps
//  */
// app.post('/api/visualize-hashmap', (req, res) => {
//   const { floorId } = req.body;

//   if (isNaN(floorId)) {
//     return res.status(400).json({ error: 'Missing or invalid floor ID' });
//   }

//   // Use the new command-line argument for HashMap visualization
//   const cpp = spawn(CPP_EXECUTABLE, [
//     '--visualize-hashmap', // Correct command
//     floorId.toString()
//   ], { shell: true });

//   let output = '';
//   let error = '';

//   cpp.stdout.on('data', (data) => {
//     output += data.toString();
//   });

//   cpp.stderr.on('data', (data) => {
//     error += data.toString();
//   });

//   cpp.on('close', (code) => {
//     if (code !== 0) {
//       console.error('C++ Error:', error);
//       return res.status(500).json({ error: 'Failed to visualize hashmap' });
//     }

//     try {
//       const result = JSON.parse(output);
//       res.json(result);
//     } catch (err) {
//       console.error('Parse Error:', err);
//       res.status(500).json({ error: 'Failed to parse hashmap data' });
//     }
//   });
// });

// /**
//  * GET /api/floors
//  * Get list of all available floors
//  */
// app.get('/api/floors', (req, res) => {
//   const floors = [
//     { id: 1, name: 'Mezzanine Floor', floorNumber: 'Mezzanine' },
//     { id: 2, name: 'Lower Ground Floor', floorNumber: 'Lower Ground' },
//     { id: 3, name: 'Ground Floor', floorNumber: 0 },
//     { id: 4, name: 'First Floor', floorNumber: 1 },
//     { id: 5, name: 'Second Floor', floorNumber: 2 },
//     { id: 6, name: '2A Floor', floorNumber: '2A' }
//   ];
//   res.json(floors);
// });

// // Start Server
// app.listen(PORT, () => {
//   console.log(`API Server listening on port ${PORT}`);
// });

/**
 * API Server - Integration Layer between React Frontend and C++ Backend
 */

const express = require('express');
const cors = require('cors');
const { spawn } = require('child_process');
const path = require('path');

const app = express();
const PORT = 8080;

// Middleware
app.use(cors());
app.use(express.json());

// Path to compiled C++ executable
const CPP_EXECUTABLE = `"${path.join(__dirname, '../backend/build/Release/evacuation_system.exe')}"`;

/**
 * GET /api/graph/floor/:floorId
 * Get graph data for a specific floor
 */
app.get('/api/graph/floor/:floorId', (req, res) => {
  const floorId = parseInt(req.params.floorId);

  if (isNaN(floorId) || floorId < 1 || floorId > 6) {
    return res.status(400).json({ error: 'Invalid floor ID' });
  }

  const cpp = spawn(CPP_EXECUTABLE, ['--get-graph', floorId.toString()], { shell: true });
  let output = '';
  let error = '';

  cpp.stdout.on('data', (data) => {
    output += data.toString();
  });

  cpp.stderr.on('data', (data) => {
    error += data.toString();
  });

  cpp.on('close', (code) => {
    if (code !== 0) {
      console.error('C++ Error:', error);
      return res.status(500).json({ error: 'Failed to load graph data' });
    }

    try {
      const graphData = JSON.parse(output);
      res.json(graphData);
    } catch (err) {
      console.error('Parse Error:', err);
      res.status(500).json({ error: 'Failed to parse graph data' });
    }
  });
});

/**
 * POST /api/compute-route
 * Compute evacuation route with full state tracking
 */
app.post('/api/compute-route', (req, res) => {
  const { floorId, startNodeId, algorithm = 'dijkstra' } = req.body;

  if (!floorId || !startNodeId) {
    return res.status(400).json({ error: 'Missing required parameters' });
  }

  console.log(`[API] Received compute-route request: floor=${floorId}, start=${startNodeId}, algo=${algorithm}`);

  const cpp = spawn(CPP_EXECUTABLE, [
    '--compute-route',
    floorId.toString(),
    startNodeId.toString(),
    algorithm
  ], { shell: true });

  let output = '';
  let error = '';

  cpp.stdout.on('data', (data) => {
    output += data.toString();
  });

  cpp.stderr.on('data', (data) => {
    error += data.toString();
  });

  cpp.on('close', (code) => {
    if (code !== 0) {
      console.error('C++ Error:', error);
      return res.status(500).json({ error: 'Failed to compute route' });
    }

    try {
      const result = JSON.parse(output);
      result.floorId = floorId;
      res.json(result);
    } catch (err) {
      console.error('Parse Error:', err);
      console.error('Output:', output);
      res.status(500).json({ error: 'Failed to parse route data' });
    }
  });
});

/**
 * POST /api/visualize-hashmap
 * Visualize HashMap creation for a floor
 */
app.post('/api/visualize-hashmap', (req, res) => {
  const { floorId } = req.body;

  if (!floorId) {
    return res.status(400).json({ error: 'Missing floor ID' });
  }

  const cpp = spawn(CPP_EXECUTABLE, [
    '--visualize-hashmap',
    floorId.toString()
  ], { shell: true });

  let output = '';
  let error = '';

  cpp.stdout.on('data', (data) => {
    output += data.toString();
  });

  cpp.stderr.on('data', (data) => {
    error += data.toString();
  });

  cpp.on('close', (code) => {
    if (code !== 0) {
      console.error('C++ Error:', error);
      return res.status(500).json({ error: 'Failed to visualize hashmap' });
    }

    try {
      const result = JSON.parse(output);
      res.json(result);
    } catch (err) {
      console.error('Parse Error:', err);
      res.status(500).json({ error: 'Failed to parse hashmap data' });
    }
  });
});

/**
 * GET /api/floors
 * Get list of all available floors
 */
app.get('/api/floors', (req, res) => {
  const floors = [
    { id: 1, name: 'Mezzanine Floor', floorNumber: 'Mezzanine' },
    { id: 2, name: 'Lower Ground Floor', floorNumber: 'Lower Ground' },
    { id: 3, name: 'Ground Floor', floorNumber: 0 },
    { id: 4, name: 'First Floor', floorNumber: 1 },
    { id: 5, name: 'Second Floor', floorNumber: 2 },
    { id: 6, name: '2A Floor', floorNumber: '2A' }
  ];
  res.json(floors);
});

/**
 * Health check endpoint
 */
app.get('/api/health', (req, res) => {
  res.json({ status: 'OK', message: 'API server is running' });
});

// Start server
app.listen(PORT, () => {
  console.log(`API Server running on http://localhost:${PORT}`);
  console.log(`C++ Backend executable: ${CPP_EXECUTABLE}`);
});
