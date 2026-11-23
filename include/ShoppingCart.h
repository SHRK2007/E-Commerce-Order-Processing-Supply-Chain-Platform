
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Represents one product added to the cart
class CartItem {
private:
    int productID;
    string productName;
    double price;
    int quantity;

public:
    CartItem(int id, string name, double p, int q) {
        productID = id;
        productName = name;
        price = p;
        quantity = q;
    }

    double getTotalPrice() const {
        return price * quantity;
    }

    void displayItem() const {
        cout << "Product: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Subtotal: " << getTotalPrice() << endl;
    }
};

// Manages products added to the shopping cart
class ShoppingCart {
private:
    vector<CartItem> items;

public:
    void addItem(CartItem item) {
        items.push_back(item);
        cout << "Item added to cart successfully!" << endl;
    }

    void displayCart() const {
        cout << "\n--- Shopping Cart ---\n";

        for (const CartItem& item : items) {
            item.displayItem();
            cout << "-------------------\n";
        }
    }

    double calculateTotal() const {
        double total = 0;

        for (const CartItem& item : items) {
            total += item.getTotalPrice();
        }

        return total;
    }
};

// Handles the checkout process
class Checkout {
private:
    double deliveryCharges;

public:
    Checkout(double charges) {
        deliveryCharges = charges;
    }

    void processCheckout(const ShoppingCart& cart) const {
        cout << "\n--- Checkout ---" << endl;
        cout << "Cart Total: " << cart.calculateTotal() << endl;
        cout << "Delivery Charges: " << deliveryCharges << endl;
        cout << "Final Amount: "
             << cart.calculateTotal() + deliveryCharges << endl;
        cout << "Checkout completed successfully!" << endl;
    }
};

#endif
