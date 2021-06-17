#include "Univeristy.hpp"

#include "Student.hpp"

University::University(const Student& s) {
    university_.push_back(s);
}
University::~University() {}

void University::dispalayBase() {
    for (int i = 0; i < university_.size() - 1; i++) {
        std::cout << i << "." << university_[i].getName() << ", "
                  << university_[i].getLname() << ", "
                  << university_[i].getAdress() << ", "
                  << university_[i].getIndex() << ", "
                  << university_[i].getPesel() << ", "
                  << university_[i].getGender() << '\n';
    }
}

void University::addStudent(std::string name, std::string l_name, std::string adress, long long indexNumber, long long pesel, std::string gender) {
    Student newStudent(name, l_name, adress, indexNumber, pesel, gender);
    university_.push_back(newStudent);
}

Student* University::findBySurname(const std::string& surname){
    auto isTheSame = [](Student* student){ return student -> getSurname() == surname; };
    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);
 
    if (result == university.end()) {
        std::cout << "There is no such student in our database with given surname" << '\n';
        return nullptr;//nie wiem ??
    }
 
    return result;
}
 
Student* University::findByPesel(const long long& pesel){
    auto isTheSame = [](Student* student){ return student -> getPesel() == pesel; };
    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);
 
    if (result == university.end()) {
        std::cout << "There is no such student in our database with given PESEL number" << '\n';
        return nullptr;//nie wiem co tutaj ??
    }
 
    return result;
}

void University::sortByPesel() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr.getPesel() < rhsPtr.getPesel();
              });
}
// Implemented sort by LName
void University::sortbyLname() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr.getLname() < rhsPtr.getLname();
              });
}

