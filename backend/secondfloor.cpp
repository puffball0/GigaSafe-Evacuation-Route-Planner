#include "secondfloor.h"

Graph SecondFloor::buildSecondFloorGraph() {
    Graph graph;

    // ==================== SECOND FLOOR - ACCURATE MAPPING ====================
    // Image dimensions reference: 1600x600 (approximate from the floor plan)

    // LEFT SECTION - TOP ROW
    graph.addNode({401, "KFC", "shop", 90, 158, 2, false, false});
    graph.addNode({402, "PIZZA N PASTA", "shop", 90, 247, 2, false, false});
    graph.addNode({403, "PAPPASALLIS", "shop", 90, 267, 2, false, false});
    graph.addNode({404, "SIMPLY SUFI EXPRESS", "shop", 90, 298, 2, false, false});
    graph.addNode({405, "HOWDY", "shop", 90, 319, 2, false, false});
    graph.addNode({406, "CHEEZIOUS", "shop", 90, 348, 2, false, false});
    graph.addNode({407, "ALI BABA", "shop", 90, 380, 2, false, false});

    // LEFT SECTION - STORES NEAR TOP
    graph.addNode({408, "BONANZA", "shop", 175, 158, 2, false, false});
    graph.addNode({409, "ECCO", "shop", 208, 158, 2, false, false});

    // LEFT CENTER SECTION
    graph.addNode({410, "SPLASH", "shop", 258, 188, 2, false, false});
    graph.addNode({411, "CROSSROADS", "shop", 295, 188, 2, false, false});
    graph.addNode({412, "COTTON & COTTON", "shop", 245, 255, 2, false, false});
    graph.addNode({413, "ENGLISH TO URDU DICTIONARY", "shop", 290, 245, 2, false, false});

    // ATRIUM LEFT
    graph.addNode({414, "ATRIUM Left", "atrium", 350, 280, 2, false, false});

    // CENTER-LEFT STORES
    graph.addNode({415, "MINISO", "shop", 420, 235, 2, false, false});
    graph.addNode({416, "SAVERS", "shop", 365, 325, 2, false, false});
    graph.addNode({417, "METRO", "shop", 318, 395, 2, false, false});
    graph.addNode({418, "HYPERSTAR", "shop", 318, 415, 2, false, false});

    // BOTTOM LEFT SECTION
    graph.addNode({419, "LEISURE CLUB", "shop", 223, 400, 2, false, false});
    graph.addNode({420, "DOLLAR STORE", "shop", 467, 400, 2, false, false});

    // CENTER SECTION - FUN CITY & TOYLAND
    graph.addNode({421, "FUN CITY", "shop", 697, 310, 2, false, false});
    graph.addNode({422, "TOYLAND", "shop", 527, 405, 2, false, false});

    // CENTER-RIGHT SECTION - TOP STORES
    graph.addNode({423, "FANKARE", "shop", 835, 148, 2, false, false});
    graph.addNode({424, "ROYAL ENFIELD", "shop", 888, 148, 2, false, false});
    graph.addNode({425, "ROYLE TAG", "shop", 920, 148, 2, false, false});

    // CENTER-RIGHT SECTION - MIDDLE STORES
    graph.addNode({426, "READER'S PLANET", "shop", 935, 245, 2, false, false});
    graph.addNode({427, "XIOMI", "shop", 975, 245, 2, false, false});
    graph.addNode({428, "SAMSUNG", "shop", 1008, 245, 2, false, false});
    graph.addNode({429, "VIVO", "shop", 1035, 245, 2, false, false});

    // ATRIUM RIGHT
    graph.addNode({430, "ATRIUM Right", "atrium", 1010, 310, 2, false, false});

    // CENTER-RIGHT BOTTOM STORES
    graph.addNode({431, "OPPO", "shop", 940, 347, 2, false, false});
    graph.addNode({432, "CARDINALI", "shop", 975, 347, 2, false, false});
    graph.addNode({433, "GILAS MADD", "shop", 1010, 347, 2, false, false});
    graph.addNode({434, "MAS", "shop", 1050, 347, 2, false, false});

    // BOTTOM CENTER SECTION
    graph.addNode({435, "PEAK LAKE", "shop", 843, 408, 2, false, false});
    graph.addNode({436, "LITTLE LONDON", "shop", 900, 408, 2, false, false});

    // RIGHT SECTION - TOP
    graph.addNode({437, "BLUE LOTUS", "shop", 1075, 163, 2, false, false});
    graph.addNode({438, "FULL CIRCLE", "shop", 1115, 163, 2, false, false});
    graph.addNode({439, "MEHRAN", "shop", 1155, 163, 2, false, false});

    // RIGHT SECTION - CINEPAX AREA
    graph.addNode({440, "CINEPAX", "shop", 1240, 250, 2, false, false});
    graph.addNode({441, "MODEL APARTMENT SALES OFFICE", "shop", 1240, 350, 2, false, false});

    // BOTTOM RIGHT SECTION
    graph.addNode({442, "BOOK CORNER", "shop", 960, 415, 2, false, false});
    graph.addNode({443, "DEBUGITO", "shop", 1008, 415, 2, false, false});

    // EMERGENCY EXITS - EXACTLY 9 (Green rectangles with stick figure)
    // Top row exits
    graph.addNode({444, "Emergency Exit 1", "exit", 225, 120, 2, true, false});
    graph.addNode({445, "Emergency Exit 2", "exit", 295, 120, 2, true, false});
    graph.addNode({446, "Emergency Exit 3", "exit", 447, 120, 2, true, false});
    graph.addNode({447, "Emergency Exit 4", "exit", 630, 120, 2, true, false});
    graph.addNode({448, "Emergency Exit 5", "exit", 835, 120, 2, true, false});
    graph.addNode({449, "Emergency Exit 6", "exit", 1010, 120, 2, true, false});
    graph.addNode({450, "Emergency Exit 7", "exit", 1300, 120, 2, true, false});
    
    // Bottom exits
    graph.addNode({451, "Emergency Exit 8", "exit", 340, 480, 2, true, false});
    graph.addNode({452, "Emergency Exit 9", "exit", 655, 480, 2, true, false});

    // STAIRS/ELEVATORS (Purple/Pink/Yellow icons)
    graph.addNode({453, "Stairs/Elevator 1", "stairs", 145, 117, 2, false, false});
    graph.addNode({454, "Stairs/Elevator 2", "stairs", 340, 117, 2, false, false});
    graph.addNode({455, "Stairs/Elevator 3", "stairs", 655, 117, 2, false, false});
    graph.addNode({456, "Stairs/Elevator 4", "stairs", 1010, 117, 2, false, false});
    graph.addNode({457, "Stairs/Elevator 5", "stairs", 1068, 117, 2, false, false});
    graph.addNode({458, "Stairs/Elevator 6", "stairs", 340, 480, 2, false, false});
    graph.addNode({459, "Stairs/Elevator 7", "stairs", 655, 480, 2, false, false});
    graph.addNode({460, "Stairs/Elevator 8", "stairs", 1020, 480, 2, false, false});

    // ==================== CORRIDOR JUNCTION NODES ====================

    // TOP HORIZONTAL CORRIDOR
    graph.addNode({500, "Top Corridor J1", "corridor", 145, 188, 2, false, false});
    graph.addNode({501, "Top Corridor J2", "corridor", 240, 188, 2, false, false});
    graph.addNode({502, "Top Corridor J3", "corridor", 330, 195, 2, false, false});
    graph.addNode({503, "Top Corridor J4", "corridor", 470, 205, 2, false, false});
    graph.addNode({504, "Top Corridor J5", "corridor", 590, 205, 2, false, false});
    graph.addNode({505, "Top Corridor J6", "corridor", 730, 205, 2, false, false});
    graph.addNode({506, "Top Corridor J7", "corridor", 870, 195, 2, false, false});
    graph.addNode({507, "Top Corridor J8", "corridor", 1010, 195, 2, false, false});
    graph.addNode({508, "Top Corridor J9", "corridor", 1120, 195, 2, false, false});
    graph.addNode({509, "Top Corridor J10", "corridor", 1240, 210, 2, false, false});

    // MIDDLE HORIZONTAL CORRIDOR
    graph.addNode({510, "Middle Corridor J1", "corridor", 145, 280, 2, false, false});
    graph.addNode({511, "Middle Corridor J2", "corridor", 270, 275, 2, false, false});
    graph.addNode({512, "Middle Corridor J3", "corridor", 390, 290, 2, false, false});
    graph.addNode({513, "Middle Corridor J4", "corridor", 590, 310, 2, false, false});
    graph.addNode({514, "Middle Corridor J5", "corridor", 800, 310, 2, false, false});
    graph.addNode({515, "Middle Corridor J6", "corridor", 1010, 290, 2, false, false});
    graph.addNode({516, "Middle Corridor J7", "corridor", 1155, 300, 2, false, false});

    // BOTTOM HORIZONTAL CORRIDOR
    graph.addNode({517, "Bottom Corridor J1", "corridor", 145, 375, 2, false, false});
    graph.addNode({518, "Bottom Corridor J2", "corridor", 270, 385, 2, false, false});
    graph.addNode({519, "Bottom Corridor J3", "corridor", 390, 385, 2, false, false});
    graph.addNode({520, "Bottom Corridor J4", "corridor", 500, 385, 2, false, false});
    graph.addNode({521, "Bottom Corridor J5", "corridor", 655, 385, 2, false, false});
    graph.addNode({522, "Bottom Corridor J6", "corridor", 825, 385, 2, false, false});
    graph.addNode({523, "Bottom Corridor J7", "corridor", 980, 395, 2, false, false});
    graph.addNode({524, "Bottom Corridor J8", "corridor", 1080, 395, 2, false, false});

    // VERTICAL CONNECTORS
    graph.addNode({525, "Vertical Connector 1", "corridor", 145, 230, 2, false, false});
    graph.addNode({526, "Vertical Connector 2", "corridor", 270, 230, 2, false, false});
    graph.addNode({527, "Vertical Connector 3", "corridor", 390, 340, 2, false, false});
    graph.addNode({528, "Vertical Connector 4", "corridor", 800, 260, 2, false, false});

    // ==================== CORRIDOR NETWORK EDGES ====================

    // TOP HORIZONTAL CORRIDOR PATH
    graph.addEdge(500, 501, 95.0f, 0.0f, "walk");
    graph.addEdge(501, 502, 90.0f, 0.0f, "walk");
    graph.addEdge(502, 503, 140.0f, 0.0f, "walk");
    graph.addEdge(503, 504, 120.0f, 0.0f, "walk");
    graph.addEdge(504, 505, 140.0f, 0.0f, "walk");
    graph.addEdge(505, 506, 140.0f, 0.0f, "walk");
    graph.addEdge(506, 507, 140.0f, 0.0f, "walk");
    graph.addEdge(507, 508, 110.0f, 0.0f, "walk");
    graph.addEdge(508, 509, 120.0f, 0.0f, "walk");

    // MIDDLE HORIZONTAL CORRIDOR PATH
    graph.addEdge(510, 511, 125.0f, 0.0f, "walk");
    graph.addEdge(511, 512, 120.0f, 0.0f, "walk");
    graph.addEdge(512, 513, 200.0f, 0.0f, "walk");
    graph.addEdge(513, 514, 210.0f, 0.0f, "walk");
    graph.addEdge(514, 515, 210.0f, 0.0f, "walk");
    graph.addEdge(515, 516, 145.0f, 0.0f, "walk");

    // BOTTOM HORIZONTAL CORRIDOR PATH
    graph.addEdge(517, 518, 125.0f, 0.0f, "walk");
    graph.addEdge(518, 519, 120.0f, 0.0f, "walk");
    graph.addEdge(519, 520, 110.0f, 0.0f, "walk");
    graph.addEdge(520, 521, 155.0f, 0.0f, "walk");
    graph.addEdge(521, 522, 170.0f, 0.0f, "walk");
    graph.addEdge(522, 523, 155.0f, 0.0f, "walk");
    graph.addEdge(523, 524, 100.0f, 0.0f, "walk");

    // VERTICAL CONNECTIONS
    graph.addEdge(500, 525, 42.0f, 0.0f, "walk");
    graph.addEdge(525, 510, 50.0f, 0.0f, "walk");
    graph.addEdge(510, 517, 95.0f, 0.0f, "walk");
    
    graph.addEdge(501, 526, 42.0f, 0.0f, "walk");
    graph.addEdge(526, 511, 45.0f, 0.0f, "walk");
    graph.addEdge(511, 518, 110.0f, 0.0f, "walk");
    
    graph.addEdge(502, 512, 95.0f, 0.0f, "walk");
    graph.addEdge(512, 527, 50.0f, 0.0f, "walk");
    graph.addEdge(527, 519, 45.0f, 0.0f, "walk");
    
    graph.addEdge(503, 512, 85.0f, 0.0f, "walk");
    graph.addEdge(512, 520, 95.0f, 0.0f, "walk");
    
    graph.addEdge(504, 513, 105.0f, 0.0f, "walk");
    graph.addEdge(513, 521, 75.0f, 0.0f, "walk");
    
    graph.addEdge(505, 514, 105.0f, 0.0f, "walk");
    graph.addEdge(514, 522, 75.0f, 0.0f, "walk");
    
    graph.addEdge(506, 528, 65.0f, 0.0f, "walk");
    graph.addEdge(528, 514, 50.0f, 0.0f, "walk");
    graph.addEdge(514, 522, 75.0f, 0.0f, "walk");
    
    graph.addEdge(507, 515, 95.0f, 0.0f, "walk");
    graph.addEdge(515, 523, 105.0f, 0.0f, "walk");
    
    graph.addEdge(508, 516, 105.0f, 0.0f, "walk");
    graph.addEdge(516, 524, 95.0f, 0.0f, "walk");

    // ==================== STORE CONNECTIONS TO CORRIDORS ====================

    // LEFT SECTION STORES
    graph.addEdge(401, 500, 55.0f, 0.0f, "walk");
    graph.addEdge(402, 525, 55.0f, 0.0f, "walk");
    graph.addEdge(403, 525, 55.0f, 0.0f, "walk");
    graph.addEdge(404, 510, 55.0f, 0.0f, "walk");
    graph.addEdge(405, 510, 55.0f, 0.0f, "walk");
    graph.addEdge(406, 510, 55.0f, 0.0f, "walk");
    graph.addEdge(407, 517, 55.0f, 0.0f, "walk");

    graph.addEdge(408, 500, 30.0f, 0.0f, "walk");
    graph.addEdge(409, 500, 30.0f, 0.0f, "walk");

    // LEFT CENTER STORES
    graph.addEdge(410, 501, 30.0f, 0.0f, "walk");
    graph.addEdge(411, 501, 30.0f, 0.0f, "walk");
    graph.addEdge(412, 511, 30.0f, 0.0f, "walk");
    graph.addEdge(413, 511, 30.0f, 0.0f, "walk");

    // ATRIUM
    graph.addEdge(414, 512, 40.0f, 0.0f, "walk");

    // CENTER-LEFT STORES
    graph.addEdge(415, 503, 40.0f, 0.0f, "walk");
    graph.addEdge(416, 512, 35.0f, 0.0f, "walk");
    graph.addEdge(417, 519, 40.0f, 0.0f, "walk");
    graph.addEdge(418, 519, 40.0f, 0.0f, "walk");

    // BOTTOM LEFT
    graph.addEdge(419, 518, 40.0f, 0.0f, "walk");
    graph.addEdge(420, 520, 40.0f, 0.0f, "walk");

    // CENTER
    graph.addEdge(421, 513, 50.0f, 0.0f, "walk");
    graph.addEdge(422, 520, 40.0f, 0.0f, "walk");

    // CENTER-RIGHT TOP STORES
    graph.addEdge(423, 506, 50.0f, 0.0f, "walk");
    graph.addEdge(424, 506, 45.0f, 0.0f, "walk");
    graph.addEdge(425, 506, 45.0f, 0.0f, "walk");

    // CENTER-RIGHT MIDDLE STORES
    graph.addEdge(426, 515, 50.0f, 0.0f, "walk");
    graph.addEdge(427, 515, 40.0f, 0.0f, "walk");
    graph.addEdge(428, 515, 40.0f, 0.0f, "walk");
    graph.addEdge(429, 515, 40.0f, 0.0f, "walk");

    // ATRIUM RIGHT
    graph.addEdge(430, 515, 40.0f, 0.0f, "walk");

    // CENTER-RIGHT BOTTOM STORES
    graph.addEdge(431, 515, 60.0f, 0.0f, "walk");
    graph.addEdge(432, 515, 60.0f, 0.0f, "walk");
    graph.addEdge(433, 515, 60.0f, 0.0f, "walk");
    graph.addEdge(434, 523, 50.0f, 0.0f, "walk");

    // BOTTOM CENTER
    graph.addEdge(435, 522, 35.0f, 0.0f, "walk");
    graph.addEdge(436, 522, 35.0f, 0.0f, "walk");

    // RIGHT SECTION TOP
    graph.addEdge(437, 508, 40.0f, 0.0f, "walk");
    graph.addEdge(438, 508, 40.0f, 0.0f, "walk");
    graph.addEdge(439, 508, 40.0f, 0.0f, "walk");

    // RIGHT SECTION - CINEPAX & MODEL APARTMENT
    graph.addEdge(440, 509, 50.0f, 0.0f, "walk");
    graph.addEdge(441, 516, 60.0f, 0.0f, "walk");

    // BOTTOM RIGHT
    graph.addEdge(442, 523, 35.0f, 0.0f, "walk");
    graph.addEdge(443, 523, 35.0f, 0.0f, "walk");

    // ==================== EMERGENCY EXIT CONNECTIONS ====================
    graph.addEdge(444, 501, 30.0f, 0.0f, "walk");
    graph.addEdge(445, 502, 30.0f, 0.0f, "walk");
    graph.addEdge(446, 503, 30.0f, 0.0f, "walk");
    graph.addEdge(447, 504, 30.0f, 0.0f, "walk");
    graph.addEdge(448, 506, 30.0f, 0.0f, "walk");
    graph.addEdge(449, 507, 30.0f, 0.0f, "walk");
    graph.addEdge(450, 509, 30.0f, 0.0f, "walk");
    
    graph.addEdge(451, 519, 95.0f, 0.0f, "walk");
    graph.addEdge(452, 521, 95.0f, 0.0f, "walk");

    // ==================== STAIRS/ELEVATOR CONNECTIONS ====================
    graph.addEdge(453, 500, 71.0f, 0.0f, "walk");
    graph.addEdge(454, 502, 78.0f, 0.0f, "walk");
    graph.addEdge(455, 504, 88.0f, 0.0f, "walk");
    graph.addEdge(456, 507, 78.0f, 0.0f, "walk");
    graph.addEdge(457, 507, 58.0f, 0.0f, "walk");
    graph.addEdge(458, 519, 95.0f, 0.0f, "walk");
    graph.addEdge(459, 521, 95.0f, 0.0f, "walk");
    graph.addEdge(460, 523, 85.0f, 0.0f, "walk");

    return graph;
}