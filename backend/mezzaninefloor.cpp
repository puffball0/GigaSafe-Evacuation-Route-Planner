// ==================== IMPLEMENTATION FILE (mezzaninefloor.cpp) ====================

#include "mezzaninefloor.h"

Graph MezzanineFloor::buildMezzanineFloorGraph() {
    Graph graph;

    // ==================== MEZZANINE FLOOR - ACCURATE MAPPING ====================
    // Image dimensions reference: 1600x600 (matching first floor scale)
    
    // ==================== TOP LEFT SECTION - STORES & FACILITIES ====================
    
    // Top left corner - Small stores/facilities
    graph.addNode({401, "Small Store 1", "shop", 160, 100, 2, false, false});
    graph.addNode({402, "Small Store 2", "shop", 220, 100, 2, false, false});
    graph.addNode({403, "Restroom/Facility 1", "facility", 280, 85, 2, false, false});
    graph.addNode({404, "Restroom/Facility 2", "facility", 320, 85, 2, false, false});
    
    // Left side stores (vertical arrangement)
    graph.addNode({405, "GADGETS", "shop", 585, 155, 2, false, false});
    graph.addNode({406, "Small Steps", "shop", 635, 155, 2, false, false});
    
    // Left center stores
    graph.addNode({407, "Junaid Etc", "shop", 440, 240, 2, false, false});
    graph.addNode({408, "Sana Sana", "shop", 485, 270, 2, false, false});
    
    // ==================== TOP RIGHT SECTION - SALES OFFICE & FACILITIES ====================
    
    graph.addNode({409, "SALES OFFICE", "shop", 735, 110, 2, false, false});
    graph.addNode({410, "Bankoalfalah", "shop", 665, 330, 2, false, false});
    graph.addNode({411, "Cash Point", "shop", 665, 365, 2, false, false});
    
    // Right side facilities
    graph.addNode({412, "SALES OFFICE Right", "shop", 740, 315, 2, false, false});
    
    // ==================== CENTER SECTION - GOLDCREST VIEWS ====================
    
    // Large central promotional area (Goldcrest Views DHA Islamabad)
    graph.addNode({413, "GOLDCREST VIEWS Center", "atrium", 880, 260, 2, false, false});
    
    // ==================== BOTTOM SECTION - STORES ====================
    
    graph.addNode({414, "Olive Tree Cafe", "shop", 445, 390, 2, false, false});
    graph.addNode({415, "Sana Sana 2", "shop", 495, 415, 2, false, false});
    
    graph.addNode({416, "EASTERN ART & HANDICRAFTS", "shop", 575, 370, 2, false, false});
    
    // ==================== EMERGENCY EXITS - EXACTLY 3 ====================
    // Top left exit
    graph.addNode({417, "Emergency Exit 1", "exit", 210, 50, 2, true, false});
    
    // Top right exit
    graph.addNode({418, "Emergency Exit 2", "exit", 735, 50, 2, true, false});
    
    // Bottom center exit
    graph.addNode({419, "Emergency Exit 3", "exit", 650, 450, 2, true, false});
    
    // ==================== STAIRS/ELEVATORS ====================
    // Matching first floor stair positions for vertical connectivity
    
    graph.addNode({420, "Stairs/Elevator Bottom Left", "stairs", 230, 485, 2, false, false});
    graph.addNode({421, "Stairs/Elevator Bottom Center", "stairs", 640, 485, 2, false, false});
    graph.addNode({422, "Stairs/Elevator Bottom Right 1", "stairs", 1015, 485, 2, false, false});
    graph.addNode({423, "Stairs/Elevator Bottom Right 2", "stairs", 1115, 485, 2, false, false});
    
    graph.addNode({424, "Stairs/Elevator Top Left", "stairs", 210, 50, 2, false, false});
    graph.addNode({425, "Stairs/Elevator Top Right", "stairs", 735, 50, 2, false, false});
    
    // ==================== CORRIDOR JUNCTION NODES ====================
    
    // TOP HORIZONTAL CORRIDOR (Main upper walkway)
    graph.addNode({500, "Top Corridor M1", "corridor", 190, 130, 2, false, false});
    graph.addNode({501, "Top Corridor M2", "corridor", 300, 130, 2, false, false});
    graph.addNode({502, "Top Corridor M3", "corridor", 420, 130, 2, false, false});
    graph.addNode({503, "Top Corridor M4", "corridor", 560, 130, 2, false, false});
    graph.addNode({504, "Top Corridor M5", "corridor", 665, 130, 2, false, false});
    graph.addNode({505, "Top Corridor M6", "corridor", 770, 150, 2, false, false});
    
    // LEFT VERTICAL CORRIDOR (Along left side)
    graph.addNode({506, "Left Vertical M1", "corridor", 380, 200, 2, false, false});
    graph.addNode({507, "Left Vertical M2", "corridor", 380, 280, 2, false, false});
    graph.addNode({508, "Left Vertical M3", "corridor", 380, 360, 2, false, false});
    graph.addNode({509, "Left Vertical M4", "corridor", 380, 440, 2, false, false});
    
    // CENTER CORRIDOR (Around Goldcrest Views)
    graph.addNode({510, "Center Corridor M1", "corridor", 770, 240, 2, false, false});
    graph.addNode({511, "Center Corridor M2", "corridor", 770, 330, 2, false, false});
    graph.addNode({512, "Center Corridor M3", "corridor", 770, 420, 2, false, false});
    
    // RIGHT SIDE CORRIDOR
    graph.addNode({513, "Right Corridor M1", "corridor", 1000, 260, 2, false, false});
    graph.addNode({514, "Right Corridor M2", "corridor", 1000, 380, 2, false, false});
    
    // BOTTOM HORIZONTAL CORRIDOR
    graph.addNode({515, "Bottom Corridor M1", "corridor", 280, 460, 2, false, false});
    graph.addNode({516, "Bottom Corridor M2", "corridor", 460, 460, 2, false, false});
    graph.addNode({517, "Bottom Corridor M3", "corridor", 580, 460, 2, false, false});
    graph.addNode({518, "Bottom Corridor M4", "corridor", 700, 460, 2, false, false});
    graph.addNode({519, "Bottom Corridor M5", "corridor", 880, 460, 2, false, false});
    graph.addNode({520, "Bottom Corridor M6", "corridor", 1015, 460, 2, false, false});
    
    // ==================== CORRIDOR NETWORK EDGES ====================
    
    // TOP HORIZONTAL CORRIDOR PATH
    graph.addEdge(500, 501, 110.0f, 0.0f, "walk");
    graph.addEdge(501, 502, 120.0f, 0.0f, "walk");
    graph.addEdge(502, 503, 140.0f, 0.0f, "walk");
    graph.addEdge(503, 504, 105.0f, 0.0f, "walk");
    graph.addEdge(504, 505, 110.0f, 0.0f, "walk");
    
    // LEFT VERTICAL CORRIDOR PATH
    graph.addEdge(506, 507, 80.0f, 0.0f, "walk");
    graph.addEdge(507, 508, 80.0f, 0.0f, "walk");
    graph.addEdge(508, 509, 80.0f, 0.0f, "walk");
    
    // CENTER VERTICAL CORRIDOR PATH
    graph.addEdge(510, 511, 90.0f, 0.0f, "walk");
    graph.addEdge(511, 512, 90.0f, 0.0f, "walk");
    
    // RIGHT VERTICAL CORRIDOR PATH
    graph.addEdge(513, 514, 120.0f, 0.0f, "walk");
    
    // BOTTOM HORIZONTAL CORRIDOR PATH
    graph.addEdge(515, 516, 180.0f, 0.0f, "walk");
    graph.addEdge(516, 517, 120.0f, 0.0f, "walk");
    graph.addEdge(517, 518, 120.0f, 0.0f, "walk");
    graph.addEdge(518, 519, 180.0f, 0.0f, "walk");
    graph.addEdge(519, 520, 135.0f, 0.0f, "walk");
    
    // CONNECTING VERTICAL AND HORIZONTAL CORRIDORS
    graph.addEdge(500, 506, 70.0f, 0.0f, "walk");
    graph.addEdge(502, 506, 70.0f, 0.0f, "walk");
    graph.addEdge(506, 507, 80.0f, 0.0f, "walk");
    graph.addEdge(507, 508, 80.0f, 0.0f, "walk");
    graph.addEdge(508, 509, 80.0f, 0.0f, "walk");
    graph.addEdge(509, 516, 85.0f, 0.0f, "walk");
    
    graph.addEdge(504, 510, 110.0f, 0.0f, "walk");
    graph.addEdge(505, 510, 90.0f, 0.0f, "walk");
    graph.addEdge(510, 511, 90.0f, 0.0f, "walk");
    graph.addEdge(511, 512, 90.0f, 0.0f, "walk");
    graph.addEdge(512, 518, 70.0f, 0.0f, "walk");
    
    graph.addEdge(505, 513, 230.0f, 0.0f, "walk");
    graph.addEdge(513, 514, 120.0f, 0.0f, "walk");
    graph.addEdge(514, 519, 120.0f, 0.0f, "walk");
    
    // ==================== STORE CONNECTIONS TO CORRIDORS ====================
    
    // Top left stores
    graph.addEdge(401, 500, 40.0f, 0.0f, "walk");
    graph.addEdge(402, 501, 35.0f, 0.0f, "walk");
    graph.addEdge(403, 501, 50.0f, 0.0f, "walk");
    graph.addEdge(404, 501, 50.0f, 0.0f, "walk");
    
    // Left side stores
    graph.addEdge(405, 503, 30.0f, 0.0f, "walk");
    graph.addEdge(406, 503, 30.0f, 0.0f, "walk");
    
    // Left center stores
    graph.addEdge(407, 506, 60.0f, 0.0f, "walk");
    graph.addEdge(408, 507, 105.0f, 0.0f, "walk");
    
    // Top right stores
    graph.addEdge(409, 504, 25.0f, 0.0f, "walk");
    graph.addEdge(410, 511, 105.0f, 0.0f, "walk");
    graph.addEdge(411, 511, 95.0f, 0.0f, "walk");
    graph.addEdge(412, 511, 35.0f, 0.0f, "walk");
    
    // Central Goldcrest Views
    graph.addEdge(413, 513, 120.0f, 0.0f, "walk");
    
    // Bottom stores
    graph.addEdge(414, 508, 65.0f, 0.0f, "walk");
    graph.addEdge(415, 516, 50.0f, 0.0f, "walk");
    graph.addEdge(416, 517, 95.0f, 0.0f, "walk");
    
    // ==================== EMERGENCY EXIT CONNECTIONS ====================
    
    graph.addEdge(417, 500, 80.0f, 0.0f, "walk");
    graph.addEdge(418, 505, 100.0f, 0.0f, "walk");
    graph.addEdge(419, 517, 20.0f, 0.0f, "walk");
    
    // ==================== STAIRS/ELEVATOR CONNECTIONS ====================
    
    graph.addEdge(420, 515, 35.0f, 0.0f, "walk");
    graph.addEdge(421, 517, 35.0f, 0.0f, "walk");
    graph.addEdge(422, 520, 35.0f, 0.0f, "walk");
    graph.addEdge(423, 520, 100.0f, 0.0f, "walk");
    
    graph.addEdge(424, 500, 80.0f, 0.0f, "walk");
    graph.addEdge(425, 505, 100.0f, 0.0f, "walk");

    return graph;
}