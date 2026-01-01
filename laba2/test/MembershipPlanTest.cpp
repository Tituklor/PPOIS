#include <gtest/gtest.h>
#include "membership/MembershipPlan.h"

TEST(MembershipPlanTest, StandardPlanHasCorrectFeeAndDuration) {
    MembershipPlan plan(MembershipPlan::STANDARD);
    EXPECT_DOUBLE_EQ(plan.getMonthlyFee(), 2500.0);
    EXPECT_EQ(plan.getDurationDays(), 30);
    EXPECT_EQ(plan.getTypeName(), "Standard");
}

TEST(MembershipPlanTest, PremiumPlanHasCorrectFeeAndDuration) {
    MembershipPlan plan(MembershipPlan::PREMIUM);
    EXPECT_DOUBLE_EQ(plan.getMonthlyFee(), 4500.0);
    EXPECT_EQ(plan.getDurationDays(), 90);
    EXPECT_EQ(plan.getTypeName(), "Premium");
}