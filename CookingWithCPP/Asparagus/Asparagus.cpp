// Asparagus.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"

#include <iostream>
#include <string>
#include "..\Core\Core.h"
#include "Asparagus.h"


// This is an example of an exported variable
ASPARAGUS_API int nAsparagus=0;

// This is an example of an exported function.
ASPARAGUS_API int fnAsparagus(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CAsparagus::CAsparagus()
{
    return;
}

void ASPARAGUS_API Asparagus::make_asparagus() {
    std::cout << "Recieved order to make Asparagus. Making...\n";
    Core::make("Asparagus");
}
void ASPARAGUS_API Asparagus::cook_asparagus() {
    std::cout << "Recieved order to cook Asparagus. Cooking...\n";
    Core::cook("Asparagus");
}