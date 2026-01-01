// config/Config.h
#ifndef SPORTCLUB_CONFIG_H
#define SPORTCLUB_CONFIG_H

#include <string>

namespace Config {
    // Возраст
    const int MIN_MEMBER_AGE = 14;
    const int MAX_MEMBER_AGE = 100;

    // Финансы
    const double MONTHLY_FEE_STANDARD = 2500.0;
    const double MONTHLY_FEE_PREMIUM = 4500.0;
    const double COACH_SALARY_BASE = 60000.0;
    const double STAFF_SALARY_BASE = 45000.0;
    const double EQUIPMENT_RENT_FEE = 150.0;

    // Ограничения
    const size_t MAX_BOOKINGS_PER_DAY = 3;
    const size_t MAX_MEMBERS_PER_SESSION = 12;
    const size_t MAX_EQUIPMENT_PER_TYPE = 10;
    const size_t MAX_LOCKER_NUMBER = 200;

    // Сроки членства (дни)
    const int MEMBERSHIP_DURATION_STANDARD = 30;
    const int MEMBERSHIP_DURATION_PREMIUM = 90;

    // Строковые константы
    const std::string CURRENCY = "RUB";
    const std::string STATUS_ACTIVE = "active";
    const std::string STATUS_EXPIRED = "expired";
    const std::string STATUS_AVAILABLE = "available";
    const std::string STATUS_BOOKED = "booked";
}

#endif // SPORTCLUB_CONFIG_H