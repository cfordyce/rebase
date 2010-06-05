/*
Copyright (C) 1997  WebThing and Nick Kew

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

WebThing is at <URL:http://www.webthing.com/>.
Nick Kew may be contacted at address <mailto:nick@webthing.com>
*/
#ifndef FILESTREAM_H
#define FILESTREAM_H
#include <fstream.h>

/* FileStream adds file locking (the reason for using it) and simple
   error handling to the fstream classes.
*/
class FileStreamStatus {
protected:
  bool status ;
  FileStreamStatus()  { status = true ; }
public:
  bool ok() { return status ; }
} ;
class Istream : public ifstream, public FileStreamStatus {
  int lock_fd ;
public:
  Istream(const char* const, const mode_t m =0600) ;
  ~Istream() ;
} ;
class Ostream : public ofstream, public FileStreamStatus {
  int lock_fd ;
public:
  Ostream(const char* const, const mode_t m =0600) ;
  ~Ostream() ;
} ;
/*
class IOstream : public fstream {
  int lock_fd ;
public:
  IOstream(const char* const) ;
  ~IOstream() ;
} ;
*/
class Astream : public fstream, public FileStreamStatus {
  int lock_fd ;
public:
  Astream(const char* const, const mode_t m =0600) ;
  ~Astream() ;
} ;

#endif
