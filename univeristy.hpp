#pragma once 

#include <iostream>
#include <vector> 
#include "student.hpp"

class University
{
    
public:
    std::vector<Student> university_;
        
    University(const Student&);
    ~University();
   
    void dispalayBase();
    void addStudent();
    Student findBySurname(const std::string&);
    Student findByPesel(const long long&);
    void sortByPesel();
    void sortbyLname();
    void removeByIndexNumber();
  
    //bool validationByPESEL();
    //void writeToFIle();
    //void readFile();

    // pomyślec jak dodać walidację pracownika.
};

