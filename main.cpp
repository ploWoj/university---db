#include "Student.hpp"
#include "Univeristy.hpp"

int main() {
    
    std::string pes = "55030101230";
    Student s1("Danuta", "Kot", "Warszawa", 166735, "89873561722", "man");
    University codersSchool(s1);
    codersSchool.addStudent("Wojtek", "Kowalski" , "Miedzychod", 162589, "45454545454", "man");
    codersSchool.addStudent("Martyna", "Tucholska", "Wroclaw", 162780, "55030101230", "woman");
    codersSchool.addStudent("Wanda", "Nowak" , "Lodz", 162576, "88530287659", "woman");
    codersSchool.addStudent("Ryszard", "Arbuz", "Gdynia", 165729, "85111507574", "man");
    codersSchool.dispalayBase();
    std::cout << '\n' << "=====================================" << '\n';
    codersSchool.sortByPesel();
    codersSchool.dispalayBase();
    std::cout << '\n' << "=====================================" << '\n';
    codersSchool.sortbyLname();
    codersSchool.dispalayBase();
    std::cout << '\n' << "=====================================" << '\n';
    codersSchool.displayStudent(codersSchool.findByPesel(pes));

    auto stud = codersSchool.findByPesel(pes);
    stud.getPesel();
    if (codersSchool.validationByPesel(stud.getPesel())) {
        std::cout << "PESEL is correct" << '\n';
    } else {
        std::cout << " PESEL is valid" << '\n';
    }


    return 0;
}
