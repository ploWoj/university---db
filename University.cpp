#include "University.hpp"

#include "Student.hpp"

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

void University::addStudent(std::string name, std::string surname, std::string address, size_t indexNumber, std::string pesel, std::string gender) {
    if (!findByPesel(pesel)) {
        university_.emplace_back(std::make_unique<Student>(name, surname, address, indexNumber, pesel, gender));
    } else {
        std::cout << "There is such student in our database" << '\n';
    }
}

Student* University::findBySurname(const std::string& surname) {
    auto isTheSame = [&surname](std::unique_ptr<Student>& student) { return student->getSurname() == surname; };
    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);

    if (result == university_.end()) {
        //std::cout << "There is no such student in our database with given surname" << '\n';
        return nullptr;
    }

    Student* student_ptr = result->get();

    return student_ptr;
}

Student* University::findByPesel(const std::string& pesel) {
    auto isTheSame = [&pesel](std::unique_ptr<Student>& student) { return student->getPesel() == pesel; };

    auto result = std::find_if(university_.begin(), university_.end(), isTheSame);

    if (result == university_.end()) {
        //std::cout << "There is no such student in our database with given PESEL number" << '\n';
        return nullptr;
    }

    Student* student_ptr = result->get();

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
    static constexpr std::array<int, 10> weightFactors{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int result = 0;
    int number = 0;

    for (size_t i = 0; i < weightFactors.size(); i++) {
        number = pesel[i] - '0';
        result += number * weightFactors[i];
    }

    result = result % weightFactors.size();

    if (result != 0) {
        result = weightFactors.size() - result;
    }

    int lastNumber = (pesel.back() - '0');

    return result == lastNumber;
}
void University::exportDatabase() {
    std::ofstream Database;
    Database.open("university-db.csv");
    if (Database.is_open()) {
        for (auto& itStudent : university_) {
            Database << itStudent->getName() << ","
                     << itStudent->getSurname() << ","
                     << itStudent->getAddress() << ","
                     << itStudent->getIndex() << ","
                     << itStudent->getPesel() << ","
                     << itStudent->getGender() << "\n";
        }
        Database.close();
    } else
        std::cout << "Unable to open file";
}

void University::importDatabase() {
    std::ifstream Database("university-db.csv");
    std::string line;
    if (Database.is_open()) {
        size_t iLine = 0;
        while (Database.peek()) {
            getline(Database, line, ',');
            university_[iLine]->setName(line);
            getline(Database, line, ',');
            university_[iLine]->setSurname(line);
            getline(Database, line, ',');
            university_[iLine]->setAddress(line);
            getline(Database, line, ',');
            university_[iLine]->setIndex(std::stoi(line));
            getline(Database, line, ',');
            university_[iLine]->setPesel(line);
            getline(Database, line, ',');
            university_[iLine]->setGender(line);
            iLine += 1;
        }
        Database.close();
    } else
        std::cout << "Unable to open file";

}
void University::deletedByIndexNumber(){
    size_t IndexNumber;
    std::cout << " Take IndexNumver";
    std::cin >> IndexNumber;
    for (int i = 0; i < university_.size(); ++i) {
        if (IndexNumber == university_[i]->getIndex()) {
            university_.erase(university_.begin() + i);
        }
     }
}

