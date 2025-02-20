#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <limits>
#include <vector>

// Weighted adjacency matrix representation
// typedef std::vector<std::vector<float>> Graph; // old alternative implementation
using Graph = std::vector<std::vector<float>>;

void print_graph(const Graph &graph, bool as_url = false);

// Adjecency list representation
struct hop_t {
  float weight;
  int vertex;
};

using SparseGraph = std::vector<std::vector<hop_t>>;

void print_graph(const SparseGraph &graph, bool as_url = false);

inline std::ostream &operator<<(std::ostream &os, const hop_t &hop) {
  return os << "(" << hop.weight << "," << hop.vertex << ')';
}

// constexpr means that inf is a constant expression known at compile time
constexpr auto inf = std::numeric_limits<float>::infinity();

// Test graphs
extern const Graph test_graph;
extern const SparseGraph sparse_test_graph;

// Graphs
extern Graph GraphStoreCustomerLocation;

#endif