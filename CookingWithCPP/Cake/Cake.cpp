// Cake.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"

#include <iostream>
#include <string>
#include "..\Core\Core.h"
#include "Cake.h"


// This is an example of an exported variable
CAKE_API int nCake=0;

// This is an example of an exported function.
CAKE_API int fnCake(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CCake::CCake()
{
    return;
}

void Cake::make_cake() {
    std::cout << "Recieved order to make Cake. Making...\n";
    Core::make("Cake");
}
void Cake::cook_cake() {
    std::cout << "Recieved order to cook Cake. Cooking...\n";
    Core::cook("Cake");
}