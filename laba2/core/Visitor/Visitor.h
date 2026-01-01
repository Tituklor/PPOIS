// core/Visitor/Visitor.h
#ifndef SPORTCLUB_VISITOR_H
#define SPORTCLUB_VISITOR_H

#include "../Person/Person.h"

class Visitor : public Person {
public:
    Visitor(const std::string& name, int age,
            const std::string& phoneNumber, const std::string& email);

    // Visitors are temporary — no ID, no membership
    // May later be converted to Member
};

#endif // SPORTCLUB_VISITOR_H