#pragma once 

#include <iostream>
#include <vector> 
#include "Student.hpp"

class University
{
    
public:
    std::vector<Student> university_;
        
    University(const Student&);
    ~University();
   
    void dispalayBase();
    void addStudent(std::string, std::string, std::string, size_t, std::string, std::string);
    Student findBySurname(const std::string&);
    Student findByPesel(const std::string&);
    void sortByPesel();
    void sortbyLname();
    void removeByIndexNumber();
    bool validationByPESEL(const std::string&);  
    
    //void writeToFIle();
    //void readFile();

    // pomyślec jak dodać walidację pracownika.
};

