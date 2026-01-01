// facility/Court.h
#ifndef SPORTCLUB_COURT_H
#define SPORTCLUB_COURT_H

#include "Facility.h"
#include <string>

class Court : public Facility {
public:
    Court(const std::string& name, int capacity, const std::string& location,
          const std::string& sportType);
    std::string getSportType() const;

private:
    std::string sportType_;
};

#endif // SPORTCLUB_COURT_H