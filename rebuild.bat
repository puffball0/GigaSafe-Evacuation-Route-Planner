@echo off
echo Recompiling backend...
g++ -std=c++17 -I./backend -o backend/build/Release/evacuation_system.exe integration/backend-wrapper.cpp backend/Graph.cpp backend/datastructures/HashMap.cpp backend/groundfloor.cpp backend/firstfloor.cpp backend/secondfloor.cpp backend/lowergroundfloor.cpp backend/mezzaninefloor.cpp backend/floor2a.cpp backend/algorithms/Dijkstra.cpp backend/algorithms/BFS.cpp backend/algorithms/DFS.cpp backend/algorithms/AStar.cpp

if %ERRORLEVEL% EQU 0 (
    echo Build successful!
    echo Now restart the API server with: cd integration ^&^& node api-server.js
) else (
    echo Build failed!
)