#include "order.hpp"
#include <iostream>
#include <random>

std::vector<Order> generateOrders(int count) {
    std::vector<Order> orders;
    // Set up the random number generator.
    std::random_device rd;
    std::mt19937 gen(4);
    std::uniform_int_distribution<int> basketDis(0, 2);

    for (int i = 1; i <= count; i++) {
        Order o;
        o.customerId = i;
        o.numBaskets = basketDis(gen);
        orders.push_back(o);
    }
    return orders;
}