
#ifndef FULFILLMENT_H
#define FULFILLMENT_H

#include <iostream>
#include <string>

using namespace std;

// Represents an order that needs delivery
class Order {
private:
    int orderID;
    string customerName;
    string deliveryAddress;

public:
    Order(int id, string name, string address) {
        orderID = id;
        customerName = name;
        deliveryAddress = address;
    }

    void displayOrder() const {
        cout << "\n--- Order Details ---" << endl;
        cout << "Order ID: " << orderID << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Delivery Address: " << deliveryAddress << endl;
    }
};

// Base class for different shipping methods
class ShippingCalculator {
public:
    virtual double calculateShippingCost(double weight) const = 0;

    virtual string getShippingMethod() const = 0;

    virtual ~ShippingCalculator() {}
};

// Air freight shipping
class AirFreight : public ShippingCalculator {
public:
    double calculateShippingCost(double weight) const override {
        return weight * 30;
    }

    string getShippingMethod() const override {
        return "Air Freight";
    }
};

// Sea freight shipping
class SeaFreight : public ShippingCalculator {
public:
    double calculateShippingCost(double weight) const override {
        return weight * 15;
    }

    string getShippingMethod() const override {
        return "Sea Freight";
    }
};

// Road freight shipping
class RoadFreight : public ShippingCalculator {
public:
    double calculateShippingCost(double weight) const override {
        return weight * 20;
    }

    string getShippingMethod() const override {
        return "Road Freight";
    }
};

#endif

