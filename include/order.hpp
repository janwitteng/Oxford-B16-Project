#ifndef ORDER_HPP
#define ORDER_HPP

#include <vector>

// Define the Order structure.
struct Order {
    int customerId;
    int numBaskets;
};

// Function prototypes.
std::vector<Order> generateOrders(int count);
void printOrders(const std::vector<Order>& orders);

#endif