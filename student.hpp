#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name_;
    std::string l_name_;
    std::string adress_;
    long long indexNumber_;
    long long pesel_;
    std::string gender_;

public:
    void setName(const std::string&);
    void setLname(const std::string&);
    void setAdress(const std::string&);
    void setIndex(const long long&);
    void setPesel(const long long&);
    void setGender(const std::string&);
    
    std::string getName() const;
    std::string getLname() const;
    std::string getAdress() const;
    long long getIndex() const;
    long long getPesel() const;
    std::string getGender() const;
    
    Student() = default;
    Student(std::string name, std::string surname, std::string adress, long long indexNumber, long long pesel, std::string gender);
    ~Student();
};