
#include <gtest/gtest.h>
#include "../Human/accountant_defs.h"
#include "../Human/client_defs.h"
#include "../Human/coach_defs.h"
#include "../Human/employee_base.h"
#include "../Human/error_defs.h"
#include "../Human/frontdesk_defs.h"
#include "../Human/janitor_defs.h"
#include "../Human/manager_defs.h"
#include "../Human/person_base.h"

// Мок-классы для тестирования
class MockPassKey {
public:
    char gender = 'm';
    PersonBase* owner = nullptr;
    void set_owner(PersonBase* o) { owner = o; }
};

class MockMembership {
public:
    PersonBase* owner = nullptr;
    double price() { return 100.0; }
    int remaining_days = 30;
    int remaining_sessions = 10;
    int validality_period = 30;
    int initial_num_of_sessions = 10;
    bool departments = false;
    char gender = 'm';
    void make_empty() { remaining_sessions = 0; remaining_days = 0; }
};

class MockKeyRack {
public:
    std::vector<std::pair<MockPassKey, MockMembership*>> passkeys;
};

class MockClientRegistry {
public:
    void add_client(PersonBase* p) {}
    void change_remaining_days() {}
};

class MockFrontDesk {
public:
    double bank = 0;
    void* gym = nullptr;
    void* fitness = nullptr;
    void* sauna = nullptr;
    void* swimming_pool = nullptr;
    void* wrestling_ring = nullptr;
};

class MockSpace {
public:
    bool cleaned = false;
};

class MockReflector {
public:
    bool cleaned = false;
};

class MockScheduleMgr {
public:
    unsigned int open_time = 9;
    unsigned int close_time = 22;
};

class MockInstagramPlatform {};
class MockTikTokPlatform {};

// Тесты для PersonBase
TEST(PersonBase, ConstructorAndGetters) {
MockPassKey key;
PersonBase person("Иван Иванов", 25, 'm', "1998-05-15", true, &key, false, 1000.0, 70.5, 180);

EXPECT_EQ(person.retrieve_name(), "Иван Иванов");
EXPECT_EQ(person.retrieve_age(), 25);
EXPECT_EQ(person.retrieve_sex(), "male");
EXPECT_EQ(person.retrieve_sex_code(), 'm');
EXPECT_TRUE(person.is_male_person());
EXPECT_FALSE(person.is_female_person());
EXPECT_EQ(person.retrieve_birth_date(), "1998-05-15");
EXPECT_DOUBLE_EQ(person.retrieve_balance(), 1000.0);
}
//правильно ли класс PersonBase реагирует на недопустимые (invalid) параметры
TEST(PersonBase, InvalidParametersThrow) {
MockPassKey key;

EXPECT_THROW(PersonBase("Тест", 20, 'm', "2003-01-01", true, &key, false, 100.0, 70.0, 140),
        InvalidHeightError);
EXPECT_THROW(PersonBase("Тест", 20, 'm', "2003-01-01", true, &key, false, 100.0, 0.5, 180),
        InvalidWeightError);
EXPECT_THROW(PersonBase("Тест", 20, 'x', "2003-01-01", true, &key, false, 100.0, 70.0, 180),
        InvalidGenderError);
EXPECT_THROW(PersonBase("Тест", 20, 'm', "2003-01-01", true, &key, false, -100.0, 70.0, 180),
        InvalidAmountError);
}
//правильно ли работают сеттеры
TEST(PersonBase, SettersWorkCorrectly) {
MockPassKey key;
PersonBase person("Иван", 25, 'm', "1998-05-15", true, &key, false, 1000.0, 70.0, 180);
//Изменение данных через сеттеры
person.update_name("Петр");
person.update_age(30);
person.update_sex('f');
person.update_birth_date("1993-02-20");
person.update_weight(65.5);
person.update_height(175);

EXPECT_EQ(person.retrieve_name(), "Петр");
EXPECT_EQ(person.retrieve_age(), 30);
EXPECT_EQ(person.retrieve_sex(), "female");
EXPECT_EQ(person.retrieve_sex_code(), 'f');
EXPECT_TRUE(person.is_female_person());
EXPECT_EQ(person.retrieve_birth_date(), "1993-02-20");
}

// Тесты для EmployeeBase
TEST(EmployeeBase, ConstructorAndGetters) {
MockPassKey key;
EmployeeBase employee("Сергей Петров", 35, 'm', "1988-07-10", true, &key, true, 2000.0, 80.0, 185, 5, 50000.0, "+375991234567");

EXPECT_DOUBLE_EQ(employee.retrieve_pay_rate(), 50000.0);
EXPECT_EQ(employee.retrieve_service_years(), 5);
EXPECT_EQ(employee.retrieve_contact(), "+375991234567");
}
//Исправность сеттеров
TEST(EmployeeBase, SettersWorkCorrectly) {
MockPassKey key;
EmployeeBase employee("Сергей", 35, 'm', "1988-07-10", true, &key, true, 2000.0, 80.0, 185, 5, 50000.0, "+375991234567");

employee.update_pay_rate(60000.0);
employee.update_contact("+375997654321");
employee.update_service_years(6);

EXPECT_DOUBLE_EQ(employee.retrieve_pay_rate(), 60000.0);
EXPECT_EQ(employee.retrieve_contact(), "+375997654321");
EXPECT_EQ(employee.retrieve_service_years(), 6);
}

// Тесты для Accountant
TEST(Accountant, CalculateTotalPayroll) {
MockPassKey key;

// Создаем тестовых сотрудников
EmployeeBase emp1("Иван", 30, 'm', "1993-01-01", true, &key, true, 1000.0, 75.0, 180, 3, 50000.0, "123");
EmployeeBase emp2("Мария", 28, 'f', "1995-02-02", true, &key, true, 1500.0, 60.0, 165, 2, 45000.0, "456");
EmployeeBase emp3("Алексей", 35, 'm', "1988-03-03", true, &key, true, 2000.0, 85.0, 190, 5, 60000.0, "789");

std::vector<EmployeeBase*> staff = {&emp1, &emp2, &emp3};

Accountant accountant("Ольга Бух", 40, 'f', "1983-04-04", true, &key, true, 3000.0, 65.0, 170, 10, 70000.0, "+79991112233");

double total = accountant.calculate_total_payroll(staff);
EXPECT_DOUBLE_EQ(total, 155000.0); // проверка общей зарплаты

// Тест с пустым списком
std::vector<EmployeeBase*> empty_staff;
double empty_total = accountant.calculate_total_payroll(empty_staff);
EXPECT_DOUBLE_EQ(empty_total, 0.0);//общая зарплата пустого списка
}
//Обновление зарплаты сотрудника
TEST(Accountant, UpdateEmployeeSalary) {
MockPassKey key;
EmployeeBase employee("Тест", 30, 'm', "1993-01-01", true, &key, true, 1000.0, 75.0, 180, 3, 50000.0, "123");
Accountant accountant("Бух", 40, 'f', "1983-01-01", true, &key, true, 3000.0, 65.0, 170, 10, 70000.0, "456");

accountant.update_employee_salary(&employee, 55000.0);
EXPECT_DOUBLE_EQ(employee.retrieve_pay_rate(), 55000.0);
}

// Тесты для Client
TEST(Client, ConstructorAndCoachMethods) {
MockPassKey key;

// Создаем мок-тренера
Coach* mockCoach = nullptr; // В реальном тесте нужно создать реальный объект

Client client("Анна", 25, 'f', "1998-06-15", true, &key, true, 1500.0, 58.0, 165, mockCoach);// Клиент создается без тренера, так как mockCoach = nullptr

// Проверяем, что при отсутствии тренера выбрасывается исключение
EXPECT_THROW(client.retrieve_coach_name(), TrainerAssignmentError);

}

// Тесты для Coach
TEST(Coach, ConstructorAndDutyStatus) {
MockPassKey key;

// конструктор Coach требует много параметров
Coach coach(
        "Алексей Тренер", 35, 'm', "1988-05-10", true, &key, true,
        2000.0, 85.0, 185, 8, 80000.0, "+79998887766",
        "coach_alex", "user123", 1000, 2000, 50, 5000, 200, 30,
        "Профессиональный тренер", true
);

// Проверяем методы, связанные с дежурством
EXPECT_TRUE(coach.is_on_duty());
}

// Тесты для FrontDeskStaff
TEST(FrontDeskStaff, MembershipOperations) {
MockPassKey key;
MockKeyRack keyRack;
MockClientRegistry clientRegistry;
MockFrontDesk frontDesk;

FrontDeskStaff staff(
        "Елена", 28, 'f', "1995-03-20", true, &key, true,
        1500.0, 55.0, 168, 3, 40000.0, "+79995554433",
        &keyRack, &clientRegistry, &frontDesk
);

// Проверяем извлечение кассы
double cash = staff.retrieve_cash_register();
EXPECT_DOUBLE_EQ(cash, 0.0);
}

// Тесты для Janitor
TEST(Janitor, CleaningOperations) {
MockPassKey key;
Janitor janitor(
        "Николай", 45, 'm', "1978-11-30", true, &key, true,
        1800.0, 90.0, 178, 15, 35000.0, "+79993332211"
);

MockSpace space;
MockReflector reflector;

janitor.sanitizeSpace(space);
janitor.polishReflector(reflector);

EXPECT_TRUE(space.cleaned);
EXPECT_TRUE(reflector.cleaned);
}

// Тесты для Manager
TEST(Manager, ScheduleAndDutyOperations) {
MockPassKey key;
Manager manager(
        "Дмитрий", 42, 'm', "1981-09-15", true, &key, true,
        2500.0, 88.0, 182, 12, 90000.0, "+79997776655"
);

MockScheduleMgr schedule;
// Coach* mockCoach = nullptr;
// Нужен реальный объект Coach

manager.updateStartTime(schedule, 8);
manager.updateEndTime(schedule, 23);

EXPECT_EQ(schedule.open_time, 8);
EXPECT_EQ(schedule.close_time, 23);

// Тесты scheduleDuty и removeFromDuty требуют реального объекта Coach
}

// Тесты для Error классов
TEST(BaseError, BaseErrorFunctionality) {
    //Создание ошибки с сообщением
BaseError error("Тестовая ошибка");
EXPECT_STREQ(error.what(), "Тестовая ошибка");
//Проверка копирования
BaseError copy(error);
EXPECT_STREQ(copy.what(), "Тестовая ошибка");
}
// Проверяем каждую специализированную ошибку
TEST(BaseError, DerivedErrorClasses) {
InsufficientFundsError fundsError("Не хватает денег");
EXPECT_STREQ(fundsError.what(), "Не хватает денег");

InvalidTimeError timeError("Неверное время");
EXPECT_STREQ(timeError.what(), "Неверное время");

InvalidGenderError genderError("Неверный пол");
EXPECT_STREQ(genderError.what(), "Неверный пол");

TrainerAssignmentError trainerError("Нет тренера");
EXPECT_STREQ(trainerError.what(), "Нет тренера");
}

// Интеграционные тесты
TEST(IntegrationTest, EmployeeHierarchy) {
MockPassKey key;

// Проверяем полиморфизм через наследование
EmployeeBase* employee = new EmployeeBase(
        "Иван", 30, 'm', "1993-01-01", true, &key, true,
        1000.0, 75.0, 180, 3, 50000.0, "123"
);

Accountant* accountant = new Accountant(
        "Ольга", 40, 'f', "1983-01-01", true, &key, true,
        3000.0, 65.0, 170, 10, 70000.0, "456"
);

// Оба объекта имеют доступ к методам EmployeeBase
EXPECT_NO_THROW(employee->retrieve_pay_rate());
EXPECT_NO_THROW(accountant->retrieve_pay_rate());

// Accountant имеет дополнительные методы
std::vector<EmployeeBase*> staff = {employee};
EXPECT_NO_THROW(accountant->calculate_total_payroll(staff));

delete employee;
delete accountant;
}

TEST(IntegrationTest, PersonEmployeeRelationship) {
MockPassKey key;

// PersonBase - базовый класс
PersonBase* person = new PersonBase(
        "Анна", 25, 'f', "1998-01-01", true, &key, true,
        1500.0, 58.0, 165
);

// EmployeeBase наследует от PersonBase
EmployeeBase* employee = new EmployeeBase(
        "Сергей", 35, 'm', "1988-01-01", true, &key, true,
        2000.0, 80.0, 185, 5, 50000.0, "123"
);

// Оба имеют общие методы PersonBase
EXPECT_EQ(person->retrieve_sex(), "female");
EXPECT_EQ(employee->retrieve_sex(), "male");

// Employee имеет дополнительные методы
EXPECT_NO_THROW(employee->retrieve_pay_rate());

delete person;
delete employee;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 