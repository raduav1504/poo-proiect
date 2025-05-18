#pragma once
#include "Equipment.h"

class Treadmill : public Equipment {
public:
    Treadmill(double max_speed);
    Treadmill(const Treadmill& other);
    Treadmill& operator=(Treadmill other);
    ~Treadmill() override = default;

    std::unique_ptr<Equipment> clone() const override;

protected:
    void print(std::ostream& os) const override;
    void do_use(int minutes) override;

private:
    double max_speed_;
    friend void swap(Treadmill& a, Treadmill& b);
};
