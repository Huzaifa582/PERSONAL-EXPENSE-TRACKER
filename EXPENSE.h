#pragma once
#include <iostream>
#include <string>
#include"NODE.h"
#include"STACK.h"
#include"QUEUE.h"
#include"BST.h"
#include"COLOUR.h"
#include <ctime> 
using namespace std;
class expensetracker {
private:
    node* head;
    node* temp;
    stack deletionstack;
    queue monthlyexpenses;
    bst categorytree;
    int totalBudget;
    int dailySpent;

public:
    expensetracker() : head(nullptr), deletionstack(&head), totalBudget(0), dailySpent(0) {}

    void setTotalBudget(int budget) {
        totalBudget = budget;
        setColor(32); // Green color
        cout << "Total Budget is set to $" << totalBudget << endl;
        resetColor();
    }

    void addexpense(int amn, string dt, string cat, string desc) {
        node* newnode = new node();
        newnode->amount = amn;
        newnode->category = cat;
        newnode->date = dt;
        newnode->description = desc;
        if (head == nullptr) {
            head = newnode;
            temp = head;
        }
        else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        deletionstack.push(newnode);
        monthlyexpenses.enqueue(newnode);
        categorytree.insert(cat, dt, newnode);
        dailySpent += amn; // Track the daily spending
        totalBudget -= amn; // Subtract the expense from the total budget

        double dailyBudget = calculateDailyBudget();

        if (amn > dailyBudget) {
            setColor(31); // Red color
            cout << "System: You have spent more than your daily budget. Your daily budget is now reduced to $" << dailyBudget << endl;
            resetColor();
        }
        else {
            double remainingBudget = dailyBudget - dailySpent;
            setColor(32); // Green color
            cout << "System: You have not met your daily budget quota, therefore your daily budget is increased by $" << remainingBudget << endl;
            resetColor();
        }

        setColor(32); // Green color
        cout << "Added Expense: Amount: $" << amn << ", Date: " << dt << ", Category: " << cat << ", Description: " << desc << endl;
        resetColor();
    }

    void undo() {
        node* undoneExpense = deletionstack.pop();
        if (undoneExpense) {
            totalBudget += undoneExpense->amount;
            dailySpent -= undoneExpense->amount;
            setColor(33); // Yellow color
            cout << "Undid Expense: Amount: $" << undoneExpense->amount << ", Date: " << undoneExpense->date
                << ", Category: " << undoneExpense->category << ", Description: " << undoneExpense->description << endl;
            resetColor();
            delete undoneExpense;
            monthlyexpenses.remove();
        }
    }

    void display() {
        int i = 1;
        temp = head;
        while (temp != nullptr) {
            setColor(34); // Blue color
            cout << i << ". Date: " << temp->date << "  Amount: $" << temp->amount
                << "  Category: " << temp->category << "  Description: " << temp->description << endl;
            temp = temp->next;
            i++;
        }
        resetColor();
    }

    void monthlysummary(string month) {
        monthlyexpenses.displaymonthsummary(month);
    }

    void searchbycategory(string cat, string dt) {
        node* result = categorytree.search(cat, dt);
        if (result == nullptr) {
            setColor(31); // Red color
            cout << "No expense found for category: " << cat << " on date: " << dt << endl;
            resetColor();
        }
        else {
            setColor(32); // Green color
            cout << "Expense found: " << endl;
            cout << "Date: " << result->date << "  Amount: $" << result->amount << "  Category: " << result->category << "  Description: " << result->description << endl;
            resetColor();
        }
    }

    void categoryAnalysis(string cat) {
        int total = 0;
        node* tempNode = head;
        while (tempNode != nullptr) {
            if (tempNode->category == cat) {
                total += tempNode->amount;
                setColor(34); // Blue color
                cout << "Date: " << tempNode->date << "  Amount: $" << tempNode->amount
                    << "  Description: " << tempNode->description << endl;
                resetColor();
            }
            tempNode = tempNode->next;
        }
        setColor(32); // Green color
        cout << "Total expenses for category " << cat << " is: $" << total << endl;
        resetColor();
    }

    void viewExpensesByDate(string dt) {
        int total = 0;
        node* tempNode = head;
        while (tempNode != nullptr) {
            if (tempNode->date == dt) {
                total += tempNode->amount;
                setColor(34); // Blue color
                cout << "Category: " << tempNode->category << "  Amount: $" << tempNode->amount
                    << "  Description: " << tempNode->description << endl;
                resetColor();
            }
            tempNode = tempNode->next;
        }
        setColor(32); // Green color
        cout << "Total expenses for date " << dt << " is: $" << total << endl;
        resetColor();
    }

    int getRemainingDaysInMonth() {
        time_t now = time(0);
        struct tm lt;
        localtime_s(&lt, &now); // Use localtime_s for safer conversion
        int currentDay = lt.tm_mday;
        int currentMonth = lt.tm_mon + 1;
        int currentYear = lt.tm_year + 1900;
        int daysInMonth = 31; // default to 31 days

        if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) {
            daysInMonth = 30;
        }
        else if (currentMonth == 2) {
            if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0)) {
                daysInMonth = 29; // leap year
            }
            else {
                daysInMonth = 28;
            }
        }

        return daysInMonth - currentDay;
    }

    double calculateDailyBudget() {
        int remainingDays = getRemainingDaysInMonth();
        double dailyBudget;
        if (remainingDays == 0) {
            dailyBudget = static_cast<double>(totalBudget);
        }
        else {
            dailyBudget = remainingDays > 0 ? static_cast<double>(totalBudget) / remainingDays : 0;
        }
        return dailyBudget;
    }

    void displayDailyBudget() {
        setColor(36); // Cyan color
        cout << "Daily Budget: $" << calculateDailyBudget() << endl;
        resetColor();
    }
};