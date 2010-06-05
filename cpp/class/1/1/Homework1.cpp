//----------------------------------------------------------- 
// Module name: 
//     Homework1.cpp 
// 
// Description: 
//    Implementation file for Homework #1.
//    void Func1_1();                               // display several types
//    void Func1_2();                               // display Pi
//    void Func1_3();                               // display number in requested base
//    void Func1_4();                               // pass-by-reference dollar amount
//    void Func1_5();                               // date, constructor, new/delete
//    void Func1_6( int argc, char **argv );        // count lines in a file
//    void CheckAmountGet( float &fAmount );
// 
// Author: 
//    Bruce M. Reynolds 
//----------------------------------------------------------- 
#include <iostream>
#include <iomanip>
using namespace std;

#include "Homework1.h"
#include "Date.h"

//----------------------------------------------------------- 
// Func1_1() 
// 
// Purpose: 
//    Using the cout object, write a program that displays a 
//    single character, a string, and an integer.
// 
// Parameters: 
//    None.
// 
// Returns: 
//    None.
// 
// Method: 
//    Use the cout object.
//    
//----------------------------------------------------------- 
void Func1_1()
{
	char c = 'A';
	char *str = "Hello, World";
	int n = 125;
	double d = 3.14159;
	
	cout << c << endl;
	cout << str << endl;
	cout << n << endl;
	cout << d << endl;
	cout << endl;
}

//----------------------------------------------------------- 
// Func1_2()
// 
// Purpose: 
//    Define a constant double variable dPI = 3.14159265359. 
//    Using the iomanip facilities of the cout object, display 
//    the value of dPI in the following ways: "3.1416", 
//    "0003.14159", "3.14159e+001", and "3.1415926".
// 
// Parameters: 
//    None.
// 
// Returns: 
//    None.
// 
// Method: 
//    Use the cout object and iomanips.
//    
//----------------------------------------------------------- 
// "3.1416", "0003.14159", "3.14159e+001", and "3.1415926".
void Func1_2()
{
	double dPi = 3.14159265359;
	cout << setprecision(5) << dPi << endl;
	cout << setprecision(6) << setfill('0') << setw(9) << dPi << endl;
	cout << setprecision(5) << scientific << dPi << endl;
	cout << setprecision(7) << fixed << dPi << endl;
	cout << endl;
}

//----------------------------------------------------------- 
// Func1_3()
// 
// Purpose: 
//    Write a program that prompts the user for a base 10 
//    integer and a base, then displays the number in the 
//    requested base. Assume the set of bases is "dec", "oct", 
//    and "hex". The program will continue to accept input from 
//    the user until she signals from the keyboard that she 
//    is done. 
// 
// Parameters: 
//    None.
// 
// Returns: 
//    None.
// 
// Method: 
//    Read input from stdin until the user signals finished.
//    Read a number into a int, and a base into a char*.
//    Identify the base input, and output the number in the 
//    proper base using iomanips.
//    
//----------------------------------------------------------- 
void Func1_3()
{
	while ( !cin.eof() )
	{
		int n;
		char str[10];

		cout << "Input a number (-1 to quit) and a base [oct|dec|hex]: ";

		cin >> n;
		if ( -1 == n ) 
		{
			break;
		}
		cin >> str;

		cout << "                                              Result: ";
		if ( strcmp( "oct", str ) == 0 )
		{
			cout << oct << n << endl;
		}
		else if ( strcmp( "dec", str ) == 0 )
		{
			cout << dec << n << endl;
		}
		else if ( strcmp ( "hex", str) == 0 )
		{
			cout << hex << n << endl;
		}
		else 
		{
			cout << "base unknown: " << str << endl;
		}
	}
	cout << endl;
}

//----------------------------------------------------------- 
// Func1_4()
// 
// Purpose: 
//    Using the pass by reference operator, write a program that 
//    tests the pass-by-reference operator in a function
//    argument list.
// 
// Parameters: 
//    None.
// 
// Returns: 
//    None.
// 
// Method: 
//    Call the function, and output the value the function returns.
//    
//----------------------------------------------------------- 
void Func1_4()
{
	float fAmount;
	CheckAmountGet( fAmount );
	cout << "The check amount entered was: " << fixed << fAmount << endl;
	cout << endl;
}

//----------------------------------------------------------- 
// CheckAmountGet( float &fAmount )
// 
// Purpose: 
//    Using the pass by reference operator, write a program that 
//    includes a function to prompt a user to enter a dollar 
//    amount representing the amount of a bank check, and returns 
//    the information as a parameter of the function.
// 
// Parameters: 
//    [out] float &fAmount       the check amount entered by the user
// 
// Returns: 
//    None.
// 
// Method: 
//    
//----------------------------------------------------------- 
void CheckAmountGet( float &fAmount )
{
	cout << "Enter the dollar amount of the check: ";
	cin >> fAmount;
}

//----------------------------------------------------------- 
// Func1_5()
// 
// Purpose: 
//    Create a program to read in several dates. For each date, 
//    use new to create a date object on the heap, print the 
//    object's date to cout, and delete the object. You do not 
//    have to check if the dates are valid.
// 
// Parameters: 
//    None.
// 
// Returns: 
//    None.
// 
// Method: 
//    Get the date from the user. Instantiate a new Date object
//    on the heap, initialized with the date entered. Print
//    the date, and delete the instantiated object.
//    
//----------------------------------------------------------- 
void Func1_5()
{
	cout << "Enter dates (-1 to quit):" << endl;
	while ( 1 )
	{
		int day, month, year;
		char slash;
		
		cin >> day;
		if ( day == -1 )
		{
			break;
		}
		cin >> slash >> month;
		cin >> slash >> year;

		Date *pDate = new Date( day, month, year );
		pDate->Print();
		delete pDate;
	}
	cout << endl;
}

