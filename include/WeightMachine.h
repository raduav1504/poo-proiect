#ifndef WEIGHTMACHINE_H
#define WEIGHTMACHINE_H

#include "EquipmentBase.h"

class WeightMachine : public EquipmentBase {
public:
    explicit WeightMachine(const std::string& id);
    WeightMachine(const WeightMachine& other);
    WeightMachine& operator=(WeightMachine other);
    ~WeightMachine() override = default;

    std::shared_ptr<EquipmentBase> clone() const override;

protected:
    void startUseImpl(std::shared_ptr<Member> member, int duration) override;
    void updateStatus() override;

private:
    int weight_;  
    void swap(WeightMachine& other);
};
