#include "Employee.hpp"
 
Employee::Employee(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t salary)
     : Person::Person(name, surname, address, pesel, gender)
     , salary_(salary)
 {}
 
 Employee::~Employee() {}
 
 void Employee::setSalary(const size_t salary) {
     salary_ = salary;
 }
 
 size_t Employee::getSalary() const {
     return salary_;
 }

