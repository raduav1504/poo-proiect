#ifndef TREADMILL_H
#define TREADMILL_H

#include "EquipmentBase.h"

class Treadmill : public EquipmentBase {
public:
    explicit Treadmill(const std::string& id);
    Treadmill(const Treadmill& other);
    Treadmill& operator=(Treadmill other);
    ~Treadmill() override = default;

    std::shared_ptr<EquipmentBase> clone() const override;

protected:
    void startUseImpl(std::shared_ptr<Member> member, int duration) override;
    void updateStatus() override;

private:
    int speedLevel_;
    void swap(Treadmill& other);
};

#endif // TREADMILL_H
