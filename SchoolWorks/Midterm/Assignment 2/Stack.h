#include <iostream>
#define STACK_H
using namespace std;
 
class Stack {
private:
    int* arr;  
    int top;       
    int capacity;  

public:

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top < capacity - 1) {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1; 
    }

    int peek() const {
        if (top >= 0) {
            return arr[top];
        }
        return -1; 
    }

    int showIdex(int index) {
        if (index >= 0 && index <= top)
          return arr[index];
        
        return -1;
    }

    bool isEmpty() const {
        return top == -1;
    }
};
