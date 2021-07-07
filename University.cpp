#include "University.hpp"

#include "Student.hpp"

University::University() {
    university_.reserve(10);
}

University::University(const Student& s) {
    university_.emplace_back(std::make_unique<Student>(s));
}

University::~University() {}

void University::displayStudent(const Student* student) {
    if (student) {
        std::cout << student->getName() << ", "
                  << student->getSurname() << ", "
                  << student->getAddress() << ", "
                  << student->getIndex() << ", "
                  << student->getPesel() << ", "
                  << student->getGender() << '\n';
    } else {
        std::cout << "There is no such student in our database with given PESEL number" << '\n';
    }
}

void University::displayBase() {
    for (const auto& student : university_) {
        std::cout << student->getName() << ", "
                  << student->getSurname() << ", "
                  << student->getAddress() << ", "
                  << student->getIndex() << ", "
                  << student->getPesel() << ", "
                  << student->getGender() << '\n';
    }
}

void University::addStudent() {
    Student newStudent;
    university_.push_back(std::make_unique<Student>(newStudent));
}

void University::addStudent(std::string name, std::string surname, std::string address, std::string pesel, std::string gender, size_t indexNumber) {
    if (!findByPesel(pesel)) {
        university_.emplace_back(std::make_unique<Student>(name, surname, address, pesel, gender, indexNumber));
    } else {
        std::cout << "There is such student in our database" << '\n';
    }
}

Student* University::findBySurname(const std::string& surname) {
    auto isTheSame = [&surname](std::unique_ptr<Student>& student) { return student->getSurname() == surname; };
    auto it = std::find_if(university_.begin(), university_.end(), isTheSame);

    if (it == university_.end()) {
        return nullptr;
    }

    Student* student_ptr = it->get();

    return student_ptr;
}

Student* University::findByPesel(const std::string& pesel) {
    auto isTheSame = [&pesel](std::unique_ptr<Student>& student) { return student->getPesel() == pesel; };

    auto it = std::find_if(university_.begin(), university_.end(), isTheSame);

    if (it == university_.end()) {
        return nullptr;
    }

    Student* student_ptr = it->get();

    return student_ptr;
}

void University::sortByPesel() {
    std::sort(university_.begin(), university_.end(),
              [](const std::unique_ptr<Student>& lhsPtr, const std::unique_ptr<Student>& rhsPtr) {
                  return lhsPtr->getPesel() < rhsPtr->getPesel();
              });
}

void University::sortBySurname() {
    std::sort(university_.begin(), university_.end(),
              [](const std::unique_ptr<Student>& lhsPtr, const std::unique_ptr<Student>& rhsPtr) {
                  return lhsPtr->getSurname() < rhsPtr->getSurname();
              });
}

bool University::validationByPesel(const std::string& pesel) {
    if (pesel.size() != peselSize) {
        return false;
    }

    static constexpr std::array<int, 10> weightFactors{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

    int checkSum = 0;
    int number = 0;

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

    int lastNumber = (pesel.back() - '0');

    return checkSum == lastNumber;
}

void University::exportDatabase(std::string fileName) {
    std::ofstream Database;
    Database.open(fileName);
    if (Database.is_open()) {
        for (auto& itStudent : university_) {
            Database << itStudent->getName() << ","
                     << itStudent->getSurname() << ","
                     << itStudent->getAddress() << ","
                     << itStudent->getPesel() << ","
                     << itStudent->getGender() << ","
                     << itStudent->getIndex() << "\n";
        }
        Database.close();
    } else
        std::cout << "Unable to save file\n";
}

void University::importDatabase(std::string fileName) {
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

void University::deletedByIndexNumber(size_t IndexNumber) {
    for (int i = 0; i < university_.size(); ++i) {
        if (IndexNumber == university_[i]->getIndex()) {
            university_.erase(university_.begin() + i);
            break;
        }
    }
}
