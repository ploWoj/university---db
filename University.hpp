#pragma once

#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Employee.hpp"
#include "Student.hpp"

constexpr auto peselSize = 11u;

class University {
    std::vector<std::unique_ptr<Person>> university_ = {};

   public:
    University();
    ~University() = default;

    const std::vector<std::unique_ptr<Person>>& getVector() const;
    void displayBase();
    void addStudent();
    void addStudent(std::string, std::string, std::string, std::string, std::string, size_t);
    void addEmployee();
    void addEmployee(std::string, std::string, std::string, std::string, std::string, double);
    Student* findBySurname(const std::string&);
    Student* findByPesel(const std::string&);
    void sortByPesel();
    void sortBySurname();
    void sortBySalary();
    bool validationByPesel(const std::string&);
    void exportDatabase(const std::string&);
    // void importDatabase(const std::string&);
    void removeByIndexNumber(size_t);
    void modifySalary(double, const std::string&);
};
