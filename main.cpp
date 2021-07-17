#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "University.hpp"

int main() {
    // initiate database
    std::cout << "\nFilling in database...\n";
    Student s1("Danuta", "Kot", "Warszawa", "89873561722", "man", 166735);
    University codersSchool;
    codersSchool.addStudent("Wojtek", "Kowalski", "Miedzychod", "45454545454", "man", 162589);
    codersSchool.addStudent("Martyna", "Tucholska", "Wroclaw", "55030101230", "woman", 162780);
    codersSchool.addStudent("Wanda", "Nowak", "Lodz", "88530287659", "woman", 162576);
    codersSchool.addStudent("Ryszard", "Arbuz", "Gdynia", "85111507574", "man", 165729);

    codersSchool.addEmployee("Adam", "Borsuk", "Grudziadz", "85111502341", "man", 4250.66);
    codersSchool.addEmployee("Tomek", "Niedzielski", "Kazimierz", "86120607584", "man", 10268.86);
    codersSchool.addEmployee("Arek", "Wojarz", "Torun", "72121608984", "man", 1200.86);
    codersSchool.addEmployee("Maria", "Konieczna", "Rzeszów", "99101908934", "woman", 8190.86);
    codersSchool.addEmployee("Maria", "Bida", "Rzeszów", "99101908934", "woman", 66666.7);
    std::cout << "\n=====================================\n";
    std::cout << "Datebase:\n";
    codersSchool.displayBase();
    std::cout << "\n=====================================\n";
    std::cout << "Datebase sorted by pesel:\n";
    codersSchool.sortByPesel();
    codersSchool.displayBase();
    std::cout << "\n=====================================\n";
    std::cout << "Datebase sorted by surname:\n";
    codersSchool.sortBySurname();
    codersSchool.displayBase();
    std::cout << "\n=====================================\n";
    std::cout << "Remove student by index number\n";
    size_t index_test = 162780;
    codersSchool.removeByIndexNumber(index_test);
    codersSchool.displayBase();
    std::cout << "\n=====================================\n";
    std::cout << "Pesel validation\n";
    auto& personVec = codersSchool.getVector();
    for (const auto& el : personVec) {
        auto pesel = el->getPesel();
        if (codersSchool.validationByPesel(pesel)) {
            std::cout << pesel << " is valid\n";
        } else {
            std::cout << pesel << " is invalid\n";
        }
    }
    std::cout << "\n=====================================\n";
    std::cout << "Modify salary\n";
    codersSchool.modifySalary(66666.66, "85111502341");
    codersSchool.modifySalary(66666.66, "88530287659");
    codersSchool.displayBase();
    std::cout << "\n=====================================\n";

    std::cout << "\n=====================================\n";
    std::cout << "Datebase sorted by salary:\n";
    codersSchool.sortBySalary();
    codersSchool.displayBase();
    std::cout << "\n=====================================\n";

    // std::cout << "Export database\n";
    // std::string fileName = "university.csv";
    // codersSchool.exportDatabase(fileName);
    return 0;
}
