#pragma once
#include <string>
#include <memory>
#include <iostream>

class Equipment {
public:
    Equipment(std::string name);
    virtual ~Equipment() = default;

    // interfață non-virtuală
    void use(int minutes);

    // clone (constructor virtual)
    virtual std::unique_ptr<Equipment> clone() const = 0;

    // afișare virtuală
    friend std::ostream& operator<<(std::ostream& os, const Equipment& e) {
        e.print(os);
        return os;
    }

protected:
    virtual void print(std::ostream& os) const {
        os << "Equipment[" << name_ << "]";
    }
    virtual void do_use(int minutes) = 0;

private:
    std::string name_;
};
