#include "EquipmentBase.h"
#include "Exceptions.h"
#include <iostream>

int EquipmentBase::count_ = 0;

EquipmentBase::EquipmentBase(const std::string& id)
    : id_(id), currentUser_(nullptr), usageDuration_(0) {
    ++count_;
}

EquipmentBase::EquipmentBase(const EquipmentBase& other)
    : id_(other.id_), currentUser_(other.currentUser_), usageDuration_(other.usageDuration_) {
    ++count_;
}

EquipmentBase& EquipmentBase::operator=(EquipmentBase other) {
    swap(*this, other);
    return *this;
}

EquipmentBase::~EquipmentBase() {
    --count_;
}

void swap(EquipmentBase& first, EquipmentBase& second) {
    using std::swap;
    swap(first.id_, second.id_);
    swap(first.currentUser_, second.currentUser_);
    swap(first.usageDuration_, second.usageDuration_);
}

int EquipmentBase::getCount() {
    return count_;
}

void EquipmentBase::operate(std::shared_ptr<Member> member, int duration) {
    if (duration <= 0) throw InvalidDurationException(duration);
    startUseImpl(member, duration);
    updateStatus();
}
