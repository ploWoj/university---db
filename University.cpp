#include "University.hpp"

#include <algorithm>

#include "Person.hpp"
#include "Student.hpp"
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
}

void University::addStudent(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t indexNumber) {
    Student student(name, surname, address, pesel, gender, indexNumber);
    auto studentUP = std::make_unique<Student>(student);
    university_.emplace_back(std::move(studentUP));
}

void University::addEmployee() {
    Employee newEmployee;
    auto newEmployeeUP = std::make_unique<Employee>(newEmployee);
    university_.push_back(std::move(newEmployeeUP));
}

void University::addEmployee(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, double salary) {
    Employee employee(name, surname, address, pesel, gender, salary);
    auto employeeUP = std::make_unique<Employee>(employee);
    university_.emplace_back(std::move(employeeUP));
}
void University::modifySalary(double newSalary, const std::string& pesel) {
    auto it = std::find_if(begin(university_), end(university_), [pesel](auto const& person) {
        return person->getPesel() == pesel;
    });
    if (it != end(university_)) {
        std::unique_ptr<Person*> p = std::make_unique<Person*>(std::move(it->get()));
        if (Employee* e = dynamic_cast<Employee*>(*p)) {
            e->setSalary(newSalary);
        } else {
            std::cout << "ERROR: Students don't have salary\n";
        }
    }
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
// Fucntion sort People included in university_.
void University::sortBySalary() {
    std::sort(university_.begin(), university_.end(),
              [](const std::unique_ptr<Person>& lhsPtr, const std::unique_ptr<Person>& rhsPtr) {
                  return lhsPtr->getSalary() > rhsPtr->getSalary() || (lhsPtr->getSalary() == rhsPtr->getSalary() && lhsPtr->getSurname() < rhsPtr->getSurname());
              });
}

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
            Database << itPerson->getName() << ","
                     << itPerson->getSurname() << ","
                     << itPerson->getAddress() << ","
                     << itPerson->getPesel() << ","
                     << itPerson->getGender() << ",";
            if (auto itStudent = dynamic_cast<Student*>(itPerson.get())) {
                Database << itStudent->getIndex() << '\n';
            } else if (auto itEmployee = dynamic_cast<Employee*>(itPerson.get())) {
                Database << itEmployee->getSalary() << '\n';
            }
        }
        Database.close();
    } else
        std::cout << "Unable to save file\n";
}
/*
void University::importDatabase(const std::string& fileName) {
    std::ifstream Database(fileName);
    std::string element;
    std::array<std::string, 6> rowLine = {};
    if (Database.is_open()) {
        while (Database.peek() != EOF) {
            for (size_t i = 0; i < rowLine.size() - 1; i++) {
                 getline(Database, element, ',');
                 rowLine[i] = element;
            }
            getline(Database, element, '\n');
            rowLine[5] = element;
            addStudent(rowLine[0], rowLine[1], rowLine[2], rowLine[3], rowLine[4], std::stoi(rowLine[5]));
        }
        Database.close();
    } else
        std::cout << "Unable to open file";
}
*/
