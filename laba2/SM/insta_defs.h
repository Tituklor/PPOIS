#ifndef INSTA_DEFS_H
#define INSTA_DEFS_H

#include "social_base.h"
#include <string>

class InstagramPlatform : public SocialBase
{
    unsigned int story_posts_count;
    std::string profile_description;

public:
    InstagramPlatform(const std::string profile_name, const std::string username,
                      const unsigned int followers_count, const unsigned int post_count,
                      const unsigned int story_posts_count, const std::string profile_description);
};

#endif
