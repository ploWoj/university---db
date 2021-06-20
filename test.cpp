#include <tuple>
#include "Student.hpp"
#include "Univeristy.hpp"
#include "gtest/gtest.h"

Student s1("Alex", "Test", "City", 666666, "56073561722", "man");

//Start Student class tests
TEST(StudentGetNameTest, ShouldVerifyStudentGetName) {
    EXPECT_EQ(s1.getName(), "Alex");
}
TEST(StudentGetLNameTest, ShouldVerifyStudentGetLName) {
    EXPECT_EQ(s1.getLname(), "Test");
}
TEST(StudentGetAdressTest, ShouldVerifyStudentGetAdress) {
    EXPECT_EQ(s1.getAdress(), "City");
}
TEST(StudentGetIndexTest, ShouldVerifyStudentGetIndex) {
    EXPECT_EQ(s1.getIndex(), 666666);
}
TEST(StudentGetPeselTest, ShouldVerifyStudentGetPesel) {
    EXPECT_EQ(s1.getPesel(), "56073561722");
}
TEST(StudentGetGenderTest, ShouldVerifyStudentGetGender) {
    EXPECT_EQ(s1.getGender(), "man");
}
TEST(StudentSetNameTest, ShouldVerifyStudentSetName) {
    s1.setName("Joe");
    EXPECT_EQ(s1.getName(), "Joe");
}
TEST(StudentSetLNameTest, ShouldVerifyStudentSetLName) {
    s1.setLname("Black");
    EXPECT_EQ(s1.getLname(), "Black");
}
TEST(StudentSetAdressTest, ShouldVerifyStudentSetAdress) {
    s1.setAdress("New York");
    EXPECT_EQ(s1.getAdress(), "New York");
}
TEST(StudentSetIndexTest, ShouldVerifyStudentSetIndex) {
    s1.setIndex(134546);
    EXPECT_EQ(s1.getIndex(), 134546);
}
TEST(StudentSetPeselTest, ShouldVerifyStudentSetPesel) {
    s1.setPesel("84091234651");
    EXPECT_EQ(s1.getPesel(), "84091234651");
}
TEST(StudentSetGenderTest, ShouldVerifyStudentSetGender) {
    s1.setGender("woman");
    EXPECT_EQ(s1.getGender(), "woman");
}
// End Student class tests
University testUni(s1);

TEST(UniversityDisplayStudentTest, ShouldVerifyUniversityDisplayStudent){
    testing::internal::CaptureStdout();
    testUni.displayStudent(s1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Joe, Black, New York, 134546, 84091234651, woman\n" ,output);
}
TEST(UniversityDisplayBaseAndAddStudentTest, ShouldVerifyUniversityDisplayBaseAndAddStudent){
    testing::internal::CaptureStdout();
    testUni.addStudent("Wojtek", "Kowalski" , "Miedzychod", 162589, "45454545454", "man");
    testUni.addStudent("Martyna", "Tucholska", "Wroclaw", 162780, "55030101230", "woman");
    testUni.addStudent("Wanda", "Nowak" , "Lodz", 162576, "88530287659", "woman");
    testUni.addStudent("Ryszard", "Arbuz", "Gdynia", 165729, "85111507574", "man");
    testUni.dispalayBase();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("0.Alex, Test, City, 666666, 56073561722, man\n1.Wojtek, Kowalski, Miedzychod, 162589, 45454545454, man\n2.Martyna, Tucholska, Wroclaw, 162780, 55030101230, woman\n3.Wanda, Nowak, Lodz, 162576, 88530287659, woman\n" ,output);
}

TEST( UniversityPeselTest, ShouldVerifyUniversityPesel) {
    EXPECT_EQ(testUni.validationByPesel("89873561722"), false);
    EXPECT_EQ(testUni.validationByPesel("55030101230"), true);
}
