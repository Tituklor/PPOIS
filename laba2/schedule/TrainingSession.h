// schedule/TrainingSession.h
#ifndef SPORTCLUB_TRAININGSESSION_H
#define SPORTCLUB_TRAININGSESSION_H

#include <string>
#include <vector>

class TrainingSession {
public:
    TrainingSession(int coachId, const std::string& facilityName,
                    const std::string& timeSlot, const std::string& activity);

    int getCoachId() const;
    std::string getFacilityName() const;
    std::string getTimeSlot() const;
    std::string getActivity() const;
    std::vector<int> getMemberIds() const;
    void addMember(int memberId);
    size_t getCurrentSize() const;
    bool isFull() const;

private:
    int coachId_;
    std::string facilityName_;
    std::string timeSlot_;
    std::string activity_;
    std::vector<int> memberIds_;
};

#endif // SPORTCLUB_TRAININGSESSION_H