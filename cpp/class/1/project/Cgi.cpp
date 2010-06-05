/*------------------------
  Charles Fordyce 
  C++ Intro Project

  CGI Class Source File
  ------------------------*/
#include "Cgi.h"
#include <map>
#include <string>
#include <iostream>

// Ctor
Cgi::Cgi() :
  http_header("Content-type: text/html\n\n"),
  query_string(getenv("QUERY_STRING"))
{
  if ( query_string.size() == 0 )
    {
      cin >> query_string;

      if ( query_string.size() == 0 )
	{
	  cerr << "No Params!!" << endl;
	  exit(1);
	}
    }
  
  decodeQueryString();
  mapQueryString();
  
}


// Copy Ctor
Cgi::Cgi(const Cgi& c)
{
  http_header = c.httpHeader();
  query_string = c.queryString();
  decodeQueryString();
  mapQueryString();
}


string Cgi::param(const string key)
{
  return query_map[key]; 
}

void Cgi::decodeQueryString()
{
  int length=query_string.size()-1, position=0;
  
  for ( int i=0;i<length; i++ )
    if ( query_string[i] == '+' )
      query_string[i] = ' ';
  
  
  char hexchar;
  while ( position < length )
    {
      int percent = query_string.find_first_of("%",position);
      
      if ( query_string[percent+2] != '\000' && percent > -1 )
	{
	  hexchar = (char)strtoul(query_string.substr(percent+1,2).c_str(),NULL,16);
	  query_string.replace(percent,3,hexchar);
	}
      else
	position=length;
      
      position++;
    }
}


void Cgi::mapQueryString()
{
  int length=query_string.size()-1, position=0;
  
  while ( position < length )
    {
      int equal = query_string.find_first_of( "=", position);
      int amper = query_string.find_first_of( "&", equal+1);
      
      int key_begin = position;
      int key_length = equal-position;
      int val_begin = equal+1;
      int val_length = amper-equal-1;
      
      query_map[query_string.substr(key_begin, key_length)]=query_string.substr(val_begin, val_length);
      
      amper < 0 ? position=length : position=amper+1;
    }
}

Cgi& Cgi::operator=(const Cgi& a)
{
  if ( this != &a )
    {
      query_string = a.queryString();
      decodeQueryString();
      mapQueryString();
    }
  return *this;
  
}

bool Cgi::operator==(const Cgi& e)
{
  return queryString() == e.queryString();
}


ostream& operator<< (ostream& os, const Cgi& s)
{
  if (!os.opfx())
      return os;
  return (  os << s.httpHeader() );
}
