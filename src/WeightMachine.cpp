#include "WeightMachine.h"
#include <iostream>

WeightMachine::WeightMachine(const std::string& id)
    : EquipmentBase(id), weight_(50) {}

WeightMachine::WeightMachine(const WeightMachine& other)
    : EquipmentBase(other), weight_(other.weight_) {}

WeightMachine& WeightMachine::operator=(WeightMachine other) {
    swap(other);
    return *this;
}

void WeightMachine::swap(WeightMachine& other) {
    EquipmentBase::swap(*this, other);
    std::swap(weight_, other.weight_);
}

std::shared_ptr<EquipmentBase> WeightMachine::clone() const {
    return std::make_shared<WeightMachine>(*this);
}

void WeightMachine::startUseImpl(std::shared_ptr<Member> member, int duration) {
    std::cout << "WeightMachine " << getId() << " started for "
              << duration << " minutes by " << member->getName() << "\n";
}

void WeightMachine::updateStatus() {
    std::cout << "WeightMachine " << getId() << " status updated (weight=" << weight_ << ")\n";
}
