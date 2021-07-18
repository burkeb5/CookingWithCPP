// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CAKE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CAKE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CAKE_EXPORTS
#define CAKE_API __declspec(dllexport)
#else
#define CAKE_API __declspec(dllimport)
#endif

// This class is exported from the dll
class CAKE_API CCake {
public:
	CCake(void);
	// TODO: add your methods here.
};

extern CAKE_API int nCake;

CAKE_API int fnCake(void);

/**
* <summary> Contains all static methods for actions that occur between ordering and serving a cake.</summary>
* The suggested implementation is for methods to rely on support from methods in [Core](@ref Core).
* Note that all methods are static which means there is no need for a Cake() constructor.
*/
class CAKE_API Cake {
public:

	/**
	* <summary> Makes/Prepares an (uncooked) cake.</summary>
	* Relies on the Core method [Core.make()](@ref Core.make()).
	*/
	static void make_cake();

	/**
	* <summary> Cooks a cake and prepares it for serving.</summary>
	* Relies on the Core method [Core.cook()](@ref Core.cook()).
	*/
	static void cook_cake();
};