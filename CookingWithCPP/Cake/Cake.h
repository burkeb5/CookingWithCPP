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

class CAKE_API Cake {
public:
	static void make_cake();
	static void cook_cake();
};