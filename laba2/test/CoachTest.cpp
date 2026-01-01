#include <gtest/gtest.h>
#include "core/Coach/Coach.h"

TEST(CoachTest, CoachSalaryIsBase) {
    Coach c("Мария", 40, "+79001234567", "m@test.ru", 201, "Pilates"); // ✅
    EXPECT_DOUBLE_EQ(c.getSalary(), 60000.0);
}

TEST(CoachTest, SpecializationIsStored) {
    Coach c("Константин", 33, "+79001234567", "k@test.ru", 202, "CrossFit"); // ✅
    EXPECT_EQ(c.getSpecialization(), "CrossFit");
}