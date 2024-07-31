#pragma once
#include <iostream>
#include <string>
#include <ctime> 
#include"NODE.h"
#include"COLOUR.h"
using namespace std;
class stacknode {
public:
    node* listnode;
    stacknode* next;
    stacknode() {
        next = nullptr;
        listnode = nullptr;
    }
};

class stack {
public:
    stacknode* top;
    node** head;
    stack(node** headref) : top(nullptr), head(headref) {}

    void push(node* Node) {
        stacknode* newnode = new stacknode();
        newnode->listnode = Node;
        newnode->next = top;
        top = newnode;
    }

    node* pop() {
        if (isempty()) {
            setColor(31); // Red color
            cout << "No expense is added. Kindly add expense first." << endl;
            resetColor();
            return nullptr;
        }
        stacknode* temp = top;
        top = top->next;
        node* targetnode = temp->listnode;
        delete temp;

        if (*head == targetnode) {
            *head = (*head)->next;
        }
        else {
            node* prev = *head;
            while (prev->next != targetnode) {
                prev = prev->next;
            }
            prev->next = targetnode->next;
        }
        return targetnode;
    }

    bool isempty() {
        return top == nullptr;
    }
};