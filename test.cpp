#include <sstream>
#include <string>

#include "Employee.hpp"
#include "Student.hpp"
#include "University.hpp"
#include "catch_amalgamated.hpp"

SCENARIO("Class Student should get and set properties", "[student]") {
    GIVEN("Create object of Student class Student(Alex, Test, City, 56073561722, man, 666666)") {
        Student* testStudent = new Student("Alex", "Test", "City", "56073561722", "man", 666666);
        AND_GIVEN("create expected name Alex") {
            std::string expected = "Alex";
            WHEN("Student should return name Alex by getName() method") {
                REQUIRE(testStudent->getName() == expected);
            }
        }
        AND_GIVEN("create expected surname Test") {
            std::string expected = "Test";
            WHEN("Student should return surname Test by getSurname() method") {
                REQUIRE(testStudent->getSurname() == expected);
            }
        }
        AND_GIVEN("create expected address City") {
            std::string expected = "City";
            WHEN("Student should return address City by getAddress() method") {
                REQUIRE(testStudent->getAddress() == expected);
            }
        }
        AND_GIVEN("create expected index 666666") {
            size_t expected = 666666;
            WHEN("Student should return index 666666 by getIndex() method") {
                REQUIRE(testStudent->getIndex() == expected);
            }
        }
        AND_GIVEN("create expected pesel 56073561722") {
            std::string expected = "56073561722";
            WHEN("Student should return pesel 56073561722 by getPesel() method") {
                REQUIRE(testStudent->getPesel() == expected);
            }
        }
        AND_GIVEN("create expected gender man") {
            std::string expected = "man";
            WHEN("Student should return gender man by getGender() method") {
                REQUIRE(testStudent->getGender() == expected);
            }
        }
        AND_GIVEN("create expected name Joe and set to student") {
            std::string expected = "Joe";
            testStudent->setName(expected);
            WHEN("Student should return name Joe by getName() method") {
                REQUIRE(testStudent->getName() == expected);
            }
        }
        AND_GIVEN("create expected surname Black and set to student") {
            std::string expected = "Black";
            testStudent->setSurname(expected);
            WHEN("Student should return surname Black by getSurname() method") {
                REQUIRE(testStudent->getSurname() == expected);
            }
        }
        AND_GIVEN("create expected address New York and set to student") {
            std::string expected = "New York";
            testStudent->setAddress(expected);
            WHEN("Student should return address  New York by getAddress() method") {
                REQUIRE(testStudent->getAddress() == expected);
            }
        }
        AND_GIVEN("create expected index 134546 and set to student") {
            size_t expected = 134546;
            testStudent->setIndex(expected);
            WHEN("Student should return index 134546 by getIndex() method") {
                REQUIRE(testStudent->getIndex() == expected);
            }
        }
        AND_GIVEN("create expected pesel 84091234651 and set to student") {
            std::string expected = "84091234651";
            testStudent->setPesel(expected);
            WHEN("Student should return pesel 84091234651 by getPesel() method") {
                REQUIRE(testStudent->getPesel() == expected);
            }
        }
        AND_GIVEN("create expected gender women and set to student") {
            std::string expected = "women";
            testStudent->setGender(expected);
            WHEN("Student should return gender women by getGender() method") {
                REQUIRE(testStudent->getGender() == expected);
            }
        }
    }
}
SCENARIO("Class Employee should get and set properties", "[employee]") {
    GIVEN("Create object of Employee class Employe(Jonny, Cross, Moscov, 56073561722, man, 6666.66)") {
        Employee* testEmployee = new Employee("Jonny", "Cross", "Moscov", "56073561722", "man", 6666.66);
        AND_GIVEN("create expected name Jonny") {
            std::string expected = "Jonny";
            WHEN("Employee should return name Jonny by getName() method") {
                REQUIRE(testEmployee->getName() == expected);
            }
        }
        AND_GIVEN("create expected surname Cross") {
            std::string expected = "Cross";
            WHEN("Employee should return surname Cross by getSurname() method") {
                REQUIRE(testEmployee->getSurname() == expected);
            }
        }
        AND_GIVEN("create expected address Moscov") {
            std::string expected = "Moscov";
            WHEN("Employee should return address Moscov by getAddress() method") {
                REQUIRE(testEmployee->getAddress() == expected);
            }
        }
        AND_GIVEN("create expected salary 6666.66") {
            double expected = 6666.66;
            WHEN("Employee should return salary 6666.66 by getSalary() method") {
                REQUIRE(testEmployee->getSalary() == expected);
            }
        }
        AND_GIVEN("create expected pesel 56073561722") {
            std::string expected = "56073561722";
            WHEN("Employee should return pesel 56073561722 by getPesel() method") {
                REQUIRE(testEmployee->getPesel() == expected);
            }
        }
        AND_GIVEN("create expected gender man") {
            std::string expected = "man";
            WHEN("Employee should return gender man by getGender() method") {
                REQUIRE(testEmployee->getGender() == expected);
            }
        }
        AND_GIVEN("create expected name Joe and set to employee") {
            std::string expected = "Joe";
            testEmployee->setName(expected);
            WHEN("Employee should return name Joe by getName() method") {
                REQUIRE(testEmployee->getName() == expected);
            }
        }
        AND_GIVEN("create expected surname Black and set to employee") {
            std::string expected = "Black";
            testEmployee->setSurname(expected);
            WHEN("Employee should return surname Black by getSurname() method") {
                REQUIRE(testEmployee->getSurname() == expected);
            }
        }
        AND_GIVEN("create expected address New York and set to employee") {
            std::string expected = "New York";
            testEmployee->setAddress(expected);
            WHEN("Employee should return address  New York by getAddress() method") {
                REQUIRE(testEmployee->getAddress() == expected);
            }
        }
        AND_GIVEN("create expected salary 55.55 and set to employee") {
            double expected = 55.55;
            testEmployee->setSalary(expected);
            WHEN("Employee should return salary 55.55 by getSalary()) method") {
                REQUIRE(testEmployee->getSalary() == expected);
            }
        }
        AND_GIVEN("create expected pesel 84091234651 and set to employee") {
            std::string expected = "84091234651";
            testEmployee->setPesel(expected);
            WHEN("Employee should return pesel 84091234651 by getPesel() method") {
                REQUIRE(testEmployee->getPesel() == expected);
            }
        }
        AND_GIVEN("create expected gender women and set to employee") {
            std::string expected = "women";
            testEmployee->setGender(expected);
            WHEN("Employee should return gender women by getGender() method") {
                REQUIRE(testEmployee->getGender() == expected);
            }
        }
    }
}

SCENARIO("Class University should show working methods", "[university]") {
    GIVEN("Create object of University class without arguments and student Student(Alex, Test, City, 56073561722, man, 666666)") {
        University testUniversity;
        testUniversity.addStudent("Alex", "Test", "City", "56073561722", "man", 666666);
        AND_GIVEN("create expected value Student: Alex, Test, City, 666666, 56073561722, man") {
            std::string expected = "Student: Alex, Test, City, 666666, 56073561722, man\n";
            WHEN("University should display output Student: Alex, Test, City, 666666, 56073561722, man by displayBase()") {
                std::stringstream buffer;
                std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
                testUniversity.displayBase();
                std::string result = buffer.str();
                std::cout.rdbuf(prevcoutbuf);
                REQUIRE(result == expected);
            }
        }
        AND_GIVEN("create expected value Student: Alex, Test, City, 666666, 56073561722, man\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\n") {
            std::string expected = "Student: Alex, Test, City, 666666, 56073561722, man\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\n";
            WHEN("University should add students with employee and display output Student: Alex, Test, City, 666666, 56073561722, man\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\n, man by displayBase()") {
                std::stringstream buffer;
                std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
                testUniversity.addStudent("Wojtek", "Kowalski", "Miedzychod", "45454545454", "man", 162589);
                testUniversity.addStudent("Martyna", "Tucholska", "Wroclaw", "55030101230", "woman", 162780);
                testUniversity.addStudent("Wanda", "Nowak", "Lodz", "88530287659", "woman", 162576);
                testUniversity.addStudent("Ryszard", "Arbuz", "Gdynia", "85111507574", "man", 165729);
                testUniversity.addEmployee("Adam", "Borsuk", "Grudziadz", "85111502341", "man", 4250.66);
                testUniversity.displayBase();
                std::string result = buffer.str();
                std::cout.rdbuf(prevcoutbuf);
                REQUIRE(result == expected);
            }
        }
        AND_GIVEN("create expected value Student: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\n") {
            std::string expected = "Student: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\n";
            WHEN("University should add students with employee and display output Student: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\n, man by displayBase()") {
                std::stringstream buffer;
                std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
                testUniversity.addStudent("Wojtek", "Kowalski", "Miedzychod", "45454545454", "man", 162589);
                testUniversity.addStudent("Martyna", "Tucholska", "Wroclaw", "55030101230", "woman", 162780);
                testUniversity.addStudent("Wanda", "Nowak", "Lodz", "88530287659", "woman", 162576);
                testUniversity.addStudent("Ryszard", "Arbuz", "Gdynia", "85111507574", "man", 165729);
                testUniversity.addEmployee("Adam", "Borsuk", "Grudziadz", "85111502341", "man", 4250.66);
                testUniversity.sortByPesel();
                testUniversity.displayBase();

                std::string result = buffer.str();
                std::cout.rdbuf(prevcoutbuf);
                REQUIRE(result == expected);
            }
        }
        AND_GIVEN("create expected value Student: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n") {
            std::string expected = "Student: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n";
            WHEN("University should add students with employee and display output Student: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n, man by displayBase()") {
                std::stringstream buffer;
                std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
                testUniversity.addStudent("Wojtek", "Kowalski", "Miedzychod", "45454545454", "man", 162589);
                testUniversity.addStudent("Martyna", "Tucholska", "Wroclaw", "55030101230", "woman", 162780);
                testUniversity.addStudent("Wanda", "Nowak", "Lodz", "88530287659", "woman", 162576);
                testUniversity.addStudent("Ryszard", "Arbuz", "Gdynia", "85111507574", "man", 165729);
                testUniversity.addEmployee("Adam", "Borsuk", "Grudziadz", "85111502341", "man", 4250.66);
                testUniversity.sortBySurname();
                testUniversity.displayBase();

                std::string result = buffer.str();
                std::cout.rdbuf(prevcoutbuf);
                REQUIRE(result == expected);
            }
        }
        AND_GIVEN("create expected value  Employee: Tomek, Niedzielsk, Kazimierz, 86120607584, man, 10268.8\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n") {
            std::string expected =
                "Employee: Tomek, Niedzielski, Kazimierz, 86120607584, man, 10268.8\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n";
            WHEN("University should add students with employee and display output Employee: Tomek, Niedzielski, Kazimierz, 86120607584, man, 10268.8\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 4250.66\nStudent: Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nStudent: Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nStudent: Wanda, Nowak, Lodz, 162576, 88530287659, woman\nStudent: Alex, Test, City, 666666, 56073561722, man\nStudent: Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n, man by displayBase()") {
                std::stringstream buffer;
                std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
                testUniversity.addStudent("Wojtek", "Kowalski", "Miedzychod", "45454545454", "man", 162589);
                testUniversity.addStudent("Martyna", "Tucholska", "Wroclaw", "55030101230", "woman", 162780);
                testUniversity.addStudent("Wanda", "Nowak", "Lodz", "88530287659", "woman", 162576);
                testUniversity.addStudent("Ryszard", "Arbuz", "Gdynia", "85111507574", "man", 165729);
                testUniversity.addEmployee("Adam", "Borsuk", "Grudziadz", "85111502341", "man", 4250.66);
                testUniversity.addEmployee("Tomek", "Niedzielski", "Kazimierz", "86120607584", "man", 10268.8);
                testUniversity.sortBySalary();
                testUniversity.displayBase();

                std::string result = buffer.str();
                std::cout.rdbuf(prevcoutbuf);
                REQUIRE(result == expected);
            }
        }

        AND_GIVEN("create two pesel 55030101230 - valid, 89873561722 - not valid") {
            std::string valid = "55030101230";
            std::string notValid = "89873561722";
            WHEN("University should prove validity of pesel") {
                REQUIRE_FALSE(testUniversity.validationByPesel(notValid));
                REQUIRE(testUniversity.validationByPesel(valid));
            }
        }
        AND_GIVEN("add employee with salary 4250.66  and modify to 9999.99") {
            testUniversity.addEmployee("Adam", "Borsuk", "Grudziadz", "85111502341", "man", 4250.66);
            std::string expected = "Student: Alex, Test, City, 666666, 56073561722, man\nEmployee: Adam, Borsuk, Grudziadz, 85111502341, man, 9999.99\n";
            double newSalary = 9999.99;
            WHEN("University should change salary to 9999.99") {
                std::stringstream buffer;
                std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
                testUniversity.modifySalary(newSalary, "85111502341");
                testUniversity.displayBase();
                std::string result = buffer.str();
                std::cout.rdbuf(prevcoutbuf);
                REQUIRE(result == expected);
            }
        }
    }
}
