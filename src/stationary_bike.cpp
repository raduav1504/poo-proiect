#include "stationary_bike.hpp"
#include <iostream>

StationaryBike::StationaryBike(const std::string& id, double resistance)
  : EquipmentBase(id), resistance_(resistance) {}

std::shared_ptr<EquipmentBase> StationaryBike::clone() const {
    return std::make_shared<StationaryBike>(*this);
}

StationaryBike::StationaryBike(const StationaryBike& other)
  : EquipmentBase(other), resistance_(other.resistance_) {}

void StationaryBike::doOperate(int min) {
    std::cout << "Bike " << id() << ": pedalat "
              << min << " min la rezistenta " << resistance_ << "\n";
}
