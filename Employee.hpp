#pragma once

#include "Person.hpp"

class Employee : public Person {
private: 
    size_t salary_{0};

public:
    void setSalary(const size_t);
 
    size_t getSalary() const;
 
    Employee() = default;
    Employee(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t salary);
    ~Employee();
};
