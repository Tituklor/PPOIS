#include <gtest/gtest.h>
#include "../Room/changing_room_defs.h"
#include "../Room/fitness_zone.h"
#include "../Room/gym_zone.h"
#include "../Room/pool_zone.h"
#include "../Room/ring_zone.h"
#include "../Room/sauna_zone.h"
#include "../Room/scale_defs.h"
#include "../Human/person_base.h"
#include "../Human/error_defs.h"

// ====================== ChangingRoom Tests ======================
class ChangingRoomTest : public ::testing::Test {
protected:
    // метод настройки
    void SetUp() override {
        WeightScale scale("ScaleCo", "ModelX", 200.0, 0.1,
                          true, true, true, true, true, 40.0);
        room = new ChangingRoom(25.5, scale, 'M');
    }
//метод очистки
    void TearDown() override {
        delete room;//освобождает память
    }

    ChangingRoom* room;
};

TEST_F(ChangingRoomTest, ConstructorAndRetrieveGender) {
EXPECT_EQ(room->retrieve_gender(), 'M');
}
// Проверка установки шкафчиков
TEST_F(ChangingRoomTest, InstallStorageUnit) {
room->install_storage_unit(101);//Установка первого шкафчика
EXPECT_EQ(room->storage_units.size(), 1); //Проверка размера вектора
room->install_storage_unit(102);
EXPECT_EQ(room->storage_units.size(), 2);
}
//шкафчики в раздевалке автоматически сортируются по номеру
TEST_F(ChangingRoomTest, InstallStorageUnitInOrder) {
room->install_storage_unit(105);
room->install_storage_unit(103);
room->install_storage_unit(104);
//Проверка
EXPECT_EQ(room->storage_units[0].num, 103);
EXPECT_EQ(room->storage_units[1].num, 104);
EXPECT_EQ(room->storage_units[2].num, 105);
}

// ====================== FitnessZone Tests ======================
class FitnessZoneTest : public ::testing::Test {
protected:
    void SetUp() override {
        //new — это оператор динамического выделения памяти
        zone = new FitnessZone(50.0, 100.0, 10, 20, 5, 8, 15, 3);
    }

    void TearDown() override {
        delete zone;
    }

    FitnessZone* zone;
};

TEST_F(FitnessZoneTest, ConstructorAndRetrievals) {
EXPECT_EQ(zone->retrieve_mat_count(), 10);
EXPECT_EQ(zone->retrieve_resistance_band_count(), 20);
EXPECT_EQ(zone->retrieve_hula_hoop_count(), 5);
EXPECT_EQ(zone->retrieve_foam_roller_count(), 8);
EXPECT_EQ(zone->retrieve_exercise_ball_count(), 15);
EXPECT_EQ(zone->retrieve_treadmill_count(), 3);
}
//проверка, что зона фитнеса может быть пустой
TEST_F(FitnessZoneTest, ZeroCounts) {
FitnessZone emptyZone(50.0, 100.0, 0, 0, 0, 0, 0, 0);
EXPECT_EQ(emptyZone.retrieve_mat_count(), 0);
EXPECT_EQ(emptyZone.retrieve_treadmill_count(), 0);
}

// ====================== GymZone Tests ======================
class GymZoneTest : public ::testing::Test {
protected:
    void SetUp() override {
        zone = new GymZone(100.0, 200.0, true, 5, 50, 20, 10, 15, 8);
    }

    void TearDown() override {
        delete zone;
    }

    GymZone* zone;
};
//проверка конструктора и наличия турника
TEST_F(GymZoneTest, ConstructorAndHasPullupBar) {
EXPECT_TRUE(zone->has_pullup_bar());//есть турник
GymZone noPullupZone(100.0, 200.0, false, 5, 50, 20, 10, 15, 8);
EXPECT_FALSE(noPullupZone.has_pullup_bar());
}
//проверка количества оборудования
TEST_F(GymZoneTest, EquipmentCounts) {
EXPECT_EQ(zone->retrieve_trainer_station_count(), 5);
EXPECT_EQ(zone->retrieve_weight_plate_count(), 50);
EXPECT_EQ(zone->retrieve_dumbbell_pair_count(), 20);
EXPECT_EQ(zone->retrieve_barbell_count(), 10);
EXPECT_EQ(zone->retrieve_kettlebell_count(), 15);
EXPECT_EQ(zone->retrieve_lifting_strap_count(), 8);
}

// ====================== PoolZone Tests ======================
class PoolZoneTest : public ::testing::Test {
protected:
    void SetUp() override {
        zone = new PoolZone(500.0, 2.5, 25.0, 8, 3.0);
    }

    void TearDown() override {
        delete zone;
    }

    PoolZone* zone;
};
// проверка конструктора и геттеров
TEST_F(PoolZoneTest, ConstructorAndRetrievals) {
EXPECT_DOUBLE_EQ(zone->retrieve_water_depth(), 2.5);
EXPECT_DOUBLE_EQ(zone->retrieve_pool_length(), 25.0);
EXPECT_EQ(zone->retrieve_swimming_lanes_count(), 8);
EXPECT_DOUBLE_EQ(zone->retrieve_diving_platform_height(), 3.0);
}
//проверка упрощённого конструктора
TEST_F(PoolZoneTest, SimplifiedConstructor) {
PoolZone simpleZone(500.0, 2.0); //Остальные парраметры по умолчанию
EXPECT_DOUBLE_EQ(simpleZone.retrieve_water_depth(), 2.0);
EXPECT_DOUBLE_EQ(simpleZone.retrieve_pool_length(), 25.0);
EXPECT_EQ(simpleZone.retrieve_swimming_lanes_count(), 8);
EXPECT_DOUBLE_EQ(simpleZone.retrieve_diving_platform_height(), 3.0);
}

// ====================== RingZone Tests ======================
class RingZoneTest : public ::testing::Test {
protected:
    void SetUp() override {
        zone = new RingZone(30.0, 80.0, true);
    }

    void TearDown() override {
        delete zone;
    }

    RingZone* zone;
};
//проверка конструктора и наличия груши
TEST_F(RingZoneTest, ConstructorAndHasCombatBag) {
EXPECT_TRUE(zone->has_combat_bag());

RingZone noBagZone(30.0, 80.0, false);
EXPECT_FALSE(noBagZone.has_combat_bag());
}


// ====================== SaunaZone Tests ======================
class SaunaZoneTest : public ::testing::Test {
protected:
    void SetUp() override {
        zone = new SaunaZone(25.0, 30.0, 120, 60);
    }

    void TearDown() override {
        delete zone;
    }

    SaunaZone* zone;
};
//проверка конструктора и геттеров
TEST_F(SaunaZoneTest, ConstructorAndRetrievals) {
EXPECT_EQ(zone->retrieve_maximum_heat_level(), 120);
EXPECT_EQ(zone->retrieve_maximum_moisture_level(), 60);
}
//проверка исключения при недопустимой влажности
TEST_F(SaunaZoneTest, InvalidMoistureLevelThrowsException) {
EXPECT_THROW({
SaunaZone invalidZone(25.0, 30.0, 120, 150);
}, HumidityControlError);
}
//проверка допустимых значений влажности
TEST_F(SaunaZoneTest, ValidMoistureLevel) {
EXPECT_NO_THROW({ //макрос проверки отсутствия исключений
SaunaZone validZone(25.0, 30.0, 120, 100);
});

EXPECT_NO_THROW({
SaunaZone validZone(25.0, 30.0, 120, 0);
});
}

// ====================== WeightScale Tests ======================
class WeightScaleTest : public ::testing::Test {
protected:
    void SetUp() override {
        scale = new WeightScale("ScaleCo", "PrecisionX", 200.0, 0.1,
                                true, true, true, true, true, 45.0);
    }

    void TearDown() override {
        delete scale;
    }

    WeightScale* scale;
};
//проверка конструктора и допустимой точности
TEST_F(WeightScaleTest, ConstructorAndValidPrecision) {
// принимает допустимые значения точности (0.1, 0.01, 0.001) без исключений
EXPECT_NO_THROW({
WeightScale scale1("A", "B", 200, 0.1, true, true, true, true, true, 40);
WeightScale scale2("A", "B", 200, 0.01, true, true, true, true, true, 40);
WeightScale scale3("A", "B", 200, 0.001, true, true, true, true, true, 40);
});
}
//проверка исключения при недопустимой точности
TEST_F(WeightScaleTest, InvalidPrecisionThrowsException) {
EXPECT_THROW({
WeightScale invalidScale("A", "B", 200, 0.15, true, true, true, true, true, 40);
}, InvalidPrecisionError);//исключение из-за недопустимой точности 0.15
}
//проверка взвешивания человека
TEST_F(WeightScaleTest, MeasurePersonWeight) {
class TestPerson : public PersonBase {
public:
    TestPerson(double weight) { body_weight = weight; }
};

TestPerson person(75.5);
EXPECT_DOUBLE_EQ(scale->measure_person_weight(person), 75.5);
}

// ====================== Integration Tests ======================
TEST(IntegrationTest, GymAndFitnessZoneTogether) {
FitnessZone fitZone(50.0, 100.0, 10, 20, 5, 8, 15, 3);
GymZone gymZone(100.0, 200.0, true, 5, 50, 20, 10, 15, 8);

EXPECT_EQ(fitZone.retrieve_mat_count(), 10);
EXPECT_EQ(gymZone.retrieve_dumbbell_pair_count(), 20);
}

TEST(IntegrationTest, ChangingRoomWithScales) {
WeightScale scale("Brand", "Model", 180.0, 0.01,
                  true, false, true, true, false, 35.0);
ChangingRoom room(30.0, scale, 'F');

EXPECT_EQ(room.retrieve_gender(), 'F');
EXPECT_NO_THROW(room.install_storage_unit(201));
}

// ====================== Main Function ======================
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}