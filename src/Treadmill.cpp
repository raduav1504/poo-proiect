#include "Treadmill.h"
#include "Exceptions.h"
#include <algorithm>
#include <iostream>

Treadmill::Treadmill(double maxSpeed)
  : Equipment("Treadmill"), maxSpeed_(maxSpeed)
{
    if (maxSpeed <= 0)
        throw EquipmentError("max_speed must be positive");
}

void Treadmill::use(int minutes) {
    if (minutes < 0) throw UsageError("negative minutes");
    std::cout << name_ << ": running at up to "
              << maxSpeed_ << " km/h for "
              << minutes << " min\n";
}

std::unique_ptr<Equipment> Treadmill::clone() const {
    return std::make_unique<Treadmill>(*this);
}

void swap(Treadmill& a, Treadmill& b) noexcept {
    using std::swap;
    swap(a.name_,      b.name_);
    swap(a.maxSpeed_,  b.maxSpeed_);
}
