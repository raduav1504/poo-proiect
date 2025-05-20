#pragma once
#include "equipment.hpp"

class Treadmill : public EquipmentBase {
public:
    Treadmill(const std::string& id, double maxSpeed);
    std::shared_ptr<EquipmentBase> clone() const override;

protected:
    Treadmill(const Treadmill& other);

private:
    void doOperate(int) override;
    double maxSpeed_;
};
