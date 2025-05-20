#pragma once
#include <memory>
#include <string>
#include "exceptions.hpp"

class EquipmentBase {
public:
    EquipmentBase(const std::string& id);
    virtual ~EquipmentBase();

    void operate(int minutes);
    const std::string& id() const noexcept;
    static int getCount() noexcept;

    virtual std::shared_ptr<EquipmentBase> clone() const = 0;

protected:
    EquipmentBase(const EquipmentBase& other);
    EquipmentBase& operator=(const EquipmentBase& other);

private:
    virtual void doOperate(int) = 0;

    std::string id_;
    static int count_;
};
