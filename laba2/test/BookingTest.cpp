#include <gtest/gtest.h>
#include "schedule/Booking.h"

TEST(BookingTest, MemberBookingIsForMember) {
    Booking b(101, "Gym", "10:00", true);
    EXPECT_TRUE(b.isForMember());
    EXPECT_EQ(b.getStatus(), "booked");
}

TEST(BookingTest, VisitorBookingIsNotForMember) {
    Booking b(0, "Pool", "11:00", false);
    EXPECT_FALSE(b.isForMember());
}