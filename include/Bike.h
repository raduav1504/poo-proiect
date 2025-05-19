#ifndef BIKE_H
#define BIKE_H

#include "Equipment.h"
#include <memory>

class Bike : public Equipment {
public:
    explicit Bike(double resistance);
    Bike(const Bike& other);
    Bike& operator=(Bike other);
    ~Bike() noexcept override = default;

    std::unique_ptr<Equipment> clone() const override;
    void use(int minutes) override;

    friend void swap(Bike& lhs, Bike& rhs) noexcept;

private:
    double resistance_;
};

#endif // BIKE_H
