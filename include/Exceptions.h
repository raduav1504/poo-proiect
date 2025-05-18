#pragma once
#include <stdexcept>
#include <string>

class ClubException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class EquipmentError : public ClubException {
public:
    explicit EquipmentError(const std::string& msg)
        : ClubException("EquipmentError: " + msg) {}
};

class MemberError : public ClubException {
public:
    explicit MemberError(const std::string& msg)
        : ClubException("MemberError: " + msg) {}
};

class UsageError : public ClubException {
public:
    explicit UsageError(const std::string& msg)
        : ClubException("UsageError: " + msg) {}
};
