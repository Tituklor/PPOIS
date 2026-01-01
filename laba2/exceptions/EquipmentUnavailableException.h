// exceptions/EquipmentUnavailableException.h
#ifndef SPORTCLUB_EQUIPMENTUNAVAILABLEEXCEPTION_H
#define SPORTCLUB_EQUIPMENTUNAVAILABLEEXCEPTION_H

#include "BaseException.h"

class EquipmentUnavailableException : public BaseException {
public:
    EquipmentUnavailableException(const std::string& equipmentType, int requested);
    std::string getEquipmentType() const;
    int getRequested() const;
private:
    std::string equipmentType_;
    int requested_;
};

#endif // SPORTCLUB_EQUIPMENTUNAVAILABLEEXCEPTION_H