#include <iostream>
#include "queue.h"

int main() {
    Queue concertQueue;
    int option;
    std::string name;

    std::cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << std::endl;

    while (true) {
        std::cout << "\n1. Enqueue a person" << std::endl;
        std::cout << "2. Check your position in the queue" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Enter the name: ";
                std::cin >> name;
                concertQueue.Enqueue(name);
                std::cout << "Queue size: " << concertQueue.Size() << std::endl;
                break;

            case 2:
                std::cout << "Enter your name or ticket number: ";
                std::cin >> name;
                concertQueue.Position(name);
                break;

            case 3:
                std::cout << "Exiting the system." << std::endl;
                return 0;

            default:
                std::cout << "Invalid option! Please choose again." << std::endl;
        }

        // Simulate the auto dequeue every minute
        std::cout << "\nAfter 1 minute..." << std::endl;
        concertQueue.AutoDequeue();
        concertQueue.Peek();
    }

    return 0;
}
