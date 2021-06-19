#include <tuple>
#include "Student.hpp"
#include "Univeristy.hpp"
#include "gtest/gtest.h"

Student s1("Alex", "Test", "City", 666666, "56073561722", "man");
University testUni(s1);

TEST(StudentNameTest, ShouldVerifyStudentGetName) {
    EXPECT_EQ(s1.getName(), "Alex");
}
TEST(StudentLNameTest, ShouldVerifyStudentGetLName) {
    EXPECT_EQ(s1.getLname(), "Test");
}
TEST(StudentAdressTest, ShouldVerifyStudentGetAdress) {
    EXPECT_EQ(s1.getAdress(), "City");
}
TEST(StudentIndexTest, ShouldVerifyStudentGetIndex) {
    EXPECT_EQ(s1.getIndex(), 666666);
}
TEST(StudentPeselTest, ShouldVerifyStudentGetPesel) {
    EXPECT_EQ(s1.getPesel(), "56073561722");
}
TEST(StudentGenderTest, ShouldVerifyStudentGetGender) {
    EXPECT_EQ(s1.getGender(), "man");
}
TEST(UniversityTest, ShouldVerifyUniversityPesel) {
    EXPECT_EQ(testUni.validationByPesel("89873561722"), false);
}
