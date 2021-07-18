// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CORE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CORE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CORE_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

// This class is exported from the dll
class CORE_API CCore {
public:
	CCore(void);
	// TODO: add your methods here.
};

extern CORE_API int nCore;

CORE_API int fnCore(void);

#include <string>

/**
* <summary> Contains all static methods for some of the common actions that would be performed while running a restaurant.</summary>
* Note that all methods are static which means there is no need for a Core() constructor.
*/
class CORE_API Core {
public:

	/**
	* <summary> Makes/Prepares a dish of a particular type of food. Applies to a wide range of food items. </summary>
	*/
	static void make(std::string);

	/**
	* <summary> Cooks a dish of a particular type of food and prepares it for serving. Applies to a wide range of food items. </summary>
	*/
	static void cook(std::string);
};
