// service/TowelService.cpp
#include "TowelService.h"
#include "../config/Config.h" //!!!!

TowelService::TowelService(int memberId, int towelCount)
        : memberId_(memberId), towelCount_(towelCount) {}

int TowelService::getMemberId() const {
    return memberId_;
}

int TowelService::getTowelCount() const {
    return towelCount_;
}

void TowelService::setTowelCount(int count) {
    towelCount_ = count;
}

double TowelService::getTotalCost() const {
    // Assume 50 RUB per towel
    return towelCount_ * 50.0;
}