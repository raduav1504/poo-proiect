#include <iostream>
#include <limits>
#include <memory>

#include "Member.h"
#include "Exceptions.h"
#include "Bike.h"
#include "Treadmill.h"
#include "RowMachine.h"

int main() {
    try {
        std::cout << "Enter member name: ";
        std::string name;
        std::getline(std::cin, name);
        Member member(name);

        std::cout << "How many equipment items do you want to add? ";
        int n; std::cin >> n;
        if (n < 0) throw MemberError("negative equipment count");

        for (int i = 0; i < n; ++i) {
            std::cout << "\nEquipment #" << (i+1) << ":\n"
                      << "  Type (Bike/Treadmill/RowMachine): ";
            std::string type;
            std::cin >> type;

            if (type == "Bike") {
                std::cout << "  Enter resistance (double): ";
                double r; std::cin >> r;
                member.addEquipment(std::make_unique<Bike>(r));
            }
            else if (type == "Treadmill") {
                std::cout << "  Enter max speed (double): ";
                double s; std::cin >> s;
                member.addEquipment(std::make_unique<Treadmill>(s));
            }
            else if (type == "RowMachine") {
                std::cout << "  Enter stroke rate (int): ";
                int sr; std::cin >> sr;
                member.addEquipment(std::make_unique<RowMachine>(sr));
            }
            else {
                std::cerr << "  Unknown type, skipping...\n";
            }
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nCurrent state:\n" << member;

        while (true) {
            std::cout << "\nEnter equipment name to use (or \"exit\"): ";
            std::string eq;
            std::getline(std::cin, eq);
            if (eq == "exit") break;

            std::cout << "Minutes to use: ";
            int mins; std::cin >> mins;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            try {
                member.useEquipment(eq, mins);
            }
            catch (const ClubException& e) {
                std::cerr << "  Error: " << e.what() << "\n";
            }
        }

        std::cout << "\nFinal state:\n" << member;
    }
    catch (const ClubException& ex) {
        std::cerr << "Fatal: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
