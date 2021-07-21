#pragma once

#include <string>
#include "IBuilder.h"

/**
* <summary> Builder class that generates new orders. Creates orders based on a set type which needs be set.</summary>
* Extends the IBuilder interface.
* 
*/
class RESTAURANTBUILDER_API FoodOrderBuilder : public IBuilder
{
public:
	/**
	* <summary> Represents types of orders available.</summary>
	*/
	enum OrderType
	{
		PriceFoodOrder,		/**< Order will based on price. */
		FoodNameOrder		/**< Order will based on name. */
	};

	/**
	* <summary> Sets the OrderType for this FoodOrderBuilder.</summary>
	* 
	*/
	void SetType(OrderType type);

	/**
	* <summary> Returns the current OrderType for this FoodOrderBuilder.</summary>
	*/
	OrderType GetType();

	/**
	* <summary> Generates a new order based-on maximizing the provided budget.</summary>
	* Utilizes the set OrderType on this FoodOrderBuilder.
	*/
	void order(int budget);

	/**
	* <summary> Generates a new minimal food order with the provided foodname.</summary>
	* Utilizes the set OrderType on this FoodOrderBuilder.
	*/
	void order(std::string foodname);

	/**
	* <summary> Returns the int unique ID for this FoodOrderBuilder.</summary>
	*/
	int getUniqueID() override;
};