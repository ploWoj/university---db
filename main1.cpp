 #include "Student.hpp"
 #include "University.hpp"
 #include "Person.hpp"
 #include "Employee.hpp"
 
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


     return 0;

}
