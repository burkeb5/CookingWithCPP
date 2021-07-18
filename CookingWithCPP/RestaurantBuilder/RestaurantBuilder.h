// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the RESTAURANTBUILDER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// RESTAURANTBUILDER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef RESTAURANTBUILDER_EXPORTS
#define RESTAURANTBUILDER_API __declspec(dllexport)
#else
#define RESTAURANTBUILDER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class RESTAURANTBUILDER_API CRestaurantBuilder {
public:
	CRestaurantBuilder(void);
	// TODO: add your methods here.
};

extern RESTAURANTBUILDER_API int nRestaurantBuilder;

RESTAURANTBUILDER_API int fnRestaurantBuilder(void);

