#ifndef PERSON_BASE_H
#define PERSON_BASE_H

#include <string>
#include "../Reception/access_defs.h"
#include "../Reception/membership_defs.h"

// Forward declarations для избежания циклических зависимостей
class FrontDeskStaff;
class FrontDesk;
class WeightScale;
class ClientRegistry;

class PersonBase
{
    // ✅ FRIEND классы - дают доступ к protected полям
    friend class FrontDeskStaff;
    friend class FrontDesk;
    friend class ClientRegistry;
    friend class WeightScale;
    friend class Membership;  // Если нужно

private:
    std::string full_name;
    unsigned int person_age;
    char sex_code;  // 'f' = female, 'm' = male
    std::string birth_date;
    double account_balance;
    double body_weight;
    unsigned int body_height;

protected:
    // ✅ PROTECTED поля - доступны для friend классов
    Membership* active_membership;
    bool key_linking_permitted;
    PassKey* access_card;
    bool membership_active;

public:
    PersonBase(const std::string full_name,
               const unsigned int person_age,
               const char sex_code,
               const std::string birth_date,
               const bool key_linking_permitted,
               PassKey* access_card,
               const bool membership_active,
               const double account_balance,
               const double body_weight,
               const unsigned int body_height);

    ~PersonBase();

    // ✅ СЕТТЕРЫ
    void update_name(std::string new_name);
    void update_age(unsigned int new_age);
    void update_sex(char new_sex);
    void update_birth_date(std::string new_date);
    void update_weight(double new_weight);
    void update_height(unsigned int new_height);
    void set_membership(Membership* membership);
    void set_access_card(PassKey* card);

    // ✅ ГЕТТЕРЫ
    std::string retrieve_name() const;
    unsigned int retrieve_age() const;
    std::string retrieve_sex() const;
    char retrieve_sex_code() const;
    bool is_male_person() const;
    bool is_female_person() const;
    std::string retrieve_birth_date() const;
    double retrieve_balance() const;

    // ✅ ГЕТТЕРЫ для protected полей (для безопасного доступа)
    Membership* get_active_membership() const { return active_membership; }
    bool is_membership_active() const { return membership_active; }
    PassKey* get_access_card() const { return access_card; }

    // Методы для Membership информации
    std::string retrieve_session_count() const;
    std::string retrieve_day_count() const;
    std::string retrieve_membership_duration() const;
    std::string retrieve_original_sessions() const;
};

#endif // PERSON_BASE_H
