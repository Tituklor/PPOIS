// service/Locker.h
#ifndef SPORTCLUB_LOCKER_H
#define SPORTCLUB_LOCKER_H

#include <string>

class Locker {
public:
    Locker(int number, int memberId);

    int getNumber() const;
    int getMemberId() const;
    bool isOccupied() const;
    void assignToMember(int memberId);
    void release();

private:
    int number_;
    int memberId_;
    bool occupied_;
};

#endif // SPORTCLUB_LOCKER_H