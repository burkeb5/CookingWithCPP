// UITestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UITestApp.h"
#include "..\CookingWithCPP\CookingWithCPP.h"


void TestClass::test_meatloaf() {
    Customer test_customer = Customer();
    RestaurantOwner test_restaurant_owner = RestaurantOwner();
    (&test_restaurant_owner)->sell_meatloaf(test_customer);
}

void TestClass::test_cake() {
    Customer test_customer = Customer();
    RestaurantOwner test_restaurant_owner = RestaurantOwner();
    (&test_restaurant_owner)->sell_cake(test_customer);
}

void TestClass::test_asparagus() {
    Customer test_customer = Customer();
    RestaurantOwner test_restaurant_owner = RestaurantOwner();
    (&test_restaurant_owner)->sell_asparagus(test_customer);
}


void launch_ui() {
    std::cout << "====================\n" << "Launching CookingWithCPP UI.\n" << "====================\n\n";
}

void cleanup_terminate_ui() {
    std::cout << "====================\n" << "Cleaning Up CookingWithCPP UI.\n" << "Shutting Down CookingWithCpp UI.\n" << "====================\n\n";
}


int main()
{
    launch_ui();

    // Read from standard input
    std::string ui_input;
    std::cout << "Enter food to test\n" << "Options: [\"meatloaf\",\"cake\",\"asparagus\"]\n";
    std::getline(std::cin, ui_input);
    std::cout << "\n";
    
    if (ui_input == "meatloaf") {
        TestClass::test_meatloaf();
    }
    else if (ui_input == "cake") {
        TestClass::test_cake();
    }
    else if (ui_input == "asparagus") {
        TestClass::test_asparagus();
    }
    else {
        std::cout << "Unable process the entered value.\nExiting...\n\n";
        // Throw error
    }
    
    cleanup_terminate_ui();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
