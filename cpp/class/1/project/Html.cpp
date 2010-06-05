/*---------------
  C++ Intro Project

  Html Class Source
  ---------------*/

#include "Html.h"
#include <string>
#include <iostream>
#include <strstream>

// Ctor
Html::Html( string page_name )
  : page_title( page_name )
{}

// Copy ctor
Html::Html(const Html& h)
{
  setTitle(h.getTitle());
}

ostream& Html::header() const
{
  string p_title(getTitle());
  
  return ( 
	  cout << "<HTML>\n<HEAD>\n<TITLE>" 
	  << p_title << "</TITLE>\n</HEAD>\n<BODY>\n"
	  );
}

ostream& Html::footer() const
{
  return ( cout << "</BODY></HTML>\n");
}

ostream& Html::hn( string text, int size=2 )
{
  if ( size > 0 && size < 5 )
    {
      ostrstream ost;
      
      ost << "<H" << size << ">"
	  << text << "</H" << size << ">\n";
      
      head_n = ost.str();
      
      return ( cout << head_n );
    }
  return ( cout );
}

ostream& Html::link( string address, string text ) const
{
  return (
	  cout << "<A HREF=\"" << address << "\">"
	  << text << "</A>\n"
	  );
}


// setter for page_title
void Html::setTitle(const string p_title)
{
  page_title = p_title;
}


// Overloaded assignment.  
// Assigns the page title of the right operand to the left.
Html& Html::operator=(const Html& a)
{
  if ( this != &a )
    {
      setTitle(a.getTitle());
    }
  return *this;
}

// Overloaded Equality
// Returns true if the objects' page title's are equal, false otherwise.
bool Html::operator==(const Html& e)
{
  return getTitle() == e.getTitle();
}

// Overloaded insertion - HEADER and HN ONLY
// Puts the header and hn members of the object into the ostream ( for push to the web )
ostream& operator<< (ostream& os, const Html& s)
{
  if (!os.opfx())
    return os;
  
  return ( os << s.header() << s.hn() );
}


// Overloaded extraction
// Extracts from istream into title
istream& operator>> (istream& is, Html& i)
{
  string in;
  is >> in;
  
  i.setTitle(in);
  
  return is;
}
