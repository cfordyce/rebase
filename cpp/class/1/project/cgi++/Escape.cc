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
#include <String.h>
#include <strstream.h>
#include "Escape.h"
#include <ctype.h>

inline unsigned char x2c(char const x) {
  if ( isdigit(x) )
    return x - '0' ;
  else if (islower(x))
    return x - 'a' + 10 ;
  else
    return x - 'A' + 10 ;
}
inline unsigned char x2c(char const * const x) {
  return (x2c(x[0]) << 4) + x2c(x[1]) ;
}

inline const unsigned char c2x(const unsigned char c) {
  return c > 9 ? 'A'+c-10 : c+'0' ;
}

inline const String& escape_char(const unsigned char c) {
  static String ret ;
  ret = '%' ;
  ret += c2x((c&0xf0)>>4) ;
  ret += c2x(c&0xf) ;
  //ret = (ret + c2x((c&0xf0)>>4)) + c2x(c&0xf) ;
  return ret ;
}
String& www_escape(String& s) {
  static const Regex toescape("[\x01-\x20\x5B-\x5E\x7B-\xFF+#%;'`<>]",1) ;
  int pos ;
  for (pos = s.index(toescape) ; pos >= 0 ; pos=s.index(toescape,pos)) {
    const String tmp = s.at(pos,1) ;
    const String& repl = escape_char(tmp[0]) ;
    s.at(pos,1) = repl ;
    pos += repl.length() ;
  }
  return s ;
}
String& www_unescape(String& s) {
  static const Regex escaped("%[0-9A-Fa-f][0-9A-Fa-f]", 1) ;
  s.gsub('+',' ') ;
  for (int pos = s.index(escaped); pos >= 0; pos = s.index(escaped,++pos)) {
	const String& nn = s.at(pos+1, 2) ;
	s.at(pos,3) = x2c(nn) ;
  }
  return s ;
}
String& html_escape(String& s) {
  s.gsub('&', "&amp;") ;
  s.gsub('<', "&lt;") ;
  s.gsub('>', "&gt;") ;
  return s ;
}

const String& www_escape(const String& s)
	{ static String x ; x = s ; return www_escape(x) ; }
const String& www_unescape(const String& s)
	{ static String x ; x = s ; return www_unescape(x) ; }
const String& html_escape(const String& s)
	{ static String x ; x = s ; return html_escape(x) ; }

String& www_escape(const char* s)
	{ static String x; x=s ; return www_escape(x) ; }
String& www_unescape(const char* s)
	{ static String x; x=s ; return www_unescape(x) ; }

/* Don't insist on String 'cos of the 32K size limitation */
const char* html_escape(const char* s) {
  if ( !s )
    return "" ;

  ostrstream o ;
  while (*s) {
    switch (*s) {
      case '&' : o << "&amp;" ; break ;
      case '<' : o << "&lt;" ; break ;
      case '>' : o << "&gt;" ; break ;
      default : o << *s ; break ;
    }
    ++s ;
  }
  o << ends ;
  return o.str() ;
}
