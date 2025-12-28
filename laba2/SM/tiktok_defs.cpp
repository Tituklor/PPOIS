#include "tiktok_defs.h"

TikTokPlatform::TikTokPlatform(const std::string profile_name, const std::string username,
                               const unsigned int followers_count, const unsigned int post_count,
                               const unsigned int total_likes, const unsigned int total_shares)
        : SocialBase(profile_name, username, followers_count, "TikTok", post_count),
          total_likes(total_likes), total_shares(total_shares)
{
}
