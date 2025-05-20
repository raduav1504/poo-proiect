#include "manager.hpp"
#include "exceptions.hpp"
#include "treadmill.hpp"    // for dynamic_pointer_cast
#include <iostream>

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
                          const std::string& eqId,
                          int minutes)
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
    auto mit = members_.find(memberName);
    if (mit == members_.end())
        throw MemberNotFoundException(memberName);

    // grab the base-pointer, then try downcast
    auto eqPtr = mit->second->getEquipment(eqId);
    auto tm = std::dynamic_pointer_cast<Treadmill>(eqPtr);
    if (!tm)
        throw EquipmentNotFoundException(eqId);  // or a custom “not-a-treadmill” exception

    tm->setMaxSpeed(newMaxSpeed);
}

void ClubManager::printAllMembers() const {
    for (const auto& [name, mptr] : members_) {
        std::cout << *mptr << "\n";
    }
}
