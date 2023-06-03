#include "Customer.h"

Customer::Customer(std::string name) : name(name) {}

std::string Customer::getName() const {
    return name;
}

void Customer::placeOrder(const Order& order) {
    orders.push_back(order);
}

double Customer::calculateTotalOrderValue() const {
    double totalValue = 0.0;
    for (const auto& order : orders) {
        totalValue += order.calculateOrderValue();
    }
    return totalValue;
}
