// main.cpp
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

        // 2) Add equipment to members
        club.addEquipmentToMember("Alice",
            std::make_shared<Treadmill>("T1", 12.5));
        club.addEquipmentToMember("Alice",
            std::make_shared<StationaryBike>("B1", 7.0));
        club.addEquipmentToMember("Bob",
            std::make_shared<WeightMachine>("W1", 50.0));

        // 3) Report how many EquipmentBase instances exist
        std::cout << "Total equipment in club: "
                  << EquipmentBase::getCount() << "\n\n";

        // 4) Perform some workouts
        club.workout("Alice", "T1", 30);   // OK
        club.workout("Alice", "B1", 20);   // OK
        club.workout("Bob",   "W1", 15);   // OK

        // 5) This one will throw EquipmentNotFoundException
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
        // fallback for any other AppException
        std::cerr << "[App error]       " << e.what() << "\n";
    }

    return 0;
}
