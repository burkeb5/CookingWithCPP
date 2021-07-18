#pragma once

#include <string>
class RESTAURANTOBSERVER_API IObserver {
public:
	enum EventTypes
	{
		Investor,
		IngredientSupplier,
		HealthInspector
	};

	virtual ~IObserver() {};
	virtual void Update(const std::string& message_from_subject) = 0;
};