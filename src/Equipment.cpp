#include "Equipment.h"
#include "Exceptions.h"
#include <utility>

Equipment::Equipment(std::string name)
  : name_(std::move(name))
{
    if (name_.empty())
        throw EquipmentError("empty equipment name");
}
