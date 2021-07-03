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

class CUSTOMER_API Customer {
public:
	Customer();

	void order_food(std::string);
	void pay_for_food(int);
};