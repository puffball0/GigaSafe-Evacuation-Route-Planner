#include "lowergroundfloor.h"

Graph LowerGroundFloor::buildLowerGroundFloorGraph() {
    Graph graph;

    // ==============================================================================================
    // LOWER GROUND FLOOR - HIGH PRECISION VISUAL OVERLAY (SHIFTED -50px LEFT)
    // ==============================================================================================
    // Coordinate System Reference: 1600x600 Image
    // - Carrefour: Left Block (x < 900) - NOT SHIFTED
    // - Exits: Entry/Exit points - NOT SHIFTED
    // - All other nodes: SHIFTED -50px LEFT

    // ==================== 1. CORRIDOR BACKBONE (THE HIGHWAYS) - SHIFTED ====================

    // --- TOP MAIN CORRIDOR (The long white path below the top exits) ---
    // y = 190 approx
    graph.addNode({200, "Top Corridor 1", "corridor", 205, 190, 0, false, false});
    graph.addNode({201, "Top Corridor 2", "corridor", 320, 190, 0, false, false});
    graph.addNode({202, "Top Corridor 3", "corridor", 435, 190, 0, false, false});
    graph.addNode({203, "Top Corridor 4", "corridor", 550, 190, 0, false, false});
    graph.addNode({204, "Top Corridor 5", "corridor", 660, 190, 0, false, false});
    graph.addNode({205, "Top Corridor 6", "corridor", 775, 190, 0, false, false}); // Junction to Right Side
    graph.addNode({206, "Top Corridor 7", "corridor", 860, 190, 0, false, false});
    graph.addNode({207, "Top Corridor 8", "corridor", 960, 190, 0, false, false});
    graph.addNode({208, "Top Corridor 9", "corridor", 1060, 190, 0, false, false});
    graph.addNode({209, "Top Corridor 10", "corridor", 1140, 190, 0, false, false});

    // --- BOTTOM MAIN CORRIDOR (The long white path above bottom exits) ---
    // y = 412 approx (serving the bottom strip of stores)
    graph.addNode({220, "Bottom Corridor 1 (Carrefour Exit)", "corridor", 260, 412, 0, false, false});
    graph.addNode({221, "Bottom Corridor 2", "corridor", 380, 412, 0, false, false});
    graph.addNode({222, "Bottom Corridor 3 (Bank Area)", "corridor", 450, 412, 0, false, false});
    graph.addNode({223, "Bottom Corridor 4 (Service Area)", "corridor", 560, 412, 0, false, false});
    graph.addNode({224, "Bottom Corridor 5 (Almirah Area)", "corridor", 650, 412, 0, false, false});
    graph.addNode({225, "Bottom Corridor 6 (Ecta Area)", "corridor", 750, 412, 0, false, false});
    graph.addNode({226, "Bottom Corridor 7 (Digi Area)", "corridor", 850, 412, 0, false, false});
    graph.addNode({227, "Bottom Corridor 8 (Sultan Area)", "corridor", 950, 412, 0, false, false});
    graph.addNode({228, "Bottom Corridor 9 (Zamzam Area)", "corridor", 1050, 412, 0, false, false});


    // --- RIGHT SIDE VERTICAL & HORIZONTAL GRID (The Mall Area) - SHIFTED ---
    
    // Level 1 Horizontal (Upper Stores) - y=230
    graph.addNode({230, "Right L1 Left", "corridor", 860, 230, 0, false, false});
    graph.addNode({231, "Right L1 Mid", "corridor", 960, 230, 0, false, false});
    graph.addNode({232, "Right L1 Right", "corridor", 1060, 230, 0, false, false});
    graph.addNode({233, "Right L1 Far", "corridor", 1135, 230, 0, false, false}); // Near Punjab Board

    // Level 2 Horizontal (Middle Stores) - y=285
    graph.addNode({240, "Right L2 Left", "corridor", 860, 285, 0, false, false});
    graph.addNode({241, "Right L2 Mid", "corridor", 960, 285, 0, false, false});
    graph.addNode({242, "Right L2 Right", "corridor", 1060, 285, 0, false, false});
    graph.addNode({243, "Right L2 Far", "corridor", 1135, 285, 0, false, false});

    // Level 3 Horizontal (Lower Stores) - y=335
    graph.addNode({250, "Right L3 Left", "corridor", 860, 335, 0, false, false});
    graph.addNode({251, "Right L3 Mid", "corridor", 960, 335, 0, false, false});
    graph.addNode({252, "Right L3 Right", "corridor", 1060, 335, 0, false, false});
    graph.addNode({253, "Right L3 Far", "corridor", 1135, 335, 0, false, false});

    // Level 4 Horizontal (Just above Bottom Corridor) - y=380
    graph.addNode({260, "Right L4 Left", "corridor", 860, 380, 0, false, false});
    graph.addNode({261, "Right L4 Mid", "corridor", 960, 380, 0, false, false});
    graph.addNode({262, "Right L4 Right", "corridor", 1060, 380, 0, false, false});
    graph.addNode({263, "Right L4 Far", "corridor", 1135, 380, 0, false, false});


    // ==================== 2. CARREFOUR INTERIOR (LEFT BLOCK) - NOT SHIFTED ====================
    // 3x3 Grid mostly centered in the grey block
    graph.addNode({101, "Carrefour NW", "shop", 250, 240, 0, false, false});
    graph.addNode({102, "Carrefour N", "shop", 480, 240, 0, false, false});
    graph.addNode({103, "Carrefour NE", "shop", 700, 240, 0, false, false});
    
    graph.addNode({104, "Carrefour W", "shop", 250, 310, 0, false, false});
    graph.addNode({105, "Carrefour Center", "shop", 480, 310, 0, false, false});
    graph.addNode({106, "Carrefour E", "shop", 700, 310, 0, false, false});
    
    graph.addNode({107, "Carrefour SW", "shop", 250, 380, 0, false, false});
    graph.addNode({108, "Carrefour S", "shop", 480, 361, 0, false, false});
    graph.addNode({109, "Carrefour SE", "shop", 700, 361, 0, false, false});


    // ==================== 3. EXITS (EXACT LOCATIONS) - NOT SHIFTED ====================
    
    // --- Carrefour Exits (Green Icons Inside) ---
    // Top Row: 3 Exits
    graph.addNode({110, "Carrefour Top Exit 1", "exit", 271, 190, 0, true, false});
    graph.addNode({111, "Carrefour Top Exit 2", "exit", 485, 185, 0, true, false});
    graph.addNode({112, "Carrefour Top Exit 3", "exit", 644, 188, 0, true, false});
    // Bottom: 1 Exit
    graph.addNode({113, "Carrefour Bottom Exit", "exit", 318, 444, 0, true, false});

    // --- Mall Exits (Green Icons Outside) ---
    // Top Row: 6 Exits (Right side)
    graph.addNode({114, "Mall Top Exit 1", "exit", 832, 184, 0, true, false});  // Near Top C7
    graph.addNode({115, "Mall Top Exit 2", "exit", 913, 161, 0, true, false}); // Between C7-C8
    graph.addNode({116, "Mall Top Exit 3", "exit", 931, 161, 0, true, false}); // Near C8
    graph.addNode({117, "Mall Top Exit 4", "exit", 975, 161, 0, true, false});
    graph.addNode({118, "Mall Top Exit 5", "exit", 995, 161, 0, true, false});
    graph.addNode({119, "Mall Top Exit 6", "exit", 1044, 186, 0, true, false}); // Far Right

    // Bottom Row: 2 Exits (Right side)
    graph.addNode({120, "Mall Bottom Exit 1", "exit", 694, 444, 0, true, false}); // Near Bottom corridor
    graph.addNode({121, "Mall Bottom Exit 2", "exit", 991, 444, 0, true, false}); // Far Right Bottom


    // ==================== 4. STORES (MAPPED TO NEAREST CORRIDOR) - SHIFTED ====================

    // --- BOTTOM STRIP STORES (y ~ 435) ---
    // They are physically below the bottom corridor (y=412)
    graph.addNode({122, "DUBAI ISLAMIC BANK", "shop", 475, 435, 0, false, false});
    graph.addNode({123, "DOLLAR STORE", "shop", 505, 435, 0, false, false});
    graph.addNode({124, "SERVICE", "shop", 564, 435, 0, false, false}); // Near C4
    graph.addNode({125, "MILLI SHOES", "shop", 614, 435, 0, false, false});
    
    // Orange Stores cluster
    graph.addNode({126, "ALMIRAH KIDS", "shop", 615, 435, 0, false, false});
    graph.addNode({127, "Store Orange", "shop", 655, 435, 0, false, false});
    graph.addNode({128, "Store Orange 2", "shop", 669, 435, 0, false, false});
    
    graph.addNode({129, "BATA", "shop", 725, 435, 0, false, false});
    graph.addNode({130, "BRAND CITY", "shop", 765, 435, 0, false, false});
    
    graph.addNode({131, "NDURE", "shop", 803, 435, 0, false, false});
    graph.addNode({132, "READER'S POINT", "shop", 841, 435, 0, false, false});
    
    graph.addNode({133, "JOHRI", "shop", 880, 435, 0, false, false});
    
    graph.addNode({134, "MUSA CARPETS", "shop", 937, 435, 0, false, false});
    graph.addNode({135, "Store Purple 1", "shop", 1059, 451, 0, false, false});
    graph.addNode({136, "Store Purple 2", "shop", 1070, 451, 0, false, false});


    // --- RIGHT SIDE MALL STORES (Blocks between corridors) - SHIFTED ---
    
    // Top Row (y ~ 200, below Top Corridor)
    graph.addNode({137, "Store Top Small", "shop", 945, 205, 0, false, false});
    graph.addNode({138, "BRAND GALLERY", "shop", 1065, 205, 0, false, false});

    // Level 1 Block (y ~ 260)
    graph.addNode({139, "FRIENDS", "shop", 914, 269, 0, false, false});
    graph.addNode({140, "LIQUID COMPANY", "shop", 970, 269, 0, false, false});
    graph.addNode({141, "D WATSON", "shop", 1028, 269, 0, false, false});
    graph.addNode({142, "PUNJAB BOARD", "shop", 1093, 256, 0, false, false});

    // Level 2 Block (y ~ 310)
    graph.addNode({143, "ZENO", "shop", 945, 315, 0, false, false});
    graph.addNode({144, "UNIQUE", "shop", 1110, 315, 0, false, false});

    // Level 3 Block (y ~ 360)
    graph.addNode({145, "ROBINSON CRUSOE", "shop", 918, 360, 0, false, false});
    graph.addNode({146, "JUNAID JAMSHED", "shop", 992, 355, 0, false, false});
    graph.addNode({147, "ROYAL FURNITURE", "shop", 1034, 355, 0, false, false});
    graph.addNode({148, "STYLO COMFORT", "shop", 1110, 387, 0, false, false});

    // ==================== 5. STAIRS/ELEVATORS - SHIFTED ====================
    // Center Cluster (y ~ 290-360)
    graph.addNode({150, "Stairs Center 1", "stairs", 845, 290, 0, false, false});
    graph.addNode({151, "Stairs Center 2", "stairs", 875, 290, 0, false, false});
    graph.addNode({152, "Stairs Center 3", "stairs", 845, 330, 0, false, false});
    graph.addNode({153, "Stairs Center 4", "stairs", 875, 330, 0, false, false});
    
    // Bottom Cluster
    graph.addNode({154, "Stairs Bottom 1", "stairs", 1015, 450, 0, false, false});
    graph.addNode({155, "Stairs Bottom 2", "stairs", 1085, 450, 0, false, false});


    // ==============================================================================================
    // EDGE CONNECTIONS (STRICT CORRIDOR TOPOLOGY)
    // ==============================================================================================

    // 1. CORRIDOR BACKBONE (Horizontal Movement)
    // Top Main Corridor - FULLY CONNECTED
    graph.addEdge(200, 201, 115.0f, 0.0f, "walk");
    graph.addEdge(201, 202, 115.0f, 0.0f, "walk");
    graph.addEdge(202, 203, 115.0f, 0.0f, "walk");
    graph.addEdge(203, 204, 110.0f, 0.0f, "walk");
    graph.addEdge(204, 205, 115.0f, 0.0f, "walk");
    graph.addEdge(205, 206, 85.0f, 0.0f, "walk");
    graph.addEdge(206, 207, 100.0f, 0.0f, "walk");
    graph.addEdge(207, 208, 100.0f, 0.0f, "walk");
    graph.addEdge(208, 209, 80.0f, 0.0f, "walk");

    // Right Side Levels (Horizontal) - FULLY CONNECTED
    // L1
    graph.addEdge(230, 231, 100.0f, 0.0f, "walk");
    graph.addEdge(231, 232, 100.0f, 0.0f, "walk");
    graph.addEdge(232, 233, 75.0f, 0.0f, "walk");
    // L2
    graph.addEdge(240, 241, 100.0f, 0.0f, "walk");
    graph.addEdge(241, 242, 100.0f, 0.0f, "walk");
    graph.addEdge(242, 243, 75.0f, 0.0f, "walk");
    // L3
    graph.addEdge(250, 251, 100.0f, 0.0f, "walk");
    graph.addEdge(251, 252, 100.0f, 0.0f, "walk");
    graph.addEdge(252, 253, 75.0f, 0.0f, "walk");
    // L4
    graph.addEdge(260, 261, 100.0f, 0.0f, "walk");
    graph.addEdge(261, 262, 100.0f, 0.0f, "walk");
    graph.addEdge(262, 263, 75.0f, 0.0f, "walk");

    // Bottom Main Corridor - FULLY CONNECTED
    graph.addEdge(220, 221, 120.0f, 0.0f, "walk");
    graph.addEdge(221, 222, 70.0f, 0.0f, "walk");
    graph.addEdge(222, 223, 110.0f, 0.0f, "walk");
    graph.addEdge(223, 224, 90.0f, 0.0f, "walk");
    graph.addEdge(224, 225, 100.0f, 0.0f, "walk");
    graph.addEdge(225, 226, 100.0f, 0.0f, "walk");
    graph.addEdge(226, 227, 100.0f, 0.0f, "walk");
    graph.addEdge(227, 228, 100.0f, 0.0f, "walk");

    // 2. CORRIDOR INTERCONNECTIONS (Vertical Movement)
    // Connecting Top Corridor to Right Side Grid
    graph.addEdge(206, 230, 40.0f, 0.0f, "walk"); // Top C7 -> L1 Left
    graph.addEdge(207, 231, 40.0f, 0.0f, "walk"); // Top C8 -> L1 Mid
    graph.addEdge(208, 232, 40.0f, 0.0f, "walk"); // Top C9 -> L1 Right
    graph.addEdge(209, 233, 40.0f, 0.0f, "walk"); // Top C10 -> L1 Far (CRITICAL CONNECTION ADDED)

    // Vertical Ladder: L1 -> L2 -> L3 -> L4 -> Bottom
    // Left Ladder
    graph.addEdge(230, 240, 55.0f, 0.0f, "walk");
    graph.addEdge(240, 250, 50.0f, 0.0f, "walk");
    graph.addEdge(250, 260, 45.0f, 0.0f, "walk");
    graph.addEdge(260, 226, 32.0f, 0.0f, "walk"); // L4 Left -> Bottom C7
    
    // Mid Ladder
    graph.addEdge(231, 241, 55.0f, 0.0f, "walk");
    graph.addEdge(241, 251, 50.0f, 0.0f, "walk");
    graph.addEdge(251, 261, 45.0f, 0.0f, "walk");
    graph.addEdge(261, 227, 32.0f, 0.0f, "walk"); // L4 Mid -> Bottom C8
    
    // Right Ladder
    graph.addEdge(232, 242, 55.0f, 0.0f, "walk");
    graph.addEdge(242, 252, 50.0f, 0.0f, "walk");
    graph.addEdge(252, 262, 45.0f, 0.0f, "walk");
    graph.addEdge(262, 228, 32.0f, 0.0f, "walk"); // L4 Right -> Bottom C9

    // Far Right Ladder (COMPLETE CONNECTION)
    graph.addEdge(233, 243, 55.0f, 0.0f, "walk");
    graph.addEdge(243, 253, 50.0f, 0.0f, "walk");
    graph.addEdge(253, 263, 45.0f, 0.0f, "walk"); // CRITICAL CONNECTION ADDED
    graph.addEdge(263, 228, 32.0f, 0.0f, "walk"); // L4 Far -> Bottom C9 (CRITICAL CONNECTION ADDED)

    // CRITICAL: Bridge between Carrefour and Right Mall
    // Connect Top Corridor 6 (junction point) to both areas
    graph.addEdge(205, 225, 222.0f, 0.0f, "walk"); // Diagonal connection from Top to Bottom

    // 3. STORE CONNECTIONS (Straight to nearest corridor node)
    
    // Bottom Strip Stores
    graph.addEdge(122, 222, 23.0f, 0.0f, "walk"); // Bank -> Bottom C3
    graph.addEdge(123, 222, 30.0f, 0.0f, "walk"); // Dollar -> Bottom C3
    graph.addEdge(124, 223, 23.0f, 0.0f, "walk"); // Service -> Bottom C4
    graph.addEdge(125, 223, 30.0f, 0.0f, "walk"); // Milli -> Bottom C4
    graph.addEdge(126, 224, 23.0f, 0.0f, "walk"); // Almirah -> Bottom C5
    graph.addEdge(127, 224, 23.0f, 0.0f, "walk"); // Orange -> Bottom C5
    graph.addEdge(128, 224, 30.0f, 0.0f, "walk"); // Orange 2 -> Bottom C5
    graph.addEdge(129, 225, 23.0f, 0.0f, "walk"); // Bata -> Bottom C6
    graph.addEdge(130, 225, 30.0f, 0.0f, "walk"); // Brand City -> Bottom C6
    graph.addEdge(131, 226, 23.0f, 0.0f, "walk"); // Ndure -> Bottom C7
    graph.addEdge(132, 226, 30.0f, 0.0f, "walk"); // Readers -> Bottom C7
    graph.addEdge(133, 227, 23.0f, 0.0f, "walk"); // Johri -> Bottom C8
    graph.addEdge(134, 227, 30.0f, 0.0f, "walk"); // Musa -> Bottom C8
    graph.addEdge(135, 228, 39.0f, 0.0f, "walk"); // Purple 1 -> Bottom C9
    graph.addEdge(136, 228, 39.0f, 0.0f, "walk"); // Purple 2 -> Bottom C9

    // Right Side Mall Stores
    graph.addEdge(137, 207, 15.0f, 0.0f, "walk"); // Top Small -> Top C8
    graph.addEdge(138, 208, 15.0f, 0.0f, "walk"); // Brand Gallery -> Top C9
    
    graph.addEdge(139, 230, 40.0f, 0.0f, "walk"); // Friends -> L1 Left
    graph.addEdge(140, 231, 39.0f, 0.0f, "walk"); // Liquid -> L1 Mid
    graph.addEdge(141, 232, 39.0f, 0.0f, "walk"); // D Watson -> L1 Right
    graph.addEdge(142, 233, 30.0f, 0.0f, "walk"); // Punjab -> L1 Far
    
    graph.addEdge(143, 241, 30.0f, 0.0f, "walk"); // Zeno -> L2 Mid
    graph.addEdge(144, 243, 30.0f, 0.0f, "walk"); // Unique -> L2 Far
    
    graph.addEdge(145, 250, 30.0f, 0.0f, "walk"); // Robinson -> L3 Left
    graph.addEdge(146, 251, 25.0f, 0.0f, "walk"); // Junaid -> L3 Mid
    graph.addEdge(147, 252, 25.0f, 0.0f, "walk"); // Royal -> L3 Right
    graph.addEdge(148, 263, 10.0f, 0.0f, "walk"); // Stylo -> L4 Far


    // 4. CARREFOUR INTERNAL & EXITS
    // Internal Grid - FULLY CONNECTED
    graph.addEdge(101, 102, 230.0f, 0.0f, "walk");
    graph.addEdge(102, 103, 220.0f, 0.0f, "walk");
    graph.addEdge(104, 105, 230.0f, 0.0f, "walk");
    graph.addEdge(105, 106, 220.0f, 0.0f, "walk");
    graph.addEdge(107, 108, 230.0f, 0.0f, "walk");
    graph.addEdge(108, 109, 220.0f, 0.0f, "walk");
    
    graph.addEdge(101, 104, 70.0f, 0.0f, "walk");
    graph.addEdge(104, 107, 70.0f, 0.0f, "walk");
    graph.addEdge(102, 105, 70.0f, 0.0f, "walk");
    graph.addEdge(105, 108, 49.0f, 0.0f, "walk");
    graph.addEdge(103, 106, 70.0f, 0.0f, "walk");
    graph.addEdge(106, 109, 51.0f, 0.0f, "walk");

    // Connect Carrefour Internal to Top Corridor
    graph.addEdge(101, 200, 50.0f, 0.0f, "walk"); // NW -> Top C1
    graph.addEdge(102, 201, 50.0f, 0.0f, "walk"); // N -> Top C2
    graph.addEdge(103, 204, 50.0f, 0.0f, "walk"); // NE -> Top C5
    
    // Connect Carrefour Internal to Bottom Corridor
    graph.addEdge(107, 220, 50.0f, 0.0f, "walk"); // SW -> Bottom C1
    graph.addEdge(108, 221, 50.0f, 0.0f, "walk"); // S -> Bottom C2
    graph.addEdge(109, 222, 50.0f, 0.0f, "walk"); // SE -> Bottom C3
    
    // Connect Carrefour Exits to Internal Grid
    graph.addEdge(110, 101, 50.0f, 0.0f, "walk"); // Exit 1 -> NW
    graph.addEdge(111, 102, 55.0f, 0.0f, "walk"); // Exit 2 -> N
    graph.addEdge(112, 103, 48.0f, 0.0f, "walk"); // Exit 3 -> NE
    graph.addEdge(113, 107, 64.0f, 0.0f, "walk"); // Bottom Exit -> SW


    // 5. MALL EXITS (OUTSIDE)
    // Top Row Exits -> Connect to Top Corridor
    graph.addEdge(114, 205, 60.0f, 0.0f, "walk"); // Exit T1 -> Top C6
    graph.addEdge(115, 206, 50.0f, 0.0f, "walk"); // Exit T2 -> Top C7
    graph.addEdge(116, 207, 29.0f, 0.0f, "walk"); // Exit T3 -> Top C8
    graph.addEdge(117, 207, 30.0f, 0.0f, "walk"); // Exit T4 -> Top C8
    graph.addEdge(118, 208, 29.0f, 0.0f, "walk"); // Exit T5 -> Top C9
    graph.addEdge(119, 208, 45.0f, 0.0f, "walk"); // Exit T6 -> Top C9

    // Bottom Row Exits -> Connect to Bottom Corridor
    graph.addEdge(120, 225, 45.0f, 0.0f, "walk"); // Exit B1 -> Bottom C6
    graph.addEdge(121, 228, 45.0f, 0.0f, "walk"); // Exit B2 -> Bottom C9
    
    // 6. STAIRS/ELEVATORS - CONNECT TO GRID
    graph.addEdge(150, 230, 50.0f, 0.0f, "walk"); // Stairs C1 -> L1 Left
    graph.addEdge(151, 240, 25.0f, 0.0f, "walk"); // Stairs C2 -> L2 Left
    graph.addEdge(152, 250, 25.0f, 0.0f, "walk"); // Stairs C3 -> L3 Left
    graph.addEdge(153, 260, 35.0f, 0.0f, "walk"); // Stairs C4 -> L4 Left
    
    graph.addEdge(154, 228, 40.0f, 0.0f, "walk"); // Stairs B1 -> Bottom C9
    graph.addEdge(155, 228, 50.0f, 0.0f, "walk"); // Stairs B2 -> Bottom C9

    return graph;
}