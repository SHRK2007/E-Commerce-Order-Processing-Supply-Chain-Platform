#include "ShoppingCart.h"

int main() {

    ShoppingCart cart;

    CartItem item1(101, "Laptop", 80000, 1);
    CartItem item2(102, "Mouse", 1500, 2);

    cart.addItem(item1);
    cart.addItem(item2);

    cart.displayCart();

    Checkout checkout(200);
    checkout.processCheckout(cart);

    return 0;
}
