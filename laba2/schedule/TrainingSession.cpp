// schedule/TrainingSession.cpp
#include "TrainingSession.h"
#include "../config/Config.h"

TrainingSession::TrainingSession(int coachId, const std::string& facilityName,
                                 const std::string& timeSlot, const std::string& activity)
        : coachId_(coachId), facilityName_(facilityName),
          timeSlot_(timeSlot), activity_(activity) {}

int TrainingSession::getCoachId() const {
    return coachId_;
}

std::string TrainingSession::getFacilityName() const {
    return facilityName_;
}

std::string TrainingSession::getTimeSlot() const {
    return timeSlot_;
}

std::string TrainingSession::getActivity() const {
    return activity_;
}

std::vector<int> TrainingSession::getMemberIds() const {
    return memberIds_;
}

void TrainingSession::addMember(int memberId) {
    if (!isFull()) {
        memberIds_.push_back(memberId);
    }
}

size_t TrainingSession::getCurrentSize() const {
    return memberIds_.size();
}

bool TrainingSession::isFull() const {
    return memberIds_.size() >= Config::MAX_MEMBERS_PER_SESSION;
}