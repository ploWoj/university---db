#include "Student.hpp"

Student::Student(std::string name,
                 std::string surname,
                 std::string address,
                 std::string pesel,
                 std::string gender,
                 size_t indexNumber)
    : Person::Person(name, surname, address, pesel, gender),
      indexNumber_(indexNumber) {}

void Student::setIndex(const size_t indexNumber) {
  indexNumber_ = indexNumber;
}

size_t Student::getIndex() const {
  return indexNumber_;
}

void Student::display() {
  std::cout << "Student: " << name_ << ", " << surname_ << ", " << address_
            << ", " << indexNumber_ << ", " << pesel_ << ", " << gender_
            << '\n';
}
