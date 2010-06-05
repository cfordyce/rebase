/*----------------------------------------
  Charles Fordyce

  Assingment 1-2
  ----------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;
int
main()
{
/////////////////////////////////////////////////////////////////////////////
// bmr
// -- You need a double here to hold this much precision. C and CC+ floats
// actually have very little precision. 
  const float dPI = 3.14159265359;
  
  // print "3.1416"
  cout << setprecision(5) << dPI << endl;

  // print "0003.14159"
  cout << setw(10) << setfill('0') << setprecision(6) << dPI << endl;
  
  // print "3.14159e+000"
  cout << setiosflags(ios::scientific) << dPI << endl;
  
/////////////////////////////////////////////////////////////////////////////
// bmr
// -- I don't know, but if you really wanted truncation, you could handle it
// on the string, I suppose.  Rounding is probably more correct.

  // How do you stop implicit rounding of numeric literals??
  // print "3.1415926"  
  cout << setiosflags(ios::fixed) << setprecision(8) << dPI << endl;
  
  return 0;
}
