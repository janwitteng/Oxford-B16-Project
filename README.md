# Oxford-B16-Project


## compile program
g++ -std=c++20 -Wall -Iinclude src/graph.cpp src/main.cpp -o graph_program

## compile and link
g++ -std=c++17 -Wall -Iinclude -c src/graph.cpp -o graph.o
g++ -std=c++17 -Wall -Iinclude -c src/main.cpp -o main.o

g++ graph.o main.o -o graph_program