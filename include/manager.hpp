// include/manager.hpp
#pragma once
#include <map>
#include <string>
#include <memory>
#include "member.hpp"
#include "exceptions.hpp"
#include "treadmill.hpp"

class ClubManager {
public:
    void addMember(const std::string& name);
    void addEquipmentToMember(const std::string& name,
                              const std::shared_ptr<EquipmentBase>& eq);
    void workout(const std::string& name,
                 const std::string& eqId, int minutes);

    // adjust the maxSpeed_ of a specific Treadmill
    void adjustTreadmillSpeed(const std::string& memberName,
                              const std::string& eqId,
                              double newMaxSpeed);

    // utility to dump all members + their equipment
    void printAllMembers() const;

private:
    std::map<std::string, std::shared_ptr<Member>> members_;
};
