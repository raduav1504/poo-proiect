// main.cpp

#include <iostream>
#include <memory>
#include <limits>
#include "exceptions.hpp"
#include "equipment.hpp"
#include "treadmill.hpp"
#include "stationary_bike.hpp"
#include "weight_machine.hpp"
#include "manager.hpp"

static void printMenu() {
    std::cout << "\n=== Club Manager ===\n"
                 "1) Add member\n"
                 "2) Add equipment to member\n"
                 "3) List all members and their equipment\n"
                 "4) Do a workout\n"
                 "5) Show total equipment count\n"
                 "6) Bump a treadmill’s max speed\n"
                 "0) Exit\n"
                 "Choose an option: ";
}

// helper to clear a failed std::cin and skip to end of line
static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    ClubManager club;
    
    bool running = true;
    while (running) {
        printMenu();
        int choice;
        if (!(std::cin >> choice)) {
            // invalid input: exit
            break;
        }

        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter member name: ";
                    std::string name;
                    std::cin >> name;
                    club.addMember(name);
                    std::cout << "Added member \"" << name << "\".\n";
                    break;
                }
                case 2: {
                    std::cout << "Member name: ";
                    std::string name;  std::cin >> name;
                    std::cout << "Equipment type (treadmill/bike/weight): ";
                    std::string type;  std::cin >> type;
                    std::cout << "Equipment ID: ";
                    std::string id;    std::cin >> id;

                    if (type == "treadmill") {
                        std::cout << "Max speed (km/h): ";
                        double v; std::cin >> v;
                        club.addEquipmentToMember(name, std::make_shared<Treadmill>(id, v));
                    }
                    else if (type == "bike") {
                        std::cout << "Resistance: ";
                        double r; std::cin >> r;
                        club.addEquipmentToMember(name, std::make_shared<StationaryBike>(id, r));
                    }
                    else if (type == "weight") {
                        std::cout << "Weight (kg): ";
                        double w; std::cin >> w;
                        club.addEquipmentToMember(name, std::make_shared<WeightMachine>(id, w));
                    }
                    else {
                        std::cout << "Unknown equipment type.\n";
                        break;
                    }
                    std::cout << "Equipment added.\n";
                    break;
                }
                case 3:
                    club.printAllMembers();
                    break;

                case 4: {
                    std::cout << "Member name: ";
                    std::string name; std::cin >> name;
                    std::cout << "Equipment ID: ";
                    std::string id;   std::cin >> id;
                    std::cout << "Minutes: ";
                    int m;            std::cin >> m;
                    club.workout(name, id, m);
                    break;
                }

                case 5:
                    std::cout << "Total equipment in club: "
                              << EquipmentBase::getCount() << "\n";
                    break;

                case 6: {
                    std::cout << "Member name: ";
                    std::string name; std::cin >> name;
                    std::cout << "Treadmill ID to bump: ";
                    std::string id;   std::cin >> id;
                    std::cout << "New max speed (km/h): ";
                    double speed;     std::cin >> speed;
                    club.adjustTreadmillSpeed(name, id, speed);
                    std::cout << "Speed updated.\n";
                    break;
                }

                case 0:
                    running = false;
                    break;

                default:
                    std::cout << "Invalid option.\n";
            }
        }
        catch (const AppException& e) {
            std::cerr << "[Error] " << e.what() << "\n";
            clearInput();
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
