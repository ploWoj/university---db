#include "student.hpp"

Student::Student (std::string name, std::string l_name, std::string adress, long long indexNumber, long long pesel, std::string gender)
    : name_(name)
    , l_name_(l_name)
    , adress_(adress)
    , indexNumber_(indexNumber)
    , pesel_(pesel)
    , gender_(gender) {} ;

//// Czy mam implementować konstruktor domyślny?
// Nie rozumiem jak miałą by wyglądać druga klasa Uniwersity?
