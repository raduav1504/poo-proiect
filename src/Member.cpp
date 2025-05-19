#include "Member.h"
#include "Exceptions.h"
#include "Bike.h"
#include "Treadmill.h"
#include "RowMachine.h"

#include <iostream>
#include <utility>
#include <algorithm>  // for std::swap

Member::Member(std::string name)
    : name_(std::move(name))
{
    if (name_.empty()) {
        throw MemberError("empty name");
    }
}

Member::Member(const Member& other)
    : name_(other.name_)
{
    for (const auto& eq : other.equipment_) {
        equipment_.push_back(eq->clone());
    }
}

Member& Member::operator=(Member other)
{
    swap(*this, other);
    return *this;
}

void Member::addEquipment(std::unique_ptr<Equipment> eq)
{
    equipment_.push_back(std::move(eq));
}

void Member::useEquipment(const std::string& eqName, int minutes)
{
    for (const auto& eq : equipment_) {
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

std::ostream& operator<<(std::ostream& os, const Member& m)
{
    os << "Member[" << m.name_ << "] owns:\n";
    for (const auto& eq : m.equipment_) {
        os << "  - " << *eq << "\n";
    }
    return os;
}

void swap(Member& a, Member& b) noexcept
{
    using std::swap;
    swap(a.name_,       b.name_);
    swap(a.equipment_,  b.equipment_);
}
