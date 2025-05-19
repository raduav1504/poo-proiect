// src/main.cpp
#include <iostream>
#include <string>
#include <limits>
#include "Member.h"
#include "Exceptions.h"
#include "Bike.h"
#include "Treadmill.h"
#include "RowMachine.h"

int main() {
    try {
        // 1. Citește numele membrului
        std::cout << "Enter member name: ";
        std::string name;
        std::getline(std::cin, name);
        Member member(name);

        // 2. Citește câte aparate va adăuga
        std::cout << "How many equipment items do you want to add? ";
        int n;
        std::cin >> n;
        if (n < 0) throw MemberError("negative equipment count");
        for (int i = 0; i < n; ++i) {
            std::cout << "\nEquipment #" << (i+1) << ":\n";
            std::cout << "  Type (Bike/Treadmill/RowMachine): ";
            std::string type;
            std::cin >> type;

            if (type == "Bike") {
                std::cout << "  Enter resistance (double): ";
                double res; std::cin >> res;
                member.addEquipment(std::make_unique<Bike>(res));
            }
            else if (type == "Treadmill") {
                std::cout << "  Enter max speed (double): ";
                double sp; std::cin >> sp;
                member.addEquipment(std::make_unique<Treadmill>(sp));
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

        // Curăţăm buffer-ul înainte de getline-ul de mai jos
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // 3. Afișăm ce are membrul
        std::cout << "\nCurrent state:\n" << member;

        // 4. Buclă de folosire a aparatelor
        while (true) {
            std::cout << "\nEnter equipment name to use (or \"exit\" to quit): ";
            std::string eqName;
            std::getline(std::cin, eqName);
            if (eqName == "exit") break;

            std::cout << "Minutes to use: ";
            int minutes;
            std::cin >> minutes;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            try {
                member.useEquipment(eqName, minutes);
            }
            catch (const ClubException& e) {
                std::cerr << "  Error: " << e.what() << "\n";
            }
        }

        // 5. Afișăm iar starea finală
        std::cout << "\nFinal state:\n" << member;
    }
    catch (const ClubException& ex) {
        std::cerr << "Fatal error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
