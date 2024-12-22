/*  Author: Connor Liu
    Program Description: A program that uses recursion to find a point on Pascal's Triangle using the row number and element number.
    Date Created: 8/2/2024
    Date Modified: 9/2/2024

    Replit Link: https://replit.com/join/axnabnwymm-connorliu2
*/

// =================== Preprocessor Commands =========================

#include <iostream>
#include <limits>
#include <string>
#include <termios.h>
#include <unistd.h>
using namespace std;

//getch code I copied from VLE.
char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
  return buf;
 }


// ===================  Function Prototypes  ==========================

void triangleMenu();
int pascalsTriangle(int, int);
int menu(string, string[], int);

// ===================  Function Definitions  ==========================
int main() 
{
int userInput = 0;
string promt = "Pascal's Triangle Calculator";
string promtOptions[] = {"Find specific point on pascals triangle", "Exit Program"};
int numberOfPromtOptions = 2;

do{
userInput = menu(promt, promtOptions, numberOfPromtOptions);
  
  if (userInput == 1)
  
    triangleMenu();

      }while(userInput != numberOfPromtOptions);
  
      (void)system ("clear");
      cout << "Closing program";
  
  return 0;
}

//========================================================================
void triangleMenu()
{
  int rowInput = 0;
  int elementInput = 0;
  bool userInputStatus = true;
  (void)system ("clear");

  do{
    userInputStatus = true; // resets the status in case of loop

    cout << "what row are you trying to find(starts from 1): ";
    cin >> rowInput;
    rowInput--;// too make the inferface more user friendly, starting with 1 instead of zero is more logical. However how the math, starting with 0 is the more optimal option.

    if(cin.fail()) 
      {
        cin.clear();
        userInputStatus = false; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Input. Please use an integer" << endl << "Press any key to continue" << endl;
        getch();
        (void)system("clear");
      }
  }while(userInputStatus == false);
  
  
    do{
      userInputStatus = true;// resets the status in case of loop

      cout << "what element are you trying to find(starts from 1): ";
      cin >> elementInput; 
      elementInput--;// too make the inferface more user friendly, starting with 1 instead of zero is more logical. However how the math, starting with 0 is the more optimal option.
      
      if(cin.fail())// in case the userInput is not valid(not an integer)
        {
          cout << "asasasasasas";
          cin.clear();
          userInputStatus = false;// sets the bool to false to meets the condition for the do while loop
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          cout << "Invalid Input. Please use an integer" << endl << "Press any key to continue" << endl;
          getch();
        }
    }while(userInputStatus == false);

  
  cout << "The value at point (" << rowInput + 1 << ", " << elementInput + 1<< ") is " << pascalsTriangle(elementInput,rowInput) << endl << "Press any key to continue" << endl; // have to add the plus 1 since we miniused one to make the operations more optimal. 

  getch();
  
  return;
}

//========================================================================
int menu(string question, string option[], int numberOfOptions)
{
  int userReponse = 0;
  do {
    (void)system ("clear");
    
    cout << question << endl;

    for (int i = 0; i < numberOfOptions; i++ )
    cout << i+1 <<"- " << option[i] << endl;
      cin >> userReponse;
    if(cin.fail())
    {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (userReponse < 1 or userReponse > numberOfOptions)
      {cout << "Invalid answer. Try again" << endl << "press any key to continue.";
                getch();
                (void)system ("clear");
      }
    } while (userReponse < 1 or userReponse > numberOfOptions);
  return userReponse; 
}

//========================================================================

int pascalsTriangle(int element, int row)
{
  if (element > row or row < 0 or element < 0) // since there is only row number of values in each row, if the element is greater then the row number it would be outside of the typical pascal's triangle and we know that the outside of is just filled with zeros. Same thing can be said for is the row or element is less then zero. The point will be outside of the typical pascal's triangle which is filled with zeros. Therefore if the element > row or row/element < 0, we can just return 0 as that is the value of the point on pascal's triangle.
    {
    return 0;
  }

  else if (element == 0 or element == row or row == 0 or row == 1) // to further optimize this code, if the element is on the border(either element is 0 or element is the row value), it has to bee one. This is because we know that the borders start at one, and is the sum of the previous border(one) and 0. If the row is 0 or 1, the value is alway be one with a notable exception. If the row is 0 or 1, and the element is greater or smaller than the row, the value will be 0. However this is dealt with in our previous if statement. 
    {
    return 1;
  }

  else if (element == row-1 or element==1 ) // if the value is beside the border(either at element 1 or element (row-1)) we know that it is just the row value. This because the sum of the value beside the border only grows by the value of the border(1) and starts at a value of one at row 1, it will increase in tandem with the row value. The exception is of the row value is negative however that is dealt with in the first if statement.
  {
    return row;
  }
    
  else
 {
   
   return pascalsTriangle(element-1, row-1)+pascalsTriangle(element, row-1); // Recursively find the value at a certain point on pascal's triangle. This is the formula given to us in class. 
 }

}

