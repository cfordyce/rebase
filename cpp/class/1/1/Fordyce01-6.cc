/*----------------------------------------
  Charles Fordyce
  
  Assingment 1-6
  ----------------------------------------*/

#include <fstream>
#include <iostream>
#include <string>


int
main()
{
  ifstream inFile( "/home/chas/class/cpp1/1/test01-6.txt", ios::in );
  string line, cmt = "//";
  int x, count = 0;
  
  if (!inFile) 
    cout << "Could not open file." << endl;
  
  while ( getline( inFile, line ))
    {
      for ( x = 0; isspace( line[x] ); x++ );
      
      if ( x < (int)line.length()-1 && cmt != line.substr( x, 2 ))
	count++;
    }
  
  cout << "Found " << count << " lines of code." << endl;
  
  return 0;
}
