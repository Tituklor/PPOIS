#ifndef SOCIAL_BASE_H
#define SOCIAL_BASE_H

#include <string>

class SocialMediaManager;

class SocialBase
{
protected:
    friend class SocialMediaManager;

    std::string account_handle;
    std::string user_identifier;
    unsigned int follower_total;
    unsigned int content_count;
    std::string platform_name;

public:
    SocialBase(const std::string& account_handle, const std::string user_identifier,
               const unsigned int follower_total, const std::string platform_name,
               const unsigned int content_count);

    std::string retrieve_account_handle() const;
    std::string retrieve_user_identifier() const;
    unsigned int retrieve_follower_total() const;
    std::string retrieve_platform_name() const;
};

#endif
