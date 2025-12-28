#ifndef TIKTOK_DEFS_H
#define TIKTOK_DEFS_H

#include "social_base.h"
#include <string>

class TikTokPlatform : public SocialBase
{
    unsigned int total_likes;
    unsigned int total_shares;

public:
    TikTokPlatform(const std::string profile_name, const std::string username,
                   const unsigned int followers_count, const unsigned int post_count,
                   const unsigned int total_likes, const unsigned int total_shares);
};

#endif
