#ifndef MEMBER_H
#define MEMBER_H

#include "Equipment.h"
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Member {
public:
    explicit Member(std::string name);
    Member(const Member&);
    Member& operator=(Member);

    void addEquipment(std::unique_ptr<Equipment> eq);
    void useEquipment(const std::string& eqName, int minutes);

    friend std::ostream& operator<<(std::ostream& os, const Member& m);
    friend void swap(Member& a, Member& b) noexcept;

private:
    std::string name_;
    std::vector<std::unique_ptr<Equipment>> equipment_;
};

#endif // MEMBER_H
