#include "Student.hpp"
#include "University.hpp"

void menu();
int wybor_menu(int);
int wybor;

void menu() {
    std::cout << "MENU GLOWNE:                      " << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "1.Dodawanie nowych studentow      " << std::endl;
    std::cout << "2.Wyświetlenie calej bazy daych   " << std::endl;
    std::cout << "3.Wyszukiwanie po nazwisku        " << std::endl;
    std::cout << "4.Wyszukiwanie po numerze pesel   " << std::endl;
    std::cout << "5.Sortowanie po nuemrze pesel     " << std::endl;
    std::cout << "6.Sortowanie po nazwisku          " << std::endl;
    std::cout << "7.Usuwanie po numerze indeksu     " << std::endl;
    std::cout << "8.Zakoncz                         " << std::endl;
    std::cout << "Wybor: ";
}
int wybor_menu(int wybor) {
    std::cin >> wybor;
    switch (wybor) {
        case 1:

            break;
        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 7:

        case 8:
            exit(0);
    }
    return wybor;
}

int main() {
    std::string pes1 = "88111507706";
    std::string pes = "55030101230";
    Student s1("Danuta", "Kot", "Warszawa", 166735, "89873561722", "man");
    University codersSchool(s1);
    codersSchool.addStudent("Wojtek", "Kowalski", "Miedzychod", 162589, "45454545454", "man");
    codersSchool.addStudent("Martyna", "Tucholska", "Wroclaw", 162780, "55030101230", "woman");
    codersSchool.addStudent("Wanda", "Nowak", "Lodz", 162576, "88530287659", "woman");
    codersSchool.addStudent("Ryszard", "Arbuz", "Gdynia", 165729, "85111507574", "man");
    codersSchool.displayBase();
    std::cout << '\n'
              << "=====================================" << '\n';
    codersSchool.sortByPesel();
    codersSchool.displayBase();
    std::cout << '\n'
              << "=====================================" << '\n';
    codersSchool.sortBySurname();
    codersSchool.displayBase();
    std::cout << '\n'
              << "=====================================" << '\n';
    codersSchool.displayStudent(codersSchool.findByPesel(pes1));

    auto stud = codersSchool.findByPesel(pes);
    if (codersSchool.validationByPesel(stud->getPesel())) {
        std::cout << "PESEL is correct" << '\n';
    } else {
        std::cout << " PESEL is valid" << '\n';
    }

    // delete student by index number
    std::cout << "\nErasing student with given index number...";
    codersSchool.deleteByIndexNumber();
    std::cout << "\n\nDatabase:\n";
    codersSchool.displayBase();

    // export database
    std::cout << "\nExporting database to CSV file...\nEnter file name: ";
    std::string fileNameExport;
    std::cin >> fileNameExport;
    codersSchool.exportDatabase(fileNameExport);

    // import database
    std::cout << "\nImporting database to CSV file...\nEnter file name: ";
    std::string fileNameImport;
    std::cin >> fileNameImport;
    University importedDatabase;
    importedDatabase.importDatabase(fileNameImport);
    std::cout << "\nImported database:\n";
    importedDatabase.displayBase();

    return 0;
}
