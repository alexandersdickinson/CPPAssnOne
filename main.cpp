/*
  main.cpp
  EmployeeSalaryRecords

  Created by Alex Dickinson on 14.02.16.
  Copyright © 2016 Alex Dickinson. All rights reserved.
  
  This program allows the user to input information about hours worked and hourly wages. It computes the total wages earned in a week.
*/

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::string;

//This function takes a string and makes sure it contains only desired characters.
string stringValidator(string desiredChars, string inputMsg);

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
    
    id = stringValidator("0123456789", "ID");
    hours = stringValidator("0123456789", "total hours worked this week");
    wage = stringValidator(".0123456789", "hourly wages");
    
    hoursMath = stof(hours);
    wageMath = stof(wage);
    grossWage = wageMath * hoursMath;
    
    cout << "ID: " << id << std::endl;
    cout << "Hours this Week: " << hours << "\n";
    cout << "Hourly Wage: $" << wage << std::endl;
    cout << "Gross Wages this Week: $" << std::setprecision(2) << std::fixed << grossWage << std::endl;
    return 0;
}

/*
 This function takes a string and makes sure it only contains characters in desiredChars. InputMsg is what
 the user is being asked to input (ex. user ID).
 Postcondition: Input is returned if all characters are digits. The user is repeatedly asked for input if any
 non-digit characters are found.
 */
string stringValidator(string desiredChars, string inputMsg){
    string input;
    
    while (true) { //input validation loop
        //Tells the user that they need to input a certain value.
        cout << "Please enter your " << inputMsg << ":\n";
        getline(cin >> std::ws, input);
        if (input.find_first_not_of(desiredChars) != string::npos) {
            //Tells the user that input has failed and that they must try again.
            cout << "The entered " << inputMsg << " is invalid\n";
            continue;
        }
        else{
            return input;
        }
    }
}
