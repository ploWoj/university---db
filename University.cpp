#include <algorithm>
#include <typeinfo>
#include "University.hpp"
#include "Student.hpp"
#include "Person.hpp"

University::University() {
    university_.reserve(10);
}

const std::vector<std::unique_ptr<Person>>& University::getVector() const { 
    return university_; 
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
 //   university_.emplace_back(std:make_unique<Student>(name, surname, address, pesel, gender,indexNumber));
}

void University::addStudent(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t indexNumber) {
    university_.emplace_back(std::make_unique<Student>(name, surname, address, pesel, gender,indexNumber));
}

 void University::addEmployee() {
     university_.emplace_back(std::make_unique<Employee>());
 }
 
void University::addEmployee(std::string name, std::string surname, std::string address, std::string pesel, std::string gender,    double salary) {
     university_.emplace_back(std::make_unique<Employee>(name, surname, address, pesel, gender, salary));
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
//I think that erase-remove idiom will be more compressed version 
void University::removeByIndexNumber(size_t indexNumber) {
    size_t i = 0;
    for (const auto& el : university_) {
        if (auto s = dynamic_cast<Student*>(el.get())) {
            if (s->getIndex() == indexNumber) {
               university_.erase(university_.begin() + i);
               break;

            }
        }
        i++;
    }
}

bool University::validationByPesel(const std::string& pesel) {
    if (pesel.size() != peselSize) {
        return false;
    }

    static constexpr std::array<size_t, 10> weightFactors{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

    size_t checkSum = 0;
    size_t number = 0;

    for (size_t i = 0; i < weightFactors.size(); i++) {
        if (!std::isdigit(pesel[i])) {
            return false;
        }
        number = pesel[i] - '0';
        checkSum += number * weightFactors[i];
    }

    checkSum = checkSum % weightFactors.size();

    if (checkSum != 0) {
        checkSum = weightFactors.size() - checkSum;
    }

    size_t lastNumber = (pesel.back() - '0');

    return checkSum == lastNumber;
}

void University::exportDatabase(const std::string& fileName) {
    std::ofstream Database;
    Database.open(fileName);
    if (Database.is_open()) {
        for (auto& itPerson : university_) {
            Database << typeid(*itPerson).name() << "," 
                     << itPerson->getName() << ","
                     << itPerson->getSurname() << ","
                     << itPerson->getAddress() << ","
                     << itPerson->getPesel() << ","
                     << itPerson->getGender() << ",";
            if (Student* itStudent; itStudent = dynamic_cast<Student*>(itPerson.get())) {
                Database << itStudent->getIndex() << '\n';
            } else if (Employee* itEmployee; itEmployee = dynamic_cast<Employee*>(itPerson.get())) {
                Database << itEmployee->getSalary() << '\n';
            }
        }
        Database.close();
    } else
        std::cout << "Unable to save file\n";
}

void University::importDatabase(const std::string& fileName) {
    std::ifstream Database(fileName);
    std::string element;
    std::array<std::string, 7> rowLine = {};
    if (Database.is_open()) {
        while (Database.peek() != EOF) {
            for (size_t i = 0; i < rowLine.size() - 1; i++) {
                 getline(Database, element, ',');
                 rowLine[i] = element;
            }
            getline(Database, element, '\n');
            rowLine[6] = element;
            if (rowLine[0] == "7Student") {
                addStudent(rowLine[1], rowLine[2], rowLine[3], rowLine[4], rowLine[5], std::stoi(rowLine[6]));
            }
            if (rowLine[0] == "8Employee") {
                addEmployee(rowLine[1], rowLine[2], rowLine[3], rowLine[4], rowLine[5], std::stod(rowLine[6]));
            }
        }
        Database.close();
    } else
        std::cout << "Unable to open file";
}


