#include <iostream>
#include <memory>
#include <vector>
#include <map>

#include "Treadmill.h"
#include "StationaryBike.h"
#include "WeightMachine.h"
#include "Member.h"
#include "Exceptions.h"

int main() {
    try {
        // Create equipments and members
        std::vector<std::shared_ptr<EquipmentBase>> equipments;
        equipments.push_back(std::make_shared<Treadmill>("T1"));
        equipments.push_back(std::make_shared<StationaryBike>("B1"));
        equipments.push_back(std::make_shared<WeightMachine>("W1"));

        std::map<int, std::shared_ptr<Member>> members;
        members.emplace(1, std::make_shared<Member>(1, "Alice"));
        members.emplace(2, std::make_shared<Member>(2, "Bob"));

        // Operate Treadmill for Alice
        auto e0 = equipments.at(0);
        if (auto tm = std::dynamic_pointer_cast<Treadmill>(e0)) {
            tm->operate(members.at(1), 30);
        }

        // Operate StationaryBike for Bob
        equipments.at(1)->operate(members.at(2), 45);

        // Clone WeightMachine and operate
        auto wmClone = equipments.at(2)->clone();
        equipments.push_back(wmClone);
        equipments.back()->operate(members.at(1), 20);

        std::cout << "Total equipments alive: " << EquipmentBase::getCount() << std::endl;

    } catch (const BaseError& ex) {
        std::cerr << "Fitness error: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Unexpected error: " << ex.what() << std::endl;
    }
    return 0;
}
