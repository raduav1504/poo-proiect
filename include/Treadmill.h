#ifndef TREADMILL_H
#define TREADMILL_H

#include "Equipment.h"
#include <memory>

class Treadmill : public Equipment {
public:
    explicit Treadmill(double max_speed);
    Treadmill(const Treadmill& other);
    Treadmill& operator=(Treadmill other);
    ~Treadmill() noexcept override = default;

    std::unique_ptr<Equipment> clone() const override;
    void use(int minutes) override;

    friend void swap(Treadmill& lhs, Treadmill& rhs) noexcept;

private:
    double maxSpeed_;
};

#endif // TREADMILL_H
