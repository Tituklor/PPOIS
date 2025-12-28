#ifndef ERROR_DEFS_H
#define ERROR_DEFS_H

#include <string>
#include <exception>

class BaseError : public std::exception
{
private:
    std::string errorMsg;

public:
    explicit BaseError(const char* errorText);
    explicit BaseError(const BaseError& source);

    const char* what() const noexcept override;
};

class InsufficientFundsError final : public BaseError
{
public:
    explicit InsufficientFundsError(const char* details);
};

class InvalidTimeRangeError final : public BaseError
{
public:
    explicit InvalidTimeRangeError(const char* details);
};

class InvalidTimeError final : public BaseError
{
public:
    explicit InvalidTimeError(const char* details);
};

class InvalidPackagingError : public BaseError
{
public:
    explicit InvalidPackagingError(const char* details);
};

class InvalidAreaError final : public BaseError
{
public:
    explicit InvalidAreaError(const char* details);
};

class InvalidHeightError final : public BaseError
{
public:
    explicit InvalidHeightError(const char* details);
};

class InvalidWeightError final : public BaseError
{
public:
    explicit InvalidWeightError(const char* details);
};

class InvalidGenderError final : public BaseError
{
public:
    explicit InvalidGenderError(const char* details);
};

class InvalidVolumeError final : public BaseError
{
public:
    explicit InvalidVolumeError(const char* details);
};

class InvalidAmountError final : public BaseError
{
public:
    explicit InvalidAmountError(const char* details);
};

class InvalidSessionCountError final : public BaseError
{
public:
    explicit InvalidSessionCountError(const char* details);
};

class SubscriptionIssueError final : public BaseError
{
public:
    explicit SubscriptionIssueError(const char* details);
};

class PasskeyValidationError final : public BaseError
{
public:
    explicit PasskeyValidationError(const char* details);
};

class TrainerAssignmentError final : public BaseError
{
public:
    explicit TrainerAssignmentError(const char* details);
};

class HumidityControlError final : public BaseError
{
public:
    explicit HumidityControlError(const char* details);
};

class InvalidPrecisionError final : public BaseError
{
public:
    explicit InvalidPrecisionError(const char* details);
};

class InvalidPriceError final : public BaseError
{
public:
    explicit InvalidPriceError(const char* details);
};

#endif
