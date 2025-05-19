#include "Member.h"
#include "Exceptions.h"
#include <iostream>
#include <utility>

Member::Member(std::string name)
    : name_(std::move(name)) {
    if (name_.empty()) {
        throw MemberError("empty name");
    }
}

Member::Member(const Member& other)
    : name_(other.name_) {
    for (auto& eq : other.equipment_) {
        equipment_.push_back(eq->clone());
    }
}

Member& Member::operator=(Member other) {
    swap(*this, other);
    return *this;
}

void Member::addEquipment(std::unique_ptr<Equipment> eq) {
    equipment_.push_back(std::move(eq));
}

void Member::useEquipment(const std::string& eqName, int minutes) {
    for (auto& eq : equipment_) {
        // downcast exemplu: căutăm bicicleta după nume
        if (dynamic_cast<Bike*>(eq.get()) && eqName == "Bike") {
            eq->use(minutes);
            return;
        }
        if (dynamic_cast<Treadmill*>(eq.get()) && eqName == "Treadmill") {
            eq->use(minutes);
            return;
        }
        if (dynamic_cast<RowMachine*>(eq.get()) && eqName == "RowMachine") {
            eq->use(minutes);
            return;
        }
    }
    throw UsageError("no equipment named " + eqName);
}

std::ostream& operator<<(std::ostream& os, const Member& m) {
    os << "Member[" << m.name_ << "] owns:\n";
    for (auto& eq : m.equipment_) {
        os << "  - " << *eq << "\n";
    }
    return os;
}

void swap(Member& a, Member& b) {
    using std::swap;
    swap(a.name_, b.name_);
    swap(a.equipment_, b.equipment_);
}
