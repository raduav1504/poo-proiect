#include <iostream>
#include <memory>

#include "exceptions.hpp"
#include "equipment.hpp"
#include "treadmill.hpp"
#include "stationary_bike.hpp"
#include "weight_machine.hpp"
#include "manager.hpp"

int main() {
    ClubManager club;

    try {
        // 1) Add members
        club.addMember("Alice");
        club.addMember("Bob");

        // 2) Add equipment
        club.addEquipmentToMember("Alice",
            std::make_shared<Treadmill>("T1", 12.5));
        club.addEquipmentToMember("Alice",
            std::make_shared<StationaryBike>("B1", 7.0));
        club.addEquipmentToMember("Bob",
            std::make_shared<WeightMachine>("W1", 50.0));

        // 3) Count
        std::cout << "Total equipment in club: "
                  << EquipmentBase::getCount() << "\n\n";

        // 4) Workouts
        club.workout("Alice", "T1", 30);
        club.workout("Alice", "B1", 20);
        club.workout("Bob",   "W1", 15);

        // 5) Missing equipment (will throw)
        club.workout("Alice", "UNKNOWN_ID", 10);
    }
    catch (const EquipmentNotFoundException& e) {
        std::cerr << "[Equipment error] " << e.what() << "\n";
    }
    catch (const MemberNotFoundException& e) {
        std::cerr << "[Member error]    " << e.what() << "\n";
    }
    catch (const InvalidDurationException& e) {
        std::cerr << "[Duration error]  " << e.what() << "\n";
    }
    catch (const AppException& e) {
        std::cerr << "[App error]       " << e.what() << "\n";
    }

    // 6) Now our new example: down-cast & adjust
    try {
        std::cout << "\n-- Bumping Alice’s treadmill speed to 15 km/h --\n";
        club.adjustTreadmillSpeed("Alice", "T1", 15.0);
        club.workout("Alice", "T1", 10);
    }
    catch (const AppException& e) {
        std::cerr << "[Error] " << e.what() << "\n";
    }

    return 0;
}
