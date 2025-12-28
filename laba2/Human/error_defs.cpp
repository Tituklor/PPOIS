#include "error_defs.h"
using namespace std;

BaseError::BaseError(const char* errorText) : errorMsg(errorText)
{
}

BaseError::BaseError(const BaseError& source) : errorMsg(source.errorMsg)
{
}

const char* BaseError::what() const noexcept
{
    return errorMsg.c_str();
}

InsufficientFundsError::InsufficientFundsError(const char* details) : BaseError(details)
{
}

InvalidTimeRangeError::InvalidTimeRangeError(const char* details) : BaseError(details)
{
}

InvalidTimeError::InvalidTimeError(const char* details) : BaseError(details)
{
}

InvalidPackagingError::InvalidPackagingError(const char* details) : BaseError(details)
{
}

InvalidAreaError::InvalidAreaError(const char* details) : BaseError(details)
{
}

InvalidHeightError::InvalidHeightError(const char* details) : BaseError(details)
{
}

InvalidWeightError::InvalidWeightError(const char* details) : BaseError(details)
{
}

InvalidGenderError::InvalidGenderError(const char* details) : BaseError(details)
{
}

InvalidVolumeError::InvalidVolumeError(const char* details) : BaseError(details)
{
}

InvalidAmountError::InvalidAmountError(const char* details) : BaseError(details)
{
}

InvalidSessionCountError::InvalidSessionCountError(const char* details) : BaseError(details)
{
}

SubscriptionIssueError::SubscriptionIssueError(const char* details) : BaseError(details)
{
}

PasskeyValidationError::PasskeyValidationError(const char* details) : BaseError(details)
{
}

TrainerAssignmentError::TrainerAssignmentError(const char* details) : BaseError(details)
{
}

HumidityControlError::HumidityControlError(const char* details) : BaseError(details)
{
}

InvalidPrecisionError::InvalidPrecisionError(const char* details) : BaseError(details)
{
}

InvalidPriceError::InvalidPriceError(const char* details) : BaseError(details)
{
}
