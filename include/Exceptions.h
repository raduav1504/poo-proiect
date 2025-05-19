#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class ClubException : public std::exception {
public:
    explicit ClubException(std::string msg) noexcept
      : msg_{std::move(msg)} {}

    const char* what() const noexcept override {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

class MemberError : public ClubException {
public:
    explicit MemberError(std::string msg) noexcept
      : ClubException(std::move(msg)) {}
};

class EquipmentError : public ClubException {
public:
    explicit EquipmentError(std::string msg) noexcept
      : ClubException(std::move(msg)) {}
};

class UsageError : public ClubException {
public:
    explicit UsageError(std::string msg) noexcept
      : ClubException(std::move(msg)) {}
};

#endif // EXCEPTIONS_H
