#include "manager.hpp"
#include "exceptions.hpp"

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

void ClubManager::adjustTreadmillSpeed(const std::string& name,
                                       const std::string& eqId,
                                       double newSpeed)
{
    auto it = members_.find(name);
    if (it == members_.end())
        throw MemberNotFoundException(name);
    it->second->adjustTreadmillSpeed(eqId, newSpeed);
}
