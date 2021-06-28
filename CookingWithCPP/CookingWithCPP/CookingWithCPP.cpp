// CookingWithCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "main.h"


void Core::make(std::string dish) {
    // Can fix this if later during translation implementation
    std::cout << "Making a";
    if (dish == "Asparagus") {
        std::cout << "n";
    }
    std::cout << " " << dish << "!\n";
}

void Core::cook(std::string dish) {
    // Can fix this if later during translation implementation
    std::cout << "Cooking a";
    if (dish == "Asparagus") {
        std::cout << "n";
    }
    std::cout << " " << dish << "!\n";
}

Customer::Customer(std::string n) {
    name = n;
};

void Customer::order_food(std::string food_item) {
    std::cout << name << " is ordering " << food_item << ".\n";
};

void Customer::pay_for_food(int food_price) {
    std::cout << name << " has paid " << food_price << " dollars.\n";
};


void Meatloaf::make_meatloaf() {
    Core::make("Meatloaf");
}
void Meatloaf::cook_meatloaf() {
    Core::cook("Meatloaf");
}

void Cake::make_cake() {
    Core::make("Cake");
}
void Cake::cook_cake() {
    Core::cook("Cake");
}

void Asparagus::make_asparagus() {
    Core::make("Asparagus");
}
void Asparagus::cook_asparagus() {
    Core::cook("Asparagus");
}


RestaurantOwner::RestaurantOwner() {
    dirty_tables = 0;
    total_sales = 0;

    lunch_prices[0] = 5;
    lunch_prices[1] = 12;
    lunch_prices[2] = 2;

    standard_prices[0] = 10;
    standard_prices[1] = 24;
    standard_prices[2] = 4;
};

void RestaurantOwner::set_prices(std::string meal) {
    std::cout << "= = = = =\nThe RestaurantOwner is setting " << meal << " prices.\n= = = = =\n\n";
    if (meal == "lunch") {
        Meatloaf::price = lunch_prices[0];
        Cake::price = lunch_prices[1];
        Asparagus::price = lunch_prices[2];
    }
    else {
        Meatloaf::price = standard_prices[0];
        Cake::price = standard_prices[1];
        Asparagus::price = standard_prices[2];
    }
}

void RestaurantOwner::cleanup_tables() {
    if (dirty_tables < 0) {
        // Throw some error
    }
    while (dirty_tables > 0) {
        std::cout << "The RestaurantOwner is cleaning a table.\n";
        RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables - 1;
    }
    std::cout << "\n";
}

void RestaurantOwner::sell_meatloaf(Customer c) {
    c.order_food("Meatloaf");
    Meatloaf::make_meatloaf();
    Meatloaf::cook_meatloaf();

    c.pay_for_food(Meatloaf::price);
    total_sales = total_sales + Meatloaf::price;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RestaurantOwner::sell_cake(Customer c) {
    c.order_food("Cake");
    Cake::make_cake();
    Cake::cook_cake();

    c.pay_for_food(Cake::price);
    total_sales = total_sales + Cake::price;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RestaurantOwner::sell_asparagus(Customer c) {
    c.order_food("Asparagus");
    Asparagus::make_asparagus();
    Asparagus::cook_asparagus();

    c.pay_for_food(Asparagus::price);
    total_sales = total_sales + Asparagus::price;
    RestaurantOwner::dirty_tables = RestaurantOwner::dirty_tables + 1;

    std::cout << "\n";
}

void RestaurantOwner::get_total_sales() {
    std::cout << "The total sales for the RestaurantOwner is " << total_sales << "!!!\n\n";
}



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
int Meatloaf::price = 0;
int Asparagus::price = 0;
int Cake::price = 0;


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
