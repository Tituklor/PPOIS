// core/Staff/Staff.h
#ifndef SPORTCLUB_STAFF_H
#define SPORTCLUB_STAFF_H

#include "../Person/Person.h"

class Staff : public Person {
public:
    Staff(const std::string& name, int age,
          const std::string& phoneNumber, const std::string& email,
          int id, const std::string& position);

    int getId() const;
    std::string getPosition() const;
    void setPosition(const std::string& position);
    double getSalary() const;

private:
    int id_;
    std::string position_;
};

#endif // SPORTCLUB_STAFF_H