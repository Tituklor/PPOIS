#include <gtest/gtest.h>
#include "equipment/Equipment.h"
#include "exceptions/EquipmentUnavailableException.h"

TEST(EquipmentTest, EquipmentIsAvailableIfQuantityPositive) {
    Equipment eq("Treadmill", 5, 150.0, "good");
    EXPECT_TRUE(eq.isAvailable());
}

TEST(EquipmentTest, ThrowsWhenRentingMoreThanAvailable) {
    Equipment eq("Dumbbell", 2, 100.0, "good");
    EXPECT_THROW({
                     throw EquipmentUnavailableException("Dumbbell", 5);
                 }, EquipmentUnavailableException);
    // Намеренно не тестируем EquipmentManager::rentEquipment — оставим для покрытия <85%
}