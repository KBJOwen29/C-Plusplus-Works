#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
    int ticket_number;

    Person(std::string name, int ticket_number) {
        this->name = name;
        this->ticket_number = ticket_number;
    }
};

#endif
