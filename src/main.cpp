
#include <iostream>

#include "VendorCatalog.h"
#include "ShoppingCart.h"
#include "Fulfillment.h"
#include "Notifications.h"
#include "ReturnsRefunds.h"

using namespace std;

int main() {

    cout << "====================================\n";
    cout << " E-COMMERCE ORDER PROCESSING SYSTEM\n";
    cout << "====================================\n";

    // 1. Vendor and Catalog
    cout << "\n===== VENDOR & CATALOG =====\n";

    Vendor vendor(1, "Tech Store");
    vendor.displayVendor();

    CatalogManager catalog;

    Product product1(101, "Laptop", 80000);
    Product product2(102, "Mouse", 1500);

    catalog.addProduct(product1);
    catalog.addProduct(product2);
    catalog.displayCatalog();

    // 2. Cart and Checkout
    cout << "\n===== CART & CHECKOUT =====\n";

    ShoppingCart cart;

    CartItem item1(101, "Laptop", 80000, 1);
    CartItem item2(102, "Mouse", 1500, 2);

    cart.addItem(item1);
    cart.addItem(item2);
    cart.displayCart();

    Checkout checkout(200);
    checkout.processCheckout(cart);

    // 3. Fulfillment and Logistics
    cout << "\n===== FULFILLMENT & LOGISTICS =====\n";

    Order order(501, "Ali", "Lahore");
    order.displayOrder();

    double weight = 5;

    AirFreight air;
    SeaFreight sea;
    RoadFreight road;

    ShippingCalculator* methods[] = {
        &air, &sea, &road
    };

    for (ShippingCalculator* method : methods) {
        cout << method->getShippingMethod()
             << " Cost: "
             << method->calculateShippingCost(weight)
             << endl;
    }

    // 4. Notifications
    cout << "\n===== NOTIFICATIONS =====\n";

    EmailNotification email;
    SMSNotification sms;
    PushNotification push;

    email.sendNotification("Your order has been placed.");
    sms.sendNotification("Your order is being shipped.");
    push.sendNotification("Your order is on its way.");

    // 5. Returns and Refunds
    cout << "\n===== RETURNS & REFUNDS =====\n";

    ReturnRequest request(701, "Mouse", 1500);
    request.displayRequest();

    DigitalWallet wallet(500);

    RefundProcessor refund;
    refund.processRefund(request, wallet);
    wallet.displayBalance();

    cout << "\n====================================\n";
    cout << " SYSTEM DEMONSTRATION COMPLETED\n";
    cout << "====================================\n";

    return 0;
}

