This program calculates the value of a specific point in Pascal's Triangle using recursion. It provides a user-friendly menu interface to input row and element numbers, and it includes error handling for invalid inputs.

Pascal's Triangle Calculator
Overview
This program calculates the value of a specific point in Pascal's Triangle using recursion. It provides a user-friendly menu interface to input row and element numbers, and it includes error handling for invalid inputs.

Author
Name: Connor Liu
Date Created: August 2, 2024
Date Modified: September 2, 2024
Replit Link: Pascal's Triangle Calculator
Features
Recursive Calculation: Computes the value at a specific point in Pascal's Triangle using a recursive formula.
Menu Interface: Provides a clear and intuitive menu for user interaction.
Error Handling: Ensures inputs are valid and prompts users for corrections if necessary.
Row and Element Adjustments: Allows users to input row and element numbers starting from 1 for convenience.
Program Structure
Main Components:
Main Function:

Displays a menu with two options:
Calculate a point in Pascal's Triangle.
Exit the program.
Handles user input to navigate between options.
Triangle Menu:

Asks the user to input a row and element number.
Validates inputs to ensure they are integers.
Displays the result of the calculation.
Recursive Function (pascalsTriangle):

Base cases handle boundary conditions and optimization:
Returns 0 for invalid inputs.
Returns 1 for points on the triangle's border.
Uses the recursive formula to compute interior values.
Menu Function:

Displays a dynamic menu based on given options.
Validates user input and handles invalid selections.
Utility Function (getch):

Captures a single key press from the user without requiring them to press Enter.
How to Use
Run the Program: Execute the program in a C++ environment (e.g., Replit or a local compiler).
Select an Option:
Choose 1 to find a point in Pascal's Triangle.
Choose 2 to exit the program.
Provide Input:
Input the row and element numbers starting from 1.
View the calculated result for the specified point.
Repeat or Exit:
Return to the main menu or exit the program.
Example Usage
Input:
Row: 5
Element: 3
Output:
The value at point (5, 3) is 6
