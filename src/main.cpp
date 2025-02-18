#include "delivery.hpp"
#include "graph.hpp"
#include "order.hpp"
#include "shortest_paths_dijkstra.hpp"
#include <algorithm>
#include <cmath>
#include <random>
#include <utils.hpp>

int main() {
  print_graph(test_graph);
  print_graph(sparse_test_graph);

  // Create a random number generator and seed it with a random device
  std::random_device rd;
  std::mt19937 gen(4);

  // Define a distribution to generate floats between 0.0 and 1.0
  std::uniform_real_distribution<float> dis(0.0f, 1.0f);

  /*
  // direct conncetion, all customer are directly connected to the store
  for (int i = 0; i < GraphStoreCustomerLocation.size(); i++) {
    // Round the random variable to the second digit
    GraphStoreCustomerLocation[0][i] = std::round(dis(gen) * 100) / 100;
  }
  */

  // a) connectivity between customer and store
  for (int i = 1; i < std::floor(GraphStoreCustomerLocation.size() / 2); i++) {
    // Round the random variable to the second digit
    GraphStoreCustomerLocation[0][i] = std::round(dis(gen) * 100) / 100;
  }
  //  ii indirect connection
  GraphStoreCustomerLocation[1][5] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[2][6] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[3][7] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[4][8] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[4][9] = std::round(dis(gen) * 100) / 100;

  GraphStoreCustomerLocation[5][10] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[6][10] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[7][10] = std::round(dis(gen) * 100) / 100;

  // b)
  // i: Write an algorithm that computes the shortest path between the store
  // and customers' houses.

  print_graph(GraphStoreCustomerLocation);

  std::vector<hop_t> res = dijkstra(GraphStoreCustomerLocation, 0);
  print(res);
  std::vector<int> _shortestPath = getPath(res, 10);
  std::cout << _shortestPath << std::endl;

  // ii: Delivery plan
  // std::uniform_int_distribution<int> basketDis(0,2);
  std::vector<Order> orders = generateOrders(10);

  // struct Order {
  //   int customerId;
  //   int numBaskets;
  // };
  // std::vector<Order> orders;

  // for (int i = 1; i <= 10; i++) {
  //   Order o;
  //   o.customerId = i;
  //   o.numBaskets = basketDis(gen);
  //   orders.push_back(o);
  // }

  for (Order &order : orders) {
    std::cout << "Customer " << order.customerId << " orders " << order.numBaskets
              << " basket(s).\n";
  }

  /* explictly written code

  // loop through
  std::vector<Delivery> deliveryPlan;
  std::vector<int> shortestPath;
  for (Order &order : orders) {
    // std::vector<hop_t> res = dijkstra(GraphStoreCustomerLocation, 0);
    shortestPath = getPath(res, order.customerId);
    Delivery d{order.customerId, shortestPath, res[order.customerId].weight, order.numBaskets};
    deliveryPlan.push_back(d);
  }

  // sort deliveryPlan
  std::sort(deliveryPlan.begin(), deliveryPlan.end(), compareDistance);

  // delivery run
  std::vector<DeliveryRun> runs;
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

  for (const auto &run : runs) {
    std::cout << "Delivery Run (Total baskets: " << run.totalBaskets << "):\n";
    for (const Delivery &deliv : run.deliveries) {
      std::cout << "  Customer " << deliv.customerId << " (Baskets: " << deliv.numBaskets
                << ", Distance: " << deliv.distance << ", Route: " << deliv.route << ")\n";
    }
    std::cout << std::endl;
  }

  */

  // class implementation of the delivey
  DeliveryPlan delivery(orders);
  std::vector<Delivery> deliveryPlan = delivery.createDeliveryPlan(res);
  std::vector<DeliveryRun> deliveryRun = delivery.createDeliveryRun();

  printDeliveryRun(deliveryRun);

  return 0;
}