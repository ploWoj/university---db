#pragma once

#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Student.hpp"

class University {
    std::vector<std::unique_ptr<Student>> university_;

   public:
    University(const Student&);
    ~University();

    void displayStudent(const Student*);
    void displayBase();
    void addStudent(std::string, std::string, std::string, size_t, std::string, std::string);
    Student* findBySurname(const std::string&);
    Student* findByPesel(const std::string&);
    void sortByPesel();
    void sortBySurname();
    void removeByIndexNumber();
    bool validationByPesel(const std::string&);
    void exportDatabase();
    void importDatabase();
    void deletedByIndexNumber();
};
