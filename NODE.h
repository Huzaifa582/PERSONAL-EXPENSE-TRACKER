#pragma once
#include <iostream>
#include <string>
#include <ctime> 
#include"COLOUR.h"
using namespace std;
class node {
public:
    int amount;
    string date;
    string category;
    string description;
    node* next;
    node() {
        next = nullptr;
    }
};