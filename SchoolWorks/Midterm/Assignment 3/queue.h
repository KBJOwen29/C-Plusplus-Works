#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <iostream>
#include "person.h"

class Queue {
private:
    std::queue<Person> q;
    int next_ticket = 1;

public:
    // Add a person to the end of the queue
    void Enqueue(std::string name) {
        Person p(name, next_ticket++);
        q.push(p);
        std::cout << name << " added to the queue with Ticket #" << p.ticket_number << std::endl;
    }

    // Automatically remove the person at the front every minute
    void AutoDequeue() {
        if (!q.empty()) {
            Person p = q.front();
            q.pop();
            std::cout << "Dequeue: " << p.name << " received a ticket (Ticket #" << p.ticket_number << ")" << std::endl;
        } else {
            std::cout << "Queue is empty. No one to dequeue!" << std::endl;
        }
    }

    // Check if the queue is empty
    bool IsEmpty() {
        return q.empty();
    }

    // Return the number of people in the queue
    int Size() {
        return q.size();
    }

    // Peek at the person next in line
    void Peek() {
        if (!q.empty()) {
            Person p = q.front();
            std::cout << "Next in line: " << p.name << " (Ticket #" << p.ticket_number << ")" << std::endl;
        } else {
            std::cout << "Queue is empty." << std::endl;
        }
    }

    // Get the position of a person based on their name or ticket number
    void Position(std::string name) {
        std::queue<Person> temp = q;
        int position = 1;
        while (!temp.empty()) {
            Person p = temp.front();
            temp.pop();
            if (p.name == name) {
                std::cout << name << " is currently at position " << position << " in the queue." << std::endl;
                return;
            }
            position++;
        }
        std::cout << name << " is not in the queue." << std::endl;
    }
};

#endif
