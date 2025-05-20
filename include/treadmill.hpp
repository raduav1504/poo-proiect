#pragma once
#include "equipment.hpp"

class Treadmill : public EquipmentBase {
public:
    Treadmill(const std::string& id, double maxSpeed);
    std::shared_ptr<EquipmentBase> clone() const override;

    /// Domain-specific API: adjust the running speed
    void setMaxSpeed(double s) noexcept { maxSpeed_ = s; }

protected:
    Treadmill(const Treadmill& other);

private:
    void doOperate(int) override;
    double maxSpeed_;
};
