#pragma once

#include "University.hpp"

#include <iostream>



enum class Order {
    PrintAll = 1,
    AddStudent,
    AddEmployee,
    SortByPesel,
    SortBySurname,
    SortBySalary,
    FindByPesel,
    FindBySurname,
    RemovePerson,
    ChangeSalary,
    SaveToFile,
    ReadFromFile,
};

class Menu {
public:
    constexpr const static uint8_t typeColumnWidth = 10;
    constexpr const static uint8_t firstNameColumnWidth = 16;   
    constexpr const static uint8_t lastNameColumnWidth = 16;   
    constexpr const static uint8_t peselColumnWidth = 14;
    constexpr const static uint8_t addressColumnWidth = 42;
    constexpr const static uint8_t sexColumnWidth = 8;
    constexpr const static uint8_t indexNumberColumnWidth = 12;
    constexpr const static uint8_t salaryColumnWidth = 10;
    
    Menu(University& db) : db_ (db){};

    void mainManu();
    void printMainManu() const;
    void printPanel(const std::string message);
    void printHeader();

    void separator();
    

    std::string menuPrintAll();
    void menuAddStudent();
    void menuAddEmplyee();

    std::string menuSortByPesel();
    std::string menuSortBySurname();
    std::string menuSaveToFile();
    std::string menuLoadFromFile();
    std::string menuSortBySalary();

    std::string menuFindByPesel();
    std::string menuFindBySurname();
private:
    University& db_;
};