#pragma once

#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Student.hpp"

constexpr auto peselSize = 11u;

class University {
    std::vector<std::unique_ptr<Student>> university_;

public:
    University();
    University(const Student&);
    ~University();

    void displayStudent(const Student*);
    void displayBase();
    void addStudent();
    void addStudent(std::string, std::string, std::string, std::string, std::string, size_t);
    Student* findBySurname(const std::string&);
    Student* findByPesel(const std::string&);
    void sortByPesel();
    void sortBySurname();
    void removeByIndexNumber();
    bool validationByPesel(const std::string&);
    void exportDatabase(std::string);
    void importDatabase(std::string);
    void deletedByIndexNumber(size_t);
};
