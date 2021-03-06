#include <algorithm>
#include <optional>
#include <typeinfo>

#include "Person.hpp"
#include "Student.hpp"
#include "University.hpp"

University::University()
{
    university_.reserve(10);
}

const std::vector<std::unique_ptr<Person>>& University::getVector() const
{
    return university_;
}

void University::displayBase()
{
    for (const auto& person : university_) {
        person->display();
    }
}

void University::addStudent()
{
    university_.emplace_back(std::make_unique<Student>());
}

void University::addStudent(std::string name,
    std::string surname,
    std::string address,
    std::string pesel,
    std::string gender,
    size_t indexNumber)
{
    if (validationByPesel(pesel)) {
        if (!findByPesel(pesel)) {
            university_.emplace_back(std::make_unique<Student>(
                name, surname, address, pesel, gender, indexNumber));
        }
    } else {
        std::cout << "Wrong pesel number.\n";
    }
}

void University::addEmployee()
{
    university_.emplace_back(std::make_unique<Employee>());
}

void University::addEmployee(std::string name,
    std::string surname,
    std::string address,
    std::string pesel,
    std::string gender,
    double salary)
{
    if (validationByPesel(pesel)) {
        if (!findByPesel(pesel)) {
            university_.emplace_back(std::make_unique<Employee>(
                name, surname, address, pesel, gender, salary));
        }
    } else {
        std::cout << "Wrong pesel number.\n";
    }
}

Person* University::findBySurname(const std::string& surname)
{
    auto isTheSame = [&surname](std::unique_ptr<Person>& person) {
        return person->getSurname() == surname;
    };
    auto it = std::find_if(university_.begin(), university_.end(), isTheSame);

    if (it == university_.end()) {
        return nullptr;
    }

    Person* person_ptr = it->get();

    return person_ptr;
}

Person* University::findByPesel(const std::string& pesel)
{
    auto isTheSame = [&pesel](std::unique_ptr<Person>& person) {
        return person->getPesel() == pesel;
    };

    auto it = std::find_if(university_.begin(), university_.end(), isTheSame);

    if (it == university_.end()) {
        return nullptr;
    }

    Person* person_ptr = it->get();

    return person_ptr;
}

void University::modifySalary(double newSalary, const std::string& pesel)
{
    auto person = findByPesel(pesel);
    if (!person) {
        std::cout << "A person with that pesel does not exists.\n";
        return;
    }

    if (Employee* e = dynamic_cast<Employee*>(person)) {
        e->setSalary(newSalary);
    } else {
        std::cout << "ERROR: Students don't have salary\n";
    }
}
void University::sortByPesel()
{
    std::sort(university_.begin(), university_.end(),
        [](const std::unique_ptr<Person>& lhsPtr,
            const std::unique_ptr<Person>& rhsPtr) {
            return lhsPtr->getPesel() < rhsPtr->getPesel();
        });
}

void University::sortBySurname()
{
    std::sort(university_.begin(), university_.end(),
        [](const std::unique_ptr<Person>& lhsPtr,
            const std::unique_ptr<Person>& rhsPtr) {
            return lhsPtr->getSurname() < rhsPtr->getSurname();
        });
}

std::optional<double> getSalaryIfIs(const std::unique_ptr<Person>& person)
{
    if (auto* employee = dynamic_cast<Employee*>(person.get())) {
        return employee->getSalary();
    }
    return std::nullopt;
}
// Function is sorting people included in university_ vector. Sorting by salary
// then by surname.
void University::sortBySalary()
{
    std::sort(university_.begin(), university_.end(),
        [](const std::unique_ptr<Person>& lhsPtr,
            const std::unique_ptr<Person>& rhsPtr) {
            return getSalaryIfIs(lhsPtr).value_or(0.0) > getSalaryIfIs(rhsPtr).value_or(0.0) || (getSalaryIfIs(lhsPtr).value_or(0.0) == getSalaryIfIs(rhsPtr).value_or(0.0) && lhsPtr->getSurname() < rhsPtr->getSurname());
        });
}

std::optional<size_t> getIndexIfIs(const std::unique_ptr<Person>& person)
{
    if (auto* student = dynamic_cast<Student*>(person.get())) {
        return student->getIndex();
    }
    return std::nullopt;
}

void University::removeByIndexNumber(size_t indexNumber, std::string& message)
{
    size_t i = 0;
    for (const auto& el : university_) {
        if (auto s = dynamic_cast<Student*>(el.get())) {
            if (s->getIndex() == indexNumber) {
                university_.erase(university_.begin() + i);
                message = "Remove successfully.\n";
                return;
            }
        }
        i++;
    }
    message = "No student with that index number in data base.\n";
}

bool University::validationByPesel(const std::string& pesel)
{
    if (pesel.size() != peselSize) {
        return false;
    }

    static constexpr std::array<size_t, 10> weightFactors { 1, 3, 7, 9, 1,
        3, 7, 9, 1, 3 };

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

void University::exportDatabase(const std::string& fileName, bool& flag)
{
    std::ofstream Database;
    Database.open(fileName);
    if (Database.is_open()) {
        for (auto& itPerson : university_) {
            Database << typeid(*itPerson).name() << "," << itPerson->getName() << ","
                     << itPerson->getSurname() << "," << itPerson->getAddress() << ","
                     << itPerson->getPesel() << "," << itPerson->getGender() << ",";
            if (auto itStudent = dynamic_cast<Student*>(itPerson.get())) {
                Database << itStudent->getIndex() << '\n';
            } else if (auto itEmployee = dynamic_cast<Employee*>(itPerson.get())) {
                Database << itEmployee->getSalary() << '\n';
            }
        }
        Database.close();
        flag = true;
    } else {
        flag = false;
    }
}

void University::importDatabase(const std::string& fileName, bool& flag)
{
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
                addStudent(rowLine[1], rowLine[2], rowLine[3], rowLine[4], rowLine[5],
                    std::stoi(rowLine[6]));
            }
            if (rowLine[0] == "8Employee") {
                addEmployee(rowLine[1], rowLine[2], rowLine[3], rowLine[4], rowLine[5],
                    std::stod(rowLine[6]));
            }
        }
        Database.close();
        flag = true;
    } else {
        flag = false;
    }
}