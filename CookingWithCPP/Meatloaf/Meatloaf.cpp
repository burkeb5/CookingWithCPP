// Meatloaf.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"

#include <iostream>
#include <string>
#include "..\Core\Core.h"
#include "Meatloaf.h"


// This is an example of an exported variable
MEATLOAF_API int nMeatloaf=0;

// This is an example of an exported function.
MEATLOAF_API int fnMeatloaf(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CMeatloaf::CMeatloaf()
{
    return;
}

void MEATLOAF_API Meatloaf::make_meatloaf() {
    std::cout << "Recieved order to make Meatloaf. Making...\n";
    Core::make("Meatloaf");
}
void MEATLOAF_API Meatloaf::cook_meatloaf() {
    std::cout << "Recieved order to cook Meatloaf. Cooking...\n";
    Core::cook("Meatloaf");
}