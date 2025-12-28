#ifndef JANITOR_DEFS_H
#define JANITOR_DEFS_H

#include "../Room/space_defs.h"
#include "../Mirror/reflector_defs.h"
#include "employee_base.h"

class PassKey;
class Space;
class Reflector;

class Janitor : public EmployeeBase
{
public:
    Janitor(std::string workerName,
            unsigned int workerAge,
            char workerGender,
            std::string workerBirth,
            bool keyLinkPerm,
            PassKey* workerKey,
            bool hasSubscr,
            double workerFunds,
            double workerMass,
            unsigned int workerStature,
            unsigned int workerExp,
            double workerWage,
            std::string workerContact);

    void sanitizeSpace(Space& targetSpace);
    void polishReflector(Reflector& targetMirror);
};

#endif
