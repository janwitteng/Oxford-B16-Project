#ifndef DELIVERY_HPP
#define DELIVERY_HPP

#include <graph.hpp>
#include <order.hpp>
#include <vector>

struct Delivery {
  int customerId;
  std::vector<int> route;
  float distance;
  int numBaskets;
};

struct DeliveryRun {
  std::vector<Delivery> deliveries;
  int totalBaskets;
};

std::vector<int> getPath(std::vector<hop_t> &hop, int node);
std::ostream &operator<<(std::ostream &out, const std::vector<int> &path);
void printDeliveryRun(std::vector<DeliveryRun> &deliveryRun);
bool compareDistance(const Delivery &a, const Delivery &b);

class DeliveryPlan {
public:
  DeliveryPlan(std::vector<Order> &_orders);

  std::vector<Delivery> createDeliveryPlan(std::vector<hop_t> &res);
  std::vector<DeliveryRun> createDeliveryRun();

private:
  std::vector<Order> &orders;
  std::vector<Delivery> deliveryPlan;
  std::vector<DeliveryRun> runs;
};

#endif