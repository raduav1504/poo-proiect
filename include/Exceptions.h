#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class FitnessException : public std::exception {
public:
    explicit FitnessException(const std::string& msg) : msg_(msg) {}
    const char* what() const noexcept override { return msg_.c_str(); }
private:
    std::string msg_;
};

// Distinct error categories
typedef FitnessException BaseError;
class EquipmentNotFoundException : public BaseError {
public:
    explicit EquipmentNotFoundException(const std::string& id)
        : BaseError("Equipment not found: " + id) {}
};

class MemberNotFoundException : public BaseError {
public:
    explicit MemberNotFoundException(int id)
        : BaseError("Member not found: " + std::to_string(id)) {}
};

class InvalidDurationException : public BaseError {
public:
    explicit InvalidDurationException(int d)
        : BaseError("Invalid duration: " + std::to_string(d)) {}
};

#endif // EXCEPTIONS_H
