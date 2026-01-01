// service/TowelService.h
#ifndef SPORTCLUB_TOWELSERVICE_H
#define SPORTCLUB_TOWELSERVICE_H

class TowelService {
public:
    TowelService(int memberId, int towelCount);

    int getMemberId() const;
    int getTowelCount() const;
    void setTowelCount(int count);
    double getTotalCost() const;

private:
    int memberId_;
    int towelCount_;
};

#endif // SPORTCLUB_TOWELSERVICE_H