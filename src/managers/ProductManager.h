#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <vector>
#include "Product.h"

class ProductManager {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product);
    void removeProduct(const std::string& code);
    Product* findProduct(const std::string& code);
    std::vector<Product> getAllProducts() const;
};

#endif
