/*----------------------------
  Charles Fordyce
  C++ Intro Project

  Class Html Header
  ---------------------------*/

#ifndef HTML_H
#define HTML_H

#include <string>
#include <iostream>

class Html 
{

 public:
  //
  // Public Functions
  //
  
  // Ctor
  Html(string);

  // Copy Ctor
  Html(const Html&);

  // Dtor
  ~Html() {}
  
  
  // Returns an ostream reference containing:
  // <HTML>
  // <HEAD>
  // <TITLE>your title here</TITLE>
  // </HEAD>
  // <BODY> 
  ostream& header() const;
  
  
  //Returns an ostream reference containing:
  // </BODY></HTML>
  ostream& footer() const ;

  // Returns an ostream reference containing 
  // a string that will appear in the <TITLE> tags
  ostream& title() const{ return cout << page_title; }
  
  // Returns an ostream reference containing 
  // the contents of the <Hn> tag
  ostream& hn() const { return cout << head_n; }
  
  // Returns an ostream reference containing 
  // a hyperlink
  ostream& link(string, string) const;
  
  // Mutator function to set a header <Hn>
  // Arg1 is the tag data, Arg2 is the size 1-4 are legal
  ostream& hn(string, int =2);
  
  // Set the title string manually
  void setTitle(const string);
  
  // Overloaded assignment.  
  // Assigns the page title of the right operand to the left.
  Html& operator=(const Html&);
  
  // Overloaded Equality
  // Returns true if the objects' page title's are equal, false otherwise.
  bool operator==(const Html&);
  
  // Overloaded insertion - HEADER and HN ONLY
  // Puts the header and hn members of the object into the ostream ( for push to the web )
  friend ostream& operator<< (ostream&, const Html&);
  
  // Overloaded extraction
  // Extracts from istream into title
  friend istream& operator>> (istream&, Html&);

 private:
  //
  // Private Methods
  //
  string getTitle() const { return page_title; }

  //
  // Private Variables
  //
  string page_title;
  string head_n;

};

#endif
