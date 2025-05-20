#pragma once
#include <map>
#include <string>
#include <memory>
#include "member.hpp"

class ClubManager {
public:
    void addMember(const std::string& name);
    void addEquipmentToMember(const std::string& name,
                              const std::shared_ptr<EquipmentBase>& eq);
    void workout(const std::string& name,
                 const std::string& eqId, int minutes);

    /// Expose the treadmill‐speed adjustment
    void adjustTreadmillSpeed(const std::string& name,
                              const std::string& eqId, double newSpeed);

private:
    std::map<std::string, std::shared_ptr<Member>> members_;
};
