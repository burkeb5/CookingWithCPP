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
class RESTAURANTOBSERVER_API RestaurantObserver : public IObserver
{
	public:
		RestaurantObserver(EventTypes entryTypes);
		virtual ~RestaurantObserver();
		void Update(const std::string& message_from_subject) override;
		void RemoveMeFromTheList();
		void PrintInfo();
		bool UpdateOnEventType(EventTypes entryTypes);

	private:
		std::string message_from_subject_;
		static int static_number_;
		int number_;
		EventTypes m_eventType;
};
