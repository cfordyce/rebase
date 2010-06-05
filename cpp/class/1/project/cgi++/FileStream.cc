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
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <String.h>
#include <unistd.h>

#include "FileStream.h"

#ifdef FEB97
#define EXIT(n) exit(n)
#else
#define EXIT(n) status = false
#endif

/* BETA 2: switch to fcntl() (POSIX compliant, -ansi -pedantic clean) locking */

struct flock* file_lock(const short type, const short whence =SEEK_SET) {
  static struct flock ret ;
  ret.l_type = type ;
  ret.l_start = 0 ;
  ret.l_whence = whence ;
  ret.l_len = 0 ;
  ret.l_pid = getpid() ;
  return &ret ;
}

Istream::Istream(char const*const name, const mode_t mode) {
// dammit attach() is nonstandard, so open twice here too
  lock_fd = ::open(name, O_RDONLY|O_CREAT, mode) ;
  if ( lock_fd == -1 ) {
	cerr << "Error " << errno << " opening " << name << ": "
		<< strerror(errno) << endl ;
	EXIT(-1) ;
  }
  if (fcntl (lock_fd, F_SETLKW, file_lock(F_RDLCK) ) == -1 ) {
	cerr << "Error locking " << name << " for read!\n"
		<< strerror(errno) << endl ;
	EXIT(-1) ;
  }
  open(name) ;
}
Istream::~Istream() {
  close() ;
  ::close(lock_fd) ;
}
Ostream::Ostream(char const*const name, const mode_t mode) {
// need to open twice, with O_TRUNC only *after* getting a lock
  lock_fd = ::open(name, O_RDWR|O_CREAT, mode) ;
  if ( lock_fd == -1 ) {
	cerr << "Error " << errno << " opening " << name << ": "
		<< strerror(errno) << endl ;
	EXIT(-1) ;
  }
  if (fcntl (lock_fd, F_SETLKW, file_lock(F_WRLCK)) == -1 ) {
	cerr << "Error locking " << name << " for write!\n"
		<< strerror(errno) << endl ;
	EXIT(-1) ;
  }
  open(name) ;
}
Ostream::~Ostream() {
  close() ;
  ::close(lock_fd) ;
}
Astream::Astream(char const*const name, const mode_t mode) {
  lock_fd = ::open(name, O_RDWR|O_CREAT, mode) ;
  if ( lock_fd == -1 ) {
	cerr << "Error " << errno << " opening " << name << ": "
		<< strerror(errno) << endl ;
	EXIT(-1) ;
  }
  if (fcntl (lock_fd, F_SETLKW, file_lock(F_WRLCK, SEEK_END)) == -1 ) {
	cerr << "Error locking " << name << " for append!\n"
		<< strerror(errno) << endl ;
	EXIT(-1) ;
  }
  open(name, ios::out|ios::app) ;
}
Astream::~Astream() {
  close() ;
  ::close(lock_fd) ;
}
