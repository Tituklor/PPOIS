// manager/CoachManager.h
#ifndef SPORTCLUB_COACHMANAGER_H
#define SPORTCLUB_COACHMANAGER_H

#include "../core/Coach/Coach.h"
#include <vector>

class CoachManager {
public:
    void addCoach(const Coach& coach);
    void removeCoach(int coachId);
    Coach* findCoachById(int id);
    std::vector<Coach> getAllCoaches() const;
    size_t getCoachCount() const;
    std::vector<Coach> getCoachesBySpecialization(const std::string& spec) const;

private:
    std::vector<Coach> coaches_;
};

#endif // SPORTCLUB_COACHMANAGER_H