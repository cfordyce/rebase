//----------------------------------------------------------- 
// Class name: 
//    Date 
// 
// Description: 
//    Class declaration for Homework #1. Create a class to 
//    hold and print out a date. Include a constructor that 
//    initializes the object with a month, day, and year. 
//    Store the month, day and year as separate private members. 
//    Include a public method that prints the date to cout in 
//    the format mm/dd/yyyy. 
// 
// Public: 
//    Print( ) 
//        Output the date to stdout.
//    Date( int aDay, int aMonth, int aYear ) 
//        Construct a date object with a day, month, and year.
// 
// Author: 
//    Bruce M. Reynolds 
//----------------------------------------------------------- 

class Date
{
private:
	const char separator;
	int day;
	int month;
	int year;
public:
	void Print() const;
	Date( int aDay, int aMonth, int aYear );
};

