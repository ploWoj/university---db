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
    codersSchool.addStudent("Marianna", "Bak", "Zlotoryja", "45454534532", "woman", 162421);
    codersSchool.addStudent("Krzysztof", "Cebula", "Wroclaw", "32145101230", "man", 163270);
    codersSchool.addStudent("Florian", "Fiolkowski", "Warszawa", "87698287659", "man", 162759);
    codersSchool.addStudent("Lidia", "Romska", "Gdansk", "85111594286", "woman", 163782);

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
    std::cout << "Export database\n";
    std::string fileName = "university.csv";
    codersSchool.exportDatabase(fileName);
    
    std::cout << "\n=====================================\n";
    std::cout << "Import database to codersSchool\n";
    codersSchool.importDatabase(fileName);
    codersSchool.displayBase();


    std::cout << "\n=====================================\n";
    std::cout << "Import database to newSchool\n";
    University newSchool;
    newSchool.importDatabase(fileName);
    newSchool.displayBase();
    
    std::cout << "\n=====================================\n";
    std::cout << "Modify salary\n";
    codersSchool.modifySalary(66666.66, "85111502341");
    codersSchool.modifySalary(66666.66, "88530287659");
    codersSchool.displayBase();
    
    std::cout << "\n=====================================\n";
    std::cout << "Find by PESEL\n";
    std::string pesel1 = "88530287659";
    if (auto* person = codersSchool.findByPesel(pesel1)) {
        person->display();
    }

    std::cout << "\n=====================================\n";
    std::cout << "Find by Surname\n";
    std::string surname1 = "Arbuz";
    if (auto* person = codersSchool.findBySurname(surname1)) {
        person->display();
    }

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
