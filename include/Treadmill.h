#ifndef TREADMILL_H
#define TREADMILL_H

#include "Equipment.h"

class Treadmill : public Equipment {
public:
    explicit Treadmill(double maxSpeed);
    Treadmill(const Treadmill&) = default;
    Treadmill& operator=(const Treadmill&) = default;
    ~Treadmill() override = default;

    void use(int minutes) override;
    std::unique_ptr<Equipment> clone() const override;

    friend void swap(Treadmill& a, Treadmill& b) noexcept;

private:
    double maxSpeed_;

    void printDetails(std::ostream& os) const override {
        os << " (maxSpeed=" << maxSpeed_ << ")";
    }
};

#endif // TREADMILL_H
