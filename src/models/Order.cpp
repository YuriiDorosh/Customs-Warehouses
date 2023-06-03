#include "Order.h"

Order::Order(std::string orderNumber) : orderNumber(orderNumber) {}

std::string Order::getOrderNumber() const {
    return orderNumber;
}

void Order::addProduct(const Product& product) {
    products.push_back(product);
}

void Order::removeProduct(const std::string& code) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getCode() == code) {
            products.erase(it);
            break;
        }
    }
}

double Order::calculateOrderValue() const {
    double totalValue = 0.0;
    for (const auto& product : products) {
        totalValue += product.calculateTotalValue();
    }
    return totalValue;
}
