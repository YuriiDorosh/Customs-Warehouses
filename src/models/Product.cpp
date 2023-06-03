#include "Product.h"

Product::Product(std::string name, std::string code, double price, int quantity)
    : name(name), code(code), price(price), quantity(quantity) {}

std::string Product::getName() const {
    return name;
}

std::string Product::getCode() const {
    return code;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

double Product::calculateTotalValue() const {
    return price * quantity;
}

void Product::saveToDatabase(sqlite3* db) const {
    std::string query = "INSERT INTO products (name, code, price, quantity) VALUES ('" +
                       name + "', '" + code + "', " + std::to_string(price) + ", " +
                       std::to_string(quantity) + ")";
    char* errMsg;
    int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (result != SQLITE_OK) {
        std::cerr << "Error saving product to database: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

std::vector<Product> Product::loadFromDatabase(sqlite3* db) {
    std::vector<Product> products;

    std::string query = "SELECT name, code, price, quantity FROM products";
    char* errMsg;
    int result = sqlite3_exec(
        db, query.c_str(),
        [](void* data, int argc, char** argv, char** /*azColName*/) -> int {
            if (argc == 4) {
                std::string name = argv[0];
                std::string code = argv[1];
                double price = std::stod(argv[2]);
                int quantity = std::stoi(argv[3]);
                Product product(name, code, price, quantity);
                static_cast<std::vector<Product>*>(data)->push_back(product);
            }
            return 0;
        },
        &products, &errMsg);

    if (result != SQLITE_OK) {
        std::cerr << "Error loading products from database: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    return products;
}
