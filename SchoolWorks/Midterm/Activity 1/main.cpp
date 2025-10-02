#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:

    Person(std::string personName, int personAge) {
        name = personName;
        age = personAge;
    }

    void displayInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    void setName(std::string newName) {
        name = newName;
    }

    std::string getName() {
        return name;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    int getAge() {
        return age;
    }
};

int main() {
    Person person1("John", 25);

    person1.displayInfo();

    person1.setName("Jane");
    person1.setAge(30);

    std::cout << "Updated Info:" << std::endl;
    person1.displayInfo();

    return 0;
}
