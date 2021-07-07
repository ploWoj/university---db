#include "Student.hpp"

Student::Student(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t indexNumber)
    : Person::Person(name, surname, address, pesel, gender)
    , indexNumber_(indexNumber) 
{}

Student::~Student() {}

void Student::setIndex(const size_t indexNumber) {
    indexNumber_ = indexNumber;
}

size_t Student::getIndex() const {
    return indexNumber_;
}
