# Oxford-B16-Project

This is the C++ project for Tutorial Sheet 2 of module B16 "Software Engineering, Algorithms, and Data Structures."
This project aims to provide an introduction to structuring and compiling C++ projects.

## Build Instructions

### Using gcc

#### Single-Command Compilation
`g++ -std=c++20 -Wall -Iinclude src/graph.cpp src/shortest_paths_dijkstra.cpp src/order.cpp src/delivery.cpp src/main.cpp -o graph_program`

### Compile and link separately
`g++ -std=c++20 -Wall -Iinclude -c src/graph.cpp -o graph.o && \
g++ -std=c++20 -Wall -Iinclude -c src/shortest_paths_dijkstra.cpp -o shortest_paths_dijkstra.o && \
g++ -std=c++20 -Wall -Iinclude -c src/order.cpp -o order.o && \
g++ -std=c++20 -Wall -Iinclude -c src/delivery.cpp -o delivery.o && \
g++ -std=c++20 -Wall -Iinclude -c src/main.cpp -o main.o`

Link

`g++ graph.o shortest_paths_dijkstra.o order.o delivery.o main.o -o graph_program`

### Compile using cmake
Create a build directory and navigate into it:  
`mkdir build`  
`cd build`  

Configure the project:  
`cmake ..`  

If you need to manually set the compiler:   
`cmake .. -DCMAKE_CXX_COMPILER=g++`  

Build the project (cross-platform):     
`cmake --build .`
