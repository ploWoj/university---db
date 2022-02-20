#include "Employee.hpp"

Employee::Employee(std::string name,
                   std::string surname,
                   std::string address,
                   std::string pesel,
                   std::string gender,
                   double salary)
    : Person::Person(name, surname, address, pesel, gender), salary_(salary) {}

void Employee::setSalary(const double& salary) {
  salary_ = salary;
}

double Employee::getSalary() const {
  return salary_;
}

void Employee::display() {
  std::cout << "Employee: " << name_ << ", " << surname_ << ", " << address_
            << ", " << pesel_ << ", " << gender_ << ", " << salary_ << '\n';
}
