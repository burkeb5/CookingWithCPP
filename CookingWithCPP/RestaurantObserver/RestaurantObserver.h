// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RESTAURANTOBSERVER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RESTAURANTOBSERVER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RESTAURANTOBSERVER_EXPORTS
#define RESTAURANTOBSERVER_API __declspec(dllexport)
#else
#define RESTAURANTOBSERVER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class RESTAURANTOBSERVER_API CRestaurantObserver {
public:
	CRestaurantObserver(void);
	// TODO: add your methods here.
};

extern RESTAURANTOBSERVER_API int nRestaurantObserver;

RESTAURANTOBSERVER_API int fnRestaurantObserver(void);

#include <string>
#include "IObserver.h"
/**
* <summary> Observer class for Restaurants.</summary>
*
* The suggested implementation is for methods to rely on support from methods in [Core](@ref Core).
* Inherits from the IObserver class.
*/
class RESTAURANTOBSERVER_API RestaurantObserver : public IObserver
{
	public:
		/**
		* <summary> Creates a new RestaurantObserver.</summary>
		*
		* The RestaurantObserver is configured to key off of the given EventType entryTypes.
		* To configure this RestaurantObserver to key off of another type, the UpdateOnEventType() method is available.
		*/
		RestaurantObserver(EventType entryTypes);
		virtual ~RestaurantObserver();

		/**
		* <summary> Update method for a RestaurantObserver.</summary>
		*
		* Keys off of the EventType specified at creation of this object.
		* Whenever a subject issues a linked-up Notify() call, this method is executed. The message and time are logged.
		*/
		void Update(const std::string& message_from_subject) override;

		/**
		* <summary> Removes this observer from all linked subjects and "unsubscribes" to all events.</summary>
		*/
		void RemoveMeFromTheList();

		/**
		* <summary> Prints Info about this Observer including configuration links and a log of past updates.</summary>
		*
		* Sends output to STDOUT. 
		*/
		void PrintInfo();

		/**
		* <summary> Update method for a RestaurantObserver that acts for specific EventType not specified for this RestaurantObserver.</summary>
		*
		* Whenever a subject issues a linked-up Notify() call, this method is executed. This only applies for the given EventType.
		*/
		bool UpdateOnEventType(EventType entryTypes);

	private:
		std::string message_from_subject_;
		static int static_number_;
		int number_;
		EventType m_eventType;
};
