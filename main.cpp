/*
  main.cpp
  EmployeeSalaryRecords

  Created by Alex Dickinson on 14.02.16.
  Copyright © 2016 Alex Dickinson. All rights reserved.
  
  This program allows the user to input information about hours worked and hourly wages. It computes the total wages earned in a week.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::string;

//This function takes a string and makes sure it only contains digits.
string stringDigitValidator(string desiredChars, string inputMsg, string failMsg);

int main(int argc, const char * argv[]) {
    string id;
    string hours;
    float hoursMath;//Hours is converted to a float after being validated for calculating total wages.
    string wage;
    float wageMath;//Hourly wages are converted to a float after being validated for calculating total wages.
    float grossWage; //This is total wages earned in a week, based on hourly wages and hours worked.
    
    cout << "Alex Dickinson\n";
    cout << "EmployeeSalaryRecords.cpp\n";
    cout << "Feb. 14th, 2016\n";
    cout << "Long Beach City College\n\n";
    cout << "===============================================================\n";
    
    id = stringDigitValidator("0123456789", "Please enter your ID:\n", "This is not an ID. Please try again:\n");
    hours = stringDigitValidator("0123456789", "Please enter your hours worked this week:\n", "These are not hours. Please try again:\n");
    wage = stringDigitValidator(".0123456789", "Please enter your hourly wages:\n", "This is not a wage. Please try again:\n");
    
    hoursMath = stof(hours);
    wageMath = stof(wage);
    grossWage = wageMath * hoursMath;
    
    cout << "ID: " << id[1] << "\n";
    cout << "Hours this Week: " << hours << "\n";
    cout << "Gross Wages this Week: $" << grossWage << "\n";
    return 0;
}

/*
 This function takes a string and makes sure it only contains digits. DesiredChars is a string representing
 a set of desired characters, which is passed to find_first_not_of.
 Postcondition: Input is returned if all characters are digits. The user is repeatedly asked for input if any
 non-digit characters are found.
 */
string stringDigitValidator(string desiredChars, string inputMsg, string failMsg){
    string input;
    
    while (true) { //input validation loop
        cout << inputMsg;//Tells the user that they need to input a certain value.
        getline(cin, input);
        if (input.find_first_not_of(desiredChars) != string::npos) {
            cout << failMsg;//Tells the user that input has failed and that they must try again.
            continue;
        }
        else{
            return input;
        }
    }
}
