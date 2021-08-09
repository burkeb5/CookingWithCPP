// FoodOrder.cpp : Defines the exported functions for the DLL.
//

#pragma once

#include "framework.h"
#include "FoodOrder.h"


// This is an example of an exported variable
FOODORDER_API int nFoodOrder=0;

// This is an example of an exported function.
FOODORDER_API int fnFoodOrder(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CFoodOrder::CFoodOrder()
{
    return;
}

FOODORDER_API FoodOrder::FoodOrder() {
    food_name = "";
    budget = 10;
    max_patience = 10;

    should_fill_order = false;
};
FOODORDER_API FoodOrder::FoodOrder(std::string my_food_name, int my_budget, int my_max_patience) {
    food_name = my_food_name;
    budget = my_budget;
    max_patience = my_max_patience;

    should_fill_order = false;
};

std::string FOODORDER_API FoodOrder::getFoodName() {
    return food_name;
};

void FOODORDER_API FoodOrder::setFoodName(std::string my_food_name) {
    food_name = my_food_name;
};

int FOODORDER_API FoodOrder::getBudget() {
    return budget;
};

void FOODORDER_API FoodOrder::setBudget(int my_budget) {
    budget = my_budget;
};

int FOODORDER_API FoodOrder::getMaxPatience() {
    return max_patience;
};

void FOODORDER_API FoodOrder::setMaxPatience(int my_max_patience) {
    max_patience = my_max_patience;
};

bool FOODORDER_API FoodOrder::getShouldFillOrder() {
    return should_fill_order;
};

void FOODORDER_API FoodOrder::setShouldFillOrder(bool my_should_fill_order) {
    should_fill_order = my_should_fill_order;
};

