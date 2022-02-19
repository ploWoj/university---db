#include "menu.hpp"
#include <iomanip>

void Menu::printMainManu() const {
    uint8_t itemSize = 23;
    std::cout << std::left << std::setfill(' ');
    std::cout << std::setw(itemSize) << "[ 1] Print DB"
              << std::setw(itemSize) << "[ 4] Sort by Pesel"
              << std::setw(itemSize) << "[ 7] Find by Pesel"
              << std::setw(itemSize) << "[10] Remove Student" 
              << std::setw(itemSize) << "[ 0] Quit" <<  '\n'
              << std::setw(itemSize) << "[ 2] Add Student"
              << std::setw(itemSize) << "[ 5] Sort by surnname"
              << std::setw(itemSize) << "[ 8] Find surnname"
              << std::setw(itemSize) << "[11] Save to file" << '\n'
              
              << std::setw(itemSize) << "[ 3] Add Emplyee"
              << std::setw(itemSize) << "[ 6] Sort by salary"
              << std::setw(itemSize) << "[ 9] Change salary"
              << std::setw(itemSize) << "[12] Read from file" << '\n';
}

void Menu::separator() {
    std::cout << std::right << std ::setfill('-') << std::setw(typeColumnWidth
                                                              + firstNameColumnWidth
                                                              + lastNameColumnWidth
                                                              + peselColumnWidth
                                                              + addressColumnWidth
                                                              + sexColumnWidth
                                                              + indexNumberColumnWidth
                                                              + salaryColumnWidth) << '\n';
    std::cout << std ::setfill(' ');
}

void Menu::printPanel(const std::string message) {
    separator();
    std::cout << "Database size: " << db_.getVector().size() << " | message: " << message << '\n';
    separator();

}


void Menu::mainManu() {
    short choice = -1;
    std::string message = "Welcom. Choose an option.";
    std::cout << "\n..:: University database ::..\n";

    // menuPrintAll();
    // std::cin >> choice;
    while (choice != 0) {
        printPanel(message);
        printMainManu();
        std::cout << " > " ;
        std::cin >> choice;
        switch(static_cast<Order>(choice)) {
            case Order::PrintAll: {
                message = menuPrintAll();
                
            }
            break;
            case Order::AddStudent: {
                menuAddStudent();
            }
            break;
            case Order::AddEmployee: {
                menuAddEmplyee();
            }
            break;
            case Order::SortByPesel: {
                message = menuSortByPesel();
            }
            break;
            case Order::SortBySurname: {
                message = menuSortBySurname();
            }
            break;
            case Order::SortBySalary: {
                
            }
            break;
            case Order::FindByPesel: {
                
            }
            break;
              case Order::FindBySurname: {
                
            }
            break;
              case Order::ChangeSalary : {
                
            }
            break;
              case Order::RemovePerson: {
                
            }
            break;
              case Order::SaveToFile : {
                
            }
            break;
              case Order::ReadFromFile : {
                
            }
            break;
        }

    }


}



std::string Menu::menuPrintAll() {
        if (db_.getVector().empty()) {
        printHeader();
        std::cout << "\n\n\t\tDatabase is empty. \n";
        std::cout << "\t\tAdd person[2] or read from a file[12]";

    } else {
        db_.displayBase();
    }
    return "Choose an option";

}

void Menu::printHeader(){
    separator();
    std::cout << std::left;
    std::cout << std::setw(typeColumnWidth) << "type:"
              << std::setw(firstNameColumnWidth) << "first name:"
              << std::setw(lastNameColumnWidth) << "last name:"
              << std::setw(addressColumnWidth) << "address:"
              << std::setw(peselColumnWidth) << "PESEL:"
              << std::setw(sexColumnWidth) << "sex:"
              << std::setw(indexNumberColumnWidth) << "index num.:"
              << std::setw(sexColumnWidth) << "salary:"
              << '\n';
    separator();
}

void Menu::menuAddStudent() {
    std::string name;
    std::string surname;
    std::string address;
    size_t indexNumber;
    std::string pesel;
    std::string gender;

    std::cout << "Give your name:";
    std::cin >> name;
    std::cout << "Give your surname:";
    std::cin >> surname;
    std::cout << "Give your city: ";
    std::cin >> address;
    std::cout << "Give your pesel:";
    std::cin >> pesel;
    std::cout << "Give your gender (woman/ man): ";
    std::cin >> gender;
    std::cout << "Give yout index number: ";
    std::cin >> indexNumber;
    db_.addStudent(name, surname, address, pesel, gender, indexNumber);
}

void Menu::menuAddEmplyee() {
        std::string name;
    std::string surname;
    std::string address;
    double salary;
    std::string pesel;
    std::string gender;

    std::cout << "Give your name:";
    std::cin >> name;
    std::cout << "Give your surname:";
    std::cin >> surname;
    std::cout << "Give your city: ";
    std::cin >> address;
    std::cout << "Give your pesel:";
    std::cin >> pesel;
    std::cout << "Give your gender (woman/ man): ";
    std::cin >> gender;
    std::cout << "Give your salar: ";
    std::cin >> salary;
    db_.addEmployee(name, surname, address, pesel, gender, salary);
}

std::string Menu::menuSortByPesel() {
    db_.sortByPesel();
    return "Data base has been sorted by pesel.";
}

std::string Menu::menuSortBySurname() {
    db_.sortBySurname();
    return "Data base has been sorted by surname.";
}