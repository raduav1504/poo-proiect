#include "Treadmill.h"
#include <iostream>
#include <utility>

Treadmill::Treadmill(double max_speed)
    : Equipment("Treadmill"), max_speed_(max_speed) {
    if (max_speed_ <= 0) {
        throw EquipmentError("max_speed must be positive");
    }
}

Treadmill::Treadmill(const Treadmill& other)
    : Equipment(other), max_speed_(other.max_speed_) {}

Treadmill& Treadmill::operator=(Treadmill other) {
    swap(*this, other);
    return *this;
}

std::unique_ptr<Equipment> Treadmill::clone() const {
    return std::make_unique<Treadmill>(*this);
}

void Treadmill::print(std::ostream& os) const {
    Equipment::print(os);
    os << " (max_speed=" << max_speed_ << ")";
}

void Treadmill::do_use(int minutes) {
    std::cout << "Running on treadmill at up to " << max_speed_
              << " km/h for " << minutes << " minutes.\n";
}

void swap(Treadmill& a, Treadmill& b) {
    using std::swap;
    swap(static_cast<Equipment&>(a), static_cast<Equipment&>(b));
    swap(a.max_speed_, b.max_speed_);
}
