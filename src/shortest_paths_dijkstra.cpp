#include "shortest_paths_dijkstra.hpp"
#include "priority_queue.hpp"

#include <cmath>

struct triplet_t {
  float d;
  int r;
  int v;
};

std::vector<hop_t> dijkstra(const Graph &graph, const int source) {
  assert(source >= 0);
  assert(source < graph.size());

auto DP = std::vector<hop_t>(graph.size(), {inf, -1});
auto compare = [](const triplet_t &lhs, const triplet_t &rhs) {
  return lhs.d < rhs.d;
};

  auto queue = std::vector<triplet_t>{};
  priority_enqueue(queue, {0, source, source}, compare);
  while (!queue.empty()) {
    auto triplet = queue[0]; // copy highest priority triplet
    priority_dequeue(queue, compare);
    if (DP[triplet.v].weight <= triplet.d) {
      continue;
    }
    DP[triplet.v] = {triplet.d, triplet.r};

    for (int v = 0; v < graph[triplet.v].size(); ++v) {
      auto d = triplet.d + graph[triplet.v][v];
      if (!std::isfinite(d)) {
        continue;
      }
      priority_enqueue(queue, {d, triplet.v, v}, compare);
    }
  }
  return DP;
}
