/*
Copyright (C) 1997  WebThing and Nick Kew

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

WebThing is at <URL:http://www.webthing.com/>.
Nick Kew may be contacted at address <mailto:nick@webthing.com>
*/
#ifndef TIMEBUF_H
#define TIMEBUF_H
#include <iostream.h>
#include <strstream.h>
#include <string.h>
#include <time.h>

class Timebuf {
	time_t _secs ;
	struct tm _tm ;
	char _day[4] ;
	char _month[4] ;
	char _year[5] ;
	char _date[3] ;
	char _time[9] ;
	inline void set() ;
	inline void set(struct tm* tm) ;
public:
	inline void set(const int, const int, const int,
		const int =12, const int =0, const int =0) ;
	Timebuf(time_t secs) : _secs(secs) { set() ; }
	Timebuf() : _secs(::time(0)) { set() ; }
	Timebuf(int yy, const int mm, const int dd,
		const int h =12, const int m =0, const int s =0)
		: _secs(::time(0)) { set() ; set(yy,mm,dd,h,m,s) ; }
	const char* day() const { return _day ; }
	const char* month() const { return _month ; }
	const char* time() const { return _time ; }
	const char* date() const { return _date ; }
	const char* year() const { return _year ; }
	inline const char* y4m2d2(const char delim ='/') const ;
	const int dd() const { return _tm.tm_mday ; }
	const int mm() const { return _tm.tm_mon ; }
	const int yy() const { return _tm.tm_year ; }
	const int wd() const { return _tm.tm_wday ; }
	const int days_in_month() const ;

	Timebuf& addss(const int dt) { _secs += dt ; set() ; return *this ; }
	Timebuf& addmm(const int dt) { return addss(60*dt) ; }
	Timebuf& addhh(const int dt) { return addss(3600*dt) ; }
	Timebuf& adddd(const int dt) { return addss(86400*dt) ; }
	Timebuf& addww(const int dt) { return addss(604800*dt) ; }
	Timebuf& addYY(const int dt) { _tm.tm_year += dt ; set(&_tm) ; return *this ; }
	Timebuf& addMM(const int dt) {
		_tm.tm_mon += dt ;
		while ( _tm.tm_mon >= 12) {
			_tm.tm_mon -= 12 ;
			++_tm.tm_year ;
		}
		while ( _tm.tm_mon < 0) {
			_tm.tm_mon += 12 ;
			--_tm.tm_year ;
		}
		set(&_tm) ;
		return *this ;
	}
} ;
  
inline ostream& operator<<(ostream& o, const Timebuf& t) {
  return o
	<< t.day() << ", " << t.date() << ' ' << t.month()
	<< ' ' << t.year() << ' ' << t.time() << " GMT" ;
}
inline void Timebuf::set() {
  memcpy(&_tm, gmtime(&_secs), sizeof(struct tm)) ;
  set(&_tm) ;
}
inline void Timebuf::set(struct tm* tm) {
  char* tbuf = asctime(tm) ;
  istrstream(tbuf,strlen(tbuf))
	>> _day >> _month >> _date >> _time >> _year ;
}
inline const char* Timebuf::y4m2d2(const char delim) const {
  static char buf[12] ;
  ostrstream ret(buf, sizeof(buf)) ;
  ret << _year << delim << mm()+1 << delim << dd() << ends ;
  return buf ;
}
inline void Timebuf::set(const int yy, const int mm, const int dd,
			const int h, const int m, const int s) {
  _tm.tm_year = yy - 1900 ;
  _tm.tm_mon = mm ;
  _tm.tm_mday = dd ;
  _tm.tm_hour = h ;
  _tm.tm_min = m ;
  _tm.tm_sec = s ;
  _secs = mktime(&_tm) ;
  set() ;
}
inline const int Timebuf::days_in_month() const {
  static int mdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 } ;
  if ( _tm.tm_mon == 1 ) {
    const int yy(_tm.tm_year+1900) ;
    if ( yy % 4 == 0 )
      if ( yy % 100 == 0 )
	if ( yy % 400 == 0 )
	  return 29 ;
	else
	  return 28 ;
      else
	return 29 ;
    else
      return 28 ;
  } else
    return mdays[_tm.tm_mon] ;
}
#endif
