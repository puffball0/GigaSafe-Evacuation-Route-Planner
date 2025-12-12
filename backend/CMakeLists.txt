cmake_minimum_required(VERSION 3.10)
project(GigaSafeBackend)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags (cross-platform)
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/algorithms)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/visualization)

# Source files
set(GRAPH_SOURCES
    Graph.cpp
    groundfloor.cpp
    firstfloor.cpp
    secondfloor.cpp
    lowergroundfloor.cpp
    mezzaninefloor.cpp
    floor2a.cpp
    algorithms/Dijkstra.cpp
    algorithms/BFS.cpp
    algorithms/DFS.cpp
    algorithms/AStar.cpp
    visualization/visualizer.cpp
    datastructures/HashMap.cpp
)

# Executables
add_executable(evacuation_cli 
    main.cpp
    ${GRAPH_SOURCES}
)

add_executable(evacuation_system 
    ../integration/backend-wrapper.cpp
    ${GRAPH_SOURCES}
)

# Static library
add_library(gigasafe_graph STATIC ${GRAPH_SOURCES})

# Link library
target_link_libraries(evacuation_cli gigasafe_graph)
target_link_libraries(evacuation_system gigasafe_graph)

# Installation rules
install(TARGETS evacuation_cli evacuation_system
    RUNTIME DESTINATION bin
)
