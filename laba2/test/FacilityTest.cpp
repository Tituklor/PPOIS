#include <gtest/gtest.h>
#include "facility/Facility.h"

TEST(FacilityTest, FacilityIsAvailableByDefault) {
    Facility f("Main Gym", "Gym", 20, "1F");
    EXPECT_TRUE(f.isAvailable());
    EXPECT_EQ(f.getStatus(), "available");
}

TEST(FacilityTest, CanMarkAsUnavailable) {
    Facility f("Pool", "Pool", 10, "B1");
    f.setStatus("maintenance");
    EXPECT_FALSE(f.isAvailable());
}