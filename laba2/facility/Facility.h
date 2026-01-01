// facility/Facility.h
#ifndef SPORTCLUB_FACILITY_H
#define SPORTCLUB_FACILITY_H

#include <string>

class Facility {
public:
    Facility(const std::string& name, const std::string& type,
             int capacity, const std::string& location);

    std::string getName() const;
    std::string getType() const;
    int getCapacity() const;
    std::string getLocation() const;
    std::string getStatus() const;
    void setStatus(const std::string& status);
    bool isAvailable() const;

private:
    std::string name_;
    std::string type_;
    int capacity_;
    std::string location_;
    std::string status_;
};

#endif // SPORTCLUB_FACILITY_H