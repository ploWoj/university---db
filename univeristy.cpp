#include "univeristy.hpp"

#include "student.hpp"

University::University(const Student& s) {
    university_.push_back(s);
}
University::~University() {}

void University::dispalayBase() {
    for (int i = 0; i < university_.size() - 1; i++) {
        std::cout << i << "." << university_[i].getName() << ", "
                  << university_[i].getLname() << ", "
                  << university_[i].getAdress() << ", "
                  << university_[i].getIndex() << ", "
                  << university_[i].getPesel() << ", "
                  << university_[i].getGender() << '\n';
    }
}
// Implemented sort by pesel
void University::sortByPesel() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr.getPesel() < rhsPtr.getPesel();
              });
}
// Implemented sort by LName
void University::sortbyLname() {
    std::sort(university_.begin(), university_.end(),
              [](const Student& lhsPtr, const Student& rhsPtr) {
                  return lhsPtr.getLname() < rhsPtr.getLname();
              });
}
