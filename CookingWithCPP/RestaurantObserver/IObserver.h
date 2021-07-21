#pragma once

#include <string>
/**
* <summary> Class that all other Observers inherit.</summary>
*
* The suggested implementation is for methods to rely on support from methods in [Core](@ref Core).
*/
class RESTAURANTOBSERVER_API IObserver {
public:
	/**
	* <summary> Represents types of Observable events available. </summary>
	*/
	enum EventType
	{
		Investor,				/**< An event with an investor is observed. */
		IngredientSupplier,		/**< An event with an ingredient supplier is observed. */
		HealthInspector			/**< An event with a health inspector is observed. */
	};

	virtual ~IObserver() {};

	/**
	* <summary> Placeholder update method for all inherited Observers. </summary>
	*/
	virtual void Update(const std::string& message_from_subject) = 0;
};