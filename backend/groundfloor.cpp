#include "groundfloor.h"

Graph GroundFloor::buildGroundFloorGraph() {
    Graph graph;

    // ==================== GROUND FLOOR - ACCURATE MAPPING ====================
    // Image dimensions reference: 1400x500 (approximate from the floor plan)

    // LEFT SECTION STORES (Top Row)
    graph.addNode({1, "SAPPHIRE", "shop", 100, 170, 0, false, false});
    graph.addNode({2, "SAYA", "shop", 235, 165, 0, false, false});
    graph.addNode({3, "CROSS STITCH", "shop", 280, 195, 0, false, false});
    graph.addNode({4, "BTW", "shop", 328, 165, 0, false, false});
    graph.addNode({5, "AIJAZN", "shop", 370, 165, 0, false, false});

    // LEFT SECTION STORES (Bottom Row)
    graph.addNode({6, "FPL", "shop", 85, 265, 0, false, false});
    graph.addNode({7, "ETHNIC", "shop", 100, 350, 0, false, false});
    graph.addNode({8, "NAKSHI", "shop", 200, 330, 0, false, false});
    graph.addNode({9, "MISHAL APPAREL", "shop", 230, 330, 0, false, false});
    graph.addNode({10, "NISTORE", "shop", 260, 330, 0, false, false});
    graph.addNode({11, "HOPSCOTCH", "shop", 290, 330, 0, false, false});
    graph.addNode({12, "INSIGNIA", "shop", 320, 330, 0, false, false});
    graph.addNode({13, "CINNAMON", "shop", 350, 330, 0, false, false});

    // CENTER-LEFT SECTION STORES (Top Row)
    graph.addNode({14, "JESTER PLUS", "shop", 445, 148, 0, false, false});
    graph.addNode({15, "SAMEER KHETTY", "shop", 495, 148, 0, false, false});
    graph.addNode({16, "ECUADOR", "shop", 535, 148, 0, false, false});
    graph.addNode({17, "BRIDGE", "shop", 575, 148, 0, false, false});

    // CENTER SECTION STORES
    graph.addNode({18, "MONARK", "shop", 570, 240, 0, false, false});
    graph.addNode({19, "CHARCOAL", "shop", 570, 280, 0, false, false});
    graph.addNode({20, "MINI-SO", "shop", 570, 320, 0, false, false});

    // CENTER-RIGHT SECTION STORES (Top Row)
    graph.addNode({21, "LORSE", "shop", 635, 175, 0, false, false});
    graph.addNode({22, "ADIDAS", "shop", 738, 175, 0, false, false});
    graph.addNode({23, "NIKE", "shop", 798, 175, 0, false, false});

    // CENTER-RIGHT SECTION STORES
    graph.addNode({24, "ROYAL TAG", "shop", 720, 240, 0, false, false});
    graph.addNode({25, "1ST STEP", "shop", 720, 280, 0, false, false});
    graph.addNode({26, "MANTRA", "shop", 695, 320, 0, false, false});
    graph.addNode({27, "ULTA CLUB", "shop", 740, 320, 0, false, false});

    // RIGHT SECTION STORES (Top Row)
    graph.addNode({28, "COUGAR", "shop", 910, 210, 0, false, false});
    graph.addNode({29, "MOOCHNI", "shop", 970, 210, 0, false, false});
    graph.addNode({30, "ECS", "shop", 1030, 210, 0, false, false});

    // RIGHT SECTION STORES (Bottom Row)
    graph.addNode({31, "ATRIUM", "shop", 970, 285, 0, false, false});
    graph.addNode({32, "NIRALA B", "shop", 910, 345, 0, false, false});
    graph.addNode({33, "LEVIS DOCKERS", "shop", 950, 345, 0, false, false});
    graph.addNode({34, "SKECHERS", "shop", 1000, 345, 0, false, false});
    graph.addNode({35, "EDENROBE STUDIO", "shop", 1050, 345, 0, false, false});

    // FAR RIGHT SECTION STORES
    graph.addNode({36, "LIMELIGHT", "shop", 1175, 235, 0, false, false});
    graph.addNode({37, "KHAADI", "shop", 1175, 315, 0, false, false});

    // TOP SPECIAL AREAS
    graph.addNode({38, "KIDS MANSION DAYCARE", "shop", 215, 110, 0, false, false});
    graph.addNode({39, "LADY PRIVACY", "shop", 1070, 165, 0, false, false});

    // EMERGENCY EXITS (Green signs with stick figure - ACCURATE POSITIONS)
    graph.addNode({40, "Emergency Exit 1", "exit", 190, 150, 0, true, false});
    graph.addNode({41, "Emergency Exit 2", "exit", 215, 125, 0, true, false});
    graph.addNode({42, "Emergency Exit 3", "exit", 425, 160, 0, true, false});
    graph.addNode({43, "Emergency Exit 4", "exit", 615, 160, 0, true, false});
    graph.addNode({44, "Emergency Exit 5", "exit", 810, 160, 0, true, false});
    graph.addNode({45, "Emergency Exit 6", "exit", 1055, 150, 0, true, false});
    graph.addNode({46, "Emergency Exit 7", "exit", 395, 395, 0, true, false});
    graph.addNode({47, "Emergency Exit 8", "exit", 455, 395, 0, true, false});
    graph.addNode({48, "Emergency Exit 9", "exit", 850, 395, 0, true, false});

    // CORRIDOR JUNCTION NODES (Wide white paths for traversal)
    // Top Horizontal Corridor
    graph.addNode({100, "Top Corridor J1", "corridor", 165, 210, 0, false, false});
    graph.addNode({101, "Top Corridor J2", "corridor", 265, 210, 0, false, false});
    graph.addNode({102, "Top Corridor J3", "corridor", 365, 210, 0, false, false});
    graph.addNode({103, "Top Corridor J4", "corridor", 465, 210, 0, false, false});
    graph.addNode({104, "Top Corridor J5", "corridor", 615, 210, 0, false, false});
    graph.addNode({105, "Top Corridor J6", "corridor", 765, 210, 0, false, false});
    graph.addNode({106, "Top Corridor J7", "corridor", 890, 210, 0, false, false});
    graph.addNode({107, "Top Corridor J8", "corridor", 1010, 210, 0, false, false});
    graph.addNode({108, "Top Corridor J9", "corridor", 1130, 235, 0, false, false});

    // Bottom Horizontal Corridor
    graph.addNode({109, "Bottom Corridor J1", "corridor", 165, 360, 0, false, false});
    graph.addNode({110, "Bottom Corridor J2", "corridor", 265, 360, 0, false, false});
    graph.addNode({111, "Bottom Corridor J3", "corridor", 365, 360, 0, false, false});
    graph.addNode({112, "Bottom Corridor J4", "corridor", 485, 355, 0, false, false});
    graph.addNode({113, "Bottom Corridor J5", "corridor", 615, 355, 0, false, false});
    graph.addNode({114, "Bottom Corridor J6", "corridor", 765, 355, 0, false, false});
    graph.addNode({115, "Bottom Corridor J7", "corridor", 890, 355, 0, false, false});
    graph.addNode({116, "Bottom Corridor J8", "corridor", 1010, 355, 0, false, false});
    graph.addNode({117, "Bottom Corridor J9", "corridor", 1130, 330, 0, false, false});

    // Vertical Corridor Connectors
    graph.addNode({118, "Vertical Connector 1", "corridor", 485, 280, 0, false, false});
    graph.addNode({119, "Vertical Connector 2", "corridor", 615, 280, 0, false, false});
    graph.addNode({120, "Vertical Connector 3", "corridor", 765, 280, 0, false, false});

    // ==================== GROUND FLOOR EDGES (Corridor Network) ====================

    // TOP HORIZONTAL CORRIDOR PATH
    graph.addEdge(100, 101, 100.0f, 0.0f, "walk");
    graph.addEdge(101, 102, 100.0f, 0.0f, "walk");
    graph.addEdge(102, 103, 100.0f, 0.0f, "walk");
    graph.addEdge(103, 104, 150.0f, 0.0f, "walk");
    graph.addEdge(104, 105, 150.0f, 0.0f, "walk");
    graph.addEdge(105, 106, 125.0f, 0.0f, "walk");
    graph.addEdge(106, 107, 120.0f, 0.0f, "walk");
    graph.addEdge(107, 108, 120.0f, 0.0f, "walk");

    // BOTTOM HORIZONTAL CORRIDOR PATH
    graph.addEdge(109, 110, 100.0f, 0.0f, "walk");
    graph.addEdge(110, 111, 100.0f, 0.0f, "walk");
    graph.addEdge(111, 112, 120.0f, 0.0f, "walk");
    graph.addEdge(112, 113, 130.0f, 0.0f, "walk");
    graph.addEdge(113, 114, 150.0f, 0.0f, "walk");
    graph.addEdge(114, 115, 125.0f, 0.0f, "walk");
    graph.addEdge(115, 116, 120.0f, 0.0f, "walk");
    graph.addEdge(116, 117, 120.0f, 0.0f, "walk");

    // VERTICAL CONNECTIONS (Top to Bottom)
    graph.addEdge(100, 109, 150.0f, 0.0f, "walk");
    graph.addEdge(103, 118, 70.0f, 0.0f, "walk");
    graph.addEdge(118, 112, 75.0f, 0.0f, "walk");
    graph.addEdge(104, 119, 70.0f, 0.0f, "walk");
    graph.addEdge(119, 113, 75.0f, 0.0f, "walk");
    graph.addEdge(105, 120, 70.0f, 0.0f, "walk");
    graph.addEdge(120, 114, 75.0f, 0.0f, "walk");
    graph.addEdge(106, 115, 145.0f, 0.0f, "walk");
    graph.addEdge(108, 117, 95.0f, 0.0f, "walk");

    // ==================== STORE CONNECTIONS TO CORRIDORS ====================

    // LEFT SECTION STORES TO CORRIDORS
    graph.addEdge(1, 100, 45.0f, 0.0f, "walk");
    graph.addEdge(2, 101, 50.0f, 0.0f, "walk");
    graph.addEdge(3, 101, 35.0f, 0.0f, "walk");
    graph.addEdge(4, 102, 50.0f, 0.0f, "walk");
    graph.addEdge(5, 102, 50.0f, 0.0f, "walk");
    graph.addEdge(6, 109, 50.0f, 0.0f, "walk");
    graph.addEdge(7, 109, 35.0f, 0.0f, "walk");
    graph.addEdge(8, 110, 35.0f, 0.0f, "walk");
    graph.addEdge(9, 110, 35.0f, 0.0f, "walk");
    graph.addEdge(10, 110, 35.0f, 0.0f, "walk");
    graph.addEdge(11, 111, 35.0f, 0.0f, "walk");
    graph.addEdge(12, 111, 35.0f, 0.0f, "walk");
    graph.addEdge(13, 111, 35.0f, 0.0f, "walk");

    // CENTER-LEFT STORES TO CORRIDORS
    graph.addEdge(14, 103, 65.0f, 0.0f, "walk");
    graph.addEdge(15, 104, 65.0f, 0.0f, "walk");
    graph.addEdge(16, 104, 65.0f, 0.0f, "walk");
    graph.addEdge(17, 104, 65.0f, 0.0f, "walk");

    // CENTER STORES TO VERTICAL CONNECTORS
    graph.addEdge(18, 119, 45.0f, 0.0f, "walk");
    graph.addEdge(19, 119, 35.0f, 0.0f, "walk");
    graph.addEdge(20, 113, 40.0f, 0.0f, "walk");

    // CENTER-RIGHT STORES TO CORRIDORS
    graph.addEdge(21, 104, 40.0f, 0.0f, "walk");
    graph.addEdge(22, 105, 40.0f, 0.0f, "walk");
    graph.addEdge(23, 105, 40.0f, 0.0f, "walk");
    graph.addEdge(24, 120, 45.0f, 0.0f, "walk");
    graph.addEdge(25, 120, 35.0f, 0.0f, "walk");
    graph.addEdge(26, 114, 40.0f, 0.0f, "walk");
    graph.addEdge(27, 114, 40.0f, 0.0f, "walk");

    // RIGHT SECTION STORES TO CORRIDORS
    graph.addEdge(28, 106, 35.0f, 0.0f, "walk");
    graph.addEdge(29, 107, 35.0f, 0.0f, "walk");
    graph.addEdge(30, 107, 35.0f, 0.0f, "walk");
    graph.addEdge(31, 115, 35.0f, 0.0f, "walk");
    graph.addEdge(32, 115, 45.0f, 0.0f, "walk");
    graph.addEdge(33, 115, 40.0f, 0.0f, "walk");
    graph.addEdge(34, 116, 40.0f, 0.0f, "walk");
    graph.addEdge(35, 116, 45.0f, 0.0f, "walk");

    // FAR RIGHT STORES TO CORRIDORS
    graph.addEdge(36, 108, 45.0f, 0.0f, "walk");
    graph.addEdge(37, 117, 40.0f, 0.0f, "walk");

    // SPECIAL AREAS TO CORRIDORS
    graph.addEdge(38, 101, 100.0f, 0.0f, "walk");
    graph.addEdge(39, 107, 55.0f, 0.0f, "walk");

    // ==================== EMERGENCY EXIT CONNECTIONS ====================
    graph.addEdge(40, 100, 35.0f, 0.0f, "walk");
    graph.addEdge(41, 101, 30.0f, 0.0f, "walk");
    graph.addEdge(42, 103, 35.0f, 0.0f, "walk");
    graph.addEdge(43, 104, 35.0f, 0.0f, "walk");
    graph.addEdge(44, 105, 35.0f, 0.0f, "walk");
    graph.addEdge(45, 107, 35.0f, 0.0f, "walk");
    graph.addEdge(46, 111, 40.0f, 0.0f, "walk");
    graph.addEdge(47, 112, 40.0f, 0.0f, "walk");
    graph.addEdge(48, 115, 45.0f, 0.0f, "walk");

    return graph;
}
