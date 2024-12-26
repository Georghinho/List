#pragma once

#include <iostream>


using namespace std;

template<typename T>
struct Node {
    int data;       
    Node* next;     

    Node(int val) : data(val), next(nullptr) {}  
};

class List {
private:
    Node* head;  

public:
    List() : head(nullptr) {}  

    
    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    
    void append(int val) {
        if (head == nullptr) {
            head = new Node(val);
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(val);
        }
    }

    
    void remove(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

   
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};