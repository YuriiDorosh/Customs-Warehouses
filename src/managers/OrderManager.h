#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <vector>
#include "Order.h"

class OrderManager {
private:
    std::vector<Order> orders;

public:
    void placeOrder(const Order& order);
    void removeOrder(const std::string& orderNumber);
    Order* findOrder(const std::string& orderNumber);
    std::vector<Order> getAllOrders() const;
};

#endif
