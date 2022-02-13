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
    Menu(University& db);

private:
    University& db_;
};