#include <iostream>
#include <string>
#include"EXPENSE.h"
#include"MENU.h"
#include"COLOUR.h"
#include <ctime>  // for working with dates

using namespace std;

// Function to set console text color
//void setColor(int color) {
//    cout << "\033[" << color << "m";
//}
//
//// Function to reset console text color to default
//void resetColor() {
//    cout << "\033[0m";
//}

//class node {
//public:
//    int amount;
//    string date;
//    string category;
//    string description;
//    node* next;
//    node() {
//        next = nullptr;
//    }
//};
//
//class stacknode {
//public:
//    node* listnode;
//    stacknode* next;
//    stacknode() {
//        next = nullptr;
//        listnode = nullptr;
//    }
//};
//
//class stack {
//public:
//    stacknode* top;
//    node** head;
//    stack(node** headref) : top(nullptr), head(headref) {}
//
//    void push(node* Node) {
//        stacknode* newnode = new stacknode();
//        newnode->listnode = Node;
//        newnode->next = top;
//        top = newnode;
//    }
//
//    node* pop() {
//        if (isempty()) {
//            setColor(31); // Red color
//            cout << "No expense is added. Kindly add expense first." << endl;
//            resetColor();
//            return nullptr;
//        }
//        stacknode* temp = top;
//        top = top->next;
//        node* targetnode = temp->listnode;
//        delete temp;
//
//        if (*head == targetnode) {
//            *head = (*head)->next;
//        }
//        else {
//            node* prev = *head;
//            while (prev->next != targetnode) {
//                prev = prev->next;
//            }
//            prev->next = targetnode->next;
//        }
//        return targetnode;
//    }
//
//    bool isempty() {
//        return top == nullptr;
//    }
//};
//
//class queuenode {
//public:
//    node* listnode;
//    queuenode* next;
//    queuenode(node* ln) : listnode(ln), next(nullptr) {}
//};
//
//class queue {
//public:
//    queuenode* front;
//    queuenode* rear;
//    queue() : front(nullptr), rear(nullptr) {}
//
//    void enqueue(node* ln) {
//        queuenode* newnode = new queuenode(ln);
//        if (rear == nullptr) {
//            front = rear = newnode;
//        }
//        else {
//            rear->next = newnode;
//            rear = newnode;
//        }
//    }
//
//    void remove() {
//        if (front == nullptr) return;
//        queuenode* temp = front;
//        while (temp->next->next != nullptr) {
//            temp = temp->next;
//        }
//        queuenode* temp1 = temp->next;
//        temp->next = nullptr;
//        delete temp1;
//    }
//
//    bool isempty() {
//        return front == nullptr;
//    }
//
//    void displaymonthsummary(string month) {
//        int total = 0;
//        queuenode* tempq = front;
//        while (tempq != nullptr) {
//            string entryMonth = tempq->listnode->date.substr(3, 2);
//            if (entryMonth == month) {
//                total += tempq->listnode->amount;
//            }
//            tempq = tempq->next;
//        }
//        cout << "Total expenses for month " << month << " is: $" << total << endl;
//    }
//};
//
//class bstnode {
//public:
//    string category;
//    string date;
//    node* listnode;
//    bstnode* left;
//    bstnode* right;
//    bstnode(string cat, string dt, node* ln) : category(cat), date(dt), listnode(ln), left(nullptr), right(nullptr) {}
//};
//
//class bst {
//public:
//    bstnode* root;
//    bst() : root(nullptr) {}
//
//    void insert(string cat, string dt, node* ln) {
//        root = insert(root, cat, dt, ln);
//    }
//
//    bstnode* insert(bstnode* root, string cat, string dt, node* ln) {
//        if (root == nullptr) {
//            return new bstnode(cat, dt, ln);
//        }
//        if (cat < root->category || (cat == root->category && dt < root->date)) {
//            root->left = insert(root->left, cat, dt, ln);
//        }
//        else if (cat > root->category || (cat == root->category && dt > root->date)) {
//            root->right = insert(root->right, cat, dt, ln);
//        }
//        return root;
//    }
//
//    node* search(string cat, string dt) {
//        return search(root, cat, dt);
//    }
//
//    node* search(bstnode* root, string cat, string dt) {
//        if (root == nullptr) {
//            return nullptr;
//        }
//        if (cat == root->category && dt == root->date) {
//            return root->listnode;
//        }
//        if (cat < root->category || (cat == root->category && dt < root->date)) {
//            return search(root->left, cat, dt);
//        }
//        else {
//            return search(root->right, cat, dt);
//        }
//    }
//};
//
//class expensetracker {
//private:
//    node* head;
//    node* temp;
//    stack deletionstack;
//    queue monthlyexpenses;
//    bst categorytree;
//    int totalBudget;
//    int dailySpent;
//
//public:
//    expensetracker() : head(nullptr), deletionstack(&head), totalBudget(0), dailySpent(0) {}
//
//    void setTotalBudget(int budget) {
//        totalBudget = budget;
//        setColor(32); // Green color
//        cout << "Total Budget is set to $" << totalBudget << endl;
//        resetColor();
//    }
//
//    void addexpense(int amn, string dt, string cat, string desc) {
//        node* newnode = new node();
//        newnode->amount = amn;
//        newnode->category = cat;
//        newnode->date = dt;
//        newnode->description = desc;
//        if (head == nullptr) {
//            head = newnode;
//            temp = head;
//        }
//        else {
//            temp->next = newnode;
//            temp = newnode;
//        }
//        deletionstack.push(newnode);
//        monthlyexpenses.enqueue(newnode);
//        categorytree.insert(cat, dt, newnode);
//        dailySpent += amn; // Track the daily spending
//        totalBudget -= amn; // Subtract the expense from the total budget
//
//        double dailyBudget = calculateDailyBudget();
//
//        if (amn > dailyBudget) {
//            setColor(31); // Red color
//            cout << "System: You have spent more than your daily budget. Your daily budget is now reduced to $" << dailyBudget << endl;
//            resetColor();
//        }
//        else {
//            double remainingBudget = dailyBudget - dailySpent;
//            setColor(32); // Green color
//            cout << "System: You have not met your daily budget quota, therefore your daily budget is increased by $" << remainingBudget << endl;
//            resetColor();
//        }
//
//        setColor(32); // Green color
//        cout << "Added Expense: Amount: $" << amn << ", Date: " << dt << ", Category: " << cat << ", Description: " << desc << endl;
//        resetColor();
//    }
//
//    void undo() {
//        node* undoneExpense = deletionstack.pop();
//        if (undoneExpense) {
//            totalBudget += undoneExpense->amount;
//            dailySpent -= undoneExpense->amount;
//            setColor(33); // Yellow color
//            cout << "Undid Expense: Amount: $" << undoneExpense->amount << ", Date: " << undoneExpense->date
//                << ", Category: " << undoneExpense->category << ", Description: " << undoneExpense->description << endl;
//            resetColor();
//            delete undoneExpense;
//            monthlyexpenses.remove();
//        }
//    }
//
//    void display() {
//        int i = 1;
//        temp = head;
//        while (temp != nullptr) {
//            setColor(34); // Blue color
//            cout << i << ". Date: " << temp->date << "  Amount: $" << temp->amount
//                << "  Category: " << temp->category << "  Description: " << temp->description << endl;
//            temp = temp->next;
//            i++;
//        }
//        resetColor();
//    }
//
//    void monthlysummary(string month) {
//        monthlyexpenses.displaymonthsummary(month);
//    }
//
//    void searchbycategory(string cat, string dt) {
//        node* result = categorytree.search(cat, dt);
//        if (result == nullptr) {
//            setColor(31); // Red color
//            cout << "No expense found for category: " << cat << " on date: " << dt << endl;
//            resetColor();
//        }
//        else {
//            setColor(32); // Green color
//            cout << "Expense found: " << endl;
//            cout << "Date: " << result->date << "  Amount: $" << result->amount << "  Category: " << result->category << "  Description: " << result->description << endl;
//            resetColor();
//        }
//    }
//
//    void categoryAnalysis(string cat) {
//        int total = 0;
//        node* tempNode = head;
//        while (tempNode != nullptr) {
//            if (tempNode->category == cat) {
//                total += tempNode->amount;
//                setColor(34); // Blue color
//                cout << "Date: " << tempNode->date << "  Amount: $" << tempNode->amount
//                    << "  Description: " << tempNode->description << endl;
//                resetColor();
//            }
//            tempNode = tempNode->next;
//        }
//        setColor(32); // Green color
//        cout << "Total expenses for category " << cat << " is: $" << total << endl;
//        resetColor();
//    }
//
//    void viewExpensesByDate(string dt) {
//        int total = 0;
//        node* tempNode = head;
//        while (tempNode != nullptr) {
//            if (tempNode->date == dt) {
//                total += tempNode->amount;
//                setColor(34); // Blue color
//                cout << "Category: " << tempNode->category << "  Amount: $" << tempNode->amount
//                    << "  Description: " << tempNode->description << endl;
//                resetColor();
//            }
//            tempNode = tempNode->next;
//        }
//        setColor(32); // Green color
//        cout << "Total expenses for date " << dt << " is: $" << total << endl;
//        resetColor();
//    }
//
//    int getRemainingDaysInMonth() {
//        time_t now = time(0);
//        struct tm lt;
//        localtime_s(&lt, &now); // Use localtime_s for safer conversion
//        int currentDay = lt.tm_mday;
//        int currentMonth = lt.tm_mon + 1;
//        int currentYear = lt.tm_year + 1900;
//        int daysInMonth = 31; // default to 31 days
//
//        if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) {
//            daysInMonth = 30;
//        }
//        else if (currentMonth == 2) {
//            if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0)) {
//                daysInMonth = 29; // leap year
//            }
//            else {
//                daysInMonth = 28;
//            }
//        }
//
//        return daysInMonth - currentDay;
//    }
//
//    double calculateDailyBudget() {
//        int remainingDays = getRemainingDaysInMonth();
//        double dailyBudget;
//        if (remainingDays == 0) {
//            dailyBudget = static_cast<double>(totalBudget);
//        }
//        else {
//            dailyBudget = remainingDays > 0 ? static_cast<double>(totalBudget) / remainingDays : 0;
//        }
//        return dailyBudget;
//    }
//
//    void displayDailyBudget() {
//        setColor(36); // Cyan color
//        cout << "Daily Budget: $" << calculateDailyBudget() << endl;
//        resetColor();
//    }
//};
//
//void displayMenu() {
//    setColor(36); // Cyan color
//    cout << "\nExpense Tracker Menu:" << endl;
//    cout << "1. Set Total Budget" << endl;
//    cout << "2. Add Expense" << endl;
//    cout << "3. Undo Expense" << endl;
//    cout << "4. Display All Expenses" << endl;
//    cout << "5. Display Monthly Expense Summary" << endl;
//    cout << "6. Search Expense by Category and Date" << endl;
//    cout << "7. Display Daily Budget" << endl;
//    cout << "8. Category Analysis" << endl;
//    cout << "9. View Expenses by Date" << endl;
//    cout << "10. Exit" << endl;
//    cout << "Enter your choice: ";
//    resetColor();
//}
//
//void displayCurrentDate() {
//    time_t now = time(0);
//    struct tm lt;
//    localtime_s(&lt, &now); // Use localtime_s for safer conversion
//    setColor(36); // Cyan color
//    cout << "Current Date: ";
//    if (lt.tm_mday < 10) {
//        cout << "0";
//    }
//    cout << lt.tm_mday << "-";
//    if (lt.tm_mon + 1 < 10) {
//        cout << "0";
//    }
//    cout << (lt.tm_mon + 1) << "-" << (lt.tm_year + 1900) << endl;
//    resetColor();
//}

int main() {
    expensetracker tracker;
    int choice;
    int amount, totalBudget;
    string category, date, description, month;
    displayCurrentDate();
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To ignore the newline character after input

        switch (choice) {
        case 1:
            cout << "Enter Total Budget: ";
            cin >> totalBudget;
            cin.ignore(); // To ignore the newline character after input
            tracker.setTotalBudget(totalBudget);
            break;

        case 2:
            cout << "Enter Amount: ";
            cin >> amount;
            cin.ignore(); // To ignore the newline character after input

            cout << "Enter Category: ";
            getline(cin, category);

            cout << "Enter Date (dd-mm-yyyy): ";
            getline(cin, date);

            cout << "Enter Description: ";
            getline(cin, description);

            tracker.addexpense(amount, date, category, description);
            break;

        case 3:
            tracker.undo();
            break;

        case 4:
            tracker.display();
            break;

        case 5:
            cout << "Enter Month (mm): ";
            getline(cin, month);
            tracker.monthlysummary(month);
            break;

        case 6:
            cout << "Enter Category: ";
            getline(cin, category);
            cout << "Enter Date (dd-mm-yyyy): ";
            getline(cin, date);
            tracker.searchbycategory(category, date);
            break;

        case 7:
            tracker.displayDailyBudget();
            break;

        case 8:
            cout << "Enter Category: ";
            getline(cin, category);
            tracker.categoryAnalysis(category);
            break;

        case 9:
            cout << "Enter Date (dd-mm-yyyy): ";
            getline(cin, date);
            tracker.viewExpensesByDate(date);
            break;

        case 10:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            setColor(31); // Red color
            cout << "Invalid choice. Please try again." << endl;
            resetColor();
            break;
        }
    }
    return 0;
}