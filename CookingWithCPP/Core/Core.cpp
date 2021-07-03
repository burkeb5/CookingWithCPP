// Core.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Core.h"


// This is an example of an exported variable
CORE_API int nCore=0;

// This is an example of an exported function.
CORE_API int fnCore(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CCore::CCore()
{
    return;
}

void Core::make(std::string dish) {
    // Can fix this if later during translation implementation
    std::cout << "Making a";
    if (dish == "Asparagus") {
        std::cout << "n";
    }
    std::cout << " " << dish << "!\n";
}

void Core::cook(std::string dish) {
    // Can fix this if later during translation implementation
    std::cout << "Cooking a";
    if (dish == "Asparagus") {
        std::cout << "n";
    }
    std::cout << " " << dish << "!\n";
}