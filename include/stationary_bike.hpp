#pragma once
#include "equipment.hpp"

class StationaryBike : public EquipmentBase {
public:
    StationaryBike(const std::string& id, double resistance);
    std::shared_ptr<EquipmentBase> clone() const override;

protected:
    StationaryBike(const StationaryBike& other);

private:
    void doOperate(int) override;
    double resistance_;
};
