#include "Equipment.h"
#include "Exceptions.h"

Equipment::Equipment(std::string name)
    : name_(std::move(name)) {
    if (name_.empty()) {
        throw EquipmentError("empty name");
    }
}

void Equipment::use(int minutes) {
    if (minutes <= 0) {
        throw EquipmentError("usage time must be positive");
    }
    do_use(minutes);
}
