/*--------------------------
  Charles Fordyce

  C++ Intro Project
  
  Main Program Source
  --------------------------*/

#include "Cgi.h"
#include "Html.h"
#include "UserData.h"

#include <string>
#include <iostream>


//
// Function Protos

// HTML body for "Add A User" form page 
ostream& add_user_form(ostream&, Cgi&);

// HTML bodt for "User Added" message page
ostream& display_user_form(ostream&, UserData&);

int main()
{
  Cgi* c = new Cgi();
  
  //
  // Present an "Add A User" form
  if ( c->param("action") == "add")
    {
      Html h("Add A New User");
      cout << c->httpHeader();
      h.header();
      h.hn("Add A New User",4);
      add_user_form(cout, *c);
      h.footer();
    }
  
  //
  // Print the success login page
  else if ( c->param("action") == "display" )
    {
      //
      // Populate a user data object
      UserData user(c->param("name"),
		 c->param("age"),
		 c->param("job") );

      //
      // Now output the user object via the web
      // 
      Html h("New User Added");
      cout << c->httpHeader();
      h.header();
      h.hn("New User Added",2);
      display_user_form(cout, user);
      h.footer();
    }

  delete c;
  
  return 0;
}

ostream& display_user_form(ostream& os, UserData& user)
{
  os << "<b>You added info for this user:</b>" << endl
     << "<br><br><font color=red><B>Name:&nbsp&nbsp;</B></font><B>" << endl
     << "<font color=blue>" << user.userName() << "</font></b><br>" << endl
     << "<br><br><font color=red><B>Age:&nbsp&nbsp;</B></font><B>" << endl
     << "<font color=blue>" << user.userAge() << "</font></b><br>" << endl
     << "<br><br><font color=red><B>Job:&nbsp&nbsp;</B></font><B>" << endl
     << "<font color=blue>" << user.userJob() << "</font></b><br>" << endl
     << endl;
  return os;
}

ostream& add_user_form(ostream& os, Cgi& c)
{
  os << "<table width=\"%5\" align=left >" << endl 
     << "<form method=post action=\"/home/chas/class/cpp1/project/Project.cgi\">" << endl 
     << "<input type=hidden name=action value=display>" << endl
     << "<tr><td width=\"name%25\"><b>Enter your name:</b><br>" << endl
     << "<input textfield width=25 max=100 name=\"name\"></tr>" << endl
     << "<tr><td width=\"%25\"><b>Enter your age:</b><br>" << endl
     << "<input textfield width=25 max=100 name=\"age\"></tr>" << endl
     << "<tr><td width=\"%25\"><b>Enter your occupation:</b><br>" << endl
     << "<input textfield width=25 max=100 name=\"job\"></tr>" << endl
     << "<tr><td width=\"%25\">" << endl
     << "<input type=\"submit\" label=\"Submit\">&nbsp;&nbsp;" << endl
     << "<input type=\"reset\" label=\"Clear\">" << endl
     << "</td></tr></form></table>" << endl;
  return os;
}
