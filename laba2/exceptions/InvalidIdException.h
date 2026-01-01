// exceptions/InvalidIdException.h
#ifndef SPORTCLUB_INVALIDIDEXCEPTION_H
#define SPORTCLUB_INVALIDIDEXCEPTION_H

#include "BaseException.h"

class InvalidIdException : public BaseException {
public:
    InvalidIdException(int id);
    int getId() const;
private:
    int id_;
};

#endif // SPORTCLUB_INVALIDIDEXCEPTION_H