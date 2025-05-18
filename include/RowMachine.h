#pragma once
#include "Equipment.h"

class RowMachine : public Equipment {
public:
    RowMachine(int stroke_rate);
    RowMachine(const RowMachine& other);
    RowMachine& operator=(RowMachine other);
    ~RowMachine() override = default;

    std::unique_ptr<Equipment> clone() const override;

protected:
    void print(std::ostream& os) const override;
    void do_use(int minutes) override;

private:
    int stroke_rate_;
    friend void swap(RowMachine& a, RowMachine& b);
};
