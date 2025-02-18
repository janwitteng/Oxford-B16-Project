#include "delivery.hpp"
#include "graph.hpp"
#include "order.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> getPath(std::vector<hop_t> &hop, int node) {
  if (node == 0) {
    return {0};
  }
  std::vector<int> path = getPath(hop, hop[node].vertex);
  path.push_back(node);
  return path;
}

std::ostream &operator<<(std::ostream &out, const std::vector<int> &path) {
  for (int i = 0; i < path.size(); ++i) {
    out << path[i];
    if (i != path.size() - 1) {
      out << "->";
    }
  }
  return out;
}

bool compareDistance(const Delivery &a, const Delivery &b) { return a.distance < b.distance; }

DeliveryPlan::DeliveryPlan(std::vector<Order> &_orders) : orders(_orders){};

std::vector<Delivery> DeliveryPlan::createDeliveryPlan(std::vector<hop_t> &res) {

  std::vector<int> shortestPath;
  for (Order &order : orders) {
    // std::vector<hop_t> res = dijkstra(GraphStoreCustomerLocation, 0);
    shortestPath = getPath(res, order.customerId);
    Delivery d{order.customerId, shortestPath, res[order.customerId].weight, order.numBaskets};
    deliveryPlan.push_back(d);
  }
  return deliveryPlan;
}

std::vector<DeliveryRun> DeliveryPlan::createDeliveryRun() {
  // sort deliveryPlan
  std::sort(deliveryPlan.begin(), deliveryPlan.end(), compareDistance);

  // delivery run
  DeliveryRun currentRun;
  currentRun.totalBaskets = 0;

  for (Delivery &deliver : deliveryPlan) {
    if (deliver.numBaskets == 0) {
      continue;
    }
    if (currentRun.totalBaskets + deliver.numBaskets > 3) {
      runs.push_back(currentRun);
      currentRun.deliveries.clear();
      currentRun.totalBaskets = 0;
    }
    currentRun.deliveries.push_back(deliver);
    currentRun.totalBaskets += deliver.numBaskets;
  }

  if (!currentRun.deliveries.empty()) {
    runs.push_back(currentRun);
  }
  return runs;
}

void printDeliveryRun(std::vector<DeliveryRun> &deliveryRun) {
  for (DeliveryRun &run : deliveryRun) {
    std::cout << "Delivery Run (Total baskets: " << run.totalBaskets << "):\n";
    for (Delivery &deliv : run.deliveries) {
      std::cout << "  Customer " << deliv.customerId << " (Baskets: " << deliv.numBaskets
                << ", Distance: " << deliv.distance << ", Route: " << deliv.route << ")\n";
    }
    std::cout << std::endl;
  }
}