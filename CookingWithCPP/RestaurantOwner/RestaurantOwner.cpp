// RestaurantOwner.cpp : Defines the exported functions for the DLL.
//
#pragma once
#include "framework.h"
#include <iostream>
#include <string>
#include "RestaurantOwner.h"

#include "..\Asparagus\Asparagus.h"
#include "..\Cake\Cake.h"
#include "..\Meatloaf\Meatloaf.h"

#include "..\FoodOrder\FoodOrder.h"


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

FoodOrder RESTAURANTOWNER_API RestaurantOwner::sell_generic_food(Customer c) {

    FoodOrder ord = FoodOrder::FoodOrder(c.getFoodName(), c.getBudget(), c.getMaxPatience());

    if (c.getFoodName() == "asparagus") {
        ord.setFoodName("asparagus");
    }
    else if (c.getFoodName() == "cake") {
        ord.setFoodName("cake");
    }
    else if (c.getFoodName() == "meatloaf") {
        ord.setFoodName("meatloaf");
    }
    else {
        ord.setFoodName("none");
    }

    if (ord.getFoodName() == "none") {
        if (c.getBudget() >= 24) {
            ord.setFoodName("cake");
        }
        else if (c.getBudget() >= 10) {
            ord.setFoodName("meatloaf");
        }
        else if (c.getBudget() >= 4) {
            ord.setFoodName("asparagus");
        }
        else {
            ord.setFoodName("none");
        }
    }

    if (ord.getFoodName() == "asparagus" && ord.getBudget() >= 4 && ord.getMaxPatience() >= 10) {
        sell_asparagus(c);
        ord.setShouldFillOrder(true);
    }
    else if (ord.getFoodName() == "cake" && ord.getBudget() >= 24 && ord.getMaxPatience() >= 25) {
        sell_cake(c);
        ord.setShouldFillOrder(true);
    }
    else if (ord.getFoodName() == "meatloaf" && ord.getBudget() >= 10 && ord.getMaxPatience() >= 10) {
        sell_meatloaf(c);
        ord.setShouldFillOrder(true);
    }
    else {
        std::cout << "The customer had an issue with one of the following:\n1) Picking a type of food\n2) Being able to pay for the meal\n3) Not having enough patience to wait for the meal.\nThe customer left without getting their order satisfied.\n\n";
        ord.setShouldFillOrder(false);
    }

    return ord;

}

void RESTAURANTOWNER_API RestaurantOwner::get_total_sales() {
    std::cout << "The total sales for the RestaurantOwner is " << total_sales << "!!!\n\n";
}


