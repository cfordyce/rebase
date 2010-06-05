#include <string>
#include "Cgi.h"
#include "Html.h"
#include "UserData.h"
#include <iostream>
#include <strstream>
#include <iomanip>

using namespace std;

int main()
{
  Html h("blah");
  cout << "Content-type: text/html\n\n";
  h.header();
  h.hn("header",1);
  h.hn();
  h.footer();
  

  
  return 0;
}

