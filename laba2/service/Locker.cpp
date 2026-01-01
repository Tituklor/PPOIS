// service/Locker.cpp
#include "Locker.h"

Locker::Locker(int number, int memberId)
        : number_(number), memberId_(memberId), occupied_(memberId > 0) {}

int Locker::getNumber() const {
    return number_;
}

int Locker::getMemberId() const {
    return memberId_;
}

bool Locker::isOccupied() const {
    return occupied_;
}

void Locker::assignToMember(int memberId) {
    memberId_ = memberId;
    occupied_ = true;
}

void Locker::release() {
    memberId_ = -1;
    occupied_ = false;
}