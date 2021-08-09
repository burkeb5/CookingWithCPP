// Customer.cpp : Defines the exported functions for the DLL.
//

#pragma once
#include "framework.h"
#include <string>
#include <iostream>
#include "Customer.h"


// This is an example of an exported variable
CUSTOMER_API int nCustomer=0;

// This is an example of an exported function.
CUSTOMER_API int fnCustomer(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CCustomer::CCustomer()
{
    return;
}

CUSTOMER_API Customer::Customer() {
    food_name = "";
    budget = 10;
    max_patience = 10;
};

void CUSTOMER_API Customer::order_food(std::string food_item) {
    std::cout << "A customer is ordering " << food_item << ".\n";
};

void CUSTOMER_API Customer::pay_for_food(int food_price) {
    std::cout << "A customer has paid " << food_price << " dollars.\n";
};

std::string CUSTOMER_API Customer::getFoodName() {
    return food_name;
};

void CUSTOMER_API Customer::setFoodName(std::string my_food_name) {
    food_name = my_food_name;
};

int CUSTOMER_API Customer::getBudget() {
    return budget;
};

void CUSTOMER_API Customer::setBudget(int my_budget) {
    budget = my_budget;
};

int CUSTOMER_API Customer::getMaxPatience() {
    return max_patience;
};

void CUSTOMER_API Customer::setMaxPatience(int my_max_patience) {
    max_patience = my_max_patience;
};

