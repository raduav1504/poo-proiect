#pragma once
#include "Equipment.h"

class Bike : public Equipment {
public:
     explicit Bike(double resistance);
    Bike(const Bike& other);
    Bike& operator=(Bike other);
    ~Bike() override = default;

    std::unique_ptr<Equipment> clone() const override;

protected:
    void print(std::ostream& os) const override;
    void do_use(int minutes) override;

private:
    double resistance_;
    friend void swap(Bike& a, Bike& b);
};
