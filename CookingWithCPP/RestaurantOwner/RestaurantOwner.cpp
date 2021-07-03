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

    lunch_prices[0] = 5;
    lunch_prices[1] = 12;
    lunch_prices[2] = 2;

    standard_prices[0] = 10;
    standard_prices[1] = 24;
    standard_prices[2] = 4;
};

void RESTAURANTOWNER_API RestaurantOwner::set_prices(std::string meal) {
    std::cout << "= = = = =\nThe RestaurantOwner is setting " << meal << " prices.\n= = = = =\n\n";
    if (meal == "lunch") {
        //Meatloaf::price = lunch_prices[0];
        //Cake::price = lunch_prices[1];
        //Asparagus::price = lunch_prices[2];
    }
    else {
        //Meatloaf::price = standard_prices[0];
        //Cake::price = standard_prices[1];
        //Asparagus::price = standard_prices[2];
    }
}

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

    //c.pay_for_food(Meatloaf::price);
    //total_sales = total_sales + Meatloaf::price;
    c.pay_for_food(1);
    total_sales = total_sales + 1;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RESTAURANTOWNER_API RestaurantOwner::sell_cake(Customer c) {
    c.order_food("Cake");
    Cake::make_cake();
    Cake::cook_cake();

    //c.pay_for_food(Cake::price);
    //total_sales = total_sales + Cake::price;
    c.pay_for_food(1);
    total_sales = total_sales + 1;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RESTAURANTOWNER_API RestaurantOwner::sell_asparagus(Customer c) {
    c.order_food("Asparagus");
    Asparagus::make_asparagus();
    Asparagus::cook_asparagus();

    //c.pay_for_food(Asparagus::price);
    //total_sales = total_sales + Asparagus::price;
    c.pay_for_food(1);
    total_sales = total_sales + 1;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RESTAURANTOWNER_API RestaurantOwner::get_total_sales() {
    std::cout << "The total sales for the RestaurantOwner is " << total_sales << "!!!\n\n";
}


