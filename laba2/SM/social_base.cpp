#include "social_base.h"

SocialBase::SocialBase(const std::string& account_handle, const std::string user_identifier,
                       const unsigned int follower_total, const std::string platform_name,
                       const unsigned int content_count)
        : account_handle(account_handle), user_identifier(user_identifier),
          follower_total(follower_total), platform_name(platform_name), content_count(content_count)
{
}

std::string SocialBase::retrieve_account_handle() const
{
    return account_handle;
}

std::string SocialBase::retrieve_user_identifier() const
{
    return user_identifier;
}

unsigned int SocialBase::retrieve_follower_total() const
{
    return follower_total;
}

std::string SocialBase::retrieve_platform_name() const
{
    return platform_name;
}
