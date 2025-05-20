// member.cpp

#include "member.hpp"
#include "exceptions.hpp"
#include <algorithm>

Member::Member(std::string name)
  : name_(std::move(name)) {}

Member::Member(const Member& other)
  : name_(other.name_) {
    // copy each piece of equipment by cloning
    for (const auto& eq : other.equipment_)
        equipment_.push_back(eq->clone());
}

Member& Member::operator=(Member other) {
    swap(*this, other);
    return *this;
}

void swap(Member& a, Member& b) {
    using std::swap;
    swap(a.name_, b.name_);
    swap(a.equipment_, b.equipment_);
}

void Member::addEquipment(const std::shared_ptr<EquipmentBase>& eq) {
    equipment_.push_back(eq);
}

void Member::doWorkout(const std::string& eqId, int minutes) {
    auto it = std::find_if(
        equipment_.begin(), equipment_.end(),
        [&](const auto& e){ return e->id() == eqId; }
    );
    if (it == equipment_.end())
        throw EquipmentNotFoundException(eqId);
    (*it)->operate(minutes);
}

std::ostream& operator<<(std::ostream& os, const Member& m) {
    os << "Membru: " << m.name_ << "\n  Echipamente:\n";
    for (const auto& eq : m.equipment_)
        os << "    - " << eq->id() << "\n";
    return os;
}
