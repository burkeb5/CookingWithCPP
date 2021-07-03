// Customer.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"

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

CUSTOMER_API Customer::Customer(std::string n) {
//    name = n;
};

void CUSTOMER_API Customer::order_food(std::string food_item) {
    //std::cout << name << " is ordering " << food_item << ".\n";
    std::cout << "A customer is ordering " << food_item << ".\n";
};


void CUSTOMER_API Customer::pay_for_food(int food_price) {
    //std::cout << name << " has paid " << food_price << " dollars.\n";
    std::cout << "A customer has paid " << food_price << " dollars.\n";
};
