/*----------------------------------------
  Charles Fordyce
  
  Assingment 1-3
  ----------------------------------------*/

#include <csignal>
#include <iostream>
#include <iomanip>

void sigHandler( int );

void sigHandler( int sig )
{
  cout << endl << "Thanks for playing." << endl;
  exit(0);
}

int
main()
{
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
    } while ( 1 );

  return 0;
}
