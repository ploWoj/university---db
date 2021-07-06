#include "Student.hpp"

Student::Student() {}

Student::Student(std::string name, std::string surname, std::string address, size_t indexNumber, std::string pesel, std::string gender)
    : name_(name), surname_(surname), address_(address), indexNumber_(indexNumber), pesel_(pesel), gender_(gender){}

Student::~Student() {}

void Student::setName(const std::string& name) {
    name_ = name;
}

void Student::setSurname(const std::string& surname) {
    surname_ = surname;
}

void Student::setAddress(const std::string& address) {
    address_ = address;
}

void Student::setIndex(const size_t indexNumber) {
    indexNumber_ = indexNumber;
}

void Student::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}

void Student::setGender(const std::string& gender) {
    gender_ = gender;
}

std::string Student::getName() const {
    return name_;
}

std::string Student::getSurname() const {
    return surname_;
}

std::string Student::getAddress() const {
    return address_;
}

size_t Student::getIndex() const {
    return indexNumber_;
}

std::string Student::getPesel() const {
    return pesel_;
}

std::string Student::getGender() const {
    return gender_;
}
