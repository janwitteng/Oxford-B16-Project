cmake_minimum_required(VERSION 3.10)
project(GraphProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory
include_directories(include)

# Source files
set(SOURCES
    src/graph.cpp
    src/shortest_paths_dijkstra.cpp
    src/order.cpp
    src/delivery.cpp
    src/main.cpp
)

# Create an executable
add_executable(graph_program ${SOURCES})