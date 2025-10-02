#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int speed;
    int year;

public:
    std::string color;

    Car(std::string carMake, std::string carModel, int carYear, std::string carColor);
    
    void displayInfo();
    void setMake(std::string carMake);
    std::string getMake();
    void upgradeSpeed();
    void startCar();
    void changeColor(std::string newColor);
};

#endif
