/*------------------------
  Charles Fordyce 
  C++ Intro Project

  CGI Class Header File
  ------------------------*/

#ifndef CGI_H
#define CGI_H

#include <map>
#include <string>
#include <iostream>

class Cgi 
{
 public:
  //
  // Public Methods
  //
  
  // Ctor
  Cgi();
  
  // Copy Ctor
  Cgi(const Cgi&);

  // Dtor
  ~Cgi() {}

  // Given a key from the query string, returns the value
  string param(const string key);
  
  // Getter that returns an http header string
  string httpHeader() const { return http_header; }

  // Getter that returns the object's query_string
  string queryString() const { return query_string; }

  // Overloaded assignment.  
  // Assigns the query string and map of the right operand to the left.
  Cgi& operator=(const Cgi&);

  // Overloaded Equality
  // Returns true if the objects' query strings are equal, false otherwise
  bool operator==(const Cgi&);
  
  // Overloaded insertion
  // Puts the http header into the ostream
  friend ostream& operator<< (ostream&, const Cgi&);

 private:
  //
  // Private Methods
  //

  // Overloaded insertion
  // Puts the http header into the stream
  //ostream& operator << (ostream&, const Cgi&);
  
  // Decode URL-encoded data in the QUERY_STRING variable.
  void decodeQueryString();

  // Parses the query_string into key=value map
  void mapQueryString();




  //
  // Private Variables
  //
  string http_header;
  string query_string;
  
  map<string, string> query_map;
};





#endif
