#ifndef SOCIAL_MGR_DEFS_H
#define SOCIAL_MGR_DEFS_H

#include "employee_base.h"
#include "../Social/insta_defs.h"
#include "../Social/tiktok_defs.h"

class TikTokPlatform;
class InstagramPlatform;

class SocialMediaManager : public EmployeeBase
{
    TikTokPlatform* tiktok_account;
    InstagramPlatform* instagram_account;
    unsigned int aggregate_followers;

public:
    SocialMediaManager(std::string mgr_name, unsigned int mgr_age, char mgr_gender,
                       std::string mgr_birth_date, bool key_link_permission, PassKey* mgr_passkey,
                       bool mgr_has_subscription, double mgr_balance, double mgr_weight,
                       unsigned int mgr_height, unsigned int mgr_experience, double mgr_salary,
                       std::string mgr_phone, const std::string account_handle,
                       const std::string user_handle, const unsigned int tiktok_followers,
                       const unsigned int insta_followers, const unsigned int total_posts,
                       const unsigned int total_likes, const unsigned int total_reposts,
                       const unsigned int total_stories, const std::string profile_bio);

    ~SocialMediaManager();

    void publish_content();
    void refresh_follower_stats();
    unsigned int retrieve_total_followers();
};

#endif
