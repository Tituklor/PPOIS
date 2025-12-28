#include "insta_defs.h"

InstagramPlatform::InstagramPlatform(const std::string profile_name,
                                     const std::string username,
                                     const unsigned int followers_count,
                                     const unsigned int post_count,
                                     const unsigned int story_posts_count,
                                     const std::string profile_description)
        : SocialBase(profile_name, username, followers_count, "Instagram", post_count),
          story_posts_count(story_posts_count), profile_description(profile_description)
{
}
