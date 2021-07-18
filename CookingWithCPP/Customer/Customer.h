// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CUSTOMER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CUSTOMER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CUSTOMER_EXPORTS
#define CUSTOMER_API __declspec(dllexport)
#else
#define CUSTOMER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class CUSTOMER_API CCustomer {
public:
	CCustomer(void);
	// TODO: add your methods here.
};

extern CUSTOMER_API int nCustomer;

CUSTOMER_API int fnCustomer(void);

#include <string>

/**
* <summary> Contains actions that occur when a customer orders a dish from a restaurant.</summary>
* Referenced by [RestaurantOwner](@ref RestaurantOwner) with a high degree of integration.
The suggested implementation is for the [RestaurantOwner](@ref RestaurantOwner) to facilitate most of the interaction and the [Customer](@ref Customer) instance to perform smaller tasks.
*/
class CUSTOMER_API Customer {
public:
	/**
	* <summary> A customer that likely would engage with a restaurant.</summary>
	* Takes no input arguments.
	*/
	Customer();

	/**
	* <summary> Requests and order of a particular a dish of food.</summary>
	* The food name is specified as a std::string arguement.
	* This order may be satisfied by a [RestaurantOwner](@ref RestaurantOwner).
	* There is no validation to ensure that a [RestaurantOwner](@ref RestaurantOwner) will choose to satisfy this request or that they're able to serve the particular requested food item or that.
	*/
	void order_food(std::string);

	/**
	* <summary> Pay a specified dollar amount for a particular food item.</summary>
	* The dollar amount is specified as a int arguement.
	* It is suggested that a [RestaurantOwner](@ref RestaurantOwner) will tracking this payment and add an equivalent dollar amount to their total sales (if desired).
	* There is no validation to ensure that a [RestaurantOwner](@ref RestaurantOwner) will track this payment.
	*/
	void pay_for_food(int);
};