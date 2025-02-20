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


  for (Order &order : orders) {
    std::cout << "Customer " << order.customerId << " orders " << order.numBaskets
              << " basket(s).\n";
  }


  // class implementation of the delivey
  DeliveryPlan delivery(orders);
  std::vector<Delivery> deliveryPlan = delivery.createDeliveryPlan(res);
  std::vector<DeliveryRun> deliveryRun = delivery.createDeliveryRun();

  printDeliveryRun(deliveryRun);

  return 0;
}