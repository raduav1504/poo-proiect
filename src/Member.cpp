#include "Member.h"
#include <utility>

Member::Member(int id, const std::string& name)
    : id_(id), name_(name) {}

Member::Member(const Member& other)
    : id_(other.id_), name_(other.name_) {}

Member& Member::operator=(Member other) {
    swap(other);
    return *this;
}

void Member::swap(Member& other) {
    using std::swap;
    swap(id_, other.id_);
    swap(name_, other.name_);
}

int Member::getId() const { return id_; }
std::string Member::getName() const { return name_; }

std::ostream& operator<<(std::ostream& os, const Member& m) {
    os << "Member[ID=" << m.id_ << ", Name=" << m.name_ << "]";
    return os;
}
