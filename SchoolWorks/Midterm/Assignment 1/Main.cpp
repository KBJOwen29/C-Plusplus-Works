#include <iostream>
#include "Car.h"

int main() {
    // Create a car object
    Car myCar("Toyota", "Corolla", 2020, "Red");

    // Display initial car information
    myCar.displayInfo();

    // Change the car's color using the changeColor method
    myCar.changeColor("Blue");

    // Update car's make
    myCar.setMake("Honda");

    std::cout << "\nAfter updates:" << std::endl;
    myCar.displayInfo();

    // Start the car animation
    myCar.startCar();

    return 0;
}
