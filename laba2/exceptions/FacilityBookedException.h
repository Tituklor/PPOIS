// exceptions/FacilityBookedException.h
#ifndef SPORTCLUB_FACILITYBOOKEDEXCEPTION_H
#define SPORTCLUB_FACILITYBOOKEDEXCEPTION_H

#include "BaseException.h"

class FacilityBookedException : public BaseException {
public:
    FacilityBookedException(const std::string& facilityName, const std::string& timeSlot);
    std::string getFacilityName() const;
    std::string getTimeSlot() const;
private:
    std::string facilityName_;
    std::string timeSlot_;
};

#endif // SPORTCLUB_FACILITYBOOKEDEXCEPTION_H