#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <vector>

class Warehouse {
private:
    std::string name;
    std::vector<Product> products;

public:
    Warehouse(std::string name);

    std::string getName() const;
    void addProduct(const Product& product);
    void removeProduct(const std::string& code);
    double calculateTotalValue() const;
};

#endif
