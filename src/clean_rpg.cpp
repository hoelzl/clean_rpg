// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include <clean_rpg_config.hpp>
#include <iostream>

int main()
{
    std::cout << "Clean RPG Version "
              << CLEAN_RPG_VERSION_MAJOR << "."
              << CLEAN_RPG_VERSION_MINOR << "."
              << CLEAN_RPG_VERSION_PATCH << " " 
              << "is up and running!" << std::endl;
    return 0;
}
