#include "StationaryBike.h"
#include <iostream>

StationaryBike::StationaryBike(const std::string& id)
    : EquipmentBase(id), resistanceLevel_(5) {}

StationaryBike::StationaryBike(const StationaryBike& other)
    : EquipmentBase(other), resistanceLevel_(other.resistanceLevel_) {}

StationaryBike& StationaryBike::operator=(StationaryBike other) {
    swap(other);
    return *this;
}

void StationaryBike::swap(StationaryBike& other) {
    EquipmentBase::swap(*this, other);
    std::swap(resistanceLevel_, other.resistanceLevel_);
}

std::shared_ptr<EquipmentBase> StationaryBike::clone() const {
    return std::make_shared<StationaryBike>(*this);
}

void StationaryBike::startUseImpl(std::shared_ptr<Member> member, int duration) {
    std::cout << "StationaryBike " << getId() << " started for "
              << duration << " minutes by " << member->getName() << "\n";
}

void StationaryBike::updateStatus() {
    std::cout << "StationaryBike " << getId() << " status updated (resistanceLevel=" << resistanceLevel_ << ")\n";
}
