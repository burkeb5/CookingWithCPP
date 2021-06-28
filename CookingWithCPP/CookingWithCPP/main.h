#pragma once
#include <string>

// This class is exported from the dll
class Core {
public:
	static void make(std::string);
	static void cook(std::string);
};

class Meatloaf {
public:
	static int price;
	static void make_meatloaf();
	static void cook_meatloaf();
};

class Cake {
public:
	static int price;
	static void make_cake();
	static void cook_cake();
};

class Asparagus {
public:
	static int price;
	static void make_asparagus();
	static void cook_asparagus();
};

class Customer {
public:
	Customer(std::string);

	std::string name;

	void order_food(std::string);
	void pay_for_food(int);
};

class RestaurantOwner {
public:
	RestaurantOwner();
	
	int lunch_prices[3];
	int standard_prices[3];

	int dirty_tables;
	int total_sales;

	void set_prices(std::string);
	void cleanup_tables();
	void sell_meatloaf(Customer);
	void sell_cake(Customer);
	void sell_asparagus(Customer);
	void get_total_sales();
};

void breakfast_rush(RestaurantOwner*);
void lunch_rush(RestaurantOwner*);
void dinner_rush(RestaurantOwner*);
