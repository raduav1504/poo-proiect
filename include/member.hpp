// include/member.hpp
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "equipment.hpp"
#include "exceptions.hpp"

class Member {
public:
    explicit Member(std::string name);
    Member(const Member& other);
    Member& operator=(Member other);
    friend void swap(Member& a, Member& b);

    void addEquipment(const std::shared_ptr<EquipmentBase>& eq);
    void doWorkout(const std::string& eqId, int minutes);

    // look up an equipment by ID (throws if not found)
    std::shared_ptr<EquipmentBase> getEquipment(const std::string& eqId) const;

    // the new helper: down-cast to Treadmill and set its speed
    void adjustTreadmillSpeed(const std::string& eqId, double newSpeed);

    friend std::ostream& operator<<(std::ostream& os, const Member& m);

private:
    std::string name_;
    std::vector<std::shared_ptr<EquipmentBase>> equipment_;
};
