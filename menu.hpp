#pragma once

#include "University.hpp"

#include <iostream>

enum class Order {
    AddStudent,
    AddEmployee,
    RemovePerson,
    ChangeSalary,
    SortByPesel,
    SortBySurname,
    SortBySalary,
    FindByPesel,
    FindBySurname,
    SaveToFile,
    ReadFromFile,
    PrintAll,
};

class Menu {
public:
    Menu(University& db) : db_ (db){};

    void printMainManu() const;
    void printHeader();
    

private:
    University& db_;
};