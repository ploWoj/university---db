#include "Student.hpp"
#include "University.hpp"
#include "Person.hpp"
#include "Employee.hpp"

int main() {
    // initiate database
    std::cout << "\nFilling in database...\n";
    Student s1("Danuta", "Kot", "Warszawa", "89873561722", "man", 166735);
    University codersSchool(s1);
    codersSchool.addStudent("Wojtek", "Kowalski", "Miedzychod", "45454545454", "man", 162589);
    codersSchool.addStudent("Martyna", "Tucholska", "Wroclaw", "55030101230", "woman", 162780);
    codersSchool.addStudent("Wanda", "Nowak", "Lodz", "88530287659", "woman", 162576);
    codersSchool.addStudent("Ryszard", "Arbuz", "Gdynia", "85111507574", "man", 165729);
    std::cout << "\n=====================================\n";
    std::cout << "Datebase:\n";
    codersSchool.displayBase();
    codersSchool.sortByPesel();
    std::cout << "\n=====================================\n";
    std::cout << "Datebase sorted by PESEL:\n";
    codersSchool.displayBase();
    codersSchool.sortBySurname();
    std::cout << "\n=====================================\n";
    std::cout << "Datebase sorted by surname:\n";
    codersSchool.displayBase();

    // search by PESEL
    std::string pesel1 = "88111507706";
    std::string pesel2 = "55030101230";
    std::cout << "\nFinding student with PESEL no. " << pesel1 << "...\n";
    codersSchool.displayStudent(codersSchool.findByPesel(pesel1));
    auto student = codersSchool.findByPesel(pesel2);
    if (codersSchool.validationByPesel(student->getPesel())) {
        std::cout << "PESEL is correct\n";
    } else {
        std::cout << "PESEL is incorrect\n";
    }

    // delete by index number
    std::cout << "\nDeleting student with index no. 162780...\n";
    size_t indexNumber = 162780;
    codersSchool.deletedByIndexNumber(indexNumber);
    std::cout << "\n=====================================\n";
    std::cout << "Database:\n";
    codersSchool.displayBase();

    // export database
    std::cout << "\nExporting database to CSV file...\n";
    std::string fileNameExport = "test.csv";
    codersSchool.exportDatabase(fileNameExport);

    // import database
    std::cout << "\nImporting database from CSV file...\n";
    std::string fileNameImport = "test.csv";
    University importedDatabase;
    importedDatabase.importDatabase(fileNameImport);
    std::cout << "\n=====================================\n";
    std::cout << "Imported database:\n";
    importedDatabase.displayBase();

    return 0;
}
