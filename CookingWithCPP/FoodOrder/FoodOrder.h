#pragma once
// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the FOODORDER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// FOODORDER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FOODORDER_EXPORTS
#define FOODORDER_API __declspec(dllexport)
#else
#define FOODORDER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class FOODORDER_API CFoodOrder {
public:
	CFoodOrder(void);
	// TODO: add your methods here.
};

extern FOODORDER_API int nFoodOrder;

FOODORDER_API int fnFoodOrder(void);

#include <string>

class FOODORDER_API FoodOrder {
public:
	std::string food_name;
	int budget;
	int max_patience;

	bool should_fill_order;

	FoodOrder();
	FoodOrder(std::string, int, int);

	std::string getFoodName();
	void setFoodName(std::string);

	int getBudget();
	void setBudget(int);

	int getMaxPatience();
	void setMaxPatience(int);

	bool getShouldFillOrder();
	void setShouldFillOrder(bool);

};
