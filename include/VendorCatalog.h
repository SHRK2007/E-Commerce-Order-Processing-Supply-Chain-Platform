
#ifndef VENDORCATALOG_H
#define VENDORCATALOG_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vendor {
private:
    int vendorID;
    string vendorName;

public:
    Vendor(int id, string name) {
        vendorID = id;
        vendorName = name;
    }

    void displayVendor() const {
        cout << "Vendor ID: " << vendorID << endl;
        cout << "Vendor Name: " << vendorName << endl;
    }
};

class Product {
private:
    int productID;
    string productName;
    double price;

public:
    Product(int id, string name, double p) {
        productID = id;
        productName = name;
        price = p;
    }

    void displayProduct() const {
        cout << "Product ID: " << productID
             << " | Name: " << productName
             << " | Price: " << price << endl;
    }
};

class CatalogManager {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayCatalog() const {
        cout << "\n--- Product Catalog ---\n";

        for (const Product& product : products) {
            product.displayProduct();
        }
    }
};

#endif
