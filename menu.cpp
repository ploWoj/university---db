#include "menu.hpp"
#include <iomanip>

void Menu::printMainManu() const {
    uint8_t itemSize = 23;
    std::cout << std::left << std::setfill(' ');
    std::cout << std::setw(itemSize) << "[ 1] Print DB"
              << std::setw(itemSize) << "[ 4] Change salary"
              << std::setw(itemSize) << "[ 7] Sort by salary"
              << std::setw(itemSize) << "[10] Generate data"
              << std::setw(itemSize) << "[13] Clear all" << '\n'
              << std::setw(itemSize) << "[ 2] Add Person"
              << std::setw(itemSize) << "[ 5] Sort by last name"
              << std::setw(itemSize) << "[ 8] Find last name"
              << std::setw(itemSize) << "[11] Save to file"
              << std::setw(itemSize) << "[ 0] Quit" << '\n'
              << std::setw(itemSize) << "[ 3] Remove Person"
              << std::setw(itemSize) << "[ 6] Sort by PESEL"
              << std::setw(itemSize) << "[ 9] Find PESEL"
              << std::setw(itemSize) << "[12] Read from file" << '\n';
}