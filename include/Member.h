#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Equipment.h"

class Member {
public:
    Member(std::string name);
    Member(const Member& other);
    Member& operator=(Member other);
    ~Member() = default;

    void addEquipment(std::unique_ptr<Equipment> eq);
    void useEquipment(const std::string& eqName, int minutes);

    friend std::ostream& operator<<(std::ostream& os, const Member& m);

private:
    std::string name_;
    std::vector<std::unique_ptr<Equipment>> equipment_;
    friend void swap(Member& a, Member& b);
};
