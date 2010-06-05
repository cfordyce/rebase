/*----------------------------------------
  Charles Fordyce

  Assingment 1-4
  ----------------------------------------*/

#include <iostream>
#include <iomanip>

void dol_amount( float& );

// Pass by reference function
void dol_amount( float& dols )
{
  cout << "Received your bank note for $";
  cout << setiosflags(ios::fixed) << setprecision(2) << dols << "." << endl;
  
  dols += 1000.00;
}


int main()
{
  float amount = 0;
  
  cout << endl << "Enter a dollar amount (exclude the $): ";
  cin >> amount;

  dol_amount( amount );

  cout << endl << "If I add $1000.00 to your note, it will be worth ";
  cout << setiosflags(ios::fixed) << setprecision(2) << amount << "." << endl;
  cout << "But that wouldn't be fair to our other cusomers now would it!" << endl;

  amount -= 1000.00;

  cout << "The amount is $";
  cout << setiosflags(ios::fixed) << setprecision(2) << amount << endl;
  
  return 0;
}
