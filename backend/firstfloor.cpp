#include "firstfloor.h"

Graph FirstFloor::buildFirstFloorGraph() {
    Graph graph;

    // ==================== FIRST FLOOR - ACCURATE MAPPING ====================
    // Image dimensions reference: 1600x600 (approximate from the floor plan)

    // LEFT SECTION STORES (Large stores on left side)
    graph.addNode({201, "IDEAS by GUL AHMED", "shop", 155, 240, 1, false, false});
    graph.addNode({202, "NISHAT", "shop", 155, 305, 1, false, false});
    graph.addNode({203, "OUTFITTERS", "shop", 155, 373, 1, false, false});

    // LEFT-CENTER SECTION STORES (Top Row)
    graph.addNode({204, "JUNAID JAMSHED", "shop", 360, 175, 1, false, false});
    graph.addNode({205, "ALKARAM & LIFESTYLE", "shop", 520, 148, 1, false, false});

    // LEFT-CENTER SECTION STORES (Middle Area)
    graph.addNode({206, "JALIPS", "shop", 340, 252, 1, false, false});
    graph.addNode({207, "HAPPYLAND", "shop", 420, 252, 1, false, false});
    graph.addNode({208, "ATRIUM", "shop", 420, 303, 1, false, false});
    graph.addNode({209, "COFFEE PLANET", "shop", 340, 335, 1, false, false});
    graph.addNode({210, "E", "shop", 390, 335, 1, false, false});
    graph.addNode({211, "MOORI", "shop", 420, 335, 1, false, false});

    // CENTER SECTION STORES (Top Row)
    graph.addNode({212, "CAMBRIDGE", "shop", 605, 148, 1, false, false});
    graph.addNode({213, "KAYSERIA", "shop", 720, 175, 1, false, false});
    graph.addNode({214, "BATIK", "shop", 770, 175, 1, false, false});
    graph.addNode({215, "SAPPHIRE", "shop", 820, 175, 1, false, false});
    graph.addNode({216, "DYNASTY", "shop", 870, 175, 1, false, false});

    // CENTER SECTION STORES (Middle Area)
    graph.addNode({217, "SATRANGI", "shop", 580, 252, 1, false, false});
    graph.addNode({218, "CHARIZMA", "shop", 580, 303, 1, false, false});
    graph.addNode({219, "MINNIE", "shop", 580, 340, 1, false, false});
    graph.addNode({220, "CHINYERE", "shop", 640, 340, 1, false, false});
    graph.addNode({221, "BAREEZE", "shop", 695, 340, 1, false, false});

    graph.addNode({222, "AMIR ADNAN", "shop", 710, 252, 1, false, false});
    graph.addNode({223, "FUROR", "shop", 735, 303, 1, false, false});
    graph.addNode({224, "SANA SAFINAZ", "shop", 760, 340, 1, false, false});

    // CENTER-RIGHT SECTION STORES
    graph.addNode({225, "ZEEN", "shop", 955, 235, 1, false, false});
    graph.addNode({226, "GENERATION", "shop", 1065, 235, 1, false, false});
    graph.addNode({227, "ATRIUM", "shop", 1065, 303, 1, false, false});

    // RIGHT SECTION STORES (Top Area)
    graph.addNode({228, "STYLO", "shop", 1165, 252, 1, false, false});
    graph.addNode({229, "FANKARE", "shop", 1220, 252, 1, false, false});
    graph.addNode({230, "HUSHPUPPIES", "shop", 1275, 252, 1, false, false});
    graph.addNode({231, "J.", "shop", 1315, 252, 1, false, false});

    // RIGHT SECTION STORES (Bottom Area)
    graph.addNode({232, "BEECHTREE PEPPERLAND", "shop", 965, 373, 1, false, false});
    graph.addNode({233, "UNIWORTH", "shop", 1010, 373, 1, false, false});
    graph.addNode({234, "DINERS", "shop", 1090, 365, 1, false, false});
    graph.addNode({235, "ECS", "shop", 1140, 365, 1, false, false});
    graph.addNode({236, "CHEN ONE PLACE", "shop", 1190, 373, 1, false, false});
    graph.addNode({237, "BREAKOUT", "shop", 1240, 388, 1, false, false});
    graph.addNode({238, "ZEALOUS", "shop", 1285, 388, 1, false, false});
    graph.addNode({239, "EDENROBE", "shop", 1350, 373, 1, false, false});

    // BOTTOM LEFT SECTION STORES
    graph.addNode({240, "BORJAN", "shop", 310, 415, 1, false, false});
    graph.addNode({241, "SERVICE SHOES", "shop", 370, 425, 1, false, false});
    graph.addNode({242, "AYSARIA", "shop", 420, 415, 1, false, false});
    graph.addNode({243, "THE MARK", "shop", 460, 415, 1, false, false});
    graph.addNode({244, "LITTLE PEOPLE", "shop", 505, 415, 1, false, false});

    // BOTTOM CENTER SECTION STORES
    graph.addNode({245, "BANANAZ", "shop", 555, 425, 1, false, false});
    graph.addNode({246, "M BLOCK", "shop", 595, 425, 1, false, false});
    graph.addNode({247, "GINY & JONY", "shop", 665, 425, 1, false, false});
    graph.addNode({248, "ARMY PRET", "shop", 720, 425, 1, false, false});
    graph.addNode({249, "MOTIFS", "shop", 765, 425, 1, false, false});

    // BOTTOM CENTER-RIGHT SECTION STORES
    graph.addNode({250, "THREADZ", "shop", 810, 415, 1, false, false});
    graph.addNode({251, "LOCO SHOES", "shop", 855, 415, 1, false, false});
    graph.addNode({252, "OAKS", "shop", 900, 415, 1, false, false});
    graph.addNode({253, "BONANZA SATRANGI", "shop", 955, 425, 1, false, false});

    // EMERGENCY EXITS - EXACTLY 8 (Green rectangles with stick figure)
    // Top row exits (left to right)
    graph.addNode({254, "Emergency Exit 1", "exit", 210, 117, 1, true, false});
    graph.addNode({255, "Emergency Exit 2", "exit", 312, 117, 1, true, false});
    graph.addNode({256, "Emergency Exit 3", "exit", 450, 175, 1, true, false});
    graph.addNode({257, "Emergency Exit 4", "exit", 625, 175, 1, true, false});
    graph.addNode({258, "Emergency Exit 5", "exit", 840, 175, 1, true, false});
    graph.addNode({259, "Emergency Exit 6", "exit", 1005, 175, 1, true, false});
    graph.addNode({260, "Emergency Exit 7", "exit", 1135, 175, 1, true, false});
    // Bottom exit
    graph.addNode({261, "Emergency Exit 8", "exit", 710, 460, 1, true, false});

    // STAIRS/ELEVATORS (Purple/Pink icons - Orange/Yellow on sides)
    graph.addNode({262, "Stairs/Elevator 1", "stairs", 230, 440, 1, false, false});
    graph.addNode({263, "Stairs/Elevator 2", "stairs", 640, 440, 1, false, false});
    graph.addNode({264, "Stairs/Elevator 3", "stairs", 1015, 440, 1, false, false});
    graph.addNode({265, "Stairs/Elevator 4", "stairs", 1115, 440, 1, false, false});
    graph.addNode({266, "Stairs/Elevator Top Left", "stairs", 210, 117, 1, false, false});
    graph.addNode({267, "Stairs/Elevator Top Center", "stairs", 312, 117, 1, false, false});
    graph.addNode({268, "Stairs/Elevator Top Right 1", "stairs", 1135, 175, 1, false, false});
    graph.addNode({269, "Stairs/Elevator Top Right 2", "stairs", 1205, 175, 1, false, false});

    // ATRIUM/OPEN SPACES (Blue vertical areas in center)
    graph.addNode({270, "ATRIUM Central Upper", "atrium", 825, 240, 1, false, false});
    graph.addNode({271, "ATRIUM Central Middle", "atrium", 825, 290, 1, false, false});
    graph.addNode({272, "ATRIUM Central Lower", "atrium", 825, 340, 1, false, false});

    // ==================== CORRIDOR JUNCTION NODES ====================
    
    // TOP HORIZONTAL CORRIDOR (Main upper walkway)
    graph.addNode({300, "Top Corridor J1", "corridor", 155, 215, 1, false, false});
    graph.addNode({301, "Top Corridor J2", "corridor", 260, 210, 1, false, false});
    graph.addNode({302, "Top Corridor J3", "corridor", 380, 210, 1, false, false});
    graph.addNode({303, "Top Corridor J4", "corridor", 490, 210, 1, false, false});
    graph.addNode({304, "Top Corridor J5", "corridor", 605, 210, 1, false, false});
    graph.addNode({305, "Top Corridor J6", "corridor", 720, 210, 1, false, false});
    graph.addNode({306, "Top Corridor J7", "corridor", 865, 210, 1, false, false});
    graph.addNode({307, "Top Corridor J8", "corridor", 1010, 210, 1, false, false});
    graph.addNode({308, "Top Corridor J9", "corridor", 1150, 215, 1, false, false});
    graph.addNode({309, "Top Corridor J10", "corridor", 1290, 215, 1, false, false});

    // MIDDLE HORIZONTAL CORRIDOR (Between stores)
    graph.addNode({310, "Middle Corridor J1", "corridor", 260, 285, 1, false, false});
    graph.addNode({311, "Middle Corridor J2", "corridor", 380, 285, 1, false, false});
    graph.addNode({312, "Middle Corridor J3", "corridor", 500, 285, 1, false, false});
    graph.addNode({313, "Middle Corridor J4", "corridor", 650, 285, 1, false, false});
    graph.addNode({314, "Middle Corridor J5", "corridor", 865, 275, 1, false, false});
    graph.addNode({315, "Middle Corridor J6", "corridor", 1010, 275, 1, false, false});
    graph.addNode({316, "Middle Corridor J7", "corridor", 1140, 300, 1, false, false});

    // BOTTOM HORIZONTAL CORRIDOR (Lower walkway)
    graph.addNode({317, "Bottom Corridor J1", "corridor", 260, 390, 1, false, false});
    graph.addNode({318, "Bottom Corridor J2", "corridor", 380, 390, 1, false, false});
    graph.addNode({319, "Bottom Corridor J3", "corridor", 490, 390, 1, false, false});
    graph.addNode({320, "Bottom Corridor J4", "corridor", 610, 390, 1, false, false});
    graph.addNode({321, "Bottom Corridor J5", "corridor", 735, 390, 1, false, false});
    graph.addNode({322, "Bottom Corridor J6", "corridor", 865, 390, 1, false, false});
    graph.addNode({323, "Bottom Corridor J7", "corridor", 985, 405, 1, false, false});
    graph.addNode({324, "Bottom Corridor J8", "corridor", 1115, 405, 1, false, false});
    graph.addNode({325, "Bottom Corridor J9", "corridor", 1240, 405, 1, false, false});

    // VERTICAL CORRIDOR CONNECTORS
    graph.addNode({326, "Vertical Connector 1", "corridor", 500, 340, 1, false, false});
    graph.addNode({327, "Vertical Connector 2", "corridor", 650, 340, 1, false, false});

    // ==================== CORRIDOR NETWORK EDGES ====================

    // TOP HORIZONTAL CORRIDOR PATH
    graph.addEdge(300, 301, 105.0f, 0.0f, "walk");
    graph.addEdge(301, 302, 120.0f, 0.0f, "walk");
    graph.addEdge(302, 303, 110.0f, 0.0f, "walk");
    graph.addEdge(303, 304, 115.0f, 0.0f, "walk");
    graph.addEdge(304, 305, 115.0f, 0.0f, "walk");
    graph.addEdge(305, 306, 145.0f, 0.0f, "walk");
    graph.addEdge(306, 307, 145.0f, 0.0f, "walk");
    graph.addEdge(307, 308, 140.0f, 0.0f, "walk");
    graph.addEdge(308, 309, 140.0f, 0.0f, "walk");

    // MIDDLE HORIZONTAL CORRIDOR PATH
    graph.addEdge(310, 311, 120.0f, 0.0f, "walk");
    graph.addEdge(311, 312, 120.0f, 0.0f, "walk");
    graph.addEdge(312, 313, 150.0f, 0.0f, "walk");
    graph.addEdge(313, 314, 215.0f, 0.0f, "walk");
    graph.addEdge(314, 315, 145.0f, 0.0f, "walk");
    graph.addEdge(315, 316, 130.0f, 0.0f, "walk");

    // BOTTOM HORIZONTAL CORRIDOR PATH
    graph.addEdge(317, 318, 120.0f, 0.0f, "walk");
    graph.addEdge(318, 319, 110.0f, 0.0f, "walk");
    graph.addEdge(319, 320, 120.0f, 0.0f, "walk");
    graph.addEdge(320, 321, 125.0f, 0.0f, "walk");
    graph.addEdge(321, 322, 130.0f, 0.0f, "walk");
    graph.addEdge(322, 323, 120.0f, 0.0f, "walk");
    graph.addEdge(323, 324, 130.0f, 0.0f, "walk");
    graph.addEdge(324, 325, 125.0f, 0.0f, "walk");

    // VERTICAL CONNECTIONS
    graph.addEdge(300, 310, 70.0f, 0.0f, "walk");
    graph.addEdge(310, 317, 105.0f, 0.0f, "walk");
    graph.addEdge(301, 310, 75.0f, 0.0f, "walk");
    graph.addEdge(302, 311, 75.0f, 0.0f, "walk");
    graph.addEdge(311, 318, 105.0f, 0.0f, "walk");
    graph.addEdge(303, 312, 75.0f, 0.0f, "walk");
    graph.addEdge(312, 326, 55.0f, 0.0f, "walk");
    graph.addEdge(326, 319, 50.0f, 0.0f, "walk");
    graph.addEdge(304, 313, 75.0f, 0.0f, "walk");
    graph.addEdge(313, 327, 55.0f, 0.0f, "walk");
    graph.addEdge(327, 320, 50.0f, 0.0f, "walk");
    graph.addEdge(305, 313, 75.0f, 0.0f, "walk");
    graph.addEdge(313, 321, 105.0f, 0.0f, "walk");
    graph.addEdge(306, 314, 65.0f, 0.0f, "walk");
    graph.addEdge(314, 322, 115.0f, 0.0f, "walk");
    graph.addEdge(307, 315, 65.0f, 0.0f, "walk");
    graph.addEdge(315, 323, 130.0f, 0.0f, "walk");
    graph.addEdge(308, 316, 85.0f, 0.0f, "walk");
    graph.addEdge(316, 324, 105.0f, 0.0f, "walk");

    // ==================== STORE CONNECTIONS TO CORRIDORS ====================

    // LEFT SECTION STORES
    graph.addEdge(201, 300, 35.0f, 0.0f, "walk");
    graph.addEdge(202, 310, 40.0f, 0.0f, "walk");
    graph.addEdge(203, 317, 40.0f, 0.0f, "walk");

    // LEFT-CENTER STORES (Top)
    graph.addEdge(204, 302, 40.0f, 0.0f, "walk");
    graph.addEdge(205, 303, 65.0f, 0.0f, "walk");

    // LEFT-CENTER STORES (Middle)
    graph.addEdge(206, 311, 40.0f, 0.0f, "walk");
    graph.addEdge(207, 312, 40.0f, 0.0f, "walk");
    graph.addEdge(208, 311, 35.0f, 0.0f, "walk");
    graph.addEdge(209, 318, 60.0f, 0.0f, "walk");
    graph.addEdge(210, 318, 50.0f, 0.0f, "walk");
    graph.addEdge(211, 318, 60.0f, 0.0f, "walk");

    // CENTER STORES (Top)
    graph.addEdge(212, 304, 65.0f, 0.0f, "walk");
    graph.addEdge(213, 305, 40.0f, 0.0f, "walk");
    graph.addEdge(214, 305, 40.0f, 0.0f, "walk");
    graph.addEdge(215, 305, 40.0f, 0.0f, "walk");
    graph.addEdge(216, 306, 40.0f, 0.0f, "walk");

    // CENTER STORES (Middle)
    graph.addEdge(217, 312, 40.0f, 0.0f, "walk");
    graph.addEdge(218, 313, 35.0f, 0.0f, "walk");
    graph.addEdge(219, 327, 45.0f, 0.0f, "walk");
    graph.addEdge(220, 327, 45.0f, 0.0f, "walk");
    graph.addEdge(221, 327, 50.0f, 0.0f, "walk");
    graph.addEdge(222, 313, 40.0f, 0.0f, "walk");
    graph.addEdge(223, 313, 35.0f, 0.0f, "walk");
    graph.addEdge(224, 321, 55.0f, 0.0f, "walk");

    // CENTER-RIGHT STORES
    graph.addEdge(225, 307, 40.0f, 0.0f, "walk");
    graph.addEdge(226, 307, 40.0f, 0.0f, "walk");
    graph.addEdge(227, 315, 35.0f, 0.0f, "walk");

    // RIGHT STORES (Top)
    graph.addEdge(228, 308, 45.0f, 0.0f, "walk");
    graph.addEdge(229, 308, 45.0f, 0.0f, "walk");
    graph.addEdge(230, 309, 45.0f, 0.0f, "walk");
    graph.addEdge(231, 309, 45.0f, 0.0f, "walk");

    // RIGHT STORES (Bottom)
    graph.addEdge(232, 323, 40.0f, 0.0f, "walk");
    graph.addEdge(233, 323, 35.0f, 0.0f, "walk");
    graph.addEdge(234, 324, 45.0f, 0.0f, "walk");
    graph.addEdge(235, 324, 45.0f, 0.0f, "walk");
    graph.addEdge(236, 324, 40.0f, 0.0f, "walk");
    graph.addEdge(237, 325, 35.0f, 0.0f, "walk");
    graph.addEdge(238, 325, 35.0f, 0.0f, "walk");
    graph.addEdge(239, 325, 40.0f, 0.0f, "walk");

    // BOTTOM LEFT STORES
    graph.addEdge(240, 318, 35.0f, 0.0f, "walk");
    graph.addEdge(241, 318, 40.0f, 0.0f, "walk");
    graph.addEdge(242, 319, 35.0f, 0.0f, "walk");
    graph.addEdge(243, 319, 35.0f, 0.0f, "walk");
    graph.addEdge(244, 319, 35.0f, 0.0f, "walk");

    // BOTTOM CENTER STORES
    graph.addEdge(245, 320, 40.0f, 0.0f, "walk");
    graph.addEdge(246, 320, 40.0f, 0.0f, "walk");
    graph.addEdge(247, 320, 40.0f, 0.0f, "walk");
    graph.addEdge(248, 321, 40.0f, 0.0f, "walk");
    graph.addEdge(249, 321, 40.0f, 0.0f, "walk");

    // BOTTOM CENTER-RIGHT STORES
    graph.addEdge(250, 322, 35.0f, 0.0f, "walk");
    graph.addEdge(251, 322, 35.0f, 0.0f, "walk");
    graph.addEdge(252, 322, 35.0f, 0.0f, "walk");
    graph.addEdge(253, 323, 35.0f, 0.0f, "walk");

    // ==================== EMERGENCY EXIT CONNECTIONS (8 EXITS) ====================
    graph.addEdge(254, 301, 95.0f, 0.0f, "walk");
    graph.addEdge(255, 302, 95.0f, 0.0f, "walk");
    graph.addEdge(256, 302, 40.0f, 0.0f, "walk");
    graph.addEdge(257, 304, 40.0f, 0.0f, "walk");
    graph.addEdge(258, 306, 40.0f, 0.0f, "walk");
    graph.addEdge(259, 307, 40.0f, 0.0f, "walk");
    graph.addEdge(260, 308, 40.0f, 0.0f, "walk");
    graph.addEdge(261, 321, 70.0f, 0.0f, "walk");

    // ==================== STAIRS/ELEVATOR CONNECTIONS ====================
    graph.addEdge(262, 317, 50.0f, 0.0f, "walk");
    graph.addEdge(263, 320, 50.0f, 0.0f, "walk");
    graph.addEdge(264, 323, 40.0f, 0.0f, "walk");
    graph.addEdge(265, 324, 40.0f, 0.0f, "walk");
    graph.addEdge(266, 301, 95.0f, 0.0f, "walk");
    graph.addEdge(267, 302, 95.0f, 0.0f, "walk");
    graph.addEdge(268, 308, 40.0f, 0.0f, "walk");
    graph.addEdge(269, 308, 40.0f, 0.0f, "walk");

    // ==================== ATRIUM CONNECTIONS ====================
    graph.addEdge(270, 306, 35.0f, 0.0f, "walk");
    graph.addEdge(271, 314, 30.0f, 0.0f, "walk");
    graph.addEdge(272, 322, 55.0f, 0.0f, "walk");

    return graph;
}