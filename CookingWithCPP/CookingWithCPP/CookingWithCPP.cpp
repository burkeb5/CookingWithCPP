// CookingWithCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/Locale.hpp>
#include "CookingWithCPP.h"
#include "..\Core\Core.h"

#include "..\Asparagus\Asparagus.h"
#include "..\Cake\Cake.h"
#include "..\Meatloaf\Meatloaf.h"

using namespace boost::locale;
using namespace std;


void breakfast_rush(RestaurantOwner* restaurant_owner) {

    Customer sweet_tooth_customer1 = Customer();
    Customer sweet_tooth_customer2 = Customer();
    Customer sweet_tooth_customer3 = Customer();

    restaurant_owner->sell_cake(sweet_tooth_customer1);
    restaurant_owner->sell_cake(sweet_tooth_customer2);
    restaurant_owner->sell_cake(sweet_tooth_customer3);

    restaurant_owner->cleanup_tables();
}

void lunch_rush(RestaurantOwner* restaurant_owner) {

    Customer hungry_customer1 = Customer();
    Customer hungry_customer2 = Customer();
    Customer vegetarian_customer1 = Customer();
    Customer hungry_customer3 = Customer();
    Customer sweet_tooth_customer4 = Customer();
    Customer sweet_tooth_customer5 = Customer();
    Customer hungry_customer4 = Customer();
    Customer hungry_customer5 = Customer();
    Customer vegetarian_customer2 = Customer();
    Customer sweet_tooth_customer6 = Customer();
    Customer vegetarian_customer3 = Customer();
    
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

    Customer hungry_customer6 = Customer();
    Customer vegetarian_customer4 = Customer();
    Customer vegetarian_customer5 = Customer();
    Customer vegetarian_customer6 = Customer();
    Customer sweet_tooth_customer7 = Customer();
    Customer vegetarian_customer7 = Customer();
    Customer hungry_customer7 = Customer();

    restaurant_owner->sell_meatloaf(hungry_customer6);
    restaurant_owner->sell_asparagus(vegetarian_customer4);
    restaurant_owner->sell_asparagus(vegetarian_customer5);
    restaurant_owner->sell_asparagus(vegetarian_customer6);
    restaurant_owner->sell_cake(sweet_tooth_customer7);
    restaurant_owner->sell_asparagus(vegetarian_customer7);
    restaurant_owner->sell_meatloaf(hungry_customer7);
    
    restaurant_owner->cleanup_tables();
}


int main()
{
    generator gen;
    gen.add_messages_path("C:\\Users\\Vic\\Documents\\code_uc\\soft_arch\\midterm\\CookingWithCPP\\CookingWithCPP\\translation\\es");
    gen.add_messages_domain("hello");
    // Create locale generator, swap appropriately 
    locale::global(gen("es_ES.UTF-8"));
    cout << translate("Enter food to test") << std::endl;
    //locale::global(gen("en_EN.UTF - 8"));

    cout.imbue(locale());
    // "" - the system default locale, set
    // it globally

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
