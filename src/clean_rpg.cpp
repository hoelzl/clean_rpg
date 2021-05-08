#include <iostream>
#include <clean_rpg_config.h>

int main()
{
    std::cout << "Clean RPG Version "
              << CLEAN_RPG_VERSION_MAJOR << "."
              << CLEAN_RPG_VERSION_MINOR << "."
              << CLEAN_RPG_VERSION_PATCH << " " 
              << "is up and running!" << std::endl;
    return 0;
}
