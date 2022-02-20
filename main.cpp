#include "Employee.hpp"
#include "Menu.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "University.hpp"

int main() {
  University codersSchool;
  Menu menu(codersSchool);
  menu.mainManu();
  return 0;
}
