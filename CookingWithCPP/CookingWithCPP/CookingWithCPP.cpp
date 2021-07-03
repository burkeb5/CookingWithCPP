// CookingWithCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "main.h" // Brings in customer
#include "..\Core\Core.h"

#include "..\Asparagus\Asparagus.h"
#include "..\Cake\Cake.h"
#include "..\Meatloaf\Meatloaf.h"


// Names are selected as the nth result from the following links: 
// https://www.bounty.com/pregnancy-and-birth/baby-names/baby-name-search/a
// https://www.bounty.com/pregnancy-and-birth/baby-names/baby-name-search/c
// https://www.bounty.com/pregnancy-and-birth/baby-names/baby-name-search/m

void breakfast_rush(RestaurantOwner* restaurant_owner) {
    restaurant_owner->set_prices("breakfast");

    Customer sweet_tooth_customer1 = Customer("Charlie");
    Customer sweet_tooth_customer2 = Customer("Chloe");
    Customer sweet_tooth_customer3 = Customer("Charlotte");

    restaurant_owner->sell_cake(sweet_tooth_customer1);
    restaurant_owner->sell_cake(sweet_tooth_customer2);
    restaurant_owner->sell_cake(sweet_tooth_customer3);

    restaurant_owner->cleanup_tables();
}

void lunch_rush(RestaurantOwner* restaurant_owner) {
    restaurant_owner->set_prices("lunch");

    Customer hungry_customer1 = Customer("Mia");
    Customer hungry_customer2 = Customer("Max");
    Customer vegetarian_customer1 = Customer("Amelia");
    Customer hungry_customer3 = Customer("Mason");
    Customer sweet_tooth_customer4 = Customer("Connor");
    Customer sweet_tooth_customer5 = Customer("Cameron");
    Customer hungry_customer4 = Customer("Millie");
    Customer hungry_customer5 = Customer("Maisie");
    Customer vegetarian_customer2 = Customer("Alfie");
    Customer sweet_tooth_customer6 = Customer("Conor");
    Customer vegetarian_customer3 = Customer("Ava");
    
    restaurant_owner->sell_meatloaf(hungry_customer1);
    restaurant_owner->sell_meatloaf(hungry_customer2);
    restaurant_owner->sell_asparagus(vegetarian_customer1);
    restaurant_owner->sell_meatloaf(hungry_customer3);
    restaurant_owner->sell_cake(sweet_tooth_customer4);
    restaurant_owner->sell_cake(sweet_tooth_customer5);
    restaurant_owner->sell_meatloaf(hungry_customer4);
    restaurant_owner->sell_meatloaf(hungry_customer5);
    restaurant_owner->sell_asparagus(vegetarian_customer2);
    restaurant_owner->sell_cake(sweet_tooth_customer6);
    restaurant_owner->sell_asparagus(vegetarian_customer3);
}

void dinner_rush(RestaurantOwner* restaurant_owner) {
    restaurant_owner->set_prices("dinner");

    Customer hungry_customer6 = Customer("Megan");
    Customer vegetarian_customer4 = Customer("Archie");
    Customer vegetarian_customer5 = Customer("Alexander");
    Customer vegetarian_customer6 = Customer("Alice");
    Customer sweet_tooth_customer7 = Customer("Caitlin");
    Customer vegetarian_customer7 = Customer("Amy");
    Customer hungry_customer7 = Customer("Mollie");

    restaurant_owner->sell_meatloaf(hungry_customer6);
    restaurant_owner->sell_asparagus(vegetarian_customer4);
    restaurant_owner->sell_asparagus(vegetarian_customer5);
    restaurant_owner->sell_asparagus(vegetarian_customer6);
    restaurant_owner->sell_cake(sweet_tooth_customer7);
    restaurant_owner->sell_asparagus(vegetarian_customer7);
    restaurant_owner->sell_meatloaf(hungry_customer7);
    
    restaurant_owner->cleanup_tables();
}


// Initialize dish prices
// If the RestaurantOwner doesn't set them it's their loss!!
//int Meatloaf::price = 0;
//int Asparagus::price = 0;
//int Cake::price = 0;


int main()
{
    RestaurantOwner local_restaurant_owner = RestaurantOwner();

    breakfast_rush(&local_restaurant_owner);
    lunch_rush(&local_restaurant_owner);
    dinner_rush(&local_restaurant_owner);

    local_restaurant_owner.get_total_sales();
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
