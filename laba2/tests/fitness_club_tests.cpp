#include <gtest/gtest.h>
#include "../FitnessClub/error_defs/error_defs.h"
#include "../FitnessClub/Enums/enums_defs.h"
#include "../FitnessClub/Human/person_base.h"
#include "../FitnessClub/Human/employee_base.h"
#include "../FitnessClub/Human/manager_defs.h"
#include "../FitnessClub/Human/janitor_defs.h"
#include "../FitnessClub/Human/client_defs.h"
#include "../FitnessClub/Human/accountant_defs.h"
#include "../FitnessClub/Human/coach_defs.h"
#include "../FitnessClub/Human/frontdesk_defs.h"
#include "../FitnessClub/Human/social_mgr_defs.h"
#include "../FitnessClub/Reception/client_registry.h"
#include "../FitnessClub/Reception/key_rack.h"
#include "../FitnessClub/Reception/access_defs.h"
#include "../FitnessClub/Reception/frontdesk.h"
#include "../FitnessClub/Reception/membership_defs.h"
#include "../FitnessClub/Room/space_defs.h"
#include "../FitnessClub/Room/zone_base.h"
#include "../FitnessClub/Room/changing_room_defs.h"
#include "../FitnessClub/Room/fitness_zone.h"
#include "../FitnessClub/Room/gym_zone.h"
#include "../FitnessClub/Room/storage_defs.h"
#include "../FitnessClub/Room/sauna_zone.h"
#include "../FitnessClub/Room/scale_defs.h"
#include "../FitnessClub/Room/pool_zone.h"
#include "../FitnessClub/Room/ring_zone.h"
#include "../FitnessClub/Schedule/schedule_mgr.h"
#include "../FitnessClub/SM/social_base.h"
#include "../FitnessClub/SM/insta_defs.h"
#include "../FitnessClub/SM/tiktok_defs.h"
#include "../FitnessClub/Shop/product_base.h"
#include "../FitnessClub/Shop/exercise_ball_defs.h"
#include "../FitnessClub/Shop/creatine_supplement.h"
#include "../FitnessClub/Shop/beverage_defs.h"
#include "../FitnessClub/Shop/pool_slippers_defs.h"
#include "../FitnessClub/Shop/headband_defs.h"
#include "../FitnessClub/Shop/jump_rope_defs.h"
#include "../FitnessClub/Shop/protein_bar_defs.h"
#include "../FitnessClub/Shop/swim_cap_defs.h"
#include "../FitnessClub/Shop/swimwear_defs.h"
#include "../FitnessClub/Shop/towel_defs.h"
#include "../FitnessClub/Shop/workout_gloves_defs.h"
#include "../FitnessClub/Mirror/reflector_defs.h"

// === HUMAN TESTS ===
TEST(PersonBaseTest, BasicInfo)
{
PersonBase person("Alice", 25, 'f', "2000-01-01");
EXPECT_EQ(person.retrieve_name(), "Alice");
EXPECT_EQ(person.retrieve_age(), 25);
EXPECT_EQ(person.retrieve_gender(), Gender::Female);
EXPECT_EQ(person.retrieve_birth_date(), "2000-01-01");
}

TEST(EmployeeBaseTest, SalaryAndContact)
{
AccessKey access_key;
EmployeeBase employee("Bob", 30, 'm', "1995-05-15", true, &access_key,
                      true, 1200.0, 75.0, 180, 5, 4500.0, "+123456789");

EXPECT_DOUBLE_EQ(employee.retrieve_salary(), 4500.0);
EXPECT_EQ(employee.retrieve_contact(), "+123456789");
EXPECT_TRUE(employee.is_full_time());
}

TEST(ManagerDefsTest, ScheduleManagement)
{
AccessKey access_key;
ScheduleManager schedule_mgr(9, 21);

ManagerDefs admin("Clara", 40, 'f', "1985-03-10", true, &access_key,
                  false, 1500.0, 65.0, 165, 12, 8000.0, "+987654321");

admin.adjust_open_hours(schedule_mgr, 8);
admin.adjust_close_hours(schedule_mgr, 22);

EXPECT_EQ(schedule_mgr.retrieve_open_hour(), 8);
EXPECT_EQ(schedule_mgr.retrieve_close_hour(), 22);
}

TEST(JanitorDefsTest, CleaningDuty)
{
AccessKey access_key;
JanitorDefs janitor("Mike", 35, 'm', "1990-07-20", true, &access_key,
                    true, 900.0, 80.0, 175, 3, 3000.0, "+555666777");

EXPECT_EQ(janitor.retrieve_cleaning_experience(), 3);
}

TEST(ClientDefsTest, ClientMeasurements)
{
AccessKey access_key;
ClientDefs client("Sara", 28, 'f', "1997-11-11", true, &access_key,
                  1100.0, 60.0, 170, 2, 0.0, "+444555666");

EXPECT_DOUBLE_EQ(client.retrieve_weight(), 60.0);
EXPECT_EQ(client.retrieve_visits_count(), 2);
}

TEST(AccountantDefsTest, FinancialTracking)
{
AccessKey access_key;
AccountantDefs accountant("Emma", 32, 'f', "1993-04-05", true, &access_key,
                          false, 1300.0, 62.0, 168, 7, 5500.0, "+777888999");

EXPECT_EQ(accountant.retrieve_accounting_experience(), 7);
}

TEST(CoachDefsTest, TrainingSpecialization)
{
AccessKey access_key;
CoachDefs trainer("Alex", 29, 'm', "1996-08-15", true, &access_key,
                  true, 1400.0, 85.0, 182, 4, 6000.0, "+111222333",
                  "alex_fit", "powerlift_pro", 8000, 12000, 180, 20000,
                  900, 75, "Strength specialist", true);

EXPECT_TRUE(trainer.is_certified());
EXPECT_EQ(trainer.retrieve_specialization(), "Strength specialist");
}

TEST(FrontdeskDefsTest, CheckInOut)
{
AccessKey access_key;
FrontdeskDefs receptionist("Lily", 26, 'f', "1999-02-28", true, &access_key,
                           true, 1000.0, 58.0, 162, 6, 4200.0, "+333444555");

ClientDefs client("TestClient", 25, 'm', "2000-01-01", true, &access_key, 80.0, 175, 1, 0.0, "");
receptionist.process_check_in(client);
EXPECT_EQ(client.retrieve_visits_count(), 2);
}

TEST(SocialMgrDefsTest, CampaignManagement)
{
AccessKey access_key;
SocialMgrDefs smm("Kate", 27, 'f', "1998-06-12", true, &access_key,
                  false, 1100.0, 59.0, 164, 5, 4800.0, "+999000111");

EXPECT_EQ(smm.retrieve_campaign_count(), 5);
}

// === RECEPTION TESTS ===
TEST(ClientRegistryTest, Registration)
{
ClientRegistry registry;
ClientDefs client("John", 30, 'm', "1995-01-01", true, nullptr, 85.0, 180, 0, 0.0, "");

registry.register_visitor(client);
EXPECT_EQ(registry.retrieve_total_clients(), 1);
}

TEST(KeyRackTest, KeyManagement)
{
KeyRack rack(50);
AccessKey key1, key2;

rack.assign_key(key1);
rack.return_key(key1);

EXPECT_EQ(rack.retrieve_available_keys(), 50);
}

TEST(FrontdeskTest, PaymentProcessing)
{
AccessKey access_key;
Frontdesk frontdesk_person("Tom", 28, 'm', "1997-09-09", true, &access_key, true, 1050.0, 78.0, 178, 4, 4300.0, "+222333444");

MembershipDefs basic_membership(3000.0, MembershipType::Monthly);
frontdesk_person.process_payment(basic_membership, 3000.0);

EXPECT_TRUE(basic_membership.is_active());
}

// === ROOM TESTS ===
TEST(SpaceDefsTest, RoomCapacity)
{
SpaceDefs gym_room("Main Gym", 100, RoomType::GymZone);
EXPECT_EQ(gym_room.retrieve_max_capacity(), 100);
}

TEST(ChangingRoomDefsTest, LockerAssignment)
{
ChangingRoomDefs changing_room(50);
ClientDefs client("User", 25, 'm', "2000-01-01", true, nullptr, 70.0, 170, 1, 0.0, "");

changing_room.assign_locker(client);
EXPECT_TRUE(changing_room.is_locker_assigned(client));
}

TEST(FitnessZoneTest, EquipmentCheck)
{
FitnessZone fitness_area(20, EquipmentType::Cardio);
EXPECT_EQ(fitness_area.retrieve_equipment_count(), 20);
}

// === SHOP TESTS ===
TEST(ProductBaseTest, PriceValidation)
{
ProductBase product(250.0);
EXPECT_DOUBLE_EQ(product.retrieve_unit_price(), 250.0);
}

TEST(ExerciseBallDefsTest, BallProperties)
{
ExerciseBallDefs ball(800.0, BallSize::Medium, BallMaterial::Rubber);
EXPECT_EQ(ball.retrieve_ball_size(), BallSize::Medium);
}

TEST(TowelDefsTest, TowelAbsorbency)
{
Towel towel(450.0, TowelDimension::Large, ProductMaterial::Cotton,
            ItemColor::Blue, AbsorbLevel::AbsorbHigh);
EXPECT_EQ(towel.retrieve_absorption(), AbsorbLevel::AbsorbHigh);
EXPECT_EQ(towel.retrieve_absorption_name(), "High");
}

TEST(WorkoutGlovesDefsTest, GloveFeatures)
{
WorkoutGloves workout_gloves(1200.0, ProductSize::Large,
                             ProductMaterial::Leather, true);
EXPECT_TRUE(workout_gloves.has_wrist_support());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
