#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "equipment.hpp"

class Member {
public:
    explicit Member(std::string name);
    Member(const Member& other);
    Member& operator=(Member other);
    friend void swap(Member& a, Member& b);

    void addEquipment(const std::shared_ptr<EquipmentBase>& eq);
    void doWorkout(const std::string& eqId, int minutes);

    /// Down-cast example: find a treadmill by id and bump its speed
    void adjustTreadmillSpeed(const std::string& eqId, double newSpeed);

    friend std::ostream& operator<<(std::ostream& os, const Member& m);

private:
    std::string name_;
    std::vector<std::shared_ptr<EquipmentBase>> equipment_;
};
