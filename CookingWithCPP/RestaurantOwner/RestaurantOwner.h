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

class RESTAURANTOWNER_API RestaurantOwner {
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