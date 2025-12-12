#include "floor2a.h"

Graph Floor2A::buildFloor2AGraph() {
    Graph graph;

    // ==================== 2A FLOOR - ACCURATE MAPPING ====================
    // Image dimensions reference: 1600x600
    // This floor has a curved right side and is larger/different from ground floor
    
    // ==================== TOP LEFT SECTION - FACILITIES & STORES ====================
    
    // Top left corner facilities
    graph.addNode({601, "Washroom Left", "facility", 180, 125, 3, false, false});
    
    // Left side stores
    graph.addNode({602, "CAT SALON", "shop", 185, 210, 3, false, false});
    graph.addNode({603, "AL HALAL BROAST ADANA", "shop", 185, 265, 3, false, false});
    graph.addNode({604, "ARIAN FLORIDA", "shop", 185, 335, 3, false, false});
    graph.addNode({605, "KUNDI COFFEE", "shop", 185, 395, 3, false, false});
    
    // ==================== TOP ROW - SMALL STORES ====================
    
    // Top row left section (small stores)
    graph.addNode({606, "Store T1", "shop", 320, 155, 3, false, false});
    graph.addNode({607, "Store T2", "shop", 355, 155, 3, false, false});
    graph.addNode({608, "Store T3", "shop", 390, 155, 3, false, false});
    graph.addNode({609, "Store T4", "shop", 425, 155, 3, false, false});
    graph.addNode({610, "Store T5", "shop", 460, 155, 3, false, false});
    graph.addNode({611, "Store T6", "shop", 495, 155, 3, false, false});
    
    // Top row center section
    graph.addNode({612, "Store T7", "shop", 570, 155, 3, false, false});
    graph.addNode({613, "Store T8", "shop", 605, 155, 3, false, false});
    graph.addNode({614, "Store T9", "shop", 640, 155, 3, false, false});
    graph.addNode({615, "Store T10", "shop", 675, 155, 3, false, false});
    graph.addNode({616, "Store T11", "shop", 710, 155, 3, false, false});
    graph.addNode({617, "Store T12", "shop", 745, 155, 3, false, false});
    graph.addNode({618, "Store T13", "shop", 780, 155, 3, false, false});
    
    // Top row right section
    graph.addNode({619, "Store T14", "shop", 900, 155, 3, false, false});
    graph.addNode({620, "Store T15", "shop", 935, 155, 3, false, false});
    graph.addNode({621, "Store T16", "shop", 970, 155, 3, false, false});
    graph.addNode({622, "Store T17", "shop", 1005, 155, 3, false, false});
    graph.addNode({623, "Store T18", "shop", 1040, 155, 3, false, false});
    graph.addNode({624, "Store T19", "shop", 1075, 155, 3, false, false});
    
    // ==================== SECOND ROW - STORES ====================
    
    // Second row left section
    graph.addNode({625, "Store S1", "shop", 300, 225, 3, false, false});
    graph.addNode({626, "Store S2", "shop", 332, 225, 3, false, false});
    graph.addNode({627, "Store S3", "shop", 364, 225, 3, false, false});
    graph.addNode({628, "Store S4", "shop", 396, 225, 3, false, false});
    graph.addNode({629, "Store S5", "shop", 428, 225, 3, false, false});
    graph.addNode({630, "Store S6", "shop", 460, 225, 3, false, false});
    
    // Second row center section
    graph.addNode({631, "Store S7", "shop", 570, 225, 3, false, false});
    graph.addNode({632, "Store S8", "shop", 602, 225, 3, false, false});
    graph.addNode({633, "Store S9", "shop", 634, 225, 3, false, false});
    graph.addNode({634, "Store S10", "shop", 666, 225, 3, false, false});
    graph.addNode({635, "Store S11", "shop", 698, 225, 3, false, false});
    graph.addNode({636, "Store S12", "shop", 730, 225, 3, false, false});
    graph.addNode({637, "Store S13", "shop", 762, 225, 3, false, false});
    graph.addNode({638, "Store S14", "shop", 794, 225, 3, false, false});
    
    // Second row right section
    graph.addNode({639, "Store S15", "shop", 875, 225, 3, false, false});
    graph.addNode({640, "Store S16", "shop", 907, 225, 3, false, false});
    graph.addNode({641, "Store S17", "shop", 939, 225, 3, false, false});
    graph.addNode({642, "Store S18", "shop", 971, 225, 3, false, false});
    graph.addNode({643, "Store S19", "shop", 1003, 225, 3, false, false});
    graph.addNode({644, "Store S20", "shop", 1035, 225, 3, false, false});
    
    // ==================== CENTER SECTION - FOOD COURT & SEATING ====================
    
    graph.addNode({645, "SMALL BNDERIES", "shop", 340, 300, 3, false, false});
    graph.addNode({646, "KOPPA", "shop", 455, 310, 3, false, false});
    graph.addNode({647, "FOOD COURT Seating Area", "seating", 670, 300, 3, false, false});
    graph.addNode({648, "TOKYO", "shop", 540, 355, 3, false, false});
    
    // ==================== THIRD ROW - STORES ====================
    
    // Third row left section
    graph.addNode({649, "Store TH1", "shop", 300, 325, 3, false, false});
    graph.addNode({650, "Store TH2", "shop", 328, 325, 3, false, false});
    graph.addNode({651, "Store TH3", "shop", 356, 325, 3, false, false});
    graph.addNode({652, "Store TH4", "shop", 384, 325, 3, false, false});
    graph.addNode({653, "Store TH5", "shop", 412, 325, 3, false, false});
    graph.addNode({654, "Store TH6", "shop", 440, 325, 3, false, false});
    graph.addNode({655, "Store TH7", "shop", 468, 325, 3, false, false});
    
    // Third row center section
    graph.addNode({656, "Store TH8", "shop", 750, 325, 3, false, false});
    graph.addNode({657, "Store TH9", "shop", 778, 325, 3, false, false});
    graph.addNode({658, "Store TH10", "shop", 806, 325, 3, false, false});
    
    // Third row right section
    graph.addNode({659, "Store TH11", "shop", 875, 325, 3, false, false});
    graph.addNode({660, "Store TH12", "shop", 903, 325, 3, false, false});
    graph.addNode({661, "Store TH13", "shop", 931, 325, 3, false, false});
    graph.addNode({662, "Store TH14", "shop", 959, 325, 3, false, false});
    graph.addNode({663, "Store TH15", "shop", 987, 325, 3, false, false});
    graph.addNode({664, "Store TH16", "shop", 1015, 325, 3, false, false});
    graph.addNode({665, "Store TH17", "shop", 1043, 325, 3, false, false});
    
    // ==================== BOTTOM ROW - STORES ====================
    
    // Bottom row left section
    graph.addNode({666, "Store B1", "shop", 305, 405, 3, false, false});
    graph.addNode({667, "Store B2", "shop", 335, 405, 3, false, false});
    graph.addNode({668, "Store B3", "shop", 365, 405, 3, false, false});
    graph.addNode({669, "Store B4", "shop", 395, 405, 3, false, false});
    graph.addNode({670, "Store B5", "shop", 425, 405, 3, false, false});
    graph.addNode({671, "Store B6", "shop", 455, 405, 3, false, false});
    graph.addNode({672, "M USHIA", "shop", 495, 405, 3, false, false});
    
    // Bottom row center section
    graph.addNode({673, "Store B7", "shop", 545, 405, 3, false, false});
    graph.addNode({674, "Store B8", "shop", 575, 405, 3, false, false});
    graph.addNode({675, "Store B9", "shop", 605, 405, 3, false, false});
    graph.addNode({676, "Store B10", "shop", 635, 405, 3, false, false});
    graph.addNode({677, "Store B11", "shop", 665, 405, 3, false, false});
    graph.addNode({678, "Store B12", "shop", 695, 405, 3, false, false});
    graph.addNode({679, "Store B13", "shop", 725, 405, 3, false, false});
    graph.addNode({680, "Store B14", "shop", 755, 405, 3, false, false});
    graph.addNode({681, "Store B15", "shop", 785, 405, 3, false, false});
    graph.addNode({682, "Store B16", "shop", 815, 405, 3, false, false});
    
    // Bottom row right section
    graph.addNode({683, "Store B17", "shop", 880, 405, 3, false, false});
    graph.addNode({684, "Store B18", "shop", 910, 405, 3, false, false});
    graph.addNode({685, "Store B19", "shop", 940, 405, 3, false, false});
    graph.addNode({686, "Store B20", "shop", 970, 405, 3, false, false});
    graph.addNode({687, "Store B21", "shop", 1000, 405, 3, false, false});
    graph.addNode({688, "Store B22", "shop", 1030, 405, 3, false, false});
    
    // ==================== RIGHT SECTION - ROUND 3 BOWLING ALLEY ====================
    
    graph.addNode({689, "ROUND 3 BOWLING ALLEY", "entertainment", 1240, 280, 3, false, false});
    
    // ==================== EMERGENCY EXITS - 7 TOTAL (4 top + 3 bottom) ====================
    
    // TOP EXITS (4 exits)
    graph.addNode({690, "Emergency Exit 1", "exit", 255, 125, 3, true, false});
    graph.addNode({691, "Emergency Exit 2", "exit", 490, 125, 3, true, false});
    graph.addNode({692, "Emergency Exit 3", "exit", 680, 125, 3, true, false});
    graph.addNode({693, "Emergency Exit 4", "exit", 900, 125, 3, true, false});
    
    // BOTTOM EXITS (3 exits)
    graph.addNode({694, "Emergency Exit 5", "exit", 265, 445, 3, true, false});
    graph.addNode({695, "Emergency Exit 6", "exit", 730, 445, 3, true, false});
    graph.addNode({696, "Emergency Exit 7", "exit", 1065, 445, 3, true, false});
    
    // ==================== STAIRS/ELEVATORS ====================
    
    // Top stairs/elevators
    graph.addNode({697, "Stairs Top 1", "stairs", 255, 125, 3, false, false});
    graph.addNode({698, "Stairs Top 2", "stairs", 330, 125, 3, false, false});
    graph.addNode({699, "Stairs Top 3", "stairs", 680, 125, 3, false, false});
    graph.addNode({700, "Stairs Top 4", "stairs", 900, 125, 3, false, false});
    graph.addNode({701, "Stairs Top 5", "stairs", 970, 125, 3, false, false});
    
    // Bottom stairs/elevators
    graph.addNode({702, "Stairs Bottom 1", "stairs", 265, 445, 3, false, false});
    graph.addNode({703, "Stairs Bottom 2", "stairs", 680, 445, 3, false, false});
    graph.addNode({704, "Stairs Bottom 3", "stairs", 1065, 445, 3, false, false});
    graph.addNode({705, "Stairs Bottom 4", "stairs", 1110, 445, 3, false, false});
    
    // ==================== CORRIDOR JUNCTION NODES ====================
    
    // TOP HORIZONTAL CORRIDOR (Main upper walkway)
    graph.addNode({800, "Top Corridor 2A-1", "corridor", 260, 185, 3, false, false});
    graph.addNode({801, "Top Corridor 2A-2", "corridor", 355, 185, 3, false, false});
    graph.addNode({802, "Top Corridor 2A-3", "corridor", 460, 185, 3, false, false});
    graph.addNode({803, "Top Corridor 2A-4", "corridor", 535, 185, 3, false, false});
    graph.addNode({804, "Top Corridor 2A-5", "corridor", 640, 185, 3, false, false});
    graph.addNode({805, "Top Corridor 2A-6", "corridor", 745, 185, 3, false, false});
    graph.addNode({806, "Top Corridor 2A-7", "corridor", 835, 185, 3, false, false});
    graph.addNode({807, "Top Corridor 2A-8", "corridor", 935, 185, 3, false, false});
    graph.addNode({808, "Top Corridor 2A-9", "corridor", 1040, 185, 3, false, false});
    graph.addNode({809, "Top Corridor 2A-10", "corridor", 1130, 185, 3, false, false});
    
    // SECOND HORIZONTAL CORRIDOR
    graph.addNode({810, "Second Corridor 2A-1", "corridor", 260, 260, 3, false, false});
    graph.addNode({811, "Second Corridor 2A-2", "corridor", 365, 260, 3, false, false});
    graph.addNode({812, "Second Corridor 2A-3", "corridor", 460, 260, 3, false, false});
    graph.addNode({813, "Second Corridor 2A-4", "corridor", 535, 260, 3, false, false});
    graph.addNode({814, "Second Corridor 2A-5", "corridor", 640, 260, 3, false, false});
    graph.addNode({815, "Second Corridor 2A-6", "corridor", 745, 260, 3, false, false});
    graph.addNode({816, "Second Corridor 2A-7", "corridor", 835, 260, 3, false, false});
    graph.addNode({817, "Second Corridor 2A-8", "corridor", 940, 260, 3, false, false});
    graph.addNode({818, "Second Corridor 2A-9", "corridor", 1040, 260, 3, false, false});
    graph.addNode({819, "Second Corridor 2A-10", "corridor", 1130, 260, 3, false, false});
    
    // THIRD HORIZONTAL CORRIDOR
    graph.addNode({820, "Third Corridor 2A-1", "corridor", 260, 360, 3, false, false});
    graph.addNode({821, "Third Corridor 2A-2", "corridor", 365, 360, 3, false, false});
    graph.addNode({822, "Third Corridor 2A-3", "corridor", 460, 360, 3, false, false});
    graph.addNode({823, "Third Corridor 2A-4", "corridor", 540, 360, 3, false, false});
    graph.addNode({824, "Third Corridor 2A-5", "corridor", 640, 360, 3, false, false});
    graph.addNode({825, "Third Corridor 2A-6", "corridor", 745, 360, 3, false, false});
    graph.addNode({826, "Third Corridor 2A-7", "corridor", 835, 360, 3, false, false});
    graph.addNode({827, "Third Corridor 2A-8", "corridor", 940, 360, 3, false, false});
    graph.addNode({828, "Third Corridor 2A-9", "corridor", 1040, 360, 3, false, false});
    graph.addNode({829, "Third Corridor 2A-10", "corridor", 1130, 360, 3, false, false});
    
    // BOTTOM HORIZONTAL CORRIDOR
    graph.addNode({830, "Bottom Corridor 2A-1", "corridor", 280, 435, 3, false, false});
    graph.addNode({831, "Bottom Corridor 2A-2", "corridor", 395, 435, 3, false, false});
    graph.addNode({832, "Bottom Corridor 2A-3", "corridor", 495, 435, 3, false, false});
    graph.addNode({833, "Bottom Corridor 2A-4", "corridor", 605, 435, 3, false, false});
    graph.addNode({834, "Bottom Corridor 2A-5", "corridor", 725, 435, 3, false, false});
    graph.addNode({835, "Bottom Corridor 2A-6", "corridor", 845, 435, 3, false, false});
    graph.addNode({836, "Bottom Corridor 2A-7", "corridor", 940, 435, 3, false, false});
    graph.addNode({837, "Bottom Corridor 2A-8", "corridor", 1030, 435, 3, false, false});
    graph.addNode({838, "Bottom Corridor 2A-9", "corridor", 1110, 435, 3, false, false});
    
    // ==================== HORIZONTAL CORRIDOR EDGES ====================
    
    // TOP CORRIDOR
    graph.addEdge(800, 801, 95.0f, 0.0f, "walk");
    graph.addEdge(801, 802, 105.0f, 0.0f, "walk");
    graph.addEdge(802, 803, 75.0f, 0.0f, "walk");
    graph.addEdge(803, 804, 105.0f, 0.0f, "walk");
    graph.addEdge(804, 805, 105.0f, 0.0f, "walk");
    graph.addEdge(805, 806, 90.0f, 0.0f, "walk");
    graph.addEdge(806, 807, 100.0f, 0.0f, "walk");
    graph.addEdge(807, 808, 105.0f, 0.0f, "walk");
    graph.addEdge(808, 809, 90.0f, 0.0f, "walk");
    
    // SECOND CORRIDOR
    graph.addEdge(810, 811, 105.0f, 0.0f, "walk");
    graph.addEdge(811, 812, 95.0f, 0.0f, "walk");
    graph.addEdge(812, 813, 75.0f, 0.0f, "walk");
    graph.addEdge(813, 814, 105.0f, 0.0f, "walk");
    graph.addEdge(814, 815, 105.0f, 0.0f, "walk");
    graph.addEdge(815, 816, 90.0f, 0.0f, "walk");
    graph.addEdge(816, 817, 105.0f, 0.0f, "walk");
    graph.addEdge(817, 818, 100.0f, 0.0f, "walk");
    graph.addEdge(818, 819, 90.0f, 0.0f, "walk");
    
    // THIRD CORRIDOR
    graph.addEdge(820, 821, 105.0f, 0.0f, "walk");
    graph.addEdge(821, 822, 95.0f, 0.0f, "walk");
    graph.addEdge(822, 823, 80.0f, 0.0f, "walk");
    graph.addEdge(823, 824, 100.0f, 0.0f, "walk");
    graph.addEdge(824, 825, 105.0f, 0.0f, "walk");
    graph.addEdge(825, 826, 90.0f, 0.0f, "walk");
    graph.addEdge(826, 827, 105.0f, 0.0f, "walk");
    graph.addEdge(827, 828, 100.0f, 0.0f, "walk");
    graph.addEdge(828, 829, 90.0f, 0.0f, "walk");
    
    // BOTTOM CORRIDOR
    graph.addEdge(830, 831, 115.0f, 0.0f, "walk");
    graph.addEdge(831, 832, 100.0f, 0.0f, "walk");
    graph.addEdge(832, 833, 110.0f, 0.0f, "walk");
    graph.addEdge(833, 834, 120.0f, 0.0f, "walk");
    graph.addEdge(834, 835, 120.0f, 0.0f, "walk");
    graph.addEdge(835, 836, 95.0f, 0.0f, "walk");
    graph.addEdge(836, 837, 90.0f, 0.0f, "walk");
    graph.addEdge(837, 838, 80.0f, 0.0f, "walk");
    
    // ==================== VERTICAL CORRIDOR CONNECTIONS ====================
    
    graph.addEdge(800, 810, 75.0f, 0.0f, "walk");
    graph.addEdge(810, 820, 100.0f, 0.0f, "walk");
    graph.addEdge(820, 830, 75.0f, 0.0f, "walk");
    
    graph.addEdge(801, 811, 75.0f, 0.0f, "walk");
    graph.addEdge(811, 821, 100.0f, 0.0f, "walk");
    graph.addEdge(821, 831, 75.0f, 0.0f, "walk");
    
    graph.addEdge(802, 812, 75.0f, 0.0f, "walk");
    graph.addEdge(812, 822, 100.0f, 0.0f, "walk");
    graph.addEdge(822, 832, 75.0f, 0.0f, "walk");
    
    graph.addEdge(803, 813, 75.0f, 0.0f, "walk");
    graph.addEdge(813, 823, 100.0f, 0.0f, "walk");
    graph.addEdge(823, 833, 75.0f, 0.0f, "walk");
    
    graph.addEdge(804, 814, 75.0f, 0.0f, "walk");
    graph.addEdge(814, 824, 100.0f, 0.0f, "walk");
    graph.addEdge(824, 834, 75.0f, 0.0f, "walk");
    
    graph.addEdge(805, 815, 75.0f, 0.0f, "walk");
    graph.addEdge(815, 825, 100.0f, 0.0f, "walk");
    graph.addEdge(825, 835, 75.0f, 0.0f, "walk");
    
    graph.addEdge(806, 816, 75.0f, 0.0f, "walk");
    graph.addEdge(816, 826, 100.0f, 0.0f, "walk");
    graph.addEdge(826, 836, 75.0f, 0.0f, "walk");
    
    graph.addEdge(807, 817, 75.0f, 0.0f, "walk");
    graph.addEdge(817, 827, 100.0f, 0.0f, "walk");
    graph.addEdge(827, 837, 75.0f, 0.0f, "walk");
    
    graph.addEdge(808, 818, 75.0f, 0.0f, "walk");
    graph.addEdge(818, 828, 100.0f, 0.0f, "walk");
    graph.addEdge(828, 838, 75.0f, 0.0f, "walk");
    
    // ==================== STORE CONNECTIONS TO CORRIDORS ====================
    
    // Left section facilities
    graph.addEdge(601, 800, 75.0f, 0.0f, "walk");
    graph.addEdge(602, 810, 30.0f, 0.0f, "walk");
    graph.addEdge(603, 810, 30.0f, 0.0f, "walk");
    graph.addEdge(604, 820, 30.0f, 0.0f, "walk");
    graph.addEdge(605, 820, 30.0f, 0.0f, "walk");
    
    // Top row stores
    for (int i = 606; i <= 611; i++) {
        graph.addEdge(i, 801, 30.0f, 0.0f, "walk");
    }
    for (int i = 612; i <= 618; i++) {
        graph.addEdge(i, 804, 30.0f, 0.0f, "walk");
    }
    for (int i = 619; i <= 624; i++) {
        graph.addEdge(i, 807, 30.0f, 0.0f, "walk");
    }
    
    // Second row stores
    for (int i = 625; i <= 630; i++) {
        graph.addEdge(i, 811, 35.0f, 0.0f, "walk");
    }
    for (int i = 631; i <= 638; i++) {
        graph.addEdge(i, 814, 35.0f, 0.0f, "walk");
    }
    for (int i = 639; i <= 644; i++) {
        graph.addEdge(i, 817, 35.0f, 0.0f, "walk");
    }
    
    // Center section
    graph.addEdge(645, 812, 40.0f, 0.0f, "walk");
    graph.addEdge(646, 813, 50.0f, 0.0f, "walk");
    graph.addEdge(647, 814, 40.0f, 0.0f, "walk");
    graph.addEdge(648, 823, 30.0f, 0.0f, "walk");
    
    // Third row stores
    for (int i = 649; i <= 655; i++) {
        graph.addEdge(i, 821, 35.0f, 0.0f, "walk");
    }
    for (int i = 656; i <= 658; i++) {
        graph.addEdge(i, 825, 35.0f, 0.0f, "walk");
    }
    for (int i = 659; i <= 665; i++) {
        graph.addEdge(i, 827, 35.0f, 0.0f, "walk");
    }
    
    // Bottom row stores
    for (int i = 666; i <= 672; i++) {
        graph.addEdge(i, 831, 30.0f, 0.0f, "walk");
    }
    for (int i = 673; i <= 682; i++) {
        graph.addEdge(i, 834, 30.0f, 0.0f, "walk");
    }
    for (int i = 683; i <= 688; i++) {
        graph.addEdge(i, 836, 30.0f, 0.0f, "walk");
    }
    
    // Bowling alley
    graph.addEdge(689, 819, 110.0f, 0.0f, "walk");
    graph.addEdge(689, 829, 110.0f, 0.0f, "walk");
    
    // ==================== EMERGENCY EXIT CONNECTIONS ====================
    
    graph.addEdge(690, 800, 65.0f, 0.0f, "walk");
    graph.addEdge(691, 802, 65.0f, 0.0f, "walk");
    graph.addEdge(692, 804, 65.0f, 0.0f, "walk");
    graph.addEdge(693, 807, 65.0f, 0.0f, "walk");
    
    graph.addEdge(694, 830, 20.0f, 0.0f, "walk");
    graph.addEdge(695, 834, 20.0f, 0.0f, "walk");
    graph.addEdge(696, 837, 20.0f, 0.0f, "walk");
    
    // ==================== STAIRS/ELEVATOR CONNECTIONS ====================
    
    graph.addEdge(697, 800, 65.0f, 0.0f, "walk");
    graph.addEdge(698, 801, 65.0f, 0.0f, "walk");
    graph.addEdge(699, 804, 65.0f, 0.0f, "walk");
    graph.addEdge(700, 807, 65.0f, 0.0f, "walk");
    graph.addEdge(701, 807, 70.0f, 0.0f, "walk");
    
    graph.addEdge(702, 830, 20.0f, 0.0f, "walk");
    graph.addEdge(703, 834, 20.0f, 0.0f, "walk");
    graph.addEdge(704, 837, 20.0f, 0.0f, "walk");
    graph.addEdge(705, 838, 20.0f, 0.0f, "walk");

    return graph;
}