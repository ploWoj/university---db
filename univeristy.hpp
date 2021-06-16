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
    void addStudent(std::string name, std::string l_name, std::string adress, long long indexNumber, long long pesel, std::string gender);
    Student findBySurname(const std::string&);
    Student findByPesel(const long long&);
    void sortByPesel(const long long&);
    void sortbyLname(const std::string&);
    void removeByIndexNumber();
  
    //bool validationByPESEL();
    //void writeToFIle();
    //void readFile();

    // pomyślec jak dodać walidację pracownika.
};

