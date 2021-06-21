#include "Student.hpp"
#include "University.hpp"

int main() {
    std::string pes1 = "88111507706";    
    std::string pes = "55030101230";
    Student s1("Danuta", "Kot", "Warszawa", 166735, "89873561722", "man");
    University codersSchool(s1);
    codersSchool.addStudent("Wojtek", "Kowalski" , "Miedzychod", 162589, "45454545454", "man");
    codersSchool.addStudent("Martyna", "Tucholska", "Wroclaw", 162780, "55030101230", "woman");
    codersSchool.addStudent("Wanda", "Nowak" , "Lodz", 162576, "88530287659", "woman");
    codersSchool.addStudent("Ryszard", "Arbuz", "Gdynia", 165729, "85111507574", "man");
    codersSchool.displayBase();
    std::cout << '\n' << "=====================================" << '\n';
    codersSchool.sortByPesel();
    codersSchool.displayBase();
    std::cout << '\n' << "=====================================" << '\n';
    codersSchool.sortbyLname();
    codersSchool.displayBase();
    std::cout << '\n' << "=====================================" << '\n';
    codersSchool.displayStudent(codersSchool.findByPesel(pes1));

    auto stud = codersSchool.findByPesel(pes);
    if (codersSchool.validationByPesel(stud -> getPesel())) {
        std::cout << "PESEL is correct" << '\n';
    } else {
        std::cout << " PESEL is valid" << '\n';
    }
    //codersSchool.importDatabase();
    //codersSchool.displayBase();
    
    return 0;
}
