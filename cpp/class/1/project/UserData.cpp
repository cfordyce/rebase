/*------------------------
  Charles Fordyce 
  C++ Intro Project

 UserData  Class Source File
  ------------------------*/

#include "UserData.h"
#include <string>
#include <iostream>
#include <strstream>


UserData::UserData(const string name, const string age, const string occupation)
  : user_name(name),
    user_age(age),
    user_job(occupation)
{}
  
  // Copy Ctor
UserData::UserData(const UserData& u)
{
  user_name = u.userName();
  user_age = u.userAge();
  user_job = u.userJob();
}


// Mutator for user_name
void UserData::setUserName(const string name)
{
  user_name = name;
}

void UserData::setUserAge(const string age)
{
  user_age = age;
}

void UserData::setUserJob(const string job)
{
  user_job = job;
}

// Overloaded assignment.  
// Assigns the attributes of one user object to another!
UserData& UserData::operator=(const UserData& a)
{
  if ( this != &a )
    {
      user_name = a.userName();
      user_age = a.userAge();
      user_job = a.userJob();
    }

  return *this;
}
  
// Overloaded Equality
// Returns true if the users'(left operand) name, age and job are the same as the right operand
bool UserData::operator==(const UserData& e)
{
  if ( userName() == e.userName()
       && 
       userJob() == e.userJob()
       && 
       userAge() == e.userAge() )
    return true;
  else
    return false;
}

// Overloaded insertion
// Inserts the user name, age and job into the out stream
ostream& operator<<(ostream& os, const UserData& i)
{
  os << "Name: " << i.userName() << endl
     << "Age: " << i.userAge() << endl 
     << "Job: " << i.userJob() << endl;
  
  return os;
}

// Overloaded extraction
// Extracts from istream into UserData::setUserName(string)
istream& operator>> (istream& is, UserData& e)
{
  string name,age,job;

  is >> name;
  
  if ( name.size()-1 > 0 ) 
    is >> age;
  else
    is.clear(ios::badbit);
  if ( age.size()-1 > 0 )
    is >> job;
  else
    is.clear(ios::badbit);
  
  if ( job.size()-1 <= 0 )
    is.clear(ios::badbit);
  
  if ( is )
    e = UserData(name,age,job);

  return is;
}
