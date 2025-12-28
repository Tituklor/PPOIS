#include "janitor_defs.h"

Janitor::Janitor(std::string workerName, unsigned int workerAge, char workerGender,
                 std::string workerBirth, bool keyLinkPerm, PassKey* workerKey,
                 bool hasSubscr, double workerFunds, double workerMass,
                 unsigned int workerStature, unsigned int workerExp,
                 double workerWage, std::string workerContact)
        : EmployeeBase(workerName, workerAge, workerGender, workerBirth, keyLinkPerm,
                       workerKey, hasSubscr, workerFunds, workerMass, workerStature,
                       workerExp, workerWage, workerContact)
{
}

void Janitor::sanitizeSpace(Space& targetSpace)
{
    targetSpace.cleaned = true;
}

void Janitor::polishReflector(Reflector& targetMirror)
{
    targetMirror.cleaned = true;
}
