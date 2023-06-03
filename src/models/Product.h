#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sqlite3.h>

class Product {
private:
    std::string name;
    std::string code;
    double price;
    int quantity;

public:
    Product(std::string name, std::string code, double price, int quantity);

    std::string getName() const;
    std::string getCode() const;
    double getPrice() const;
    int getQuantity() const;
    void setQuantity(int newQuantity);
    double calculateTotalValue() const;

    void saveToDatabase(sqlite3* db) const;
    static std::vector<Product> loadFromDatabase(sqlite3* db);
};

#endif
