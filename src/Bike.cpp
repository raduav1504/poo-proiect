#include "Bike.h"
#include <iostream>
#include <utility>

Bike::Bike(double resistance)
    : Equipment("Bike"), resistance_(resistance) {
    if (resistance_ < 0) {
        throw EquipmentError("resistance must be non-negative");
    }
}

Bike::Bike(const Bike& other)
    : Equipment(other), resistance_(other.resistance_) {}

Bike& Bike::operator=(Bike other) {
    swap(*this, other);
    return *this;
}

std::unique_ptr<Equipment> Bike::clone() const {
    return std::make_unique<Bike>(*this);
}

void Bike::print(std::ostream& os) const {
    Equipment::print(os);
    os << " (resistance=" << resistance_ << ")";
}

void Bike::do_use(int minutes) {
    std::cout << "Cycling with resistance " << resistance_
              << " for " << minutes << " minutes.\n";
}

void swap(Bike& a, Bike& b) {
    using std::swap;
    swap(static_cast<Equipment&>(a), static_cast<Equipment&>(b));
    swap(a.resistance_, b.resistance_);
}
