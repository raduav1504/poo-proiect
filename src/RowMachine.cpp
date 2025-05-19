#include "RowMachine.h"
#include "Exceptions.h"
#include "Equipment.h"
#include <algorithm>
#include <iostream>
#include <utility>

RowMachine::RowMachine(int stroke_rate)
    : Equipment("RowMachine"), stroke_rate_(stroke_rate) {
    if (stroke_rate_ <= 0) {
        throw EquipmentError("stroke_rate must be positive");
    }
}

RowMachine::RowMachine(const RowMachine& other)
    : Equipment(other), stroke_rate_(other.stroke_rate_) {}

RowMachine& RowMachine::operator=(RowMachine other) {
    swap(*this, other);
    return *this;
}

std::unique_ptr<Equipment> RowMachine::clone() const {
    return std::make_unique<RowMachine>(*this);
}

void RowMachine::print(std::ostream& os) const {
    Equipment::print(os);
    os << " (stroke_rate=" << stroke_rate_ << ")";
}

void RowMachine::do_use(int minutes) {
    std::cout << "Rowing at " << stroke_rate_
              << " strokes/min for " << minutes << " minutes.\n";
}

void swap(RowMachine& a, RowMachine& b) {
    using std::swap;
    swap(static_cast<Equipment&>(a), static_cast<Equipment&>(b));
    swap(a.stroke_rate_, b.stroke_rate_);
}
