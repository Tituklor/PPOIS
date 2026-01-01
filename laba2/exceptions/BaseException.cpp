// exceptions/BaseException.cpp
#include "BaseException.h"

BaseException::BaseException(const std::string& message)
        : std::runtime_error(message) {}