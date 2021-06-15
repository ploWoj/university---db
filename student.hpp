#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <fstream>

class Student
{
private:
    std::string name_;
    std::string l_name_;
    std::string adress_;
    long long indexNumber_;
    long long pesel_;
    std::string gender_;

public:
    void addNewStudent();
    void dispalayBase();
    void findBySurname();
    void findByPesel();
    void sortByPesel();
    void sortbySurname();
    void removeByIndexNumber();
    Student() = default;
    Student(std::string name, std::string surname, std::string adress, long long indexNumber, long long pesel, std::string gender);
    ~Student();
    //bool validationByPESEL();
    //void writeToFIle();
    //void readFile();
};