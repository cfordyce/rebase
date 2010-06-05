//----------------------------------------------------------- 
// Module name: 
//     Date.cpp 
// 
// Description: 
//    Class implementation for Homework #1. Create a class to 
//    hold and print out a date. Include a constructor that 
//    initializes the object with a month, day, and year. 
//    Store the month, day and year as separate private members. 
//    Include a public method that prints the date to cout in 
//    the format mm/dd/yyyy. 
// 
// Author: 
//    Bruce M. Reynolds 
//----------------------------------------------------------- 
#include <iostream>
#include <iomanip>
using namespace std;

#include "Date.h"

//----------------------------------------------------------- 
// Date::Date( int aDay, int aMonth, int aYear )
// 
// Purpose: 
//    Construct a date object with a day, month, and year.
//                            
// Parameters: 
//    [in] int aDay           day
//    [in] int aMonth         month
//    [in] int aYear          year 
//
// Returns: 
//    None
// 
// Method: 
//    Set class members.
//    
//----------------------------------------------------------- 
Date::Date( int aDay, int aMonth, int aYear ) : separator ( '/' )
{
	day = aDay;
	month = aMonth;
	year = aYear;
}
	
//----------------------------------------------------------- 
// Date::Print()
// 
// Purpose: 
//    Output the date to stdout.
//                            
// Parameters: 
//    None.
//
// Returns: 
//    None
// 
// Method: 
//    Formats and prints the date to cout in the format mm/dd/yyyy.
//    
//----------------------------------------------------------- 
void Date::Print() const
{
	cout << "Date is: ";
	cout.fill('0');
	cout << setw(2) << day << separator << setw(2) << month;
	cout << separator << setw(4) << year << endl;
}

