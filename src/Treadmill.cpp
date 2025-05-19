#include "Treadmill.h"
#include <iostream>

Treadmill::Treadmill(const std::string& id)
    : EquipmentBase(id), speedLevel_(1) {}

Treadmill::Treadmill(const Treadmill& other)
    : EquipmentBase(other), speedLevel_(other.speedLevel_) {}

Treadmill& Treadmill::operator=(Treadmill other) {
    swap(other);
    return *this;
}

void Treadmill::swap(Treadmill& other) {
    EquipmentBase::swap(*this, other);
    std::swap(speedLevel_, other.speedLevel_);
}

std::shared_ptr<EquipmentBase> Treadmill::clone() const {
    return std::make_shared<Treadmill>(*this);
}

void Treadmill::startUseImpl(std::shared_ptr<Member> member, int duration) {
    std::cout << "Treadmill " << getId() << " started for "
              << duration << " minutes by " << member->getName() << "\n";
}

void Treadmill::updateStatus() {
    std::cout << "Treadmill " << getId() << " status updated (speedLevel=" << speedLevel_ << ")\n";
}
