// core/Administrator/Administrator.h
#ifndef SPORTCLUB_ADMINISTRATOR_H
#define SPORTCLUB_ADMINISTRATOR_H

#include "../Person/Person.h"

class Administrator : public Person {
public:
    Administrator(const std::string& name, int age,
                  const std::string& phoneNumber, const std::string& email,
                  int id);

    int getId() const;

private:
    int id_;
};

#endif // SPORTCLUB_ADMINISTRATOR_H