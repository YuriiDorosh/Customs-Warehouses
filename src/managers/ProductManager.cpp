#include "ProductManager.h"

void ProductManager::addProduct(const Product& product) {
    products.push_back(product);
}

void ProductManager::removeProduct(const std::string& code) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getCode() == code) {
            products.erase(it);
            break;
        }
    }
}

Product* ProductManager::findProduct(const std::string& code) {
    for (auto& product : products) {
        if (product.getCode() == code) {
            return &product;
        }
    }
    return nullptr;
}

std::vector<Product> ProductManager::getAllProducts() const {
    return products;
}
