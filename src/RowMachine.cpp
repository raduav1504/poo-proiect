#include "RowMachine.h"
#include "Exceptions.h"
#include <algorithm>
#include <iostream>

RowMachine::RowMachine(int strokeRate)
  : Equipment("RowMachine"), strokeRate_(strokeRate)
{
    if (strokeRate <= 0)
        throw EquipmentError("stroke_rate must be positive");
}

void RowMachine::use(int minutes) {
    if (minutes < 0) throw UsageError("negative minutes");
    std::cout << name_ << ": rowing at rate "
              << strokeRate_ << " spm for "
              << minutes << " min\n";
}

std::unique_ptr<Equipment> RowMachine::clone() const {
    return std::make_unique<RowMachine>(*this);
}

void swap(RowMachine& a, RowMachine& b) noexcept {
    using std::swap;
    swap(a.name_,        b.name_);
    swap(a.strokeRate_,  b.strokeRate_);
}
