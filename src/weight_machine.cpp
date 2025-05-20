#include "weight_machine.hpp"
#include <iostream>

WeightMachine::WeightMachine(const std::string& id, double weight)
  : EquipmentBase(id), weight_(weight) {}

std::shared_ptr<EquipmentBase> WeightMachine::clone() const {
    return std::make_shared<WeightMachine>(*this);
}

WeightMachine::WeightMachine(const WeightMachine& other)
  : EquipmentBase(other), weight_(other.weight_) {}

void WeightMachine::doOperate(int min) {
    std::cout << "WeightMachine " << id() << ": ridicat "
              << weight_ << " kg pentru " << min << " min\n";
}
