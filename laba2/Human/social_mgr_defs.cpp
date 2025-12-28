#include "social_mgr_defs.h"

SocialMediaManager::SocialMediaManager(std::string mgr_name, unsigned int mgr_age,
                                       char mgr_gender, std::string mgr_birth_date,
                                       bool key_link_permission, PassKey* mgr_passkey,
                                       bool mgr_has_subscription, double mgr_balance,
                                       double mgr_weight, unsigned int mgr_height,
                                       unsigned int mgr_experience, double mgr_salary,
                                       std::string mgr_phone, const std::string account_handle,
                                       const std::string user_handle,
                                       const unsigned int tiktok_followers,
                                       const unsigned int insta_followers,
                                       const unsigned int total_posts,
                                       const unsigned int total_likes,
                                       const unsigned int total_reposts,
                                       const unsigned int total_stories,
                                       const std::string profile_bio)
        : EmployeeBase(mgr_name, mgr_age, mgr_gender, mgr_birth_date, key_link_permission,
                       mgr_passkey, mgr_has_subscription, mgr_balance, mgr_weight, mgr_height,
                       mgr_experience, mgr_salary, mgr_phone)
{
    instagram_account = new InstagramPlatform(account_handle, user_handle, insta_followers,
                                              total_posts, total_stories, profile_bio);
    tiktok_account = new TikTokPlatform(account_handle, user_handle, tiktok_followers,
                                        total_posts, total_likes, total_reposts);
    aggregate_followers = insta_followers + tiktok_followers;
}

void SocialMediaManager::publish_content()
{
    if (tiktok_account)
        tiktok_account->post_count++;
    if (instagram_account)
        instagram_account->post_count++;
}

void SocialMediaManager::refresh_follower_stats()
{
    aggregate_followers = 0;
    if (tiktok_account)
        aggregate_followers += tiktok_account->followers_count;
    if (instagram_account)
        aggregate_followers += instagram_account->followers_count;
}

unsigned int SocialMediaManager::retrieve_total_followers()
{
    return aggregate_followers;
}

SocialMediaManager::~SocialMediaManager()
{
    delete tiktok_account;
    delete instagram_account;
}
