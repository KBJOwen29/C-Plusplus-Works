#define LINKEDLIST_H
#include <iostream>
using namespace std;



// Node class representing each element in the linked list
class Node {
    public:
        int data;
        Node* next;

        // Constructor to initialize node
        Node(int value) {
            data = value;
            next = nullptr;
        }
};

// LinkedList class containing linked list operations
class LinkedList {
    private:
        Node* head;
    
    public:
        // Constructor to initialize the head to nullptr
        LinkedList() {
            head = nullptr;
        }
    
        // method to insert a new node at the end of the list
        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    
        // method to insert a new node at the beginning of the list
        void insertAtBeginning(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

         // method to insert a node at a specific position
        void insertAtPosition(int value, int position) {
            Node* newNode = new Node(value);
            if (position == 1) {  // Insert at the head if position is 1
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Position out of bounds!" << endl;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    
        bool search(int value) {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->data == value) {
                    return true;  // Value found
                }
                temp = temp->next;
            }
            return false;  // Value not found
        }

        // method to display the linked list
        void display() {
            if (head == nullptr) {
                cout << "List is empty!" << endl;
            } else {
                Node* temp = head;
                while (temp != nullptr) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }
        }
    
        // method to delete a node from the list by value
        void deleteNode(int value) {
            if (head == nullptr) {
                cout << "List is empty!" << endl;
                return;
            }
    
            if (head->data == value) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
    
            Node* temp = head;
            Node* prev = nullptr;
            while (temp != nullptr && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }
    
            if (temp == nullptr) {
                cout << "Value not found!" << endl;
                return;
            }
    
            prev->next = temp->next;
            delete temp;
        }

        void reverse(){
            Node* previous = nullptr;
            Node* current = head;
            Node* next = nullptr;
            
            while (current != nullptr) {
                next = current->next;  
                current->next = previous;  
                previous = current;  
                current = next;  
            }
            head = previous; 

        }
    
        // Destructor to free allocated memory
        ~LinkedList() {
            Node* temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }
};