#ifndef ROWMACHINE_H
#define ROWMACHINE_H

#include "Equipment.h"

class RowMachine : public Equipment {
public:
    explicit RowMachine(int strokeRate);
    RowMachine(const RowMachine&) = default;
    RowMachine& operator=(const RowMachine&) = default;
    ~RowMachine() override = default;

    void use(int minutes) override;
    std::unique_ptr<Equipment> clone() const override;

    friend void swap(RowMachine& a, RowMachine& b) noexcept;

private:
    int strokeRate_;

    void printDetails(std::ostream& os) const override {
        os << " (strokeRate=" << strokeRate_ << ")";
    }
};

#endif // ROWMACHINE_H
