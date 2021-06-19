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
    size_t indexNumber_;
    std::string pesel_;
    std::string gender_;

public:
    void setName(const std::string&);
    void setLname(const std::string&);
    void setAdress(const std::string&);
    void setIndex(const size_t);
    void setPesel(const std::string&);
    void setGender(const std::string&);
    
    std::string getName() const;
    std::string getLname() const;
    std::string getAdress() const;
    size_t getIndex() const;
    std::string getPesel() const;
    std::string getGender() const;
    
    Student() = default;
    Student(std::string name, std::string surname, std::string adress, size_t indexNumber, std::string pesel, std::string gender);
    ~Student();
};
