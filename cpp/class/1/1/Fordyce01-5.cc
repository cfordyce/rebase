/*----------------------------------------
  Charles Fordyce
  
  Assingment 1-5
  ----------------------------------------*/

#include <iostream>
#include <iomanip>

class Date {
  
public:
  Date( int mm=0, int dd=0, int yy=0 );
  ~Date();
  void print();
  
private:
  int m,d,y;
  
}; // Date

Date::Date( int mm=0, int dd=0, int yy=0 )
{
  m = mm;
  d = dd;
  y = yy;
}

void Date::print()
{
  cout << m << "/" << d << "/" << y << endl;
  return;
}

Date::~Date()
{
}


int
main()
{
  int mm[] = {1,5,9,6};
  int dd[] = {12,15,2,12};
  int yy[] = {1970,1971,1998,2001};

  for (int inx = 0; inx < ( sizeof(mm) / sizeof(int) ); ++inx )
    {
      Date* d = new Date(mm[inx],dd[inx],yy[inx]);
      
      d->print();
      
      delete d;
    }
  return 0;
}
