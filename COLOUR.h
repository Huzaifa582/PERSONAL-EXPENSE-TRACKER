#pragma once
#include<iostream>
using namespace std;
void setColor(int color) {
    cout << "\033[" << color << "m";
}

// Function to reset console text color to default
void resetColor() {
    cout << "\033[0m";
}