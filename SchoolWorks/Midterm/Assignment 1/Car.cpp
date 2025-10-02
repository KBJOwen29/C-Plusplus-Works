#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <thread>     // For cross-platform sleep functionality
#include <chrono>     // For time handling

#ifdef _WIN32
#include <windows.h>  // For Windows-specific console handling
#endif

// Function to set console text color on Windows (Windows-specific)
#ifdef _WIN32
void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
// Dummy function for non-Windows platforms
void setConsoleColor(int color) {
    // No-op on non-Windows systems
}
#endif

Car::Car(std::string carMake, std::string carModel, int carYear, std::string carColor)
    : make(carMake), model(carModel), year(carYear), color(carColor), speed(1) {}

void Car::displayInfo() {
    std::cout << "Car Information:" << std::endl;
    std::cout << "Make: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Speed: " << speed << std::endl;
}

void Car::setMake(std::string carMake) {
    make = carMake;
}

std::string Car::getMake() {
    return make;
}

void Car::upgradeSpeed() {
    speed += 1;
}

void Car::startCar() {
    int moving_speed = 1;

    while (true) {
        std::string stuff(moving_speed, ' ');
        system("clear");  // Use 'clear' on Unix-like systems instead of 'cls'

        setConsoleColor(12);  // Set text color to Light Red (ignored on non-Windows)

        std::cout << std::endl << std::endl << std::endl;
        std::cout << "======================================================================================" << std::endl;
        std::cout << stuff <<"   /|_||_\\`.__  " << std::endl;
        std::cout << stuff <<"  (   _    _ _\\ " << std::endl;
        std::cout << stuff <<"  =`-(_)--(_)-' " << std::endl;
        std::cout << "======================================================================================" << std::endl;

        setConsoleColor(7);  // Reset to default color (ignored on non-Windows)

        moving_speed += speed;

        // Cross-platform sleep for 300 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void Car::changeColor(std::string newColor) {
    color = newColor;
    std::cout << "The car's color has been changed to: " << color << std::endl;
}
