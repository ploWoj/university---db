#include "Student.hpp"

Student::Student(std::string name, std::string l_name, std::string adress, long long indexNumber, long long pesel, std::string gender)
    : name_(name), l_name_(l_name), adress_(adress), indexNumber_(indexNumber), pesel_(pesel), gender_(gender){};

Student::~Student() {}

void Student::setName(const std::string& name) {
    name_ = name;
}

void Student::setLname(const std::string& l_name) {
    l_name_ = l_name;
}
void Student::setAdress(const std::string& adress) {
    adress_ = adress;
}
void Student::setIndex(const long long& indexNumber) {
    indexNumber_ = indexNumber;
}
void Student::setPesel(const long long& pesel) {
    pesel_ = pesel;
}
void Student::setGender(const std::string& gender) {
    gender_ = gender;
}

std::string Student::getName() const {
    return name_;
}
std::string Student::getLname() const {
    return l_name_;
}
std::string Student::getAdress() const {
    return adress_;
}
long long Student::getIndex() const {
    return indexNumber_;
}
long long Student::getPesel() const {
    return pesel_;
}
std::string Student::getGender() const {
    return gender_;
}
//// Czy mam implementować konstruktor domyślny?
// Nie rozumiem jak miałą by wyglądać druga klasa Uniwersity?
