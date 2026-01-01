// core/Visitor/Visitor.cpp
#include "Visitor.h"

Visitor::Visitor(const std::string& name, int age,
                 const std::string& phoneNumber, const std::string& email)
        : Person(name, age, phoneNumber, email) {}