#pragma once
#include "equipment.hpp"

class WeightMachine : public EquipmentBase {
public:
    WeightMachine(const std::string& id, double weight);
    std::shared_ptr<EquipmentBase> clone() const override;

protected:
    WeightMachine(const WeightMachine& other);

private:
    void doOperate(int) override;
    double weight_;
};
