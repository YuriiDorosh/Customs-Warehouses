#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>

class Order {
private:
    std::string orderNumber;
    std::vector<Product> products;

public:
    Order(std::string orderNumber);

    std::string getOrderNumber() const;
    void addProduct(const Product& product);
    void removeProduct(const std::string& code);
    double calculateOrderValue() const;
};

#endif
