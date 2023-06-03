#include "Warehouse.h"

Warehouse::Warehouse(std::string name) : name(name) {}

std::string Warehouse::getName() const {
    return name;
}

void Warehouse::addProduct(const Product& product) {
    products.push_back(product);
}

void Warehouse::removeProduct(const std::string& code) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getCode() == code) {
            products.erase(it);
            break;
        }
    }
}

double Warehouse::calculateTotalValue() const {
    double totalValue = 0.0;
    for (const auto& product : products) {
        totalValue += product.calculateTotalValue();
    }
    return totalValue;
}
