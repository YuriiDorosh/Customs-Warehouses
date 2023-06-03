#include "OrderManager.h"

void OrderManager::placeOrder(const Order& order) {
    orders.push_back(order);
}

void OrderManager::removeOrder(const std::string& orderNumber) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->getOrderNumber() == orderNumber) {
            orders.erase(it);
            break;
        }
    }
}

Order* OrderManager::findOrder(const std::string& orderNumber) {
    for (auto& order : orders) {
        if (order.getOrderNumber() == orderNumber) {
            return &order;
        }
    }
    return nullptr;
}

std::vector<Order> OrderManager::getAllOrders() const {
    return orders;
}
