#include "treadmill.hpp"
#include <iostream>

Treadmill::Treadmill(const std::string& id, double maxSpeed)
  : EquipmentBase(id), maxSpeed_(maxSpeed) {}

std::shared_ptr<EquipmentBase> Treadmill::clone() const {
    return std::make_shared<Treadmill>(*this);
}

Treadmill::Treadmill(const Treadmill& other)
  : EquipmentBase(other), maxSpeed_(other.maxSpeed_) {}

void Treadmill::doOperate(int min) {
    std::cout << "Treadmill " << id() << ": alergat "
              << min << " min la " << maxSpeed_ << " km/h\n";
}
