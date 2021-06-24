#include "Student.hpp"
#include "University.hpp"
#include "gtest/gtest.h"

Student* initStudent = new Student("Alex", "Test", "City", 666666, "56073561722", "man");

//Start Student class tests
TEST(StudentGetNameTest, ShouldVerifyStudentGetName) {
    EXPECT_EQ(initStudent->getName(), "Alex");
}
TEST(StudentGetSurnameTest, ShouldVerifyStudentGetSurname) {
    EXPECT_EQ(initStudent->getSurname(), "Test");
}
TEST(StudentGetAddressTest, ShouldVerifyStudentGetAddress) {
    EXPECT_EQ(initStudent->getAddress(), "City");
}
TEST(StudentGetIndexTest, ShouldVerifyStudentGetIndex) {
    EXPECT_EQ(initStudent->getIndex(), 666666);
}
TEST(StudentGetPeselTest, ShouldVerifyStudentGetPesel) {
    EXPECT_EQ(initStudent->getPesel(), "56073561722");
}
TEST(StudentGetGenderTest, ShouldVerifyStudentGetGender) {
    EXPECT_EQ(initStudent->getGender(), "man");
}
TEST(StudentSetNameTest, ShouldVerifyStudentSetName) {
    initStudent->setName("Joe");
    EXPECT_EQ(initStudent->getName(), "Joe");
}
TEST(StudentSetSurnameTest, ShouldVerifyStudentSetSurname) {
    initStudent->setSurname("Black");
    EXPECT_EQ(initStudent->getSurname(), "Black");
}
TEST(StudentSetAddressTest, ShouldVerifyStudentSetAddress) {
    initStudent->setAddress("New York");
    EXPECT_EQ(initStudent->getAddress(), "New York");
}
TEST(StudentSetIndexTest, ShouldVerifyStudentSetIndex) {
    initStudent->setIndex(134546);
    EXPECT_EQ(initStudent->getIndex(), 134546);
}
TEST(StudentSetPeselTest, ShouldVerifyStudentSetPesel) {
    initStudent->setPesel("84091234651");
    EXPECT_EQ(initStudent->getPesel(), "84091234651");
}
TEST(StudentSetGenderTest, ShouldVerifyStudentSetGender) {
    initStudent->setGender("woman");
    EXPECT_EQ(initStudent->getGender(), "woman");
}
// End Student class tests
University testUniversityDB(*initStudent);

TEST(UniversityDisplayStudentTest, ShouldVerifyUniversityDisplayStudent) {
    testing::internal::CaptureStdout();
    testUniversityDB.displayStudent(initStudent);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Joe, Black, New York, 134546, 84091234651, woman\n", output);
}
TEST(UniversityDisplayBaseAndAddStudentTest, ShouldVerifyUniversityDisplayBaseAndAddStudent) {
    testing::internal::CaptureStdout();
    testUniversityDB.addStudent("Wojtek", "Kowalski", "Miedzychod", 162589, "45454545454", "man");
    testUniversityDB.addStudent("Martyna", "Tucholska", "Wroclaw", 162780, "55030101230", "woman");
    testUniversityDB.addStudent("Wanda", "Nowak", "Lodz", 162576, "88530287659", "woman");
    testUniversityDB.addStudent("Ryszard", "Arbuz", "Gdynia", 165729, "85111507574", "man");
    testUniversityDB.displayBase();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Alex, Test, City, 666666, 56073561722, man\nWojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nMartyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nWanda, Nowak, Lodz, 162576, 88530287659, woman\nRyszard, Arbuz, Gdynia, 165729, 85111507574, man\n", output);
}
TEST(UniversitySortByPeselTest, ShouldVerifyUniversitySortByPesel) {
    testing::internal::CaptureStdout();
    testUniversityDB.sortByPesel();
    testUniversityDB.displayBase();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nMartyna, Tucholska, Wroclaw, 162780, 55030101230, woman\nAlex, Test, City, 666666, 56073561722, man\nRyszard, Arbuz, Gdynia, 165729, 85111507574, man\nWanda, Nowak, Lodz, 162576, 88530287659, woman\n", output);
}
TEST(UniversitySortBySurnameTest, ShouldVerifyUniversitySortBySurname) {
    testing::internal::CaptureStdout();
    testUniversityDB.sortBySurname();
    testUniversityDB.displayBase();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Ryszard, Arbuz, Gdynia, 165729, 85111507574, man\nWojtek, Kowalski, Miedzychod, 162589, 45454545454, man\nWanda, Nowak, Lodz, 162576, 88530287659, woman\nAlex, Test, City, 666666, 56073561722, man\nMartyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n", output);
}
TEST(UniversityPeselTest, ShouldVerifyUniversityPesel) {
    EXPECT_EQ(testUniversityDB.validationByPesel("89873561722"), false);
    EXPECT_EQ(testUniversityDB.validationByPesel("55030101230"), true);
}
TEST(UniversityFindBySurnameTest, ShouldVerifyUniversityFindBySurname) {
    // Existing students in university database
    EXPECT_TRUE(testUniversityDB.findBySurname("Nowak") != nullptr);
    EXPECT_TRUE(testUniversityDB.findBySurname("Arbuz") != nullptr);
    EXPECT_TRUE(testUniversityDB.findBySurname("Kowalski") != nullptr);
    EXPECT_TRUE(testUniversityDB.findBySurname("Test") != nullptr);
    EXPECT_TRUE(testUniversityDB.findBySurname("Tucholska") != nullptr);

    // Imagined student surnames
    EXPECT_TRUE(testUniversityDB.findBySurname("NOwak") == nullptr);
    EXPECT_TRUE(testUniversityDB.findBySurname("Black") == nullptr);
    EXPECT_TRUE(testUniversityDB.findBySurname("Ziobron") == nullptr);
}
TEST(UniversityFindByPeselTest, ShouldVerifyUniversityFindByPesel) {
    // Existing students in university database
    EXPECT_TRUE(testUniversityDB.findByPesel("85111507574") != nullptr);
    EXPECT_TRUE(testUniversityDB.findByPesel("45454545454") != nullptr);
    EXPECT_TRUE(testUniversityDB.findByPesel("88530287659") != nullptr);
    EXPECT_TRUE(testUniversityDB.findByPesel("56073561722") != nullptr);
    EXPECT_TRUE(testUniversityDB.findByPesel("55030101230") != nullptr);
    // Imagined student pesels
    EXPECT_TRUE(testUniversityDB.findByPesel("88599287659") == nullptr);
    EXPECT_TRUE(testUniversityDB.findByPesel("55030121230") == nullptr);
    EXPECT_TRUE(testUniversityDB.findByPesel("56073961722") == nullptr);
}
TEST(UniversityDeleteByIndexNumber, ShouldVerifyUniversityDeleteByIndexNumber) {
    testUniversityDB.deletedByIndexNumber(165729);
    EXPECT_TRUE(testUniversityDB.findByPesel("85111507574") == nullptr);

    testUniversityDB.deletedByIndexNumber(162589);
    EXPECT_TRUE(testUniversityDB.findByPesel("45454545454") == nullptr);

    testUniversityDB.deletedByIndexNumber(162576);
    EXPECT_TRUE(testUniversityDB.findByPesel("88530287659") == nullptr);

    testUniversityDB.deletedByIndexNumber(162780);
    EXPECT_TRUE(testUniversityDB.findByPesel("55030101230") == nullptr);

    testing::internal::CaptureStdout();
    testUniversityDB.displayBase();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Alex, Test, City, 666666, 56073561722, man\n", output);
}
TEST(UniversityExportDatabaseTest, ShouldVerifyUniversityExportDatabase) {
     testUniversityDB.exportDatabase("testUniversityDatabase.csv");
    //testUniversityDB.deletedByIndexNumber(666666);
    testing::internal::CaptureStdout();
    testUniversityDB.importDatabase("testUniversityDatabase.csv");
    testUniversityDB.displayBase();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("There is such student in our database\nAlex, Test, City, 666666, 56073561722, man\n", output);
}
