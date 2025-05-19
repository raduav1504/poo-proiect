#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <memory>
#include <string>
#include <ostream>

class Equipment {
public:
    explicit Equipment(std::string name)
      : name_{std::move(name)} {}

    Equipment(const Equipment&)            = default;
    Equipment& operator=(const Equipment&) = default;
    virtual ~Equipment() noexcept          = default;

    // Virtual “clone” constructor
    virtual std::unique_ptr<Equipment> clone() const = 0;

    // Theme-specific action
    virtual void use(int minutes) = 0;

    // Non-virtual display interface
    void display(std::ostream& os) const {
        os << "[" << name_ << "] ";
        doDisplay(os);
    }

    friend std::ostream& operator<<(std::ostream& os, const Equipment& eq) {
        eq.display(os);
        return os;
    }

protected:
    // Hook for subclass-specific display
    virtual void doDisplay(std::ostream& os) const = 0;

private:
    std::string name_;
};

#endif // EQUIPMENT_H
