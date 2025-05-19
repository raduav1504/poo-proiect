#ifndef BIKE_H
#define BIKE_H

#include "Equipment.h"

class Bike : public Equipment {
public:
    explicit Bike(double resistance);
    Bike(const Bike&) = default;
    Bike& operator=(const Bike&) = default;
    ~Bike() override = default;

    void use(int minutes) override;
    std::unique_ptr<Equipment> clone() const override;

    friend void swap(Bike& a, Bike& b) noexcept;

private:
    double resistance_;

    void printDetails(std::ostream& os) const override {
        os << " (resistance=" << resistance_ << ")";
    }
};

#endif // BIKE_H
