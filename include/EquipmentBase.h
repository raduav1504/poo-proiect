#ifndef EQUIPMENTBASE_H
#define EQUIPMENTBASE_H

#include <string>
#include <memory>
#include "Member.h"

class EquipmentBase {
public:
    EquipmentBase(const std::string& id);
    EquipmentBase(const EquipmentBase& other);
    EquipmentBase& operator=(EquipmentBase other);
    virtual ~EquipmentBase();

    // High-level non-virtual interface
    void operate(std::shared_ptr<Member> member, int duration);

    std::string getId() const { return id_; }
    static int getCount();

    // Virtual copy-constructor (clone idiom)
    virtual std::shared_ptr<EquipmentBase> clone() const = 0;

protected:
    // Theme-specific pure virtual functions
    virtual void startUseImpl(std::shared_ptr<Member> member, int duration) = 0;
    virtual void updateStatus() = 0;

    // Swap helper
    friend void swap(EquipmentBase& first, EquipmentBase& second);

private:
    std::string id_;                           // Equipment identifier
    std::shared_ptr<Member> currentUser_;      // Current member using
    int usageDuration_;                        // Duration in minutes
    static int count_;                         // Total instances alive
};

#endif // EQUIPMENTBASE_H
