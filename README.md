Personal Expense Tracker
Introduction
The Personal Expense Tracker is a C++ application designed to help users manage and track their daily expenses. It offers features such as setting a total budget, adding expenses, undoing expenses, viewing expenses by category and date, and providing daily budget calculations. The application utilizes data structures like stacks, queues, and binary search trees to efficiently manage and organize expense data.

Features
Set Total Budget: Allows the user to set an overall budget for managing expenses.
Add Expense: Users can add new expenses with details such as amount, date, category, and description.
Undo Expense: The last added expense can be undone and removed from the records.
Display All Expenses: Lists all expenses added by the user.
Display Monthly Expense Summary: Shows the total expenses for a specified month.
Search Expense by Category and Date: Finds expenses based on category and date.
Display Daily Budget: Calculates and displays the daily budget based on the remaining budget and days in the month.
Category Analysis: Provides a summary of expenses for a specified category.
View Expenses by Date: Lists all expenses for a specified date.
Notifications: Alerts when the user reaches half of the set budget or when only $100 remains. Provides appreciation messages for spending less than the set budget.
Data Structures Used
Stack: Used to manage undo operations for expenses.
Queue: Used to track monthly expenses.
Binary Search Tree (BST): Used to organize and search expenses by category and date.
Flow of the Application
Start the Application:

Displays the current date and the main menu.
Setting Total Budget:

User sets the total budget which is tracked throughout the month.
Adding Expenses:

Users can add up to 5 expenses per day.
Each expense includes the amount, date, category, and description.
Updates the total budget and checks if the user has reached half of the budget or if only $100 remains.
If the user spends less than the daily budget, an appreciation message is displayed.
Undoing Expenses:

Allows the user to undo the last added expense.
The total budget is updated accordingly.
Displaying All Expenses:

Lists all recorded expenses.
Monthly Expense Summary:

Provides a summary of expenses for a specified month.
Searching by Category and Date:

Finds and displays an expense based on the category and date.
Displaying Daily Budget:

Calculates and displays the remaining daily budget based on the remaining days of the month and the total budget.
Category Analysis:

Summarizes the total expenses for a specified category.
Viewing Expenses by Date:

Lists all expenses for a specified date.
Exiting the Application:

The user can choose to exit the application from the main menu.
Usage
Compile and run the application.
Follow the prompts to navigate through the menu options and manage your expenses.
Enter the required information for each option as prompted.
Conclusion
This Personal Expense Tracker provides an efficient way to manage daily expenses, track budget usage, and analyze spending patterns. By leveraging various data structures, the application ensures quick and easy access to expense data, making budgeting simpler and more effective.
