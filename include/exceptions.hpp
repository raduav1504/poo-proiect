#pragma once
#include <stdexcept>
#include <string>

class AppException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class EquipmentNotFoundException : public AppException {
public:
    explicit EquipmentNotFoundException(const std::string& id);
};

class MemberNotFoundException : public AppException {
public:
    explicit MemberNotFoundException(const std::string& name);
};

class InvalidDurationException : public AppException {
public:
    explicit InvalidDurationException(int d);
};
