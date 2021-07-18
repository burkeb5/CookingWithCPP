// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RESTAURANTOWNER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RESTAURANTOWNER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RESTAURANTOWNER_EXPORTS
#define RESTAURANTOWNER_API __declspec(dllexport)
#else
#define RESTAURANTOWNER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class RESTAURANTOWNER_API CRestaurantOwner {
public:
	CRestaurantOwner(void);
	// TODO: add your methods here.
};

extern RESTAURANTOWNER_API int nRestaurantOwner;

RESTAURANTOWNER_API int fnRestaurantOwner(void);

#include <string>
#include "..\Customer\Customer.h"

/**
* <summary> Contains all methods for actions that occur by the owner of a restaurant for smooth operation.</summary>
* References [Customer](@ref Customer) with a high degree of integration.
The suggested implementation is to facilitate most of the interaction with a [Customer](@ref Customer) instance.
Contains additional (standalone) methods for general restaurant upkeep.
*/
class RESTAURANTOWNER_API RestaurantOwner {
public:

	/**
	* <summary> Owner of a restaurant participating in general restaurant operations and upkeep.</summary>
	* Takes no input arguments.
	*/
	RestaurantOwner();

	/**
	* <summary> The total number of tables that the owner is tracking as dirty. </summary>
	* Suggested implentation involves incrementing this value after selling a food item to a [Customer](@ref Customer).
	* Additonally, suggested implementation would be that this value never falls below 0, but this method will do nothing in the event this happens.
	*/
	int dirty_tables;

	/**
	* <summary> The total profit that an owner has recieved from customers. </summary>
	* There is no suggested implementation for resetting this value, and it can be used to track daily, weekly, monthy, etc total sales depending on need.
	*/
	int total_sales;


	/**
	* <summary> Clean a total of dirty tables equal to the number that the owner is tracking. </summary>
	* Determines the number of dirty tables from [RestaurantOwner.dirty_tables](@ref RestaurantOwner.dirty_tables).
	*/
	void cleanup_tables();

	/**
	* <summary> Sell a dish of meatloaf to a specified customer. </summary>
	* This method takes a [Customer](@ref Customer) instance as an argument to keep track of the customer that has ordered the meal.
	* Suggested implementation has the owner keep track of when this method is called and update [RestaurantOwner.dirty_tables](@ref RestaurantOwner.dirty_tables) and [RestaurantOwner.total_sales](@ref RestaurantOwner.total_sales) in response.
	*/
	void sell_meatloaf(Customer);

	/**
	* <summary> Sell a cake to a specified customer. </summary>
	* This method takes a [Customer](@ref Customer) instance as an argument to keep track of the customer that has ordered the meal.
	* Suggested implementation has the owner keep track of when this method is called and update [RestaurantOwner.dirty_tables](@ref RestaurantOwner.dirty_tables) and [RestaurantOwner.total_sales](@ref RestaurantOwner.total_sales) in response.
	*/
	void sell_cake(Customer);

	/**
	* <summary> Sell a dish of asparagus to a specified customer. </summary>
	* This method takes a [Customer](@ref Customer) instance as an argument to keep track of the customer that has ordered the meal.
	* Suggested implementation has the owner keep track of when this method is called and update [RestaurantOwner.dirty_tables](@ref RestaurantOwner.dirty_tables) and [RestaurantOwner.total_sales](@ref RestaurantOwner.total_sales) in response.
	*/
	void sell_asparagus(Customer);

	/**
	* <summary> Get the total sales amount that the owner is tracking. </summary>
	* Determines the number of total sales from [RestaurantOwner.total_sales](@ref RestaurantOwner.total_sales).
	*/
	void get_total_sales();
};