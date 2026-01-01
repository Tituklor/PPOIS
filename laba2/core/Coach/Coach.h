// core/Coach/Coach.h
#ifndef SPORTCLUB_COACH_H
#define SPORTCLUB_COACH_H

#include "../Person/Person.h"
#include <string>
#include <vector>

class Coach : public Person {
public:
    Coach(const std::string& name, int age,
          const std::string& phoneNumber, const std::string& email,
          int id, const std::string& specialization);

    int getId() const;
    std::string getSpecialization() const;
    void setSpecialization(const std::string& specialization);
    double getSalary() const;

private:
    int id_;
    std::string specialization_;
};

#endif // SPORTCLUB_COACH_H