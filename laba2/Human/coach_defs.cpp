#include "coach_defs.h"
#include "../Social/insta_defs.h"
#include "../Social/tiktok_defs.h"

Coach::Coach(std::string coach_name, unsigned int coach_age, char coach_gender,
             std::string coach_birth_date, bool key_link_authorized, PassKey* coach_passkey,
             bool coach_has_membership, double coach_balance, double coach_weight,
             unsigned int coach_height, unsigned int coach_experience, double coach_salary,
             std::string coach_phone, const std::string profile_handle,
             const std::string user_id, const unsigned int tiktok_followers,
             const unsigned int instagram_followers, const unsigned int content_posts,
             const unsigned int total_likes, const unsigned int total_shares,
             const unsigned int story_posts, const std::string profile_description,
             const bool duty_status)
        : EmployeeBase(coach_name, coach_age, coach_gender, coach_birth_date,
                       key_link_authorized, coach_passkey, coach_has_membership,
                       coach_balance, coach_weight, coach_height, coach_experience,
                       coach_salary, coach_phone),
          duty_status(duty_status)
{
    instagram_profile = new InstagramPlatform(profile_handle, user_id, instagram_followers,
                                              content_posts, story_posts, profile_description);
    tiktok_profile = new TikTokPlatform(profile_handle, user_id, tiktok_followers,
                                        content_posts, total_likes, total_shares);
}

bool Coach::check_duty_status()
{
    return duty_status;
}
