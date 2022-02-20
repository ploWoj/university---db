#pragma once

#include "Person.hpp"

class Employee : public Person {
private:
    double salary_ { 0.0 };

public:
    void setSalary(const double&);
    double getSalary() const override;
    void display() override;

    Employee() = default;
    Employee(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, double salary);
    ~Employee() override = default;
};
