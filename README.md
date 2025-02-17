# Oxford-B16-Project

This is the C++ project of the tutirial sheet 2 of the module B16 "Software Engineeirng and Algortihms and Data Strucutres"


## Compile using gcc
`g++ -std=c++20 -Wall -Iinclude src/graph.cpp src/main.cpp -o graph_program`

### Compile and link separately
`g++ -std=c++20 -Wall -Iinclude -c src/graph.cpp -o graph.o`  
`g++ -std=c++20 -Wall -Iinclude -c src/main.cpp -o main.o`  
`g++ graph.o main.o -o graph_program`

## Compile using cmake
`mkdir build`  
`cd build`  

cmake configures the project  
`cmake ..`  

if manually setting compiler    
`cmake .. -DCMAKE_CXX_COMPILER=g++`  

cmake --build builds the project (cross-platform)  
`cmake --build .`
