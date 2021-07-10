#include <algorithm>
#include "University.hpp"
#include "Student.hpp"
#include "Person.hpp"

University::University() {
    university_.reserve(10);
}

void University::displayBase() {
    for (const auto& person : university_) {
            person->display();
    }
}

void University::addStudent() {
    Student newStudent;
    auto newStudentUP = std::make_unique<Student>(newStudent);
    university_.push_back(std::move(newStudentUP));
}

void University::addStudent(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t indexNumber) {
    Student student(name, surname, address, pesel, gender,indexNumber);
    auto studentUP = std::make_unique<Student>(student);
    university_.push_back(std::move(studentUP));
}

 void University::addEmployee() {
     Employee newEmployee;
     auto newEmployeeUP = std::make_unique<Employee>(newEmployee);
     university_.push_back(std::move(newEmployeeUP));
 }
 
void University::addEmployee(std::string name, std::string surname, std::string address, std::string pesel, std::string gender,    double salary) {
     Employee employee(name, surname, address, pesel, gender, salary);
     auto employeeUP = std::make_unique<Employee>(employee);
     university_.push_back(std::move(employeeUP));
}

void University::sortByPesel() {
    std::sort(university_.begin(), university_.end(),
              [](const std::unique_ptr<Person>& lhsPtr, const std::unique_ptr<Person>& rhsPtr) {
                  return lhsPtr->getPesel() < rhsPtr->getPesel();
              });
}

void University::sortBySurname() {
    std::sort(university_.begin(), university_.end(),
              [](const std::unique_ptr<Person>& lhsPtr, const std::unique_ptr<Person>& rhsPtr) {
                  return lhsPtr->getSurname() < rhsPtr->getSurname();
              });
}

void University::removeByIndexNumber(size_t indexNumber) {
    size_t i = 0;
    for (const auto& el : university_) {
        if (Student* s; s = dynamic_cast<Student*>(el.get())) {
            if (s->getIndex() == indexNumber) {
               university_.erase(university_.begin() + i);
               break;

            }
        }
        i++;
    }
}
