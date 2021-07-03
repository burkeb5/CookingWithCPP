// RestaurantOwner.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include <iostream>
#include "RestaurantOwner.h"

#include "..\Asparagus\Asparagus.h"
#include "..\Cake\Cake.h"
#include "..\Meatloaf\Meatloaf.h"


// This is an example of an exported variable
RESTAURANTOWNER_API int nRestaurantOwner=0;

// This is an example of an exported function.
RESTAURANTOWNER_API int fnRestaurantOwner(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CRestaurantOwner::CRestaurantOwner()
{
    return;
}

RESTAURANTOWNER_API RestaurantOwner::RestaurantOwner() {
    dirty_tables = 0;
    total_sales = 0;
};

void RESTAURANTOWNER_API RestaurantOwner::cleanup_tables() {
    if (dirty_tables < 0) {
        // Throw some error
    }
    while (dirty_tables > 0) {
        std::cout << "The RestaurantOwner is cleaning a table.\n";
        RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables - 1;
    }
    std::cout << "\n";
}

void RESTAURANTOWNER_API RestaurantOwner::sell_meatloaf(Customer c) {
    c.order_food("Meatloaf");
    Meatloaf::make_meatloaf();
    Meatloaf::cook_meatloaf();

    int meatloaf_price = 10;
    c.pay_for_food(meatloaf_price);
    total_sales = total_sales + meatloaf_price;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RESTAURANTOWNER_API RestaurantOwner::sell_cake(Customer c) {
    c.order_food("Cake");
    Cake::make_cake();
    Cake::cook_cake();

    int cake_price = 24;
    c.pay_for_food(cake_price);
    total_sales = total_sales + cake_price;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RESTAURANTOWNER_API RestaurantOwner::sell_asparagus(Customer c) {
    c.order_food("Asparagus");
    Asparagus::make_asparagus();
    Asparagus::cook_asparagus();

    int asparagus_price = 4;
    c.pay_for_food(asparagus_price);
    total_sales = total_sales + asparagus_price;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RESTAURANTOWNER_API RestaurantOwner::get_total_sales() {
    std::cout << "The total sales for the RestaurantOwner is " << total_sales << "!!!\n\n";
}


