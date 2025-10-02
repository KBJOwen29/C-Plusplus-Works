#include <iostream>
#define QUEUE_H
using namespace std;

class Queue {
private:
    int front, rear, size, capacity;
    int* queue;

public:

    Queue(int cap) {
        front = 0;
        rear = 0;  
        size = 0;  
        capacity = cap;
        queue = new int[capacity];
    }

    
    ~Queue() {
        delete[] queue;
    }

   
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        queue[rear] = data;
        rear = (rear + 1) % capacity; 
        size++;  
        cout << data << " added to the queue\n";
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        
        front = (front + 1) % capacity;  
        size--;  
    }

   
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity; 
    }

   
    bool isEmpty() {
        return size == 0; 
    }

   
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " < ";  
        }
        cout << endl;
    }
};
