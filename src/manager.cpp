// src/manager.cpp
#include "manager.hpp"
#include "exceptions.hpp"
#include "treadmill.hpp"           // for dynamic_pointer_cast
#include <iostream>                // for std::cout, std::endl

void ClubManager::addMember(const std::string& name) {
    members_.emplace(name, std::make_shared<Member>(name));
}

void ClubManager::addEquipmentToMember(const std::string& name,
                                       const std::shared_ptr<EquipmentBase>& eq)
{
    auto it = members_.find(name);
    if (it == members_.end())
        throw MemberNotFoundException(name);
    it->second->addEquipment(eq);
}

void ClubManager::workout(const std::string& name,
                          const std::string& eqId, int minutes)
{
    auto it = members_.find(name);
    if (it == members_.end())
        throw MemberNotFoundException(name);
    it->second->doWorkout(eqId, minutes);
}

void ClubManager::adjustTreadmillSpeed(const std::string& memberName,
                                       const std::string& eqId,
                                       double newMaxSpeed)
{
    // 1) find the member
    auto mit = members_.find(memberName);
    if (mit == members_.end())
        throw MemberNotFoundException(memberName);

    // 2) find the equipment by id
    auto eqPtr = mit->second->getEquipment(eqId);
    if (!eqPtr)
        throw EquipmentNotFoundException(eqId);

    // 3) down-cast to Treadmill
    auto tm = std::dynamic_pointer_cast<Treadmill>(eqPtr);
    if (!tm)
        throw AppException("Equipment '" + eqId + "' is not a treadmill");

    // 4) adjust its speed
    tm->setMaxSpeed(newMaxSpeed);
}

void ClubManager::printAllMembers() const {
    for (const auto& [name, memberPtr] : members_) {
        std::cout << *memberPtr << std::endl;
    }
}
