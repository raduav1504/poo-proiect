#include "equipment.hpp"

int EquipmentBase::count_ = 0;


EquipmentBase::EquipmentBase(const std::string& id)
  : id_(id) { ++count_; }

EquipmentBase::~EquipmentBase() { --count_; }

void EquipmentBase::operate(int minutes) {
    if (minutes <= 0) throw InvalidDurationException(minutes);
    doOperate(minutes);
}

const std::string& EquipmentBase::id() const noexcept {
    return id_;
}

int EquipmentBase::getCount() noexcept {
    return count_;
}

EquipmentBase::EquipmentBase(const EquipmentBase& other)
  : id_(other.id_) { ++count_; }

EquipmentBase& EquipmentBase::operator=(const EquipmentBase& other) {
    id_ = other.id_;
    return *this;
}
