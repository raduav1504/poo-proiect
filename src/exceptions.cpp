#include "exceptions.hpp"

EquipmentNotFoundException::EquipmentNotFoundException(const std::string& id)
  : AppException("Echipament inexistent: " + id) {}

MemberNotFoundException::MemberNotFoundException(const std::string& name)
  : AppException("Membru inexistent: " + name) {}

InvalidDurationException::InvalidDurationException(int d)
  : AppException("Durata invalida: " + std::to_string(d)) {}
