// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ASPARAGUS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ASPARAGUS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ASPARAGUS_EXPORTS
#define ASPARAGUS_API __declspec(dllexport)
#else
#define ASPARAGUS_API __declspec(dllimport)
#endif

// This class is exported from the dll
class ASPARAGUS_API CAsparagus {
public:
	CAsparagus(void);
	// TODO: add your methods here.
};

extern ASPARAGUS_API int nAsparagus;

ASPARAGUS_API int fnAsparagus(void);

// Mine

class ASPARAGUS_API Asparagus {
public:
	static int price;
	static void make_asparagus();
	static void cook_asparagus();
};