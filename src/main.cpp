#include "delivery.hpp"
#include "graph.hpp"
#include "order.hpp"
#include "shortest_paths_dijkstra.hpp"
#include <algorithm>
#include <cmath>
#include <random>
#include <utils.hpp>

int main() {
  // Print initial test graphs
  // print_graph(test_graph);
  // print_graph(sparse_test_graph);

  // Set up a random number generator (using a fixed seed for reproducibility)
  std::random_device rd;
  std::mt19937 gen(4);

  // Define a distribution to generate float values between 0.0 and 1.0
  std::uniform_real_distribution<float> dis(0.0f, 1.0f);

  // (a) Establish connectivity between the store and customer locations
  // For the first half of the customers, set direct connectivity with random weights
  for (int i = 1; i < std::floor(GraphStoreCustomerLocation.size() / 2); i++) {
    // Generate a random weight rounded to two decimal places
    GraphStoreCustomerLocation[0][i] = std::round(dis(gen) * 100) / 100;
  }
  
  // (a-ii) Set up indirect connections between specific nodes
  GraphStoreCustomerLocation[1][5] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[2][6] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[3][7] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[4][8] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[4][9] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[5][10] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[6][10] = std::round(dis(gen) * 100) / 100;
  GraphStoreCustomerLocation[7][10] = std::round(dis(gen) * 100) / 100;

  // (b) Compute and display the shortest path between the store and customer houses

  // Print the updated graph with store-customer connections
  // Visualise graph: https://dreampuf.github.io/GraphvizOnline
  print_graph(GraphStoreCustomerLocation);

  // Compute shortest paths from the store (node 0) using Dijkstra's algorithm
  std::vector<hop_t> res = dijkstra(GraphStoreCustomerLocation, 0);
  print(res);

  // Retrieve and print the shortest path to customer node 10
  std::vector<int> shortestPath = getPath(res, 10);
  std::cout << shortestPath << std::endl;

  // (c) Generate and display a delivery plan based on customer orders

  // Generate a list of orders for 10 customers
  std::vector<Order> orders = generateOrders(10);
  for (const Order &order : orders) {
    std::cout << "Customer " << order.customerId << " orders " 
              << order.numBaskets << " basket(s)." << std::endl;
  }

  // Create a delivery plan using the computed shortest paths and orders
  DeliveryPlan delivery(orders);
  std::vector<Delivery> deliveryPlan = delivery.createDeliveryPlan(res);
  std::vector<DeliveryRun> deliveryRun = delivery.createDeliveryRun();

  // Print the final delivery run plan
  printDeliveryRun(deliveryRun);

  return 0;
}