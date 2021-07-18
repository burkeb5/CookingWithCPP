// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MEATLOAF_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MEATLOAF_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MEATLOAF_EXPORTS
#define MEATLOAF_API __declspec(dllexport)
#else
#define MEATLOAF_API __declspec(dllimport)
#endif

// This class is exported from the dll
class MEATLOAF_API CMeatloaf {
public:
	CMeatloaf(void);
	// TODO: add your methods here.
};

extern MEATLOAF_API int nMeatloaf;

MEATLOAF_API int fnMeatloaf(void);

/**
* <summary> Contains all static methods for actions that occur between ordering and serving a dish of meatloaf.</summary>
* The suggested implementation is for methods to rely on support from methods in [Core](@ref Core).
* Note that all methods are static which means there is no need for a Meatloaf() constructor.
*/
class MEATLOAF_API Meatloaf {
public:

	/**
	* <summary> Makes/Prepares a dish of (uncooked) meatloaf.</summary>
	* Relies on the Core method [Core.make()](@ref Core.make()).
	*/
	static void make_meatloaf();

	/**
	* <summary> Cooks a dish of meatloaf and prepares it for serving.</summary>
	* Relies on the Core method [Core.cook()](@ref Core.cook()).
	*/
	static void cook_meatloaf();
};