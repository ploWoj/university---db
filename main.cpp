#include "student.hpp"
#include "univeristy.hpp"

void menu();
int wybor_menu(int);
int wybor;

int main() {

    Student s1("Wojtek", "Kowalski" , "Miedzychod", 1111111111, 45454545454, "man");

      


    return 0;
}

void menu() {
   std::cout << "MENU GLOWNE:                      " <<std::endl;
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
    switch (wybor)
    {
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

