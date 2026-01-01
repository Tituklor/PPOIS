// core/Administrator/Administrator.cpp
#include "Administrator.h"

Administrator::Administrator(const std::string& name, int age,
                             const std::string& phoneNumber, const std::string& email,
                             int id)
        : Person(name, age, phoneNumber, email), id_(id) {}

int Administrator::getId() const {
    return id_;
}