/*------------------------
  Charles Fordyce 
  C++ Intro Project
  
  UserData Class Header File
  ------------------------*/

#ifndef USER_DATA_H
#define USER_DATA_H

#include <string>
#include <iostream>


class UserData 
{

 public:
  
  //
  // Methods
  //
  
  // Ctor
  // Takes 3 required <string> parameters:
  // (and aren't they all that really matter?)
  // 1-User Name
  // 2-User Age
  // 3-User Occupation
  UserData(const string, const string, const string);
  
  // Copy Ctor
  UserData(const UserData&);

  // Dtor
  ~UserData() {}
  
  //
  // Public Methods
  //
  
  // Returns the object's user name string 
  string userName() const { return user_name; }
  
  // Returns the object's user age string
  string userAge() const { return user_age; }
  
  // Returns the object's user occupation string
  string userJob() const { return user_job; }

  
  // 
  // Mutator Methods
  //
  
  //  Allows the class user to change the user name string
  void setUserName(const string);

  // Allows the class user to change the user age string
  void setUserAge(const string);
  
  // Allows the class user to change the user occupation string
  void setUserJob(const string);
  
  //
  // Overloaded Operators
  //
  
  // Overloaded assignment.  
  // Assigns the UserData object to the right operand to the UD object to the left.
  UserData& operator=(const UserData&);
  
  // Overloaded Equality
  // Returns true if the object's user names are the same
  bool operator==(const UserData&);
  
  // Overloaded insertion
  // Inserts a UserData object into the specified ostream
  friend ostream& operator<< (ostream&, const UserData&);
  
  // Overloaded extraction
  // Extracts from the in stream into UserData::setUserName(string)
  friend istream& operator>> (istream&, const UserData&);

 private:
  
  //
  // Variables
  //
  string user_name;
  string user_age;
  string user_job;
};

#endif
