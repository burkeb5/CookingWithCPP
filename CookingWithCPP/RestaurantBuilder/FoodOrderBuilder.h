#pragma once

#include <string>
#include "IBuilder.h"

class RESTAURANTBUILDER_API FoodOrderBuilder : public IBuilder
{
public:
	enum OrderTypes
	{
		PriceFoodOrder,
		FoodNameOrder
	};

	void SetType(OrderTypes type);
	OrderTypes GetType();

	void order(int budget);
	void order(std::string foodname);

	int getUniqueID() override;
};