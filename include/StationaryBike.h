#ifndef STATIONARYBIKE_H
#define STATIONARYBIKE_H

#include "EquipmentBase.h"

class StationaryBike : public EquipmentBase {
public:
    explicit StationaryBike(const std::string& id);
    StationaryBike(const StationaryBike& other);
    StationaryBike& operator=(StationaryBike other);
    ~StationaryBike() override = default;

    std::shared_ptr<EquipmentBase> clone() const override;

protected:
    void startUseImpl(std::shared_ptr<Member> member, int duration) override;
    void updateStatus() override;

private:
    int resistanceLevel_;
    void swap(StationaryBike& other);
};

#endif // STATIONARYBIKE_H
