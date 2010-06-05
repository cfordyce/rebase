/*----------------------------------------
  Charles Fordyce
  
  Assingment 1-3
  ----------------------------------------*/

#include <csignal>
#include <iostream>
#include <iomanip>
using namespace std;

void sigHandler( int );

void sigHandler( int sig )
{
  cout << endl << "Thanks for playing." << endl;
  exit(0);
}

int
main()
{
/////////////////////////////////////////////////////////////////////////////
// bmr
// -- I tend to avoid operating-system specific solutions when possible, since
// it limits portability. You could also create this solution just using C++,
// and if you ever decide you wanted to run it on a system without signals,
// or with slightly different support for signals, you would be able to. On
// my PC, I can compile this, but it crashes when I hit control-C.
  signal( SIGHUP, &sigHandler );
  signal( SIGINT, &sigHandler );
  signal( SIGQUIT, &sigHandler );
  signal( SIGTERM, &sigHandler );

  int num, base;
  
  do
    {
      cout << endl << "Fun with integer bases.  Hit Ctrl-c when done." << endl;
      cout << "Enter an integer: ";
      cin >> num;
      cout << "Enter a base [8,10,16]: ";
      cin >> base;

      switch (base)
	{
      	case 8:
	  cout << "The number in Octal is: " << setbase(8) << num << endl;
	  break;
	  
	case 10:
	  cout << "The number in Decimal is: " << setbase(10) << num << endl;
	  break;
	  
	case 16:
	  cout << "The number in Hexadecimal is: " << setbase(16) << num << endl;
	  break;
	  
	default:
	  cout << "Invalid choice: " << base << endl;
	  break;
	}
/////////////////////////////////////////////////////////////////////////////
// bmr
// -- I do not like control structures like this. Some companies that I have
// worked for have coding standards that would prohibit this, since it is 
// impossible to demonstrate at compile-time that this loop must terminate.

    } while ( 1 );

  return 0;
}
