#include "CGI.h"

int main() {
  CGI cgi ;		// constructor does nothing

/* Let's start by defining a small form ...  */

  cgi.define(4,		// a FORM with four elements
    "foo:input:Hello World:12:12" ,
			// an input with default value "Hello World",
			// size and maxlength 12
    "bar:password:secret" ,
			// an input of type PASSWORD with default value
			// "secret", and no size parameters set.
    "baz:select:option2" ,
			// a popup menu with default value "option2"
    "OK:submit:Hit Me!"	// a submit button labelled "Hit Me"
  ) ;

/* We can implicitly add elements (we didn't need to call define() at all).
*/
  String wombat = "wombat" ;
  cgi["animal"] = new form_input(wombat) ;

/* The popup menu isn't fully defined by the above.   The following
   lines will turn it into a <SELECT> menu with three options,
   of which the second is currently selected.
*/
   cgi["baz"]["option1"] = "First Choice" ;
   cgi["baz"]["option2"] = "Second Choice" ;
   cgi["baz"]["option3"] = "Third Choice" ;

/* ===============================================================
   Everything up to this point uses class FORM (a parent of CGI).
   In other words, nothing up to here depends on actual form input.

   Now we depart from this, and read the data (if any) that has
   actually been supplied in an HTTP request.   The following will
   parse all input, and set all name/value pairs.  Any names that
   haven't been defined above take the default type form_input.
*/
  cgi.form() ;		// does the same as the CGI.pm constructor.
			// Will overwrite the above values for
			// foo,bar,baz,OK,animal if they're in the input,


/* OK, time to print something */

  cout	<< "Content-type: text/html\n\n"
	<< "<head><title>CGI++ mini-demonstration program</title></head>"
	<< "<body><h1>CGI++ Demonstrator Sample Page</h1><hr>" ;

/* some gratuitous messing about with environment variables
   just to demonstrate how to work with them.
*/
  if ( cgi.env("HTTP_FROM") != NULL_String)
    cout << "<p>Either you're a robot, or you're using a really ancient or "
	 << "unusual browser!</p>" ;

  if (cgi.accept_language("en"))
    cout << "<p>It's just as well you speak English, since I'm not "
	<< "programmed to write anything else!</p>" ;
  else
    cout << "<p>I'm sorry your browser thinks you don't speak English, "
	<< "but I'm afraid it's all I'm programmed to write in!</p>" ;

  if ( cgi.cookie("id") == NULL_String )
     cout << "<p>You are not logged into <a href=\"../\">Web&#222;ing</a>. "
	  << "Without logging in, you have read-only access.</p>";

  String document = cgi.cookie("ref") ;
  if ( document != NULL_String )
    cout << "<p>Here is your <a href=\"../show.cgi?ref=" << document
	 << "\">Web&#222;ing Bookmark</a> (current document).</p>" ;

/* OK, you got the idea ..
   Now let's dump() the form.   We could select as_text, which is
   like CGI.pm's dump but IMHO better 'cos you can cut'n'paste from it
   and 'cos it tells you a lot more.   However, we'll use as_html which,
   in addition to the above, renders the entire form.   By hitting
   "submit", you call this CGI program with your inputs (which will of
   course replace the defaults when the form is reprinted).
*/
  cout << "<hr>" << cgi.dump_as_html("demo.cgi") ;

  cout << "<hr><p align=right><a href=\"demo.cc\">The C++ source for this "
	<< "demo program is here.</a></p><hr>" ;
/* enough for a little demo ;-) */
  cout << "</body></html>" ;

  return 0 ;
}
