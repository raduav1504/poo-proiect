#ifndef ROWMACHINE_H
#define ROWMACHINE_H

#include "Equipment.h"
#include <memory>

class RowMachine : public Equipment {
public:
    explicit RowMachine(int stroke_rate);
    RowMachine(const RowMachine& other);
    RowMachine& operator=(RowMachine other);
    ~RowMachine() noexcept override = default;

    std::unique_ptr<Equipment> clone() const override;
    void use(int minutes) override;

    friend void swap(RowMachine& lhs, RowMachine& rhs) noexcept;

private:
    int strokeRate_;
};

#endif // ROWMACHINE_H
