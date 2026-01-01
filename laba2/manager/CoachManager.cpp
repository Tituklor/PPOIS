// manager/CoachManager.cpp
#include "CoachManager.h"
#include "../exceptions/InvalidIdException.h"

void CoachManager::addCoach(const Coach& coach) {
    coaches_.push_back(coach);
}

void CoachManager::removeCoach(int coachId) {
    for (auto it = coaches_.begin(); it != coaches_.end(); ++it) {
        if (it->getId() == coachId) {
            coaches_.erase(it);
            return;
        }
    }
    throw InvalidIdException(coachId);
}

Coach* CoachManager::findCoachById(int id) {
    for (auto& coach : coaches_) {
        if (coach.getId() == id) {
            return &coach;
        }
    }
    return nullptr;
}

std::vector<Coach> CoachManager::getAllCoaches() const {
    return coaches_;
}

size_t CoachManager::getCoachCount() const {
    return coaches_.size();
}

std::vector<Coach> CoachManager::getCoachesBySpecialization(const std::string& spec) const {
    std::vector<Coach> result;
    for (const auto& coach : coaches_) {
        if (coach.getSpecialization() == spec) {
            result.push_back(coach);
        }
    }
    return result;
}