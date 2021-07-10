#pragma once

#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Student.hpp"
#include "Employee.hpp"

constexpr auto peselSize = 11u;

class University {
    std::vector<std::unique_ptr<Person>> university_ = {};

public:
    University();
    ~University() = default;

    void displayBase();
    void addStudent();
    void addStudent(std::string, std::string, std::string, std::string, std::string, size_t);
    void addEmployee();
    void addEmployee(std::string, std::string, std::string, std::string, std::string, double);
    void sortByPesel();
    void sortBySurname();
    void removeByIndexNumber(size_t);

};
