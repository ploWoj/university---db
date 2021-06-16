#include "student.hpp"
#include "univeristy.hpp"


University::University(const Student& s) {
    university_.push_back(s);
}
University::~University() {}

void University::dispalayBase() {
    for (int i = 0; i < university_.size() -1; i++) {
        std::cout << i << "." << university_[i].getName() <<", " 
        << university_[i].getLname() << ", " 
        << university_[i].getAdress() << ", "
        << university_[i].getIndex() << ", "
        << university_[i].getPesel() << ", "
        << university_[i].getGender() << '\n';
    }
}