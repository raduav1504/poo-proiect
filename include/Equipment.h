#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <memory>
#include <ostream>
#include <string>

class Equipment {
protected:
    std::string name_;
    explicit Equipment(std::string name);

public:
    virtual ~Equipment() = default;
    Equipment(const Equipment&) = default;
    Equipment& operator=(const Equipment&) = default;

    // theme-specific virtual
    virtual void use(int minutes) = 0;
    virtual std::unique_ptr<Equipment> clone() const = 0;

    // non-virtual interface + private virtual hook
    void print(std::ostream& os) const {
        os << name_;
        printDetails(os);
    }

    const std::string& getName() const noexcept { return name_; }

private:
    virtual void printDetails(std::ostream& os) const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const Equipment& eq) {
    eq.print(os);
    return os;
}

#endif // EQUIPMENT_H
