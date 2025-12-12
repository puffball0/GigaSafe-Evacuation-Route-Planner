#include "lowergroundfloor.h"

Graph LowerGroundFloor::buildLowerGroundFloorGraph() {
    Graph graph;

    // ==================== LOWER GROUND FLOOR - ACCURATE MAPPING ====================
    // Image dimensions reference: 1600x600 (approximate from the floor plan)

    // ==================== CARREFOUR INTERIOR NODES ====================
    // Multiple nodes inside Carrefour for internal navigation
    graph.addNode({101, "Carrefour North West", "shop", 380, 230, 0, false, false});
    graph.addNode({102, "Carrefour North Center", "shop", 520, 230, 0, false, false});
    graph.addNode({103, "Carrefour North East", "shop", 660, 230, 0, false, false});
    graph.addNode({104, "Carrefour Center West", "shop", 380, 300, 0, false, false});
    graph.addNode({105, "Carrefour Center", "shop", 520, 300, 0, false, false});
    graph.addNode({106, "Carrefour Center East", "shop", 660, 300, 0, false, false});
    graph.addNode({107, "Carrefour South West", "shop", 380, 370, 0, false, false});
    graph.addNode({108, "Carrefour South Center", "shop", 520, 370, 0, false, false});
    graph.addNode({109, "Carrefour South East", "shop", 660, 370, 0, false, false});

    // ==================== CARREFOUR EXITS (INSIDE) ====================
    // Top side exits (3 exits inside Carrefour upper boundary)
    graph.addNode({110, "Carrefour Exit Top 1", "exit", 305, 165, 0, true, false});
    graph.addNode({111, "Carrefour Exit Top 2", "exit", 540, 165, 0, true, false});
    graph.addNode({112, "Carrefour Exit Top 3", "exit", 725, 165, 0, true, false});
    // Bottom side exit (1 exit inside Carrefour lower boundary)
    graph.addNode({113, "Carrefour Exit Bottom", "exit", 355, 438, 0, true, false});

    // ==================== MAIN MALL EMERGENCY EXITS (OUTSIDE CARREFOUR) ====================
    // Upper side exits (6 exits on top boundary)
    graph.addNode({114, "Emergency Exit Upper 1", "exit", 935, 165, 0, true, false});
    graph.addNode({115, "Emergency Exit Upper 2", "exit", 1000, 165, 0, true, false});
    graph.addNode({116, "Emergency Exit Upper 3", "exit", 1105, 165, 0, true, false});
    graph.addNode({117, "Emergency Exit Upper 4", "exit", 1145, 165, 0, true, false});
    graph.addNode({118, "Emergency Exit Upper 5", "exit", 1175, 165, 0, true, false});
    graph.addNode({119, "Emergency Exit Upper 6", "exit", 1255, 165, 0, true, false});
    
    // Lower side exits (2 exits on bottom boundary)
    graph.addNode({120, "Emergency Exit Lower 1", "exit", 1115, 445, 0, true, false});
    graph.addNode({121, "Emergency Exit Lower 2", "exit", 1185, 445, 0, true, false});

    // ==================== LEFT SECTION STORES (Below Carrefour) ====================
    graph.addNode({122, "DUBAI ISLAMIC BANK", "shop", 545, 425, 0, false, false});
    graph.addNode({123, "DOLLAR STORE", "shop", 590, 425, 0, false, false});
    graph.addNode({124, "SERVICE", "shop", 635, 425, 0, false, false});
    graph.addNode({125, "UFONE STORE", "shop", 693, 425, 0, false, false});

    // ==================== CENTER SECTION STORES (Right side) ====================
    // Top row stores
    graph.addNode({126, "ALMIRAH", "shop", 735, 425, 0, false, false});
    graph.addNode({127, "NETWORK", "shop", 777, 425, 0, false, false});
    graph.addNode({128, "ECTA", "shop", 820, 425, 0, false, false});
    graph.addNode({129, "JAYS", "shop", 860, 425, 0, false, false});
    graph.addNode({130, "DIGI MART", "shop", 910, 425, 0, false, false});
    graph.addNode({131, "JUNK", "shop", 958, 425, 0, false, false});
    graph.addNode({132, "SULTAN JEWELLERS", "shop", 1018, 425, 0, false, false});

    // ==================== RIGHT TOP SECTION STORES ====================
    graph.addNode({133, "FRIENDS", "shop", 1030, 270, 0, false, false});
    graph.addNode({134, "THE LIQUID COMPANY", "shop", 1078, 270, 0, false, false});
    graph.addNode({135, "D WATSON", "shop", 1155, 270, 0, false, false});
    graph.addNode({136, "ZENO", "shop", 1058, 310, 0, false, false});
    graph.addNode({137, "ROBINSON CRUSOE", "shop", 1018, 350, 0, false, false});
    graph.addNode({138, "JUNAID JAMSHED", "shop", 1078, 350, 0, false, false});
    graph.addNode({139, "ROYAL FURNITURE", "shop", 1155, 350, 0, false, false});
    graph.addNode({140, "PUNJAB BOARD", "shop", 1230, 245, 0, false, false});
    graph.addNode({141, "UNIQUE", "shop", 1250, 310, 0, false, false});
    graph.addNode({142, "STYLO COMFORT", "shop", 1250, 385, 0, false, false});

    // ==================== FAR RIGHT SECTION STORES ====================
    graph.addNode({143, "FORMAL FASHION", "shop", 1050, 180, 0, false, false});
    graph.addNode({144, "ZAMZAM", "shop", 1140, 180, 0, false, false});

    // ==================== STAIRS/ELEVATORS ====================
    // Vertical (purple/pink) stair icons
    graph.addNode({145, "Stairs 1", "stairs", 945, 295, 0, false, false});
    graph.addNode({146, "Stairs 2", "stairs", 980, 295, 0, false, false});
    graph.addNode({147, "Stairs 3", "stairs", 945, 335, 0, false, false});
    graph.addNode({148, "Stairs 4", "stairs", 980, 335, 0, false, false});
    graph.addNode({149, "Stairs 5", "stairs", 945, 375, 0, false, false});
    
    // Orange/yellow stair icons on sides
    graph.addNode({150, "Stairs Top Right 1", "stairs", 1145, 425, 0, false, false});
    graph.addNode({151, "Stairs Top Right 2", "stairs", 1185, 425, 0, false, false});

    // ==================== CORRIDOR JUNCTION NODES ====================
    
    // MAIN UPPER HORIZONTAL CORRIDOR (Above stores, below Carrefour exits)
    graph.addNode({200, "Upper Corridor J1", "corridor", 305, 200, 0, false, false});
    graph.addNode({201, "Upper Corridor J2", "corridor", 420, 200, 0, false, false});
    graph.addNode({202, "Upper Corridor J3", "corridor", 540, 200, 0, false, false});
    graph.addNode({203, "Upper Corridor J4", "corridor", 660, 200, 0, false, false});
    graph.addNode({204, "Upper Corridor J5", "corridor", 780, 200, 0, false, false});
    graph.addNode({205, "Upper Corridor J6", "corridor", 900, 200, 0, false, false});
    graph.addNode({206, "Upper Corridor J7", "corridor", 1020, 200, 0, false, false});
    graph.addNode({207, "Upper Corridor J8", "corridor", 1140, 200, 0, false, false});
    graph.addNode({208, "Upper Corridor J9", "corridor", 1255, 200, 0, false, false});

    // MIDDLE HORIZONTAL CORRIDOR (Between upper and lower store sections)
    graph.addNode({209, "Middle Corridor J1", "corridor", 950, 265, 0, false, false});
    graph.addNode({210, "Middle Corridor J2", "corridor", 1020, 265, 0, false, false});
    graph.addNode({211, "Middle Corridor J3", "corridor", 1100, 265, 0, false, false});
    graph.addNode({212, "Middle Corridor J4", "corridor", 1180, 265, 0, false, false});
    graph.addNode({213, "Middle Corridor J5", "corridor", 1250, 265, 0, false, false});

    // MIDDLE-LOWER HORIZONTAL CORRIDOR
    graph.addNode({214, "Mid-Lower Corridor J1", "corridor", 950, 320, 0, false, false});
    graph.addNode({215, "Mid-Lower Corridor J2", "corridor", 1020, 320, 0, false, false});
    graph.addNode({216, "Mid-Lower Corridor J3", "corridor", 1100, 320, 0, false, false});
    graph.addNode({217, "Mid-Lower Corridor J4", "corridor", 1180, 320, 0, false, false});
    graph.addNode({218, "Mid-Lower Corridor J5", "corridor", 1250, 320, 0, false, false});

    // LOWER HORIZONTAL CORRIDOR (Between stores and bottom edge)
    graph.addNode({219, "Lower Corridor J1", "corridor", 520, 390, 0, false, false});
    graph.addNode({220, "Lower Corridor J2", "corridor", 615, 390, 0, false, false});
    graph.addNode({221, "Lower Corridor J3", "corridor", 710, 390, 0, false, false});
    graph.addNode({222, "Lower Corridor J4", "corridor", 800, 390, 0, false, false});
    graph.addNode({223, "Lower Corridor J5", "corridor", 890, 390, 0, false, false});
    graph.addNode({224, "Lower Corridor J6", "corridor", 980, 390, 0, false, false});
    graph.addNode({225, "Lower Corridor J7", "corridor", 1070, 390, 0, false, false});
    graph.addNode({226, "Lower Corridor J8", "corridor", 1150, 390, 0, false, false});

    // VERTICAL CONNECTORS (Right side)
    graph.addNode({227, "Vertical Right 1", "corridor", 950, 360, 0, false, false});
    graph.addNode({228, "Vertical Right 2", "corridor", 1020, 360, 0, false, false});
    graph.addNode({229, "Vertical Right 3", "corridor", 1100, 360, 0, false, false});
    graph.addNode({230, "Vertical Right 4", "corridor", 1180, 360, 0, false, false});

    // ==================== CARREFOUR INTERNAL CONNECTIONS ====================
    // Horizontal connections within Carrefour
    graph.addEdge(101, 102, 140.0f, 0.0f, "walk");
    graph.addEdge(102, 103, 140.0f, 0.0f, "walk");
    graph.addEdge(104, 105, 140.0f, 0.0f, "walk");
    graph.addEdge(105, 106, 140.0f, 0.0f, "walk");
    graph.addEdge(107, 108, 140.0f, 0.0f, "walk");
    graph.addEdge(108, 109, 140.0f, 0.0f, "walk");
    
    // Vertical connections within Carrefour
    graph.addEdge(101, 104, 70.0f, 0.0f, "walk");
    graph.addEdge(104, 107, 70.0f, 0.0f, "walk");
    graph.addEdge(102, 105, 70.0f, 0.0f, "walk");
    graph.addEdge(105, 108, 70.0f, 0.0f, "walk");
    graph.addEdge(103, 106, 70.0f, 0.0f, "walk");
    graph.addEdge(106, 109, 70.0f, 0.0f, "walk");

    // ==================== CARREFOUR EXITS TO INTERNAL NODES ====================
    graph.addEdge(110, 101, 65.0f, 0.0f, "walk");
    graph.addEdge(111, 102, 65.0f, 0.0f, "walk");
    graph.addEdge(112, 103, 65.0f, 0.0f, "walk");
    graph.addEdge(113, 107, 68.0f, 0.0f, "walk");

    // ==================== CARREFOUR TO CORRIDOR CONNECTIONS ====================
    graph.addEdge(101, 200, 65.0f, 0.0f, "walk");
    graph.addEdge(102, 202, 65.0f, 0.0f, "walk");
    graph.addEdge(103, 203, 65.0f, 0.0f, "walk");
    graph.addEdge(107, 219, 80.0f, 0.0f, "walk");

    // ==================== MAIN CORRIDOR NETWORK ====================
    
    // UPPER HORIZONTAL CORRIDOR
    graph.addEdge(200, 201, 115.0f, 0.0f, "walk");
    graph.addEdge(201, 202, 120.0f, 0.0f, "walk");
    graph.addEdge(202, 203, 120.0f, 0.0f, "walk");
    graph.addEdge(203, 204, 120.0f, 0.0f, "walk");
    graph.addEdge(204, 205, 120.0f, 0.0f, "walk");
    graph.addEdge(205, 206, 120.0f, 0.0f, "walk");
    graph.addEdge(206, 207, 120.0f, 0.0f, "walk");
    graph.addEdge(207, 208, 115.0f, 0.0f, "walk");

    // MIDDLE HORIZONTAL CORRIDOR
    graph.addEdge(209, 210, 70.0f, 0.0f, "walk");
    graph.addEdge(210, 211, 80.0f, 0.0f, "walk");
    graph.addEdge(211, 212, 80.0f, 0.0f, "walk");
    graph.addEdge(212, 213, 70.0f, 0.0f, "walk");

    // MIDDLE-LOWER HORIZONTAL CORRIDOR
    graph.addEdge(214, 215, 70.0f, 0.0f, "walk");
    graph.addEdge(215, 216, 80.0f, 0.0f, "walk");
    graph.addEdge(216, 217, 80.0f, 0.0f, "walk");
    graph.addEdge(217, 218, 70.0f, 0.0f, "walk");

    // LOWER HORIZONTAL CORRIDOR
    graph.addEdge(219, 220, 95.0f, 0.0f, "walk");
    graph.addEdge(220, 221, 95.0f, 0.0f, "walk");
    graph.addEdge(221, 222, 90.0f, 0.0f, "walk");
    graph.addEdge(222, 223, 90.0f, 0.0f, "walk");
    graph.addEdge(223, 224, 90.0f, 0.0f, "walk");
    graph.addEdge(224, 225, 90.0f, 0.0f, "walk");
    graph.addEdge(225, 226, 80.0f, 0.0f, "walk");

    // VERTICAL CONNECTIONS (Right side)
    graph.addEdge(209, 214, 55.0f, 0.0f, "walk");
    graph.addEdge(214, 227, 40.0f, 0.0f, "walk");
    graph.addEdge(227, 224, 30.0f, 0.0f, "walk");
    
    graph.addEdge(210, 215, 55.0f, 0.0f, "walk");
    graph.addEdge(215, 228, 40.0f, 0.0f, "walk");
    graph.addEdge(228, 224, 30.0f, 0.0f, "walk");
    
    graph.addEdge(211, 216, 55.0f, 0.0f, "walk");
    graph.addEdge(216, 229, 40.0f, 0.0f, "walk");
    graph.addEdge(229, 225, 30.0f, 0.0f, "walk");
    
    graph.addEdge(212, 217, 55.0f, 0.0f, "walk");
    graph.addEdge(217, 230, 40.0f, 0.0f, "walk");
    graph.addEdge(230, 226, 30.0f, 0.0f, "walk");

    // Connect upper to middle corridors
    graph.addEdge(205, 209, 65.0f, 0.0f, "walk");
    graph.addEdge(206, 210, 65.0f, 0.0f, "walk");
    graph.addEdge(207, 211, 65.0f, 0.0f, "walk");

    // ==================== STORE CONNECTIONS TO CORRIDORS ====================
    
    // LEFT SECTION STORES (below Carrefour)
    graph.addEdge(122, 219, 35.0f, 0.0f, "walk");
    graph.addEdge(123, 220, 35.0f, 0.0f, "walk");
    graph.addEdge(124, 220, 35.0f, 0.0f, "walk");
    graph.addEdge(125, 221, 35.0f, 0.0f, "walk");

    // CENTER SECTION STORES
    graph.addEdge(126, 221, 35.0f, 0.0f, "walk");
    graph.addEdge(127, 222, 35.0f, 0.0f, "walk");
    graph.addEdge(128, 222, 35.0f, 0.0f, "walk");
    graph.addEdge(129, 223, 35.0f, 0.0f, "walk");
    graph.addEdge(130, 223, 35.0f, 0.0f, "walk");
    graph.addEdge(131, 224, 35.0f, 0.0f, "walk");
    graph.addEdge(132, 225, 35.0f, 0.0f, "walk");

    // RIGHT TOP SECTION STORES
    graph.addEdge(133, 210, 55.0f, 0.0f, "walk");
    graph.addEdge(134, 210, 45.0f, 0.0f, "walk");
    graph.addEdge(135, 212, 45.0f, 0.0f, "walk");
    graph.addEdge(136, 215, 50.0f, 0.0f, "walk");
    graph.addEdge(137, 215, 50.0f, 0.0f, "walk");
    graph.addEdge(138, 215, 45.0f, 0.0f, "walk");
    graph.addEdge(139, 217, 45.0f, 0.0f, "walk");
    graph.addEdge(140, 213, 55.0f, 0.0f, "walk");
    graph.addEdge(141, 218, 50.0f, 0.0f, "walk");
    graph.addEdge(142, 218, 45.0f, 0.0f, "walk");

    // FAR RIGHT SECTION STORES
    graph.addEdge(143, 206, 40.0f, 0.0f, "walk");
    graph.addEdge(144, 207, 40.0f, 0.0f, "walk");

    // ==================== EMERGENCY EXIT CONNECTIONS ====================
    
    // Upper exits (outside Carrefour)
    graph.addEdge(114, 205, 40.0f, 0.0f, "walk");
    graph.addEdge(115, 206, 40.0f, 0.0f, "walk");
    graph.addEdge(116, 207, 40.0f, 0.0f, "walk");
    graph.addEdge(117, 207, 40.0f, 0.0f, "walk");
    graph.addEdge(118, 207, 40.0f, 0.0f, "walk");
    graph.addEdge(119, 208, 40.0f, 0.0f, "walk");
    
    // Lower exits
    graph.addEdge(120, 226, 55.0f, 0.0f, "walk");
    graph.addEdge(121, 226, 55.0f, 0.0f, "walk");

    // ==================== STAIRS/ELEVATOR CONNECTIONS ====================
    graph.addEdge(145, 209, 30.0f, 0.0f, "walk");
    graph.addEdge(146, 209, 35.0f, 0.0f, "walk");
    graph.addEdge(147, 214, 30.0f, 0.0f, "walk");
    graph.addEdge(148, 214, 35.0f, 0.0f, "walk");
    graph.addEdge(149, 227, 30.0f, 0.0f, "walk");
    graph.addEdge(150, 226, 40.0f, 0.0f, "walk");
    graph.addEdge(151, 226, 40.0f, 0.0f, "walk");

    return graph;
}