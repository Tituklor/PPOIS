#ifndef COACH_DEFS_H
#define COACH_DEFS_H

#include <string>
#include "employee_base.h"


class PassKey;
class TikTokPlatform;
class InstagramPlatform;
class Manager;

class Coach : public EmployeeBase
{
    friend class Manager;

private:
    TikTokPlatform* tiktok_profile;
    InstagramPlatform* instagram_profile;
    bool on_duty; 

public:
    Coach(std::string coach_name, unsigned int coach_age, char coach_gender,
          std::string coach_birth_date, bool key_link_authorized, PassKey* coach_passkey,
          bool coach_has_membership, double coach_balance, double coach_weight,
          unsigned int coach_height, unsigned int coach_experience, double coach_salary,
          std::string coach_phone, const std::string profile_handle,
          const std::string user_id, const unsigned int tiktok_followers,
          const unsigned int instagram_followers, const unsigned int content_posts,
          const unsigned int total_likes, const unsigned int total_shares,
          const unsigned int story_posts, const std::string profile_description,
          bool duty_status);

    std::string get_name() const;
    bool check_duty_status() const;
    bool is_on_duty() const { return on_duty; } 
};

#endif // COACH_DEFS_H

