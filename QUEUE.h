#pragma once
#include <iostream>
#include <string>
#include <ctime> 
#include"NODE.h"
#include"COLOUR.h"
using namespace std;
class queuenode {
public:
    node* listnode;
    queuenode* next;
    queuenode(node* ln) : listnode(ln), next(nullptr) {}
};

class queue {
public:
    queuenode* front;
    queuenode* rear;
    queue() : front(nullptr), rear(nullptr) {}

    void enqueue(node* ln) {
        queuenode* newnode = new queuenode(ln);
        if (rear == nullptr) {
            front = rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void remove() {
        if (front == nullptr) return;
        if (front->next == nullptr)
        {
            front = nullptr;
            return;
        }
        queuenode* temp = front;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        queuenode* temp1 = temp->next;
        temp->next = nullptr;
        delete temp1;
    }

    bool isempty() {
        return front == nullptr;
    }

    void displaymonthsummary(string month) {
        int total = 0;
        queuenode* tempq = front;
        while (tempq != nullptr) {
            string entryMonth = tempq->listnode->date.substr(3, 2);
            if (entryMonth == month) {
                total += tempq->listnode->amount;
            }
            tempq = tempq->next;
        }
        cout << "Total expenses for month " << month << " is: $" << total << endl;
    }
};