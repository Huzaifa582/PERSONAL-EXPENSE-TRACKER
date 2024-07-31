#pragma once
#include <iostream>
#include <string>
#include"COLOUR.h"
using namespace std;
void displayMenu() {
    setColor(36); // Cyan color
    cout << "\nExpense Tracker Menu:" << endl;
    cout << "1. Set Total Budget" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Undo Expense" << endl;
    cout << "4. Display All Expenses" << endl;
    cout << "5. Display Monthly Expense Summary" << endl;
    cout << "6. Search Expense by Category and Date" << endl;
    cout << "7. Display Daily Budget" << endl;
    cout << "8. Category Analysis" << endl;
    cout << "9. View Expenses by Date" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";
    resetColor();
}

void displayCurrentDate() {
    time_t now = time(0);
    struct tm lt;
    localtime_s(&lt, &now); // Use localtime_s for safer conversion
    setColor(36); // Cyan color
    cout << "Current Date: ";
    if (lt.tm_mday < 10) {
        cout << "0";
    }
    cout << lt.tm_mday << "-";
    if (lt.tm_mon + 1 < 10) {
        cout << "0";
    }
    cout << (lt.tm_mon + 1) << "-" << (lt.tm_year + 1900) << endl;
    resetColor();
}