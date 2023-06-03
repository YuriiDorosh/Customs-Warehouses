#include <iostream>
#include "Product.h"
#include "Customs.h"
#include "Warehouse.h"
#include "Customer.h"
#include "Order.h"
#include "ProductManager.h"
#include "CustomsManager.h"
#include "OrderManager.h"

int main() {
    // Створення об'єктів продуктів
    Product product1("P1", "Product 1", 10.99);
    Product product2("P2", "Product 2", 20.49);
    
    // Створення об'єктів митниць
    Customs customs1("C1");
    Customs customs2("C2");
    
    // Створення об'єктів складів
    Warehouse warehouse1("Warehouse 1");
    Warehouse warehouse2("Warehouse 2");
    
    // Додавання продуктів на склади
    warehouse1.addProduct(product1);
    warehouse1.addProduct(product2);
    warehouse2.addProduct(product1);
    
    // Створення об'єктів клієнтів
    Customer customer1("Customer 1");
    Customer customer2("Customer 2");
    
    // Створення об'єктів замовлень
    Order order1("O1");
    Order order2("O2");
    
    // Додавання продуктів до замовлень
    order1.addProduct(product1);
    order1.addProduct(product2);
    order2.addProduct(product1);
    
    // Розміщення замовлень клієнтами
    customer1.placeOrder(order1);
    customer2.placeOrder(order2);
    
    // Створення об'єктів менеджерів продуктів, митниць та замовлень
    ProductManager productManager;
    CustomsManager customsManager;
    OrderManager orderManager;
    
    // Додавання продуктів, митниць та замовлень до відповідних менеджерів
    productManager.addProduct(product1);
    productManager.addProduct(product2);
    customsManager.addCustoms(customs1);
    customsManager.addCustoms(customs2);
    orderManager.placeOrder(order1);
    orderManager.placeOrder(order2);
    
    // Виведення даних
    std::cout << "Product: " << product1.getCode() << ", " << product1.getName() << ", " << product1.getPrice() << std::endl;
    std::cout << "Customs: " << customs1.getCountryCode() << std::endl;
    std::cout << "Warehouse: " << warehouse1.getName() << std::endl;
    std::cout << "Customer: " << customer1.getName() << std::endl;
    std::cout << "Order: " << order1.getOrderNumber() << std::endl;
    
    return 0;
}
