// core/Person/Person.h
#ifndef SPORTCLUB_PERSON_H
#define SPORTCLUB_PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& name, int age,
           const std::string& phoneNumber, const std::string& email);

    std::string getName() const;
    void setName(const std::string& name);

    int getAge() const;
    void setAge(int age);

    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string& phoneNumber);

    std::string getEmail() const;
    void setEmail(const std::string& email);

private:
    std::string name_;
    int age_;
    std::string phoneNumber_;
    std::string email_;
};

#endif // SPORTCLUB_PERSON_H