#include "Bike.h"
#include "Exceptions.h"
#include <algorithm>
#include <iostream>

Bike::Bike(double resistance)
  : Equipment("Bike"), resistance_(resistance)
{
    if (resistance < 0)
        throw EquipmentError("resistance must be non-negative");
}

void Bike::use(int minutes) {
    if (minutes < 0) throw UsageError("negative minutes");
    std::cout << name_ << ": pedaling at resistance "
              << resistance_ << " for "
              << minutes << " min\n";
}

std::unique_ptr<Equipment> Bike::clone() const {
    return std::make_unique<Bike>(*this);
}

void swap(Bike& a, Bike& b) noexcept {
    using std::swap;
    swap(a.name_,       b.name_);       // base protected member
    swap(a.resistance_, b.resistance_); // derived
}
