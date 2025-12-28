#include "person_base.h"
#include "error_defs.h"
#include <string>  // ✅ Для std::to_string

// ✅ Forward declarations для избежания циклических зависимостей
class Membership;

PersonBase::PersonBase(std::string full_name, unsigned int person_age,
                       char sex_code, std::string birth_date,
                       bool key_linking_permitted, PassKey* access_card,
                       bool membership_active, double account_balance,
                       double body_weight, unsigned int body_height)
        : full_name(full_name),
          person_age(person_age),
          sex_code(sex_code),
          birth_date(birth_date),
          account_balance(account_balance),
          body_weight(body_weight),
          body_height(body_height),
          active_membership(nullptr),        // ✅ Инициализация protected
          key_linking_permitted(key_linking_permitted),
          access_card(access_card),
          membership_active(membership_active)
{
    if (body_height < 145)
        throw InvalidHeightError("Карликов не пускаем в спортклуб");
    if (body_weight < 1)
        throw InvalidWeightError("С таким весом надо идти к врачу");
    if (sex_code != 'm' && sex_code != 'f')
        throw InvalidGenderError("Либо m, либо f");
    if (account_balance < 0)
        throw InvalidAmountError("Должников не принимаем");
}

PersonBase::~PersonBase()
{
    // ✅ НЕ удаляем active_membership - это не наша ответственность!
    // active_membership управляется Membership системой
    if (access_card)
        delete access_card;  // ✅ Если владеем указателем
}

std::string PersonBase::retrieve_name() const
{
    return full_name;
}

unsigned int PersonBase::retrieve_age() const
{
    return person_age;
}

std::string PersonBase::retrieve_sex() const
{
    if (sex_code == 'm')
        return "male";
    return "female";
}

char PersonBase::retrieve_sex_code() const
{
    return sex_code;
}

bool PersonBase::is_male_person() const
{
    return sex_code == 'm';
}

bool PersonBase::is_female_person() const
{
    return sex_code == 'f';
}

std::string PersonBase::retrieve_birth_date() const
{
    return birth_date;
}

double PersonBase::retrieve_balance() const
{
    return account_balance;
}

void PersonBase::update_name(std::string new_name)
{
    full_name = new_name;
}

void PersonBase::update_age(unsigned int new_age)
{
    person_age = new_age;
}

void PersonBase::update_sex(char new_sex)
{
    sex_code = new_sex;
}

void PersonBase::update_birth_date(std::string new_date)
{
    birth_date = new_date;
}

void PersonBase::update_weight(double new_weight)
{
    body_weight = new_weight;
}

void PersonBase::update_height(unsigned int new_height)
{
    body_height = new_height;
}

// ✅ НОВЫЕ ГЕТТЕРЫ для protected полей
Membership* PersonBase::get_active_membership() const
{
    return active_membership;
}

bool PersonBase::is_membership_active() const
{
    return membership_active;
}

PassKey* PersonBase::get_access_card() const
{
    return access_card;
}

void PersonBase::set_membership(Membership* membership)
{
    active_membership = membership;
    membership_active = (membership != nullptr);
}

void PersonBase::set_access_card(PassKey* card)
{
    access_card = card;
}

std::string PersonBase::retrieve_session_count()
{
    if (!active_membership)
        throw SubscriptionIssueError("Нет абонемента");

    if (active_membership->remaining_sessions == -1)
        return "unlimited";
    return std::to_string(active_membership->remaining_sessions);
}

std::string PersonBase::retrieve_day_count()
{
    if (!active_membership)
        throw SubscriptionIssueError("Нет абонемента");

    return std::to_string(active_membership->remaining_days);
}

std::string PersonBase::retrieve_membership_duration()
{
    if (!active_membership)
        throw SubscriptionIssueError("Нет абонемента");

    return std::to_string(active_membership->validality_period);
}

std::string PersonBase::retrieve_original_sessions()
{
    if (!active_membership)
        throw SubscriptionIssueError("Нет абонемента");

    if (active_membership->initial_num_of_sessions == -1)
        return "unlimited";
    return std::to_string(active_membership->initial_num_of_sessions);
}
