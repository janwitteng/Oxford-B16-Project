#include "graph.hpp"
#include <cmath>
#include <random>

class Robot;
class Customer;
class LocationGraph;

int main() {
  print_graph(test_graph);
  print_graph(sparse_test_graph);

  // Create a random number generator and seed it with a random device
  std::random_device rd;
  std::mt19937 gen(rd());

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


  print_graph(GraphStoreCustomerLocation);
  return 0;
}