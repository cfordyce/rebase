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
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <strstream.h>
#include <String.h>
#include "CGI.h"
#include "FileStream.h"
#include "Escape.h"

int CGI::max_length = 1073741824 ;

istream& operator>> (istream& in, CGI& cgi) {
  String buf ;
  in >> buf ;
  cgi.decode(buf) ;
  return in ;
}
ostream& operator<< (ostream& out, CGI& cgi) {
  Pix x = cgi.first() ;
  while (x) {
    String& s = cgi.contents(x).encode(cgi.key(x)) ;
    cgi.next(x) ;
    if ( ! s.length() )
	continue ;
    out << s ;
    if (x)
	out << '&' ;
  }
  return out ;
}
void CGI::errordoc(const int status, const char* msg) const {
  cout << "Status: " << status << msg << "\n"
	"Content-Type: text/html\n\n"
"<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\">\n"
"<html><head><title>CGI++ Error</title>"
"</head><body>"
"<p><a href=\"http://www.webthing.com/cgiplusplus/\">CGI++</a> was unable"
"to process your request.  The reason given was:<br>"
"<code>" << status << " " << msg << "</code></p>"
"<p>This is a soft error, and can be adjusted by the programmer"
"changing the limits in"
"<a href=\"http://www.webthing.com/cgiplusplus/\">CGI++</a>"
"if required.</p>"
	;
	exit(0) ;
}
bool CGI::readfrom(char const* const from) {
  Istream in (from) ;
  in >> *this ;
  return in.ok() ;
}
bool CGI::saveto(char const* const to) {
  Ostream out (to) ;
  out << *this ;
  return out.ok() ;
}
void CGI::clean() {
  for (Pix x = first() ; x; next(x) )
    contents(x).set(NULL_String) ;
}
const char*const CGI::cenv(char *const x) {
  return (const char*) env(x) ;
}
String& CGI::env(char *const x) {
  String v(x) ;
  String& e = _env[v] ;
  if ( e == NULL_String )
    e = getenv(x) ;
  return e ;
}

void CGI::form() {
/*
   The following regime will deal with all HTTP/1.1 methods.
   Passing FORM data is only defined for the old methods
   (GET, HEAD, POST)
   so we just decode form data passed in ANY recognised format.
   This deals with all protocols available now (Jan.97)

Read and decode form data:
  IF there's anything on STDIN		(POST, PUT)
    IF we recognise the content type
      Decode it
    ELSE
      put it raw in _body
    ENDIF
  ENDIF
  IF there's a QUERY_STRING		(GET, HEAD)
    Decode it
  ENDIF
*/
  const String& clen = content_length() ;
  int len = clen == NULL_String ? 0 : atoi(clen) ;
  const String& ctype = content_type() ;
  const String& method = request_method() ;

/* if there isn't a method, assume online debug mode */
  if ( method == NULL_String ) {
	debug_mode() ;
	return ;
  }
/* GET or HEAD will send us form data in here.   The new HTTP/1.1 methods
   could in principle also do so.   We'll decode whatever we get.
*/
  decode(query_string()) ;

/* POST and PUT require a body (for other methods, we'll take one if
   we're given one, but not insist :-)

   CGI/1.1 guarantees us a valid Content-length.   However, so does
   HTTP/1.0, for which CGI/1.1 was really written.   HTTP/1.1 doesn't,
   so we might find someone sending us a body WITHOUT a content-length
   (in violation of the spec).   If so, this will break.
*/
  if ( clen == NULL_String )
    if ( method == "PUT" || method == "POST" ) {
	cerr << "Methods POST and PUT without Content-length not supported\n" ;
	exit(-1) ;
    }
  if ( len > 0 ) {
    if (len > max_length) {
	errordoc(413, "Document too long") ;
    }
    _bodylen = len+1;
    _body = new char[_bodylen] ;
    VERIFY(_body) ;
    cin.read(_body,len) ;
    _body[len] = 0 ;
    if ( ctype == "application/x-www-form-urlencoded" ) {
  	decode(_body) ;
        delete[] _body ;
	_body = 0 ;
    } else if ( ctype.contains("multipart/form-data", 0) ) {
	/* why couldn't Netscape have done this with PUT ? */
	read_mime_body(key_val(ctype,"boundary") ) ;
        delete[] _body ;
	_body = 0 ;
    } else {
/* Got a BODY of unknown type: might be an error.   Let the programmer
   have it in its raw form (i.e. do nothing - keep it in _body).
*/
#ifdef DEBUG
	cerr << "Unknown content-type " << ctype << " - not decoded.\n" ;
#endif
    }
  }
}
void CGI::debug_mode() {
    char buf[256] ;
    int option = -1 ;
    while (option) {
      cerr << "\nCGI++ Debug mode:\n"
	<< "	0: continue program execution\n"
	<< "	1: display current form data and environment:\n"
	<< "	2: enter environment variable(s) (name=value pairs):\n"
	<< "	3: enter form data (name=value pairs):\n"
	<< "	4: Save current form data to file\n"
	<< "	5: Restore form data from file\n> " ;
      cin >> option ; cin.getline(buf,256) ;
      switch(option) {
	case 4:
	  cerr << "Filename ? " ;
	  cin >> buf ;
	  saveto(buf) ;
	  break ;
	case 5:
	  cerr << "Filename ? " ;
	  cin >> buf ;
	  readfrom(buf) ;
	  break ;
	case 0:
	  break ;
	case 1:
	  cerr << dump_as_text() ;
	  break ;
	case 2:
	  while (1) {
	    cerr << "ENV> " ;
	    cin.getline(buf,256) ;
	    if (buf[0] == 0) break ;
	    String name = strtok(buf,"=") ;
	    String value = strtok(0,"") ;
	    _env[name] = value ;
	  }
	  break ;
	case 3:
	  while (1) {
	    cerr << "FORM> " ;
	    cin.getline(buf,256) ;
	    if (buf[0] == 0) break ;
	    String name = strtok(buf,"=") ;
	    String value = strtok(0,"") ;
	    if ( (*this)[name].is_dflt() )
		(*this)[name] = new form_unknown(value) ;
	    else
		(*this)[name].set(value) ;
	  }
	  break ;
	default:
	  cerr << "Pardon? " ;
	  break ;
      }
    }
}

void CGI::decode(charp buf) {
  const String s(buf) ;
  decode(s) ;
}
void CGI::decode(const String& buf) {
  if (buf == NULL_String) return ;
  int npairs = buf.freq('&') + 1 ;
  String* pairs = new String[npairs] ;
  VERIFY(pairs) ;
  npairs = split(buf,pairs,npairs,'&') ;
  for (String* pair = pairs ; npairs-- ; ++pair) {
    String keyval[2] ;
    split(*pair,keyval,2,'=') ;
    String& key = www_unescape(keyval[0]) ;
    if ((*this)[key].is_dflt())
	(*this)[key] = new form_unknown(www_unescape(keyval[1])) ;
    else
	(*this)[key].set(www_unescape(keyval[1])) ;
  }
  delete[] pairs ;
}

const String& CGI::dump_as_text() {
  static String ret ;
  ret =	"FORM DATA\n" ;
  ret +=	"=========\n" ;
  ret += FORM::dump_as_text() ;
  ret += "\nENVIRONMENT\n" ;
  ret +=   "===========\n" ;
  setenv() ;
  for (Pix x = _env.first() ; x ; _env.next(x)) {
    String& c = _env.contents(x) ;
    if ( c != NULL_String )
	ret += _env.key(x) + ':' + c + "\n" ;
  }
  return ret ;
}
const CDATA& CGI::dump_as_html(charp const URL,
	charp const meth, charp const enc) {
  static CDATA ret ;
  ret = FORM::dump_as_html(URL, meth,enc) + "<hr>" ;
  setenv() ;
  ret += "<table border=1><caption><big><b>ENVIRONMENT</b></big></caption>" ;
  for (Pix x = _env.first() ; x ; _env.next(x)) {
    String& c = html_escape(_env.contents(x)) ;
    if ( c != NULL_String )
	ret += "<tr><th>" + _env.key(x) + "</th><td>" + c + "</td></tr>" ;
  }
  ret += "</tr></table>" ;
  return ret ;
}
void CGI::setenv() {
/* Ensures ALL env vars are in _env.   Only useful if you want to dump(),
   since env() will get them for you in any case.   There is ABSOLUTELY NO
   reason to call setenv yourself, so it's private!
*/
  static int called = -1 ;
  if ( ++called ) return ;
  auth_type() ;
  content_length() ;
  content_type() ;
  gateway_interface() ;
  path_info() ;
  path_translated() ;
  query_string() ;
  remote_addr() ;
  remote_host() ;
  remote_ident() ;
  remote_user() ;
  request_method() ;
  script_filename() ;
  script_name() ;
  server_admin() ;
  server_name() ;
  server_port() ;
  server_protocol() ;
  server_software() ;

  cache_control() ;
  connection() ;
  date() ;
  pragma() ;
  transfer_encoding() ;
  upgrade() ;
  via() ;

  accept() ;
  accept_charset() ;
  accept_encoding() ;
  accept_language() ;
  cookie() ;
  from() ;
  host() ;
  if_modified_since() ;
  range() ;
  referer() ;
  user_agent() ;

  allow() ;
  content_base() ;
  content_encoding() ;
  content_language() ;
  http_content_length() ;
  content_location() ;
  content_md5() ;
  content_range() ;
  http_content_type() ;
  etag() ;
  expires() ;
  last_modified() ;

}

const int CGI::word_match(const String& in, const char* const word) const {
  int match = 0 ;
  const int len = strlen(word) ;
  const int slen = in.length() ;
  for (int pos = in.index(word) ; pos >= 0 ; pos = in.index(word,pos)) {
    match = 1 ;
    if ( pos > 0)
      if ( isalnum(in[pos-1]) )
	match = 0 ;
    pos += len ;
    if (pos >= slen)
	break ;
    if ( isalnum(in[pos]) )
	match = 0 ;
    if (match)
	break ;
  }
  return match ;
}
String& CGI::key_val(String& in, const char* const key,
	const char eq, const char end) const {
  static String ret ;
  ret = key ;
  ret = ret + eq + "[^" + end + "]*" ;
  const Regex r(ret) ;
  ret = in.at(r) ;
  ret = ret.after(key) ;
  ret = ret.after(eq) ;
  return ret ;
}

const int CGI::accept(const char* const x) {
  return word_match(accept(), x) ;
}
const int CGI::accept_charset(const char* const x) {
  return word_match(accept_charset(), x) ;
}
const int CGI::accept_encoding(const char* const x) {
  return word_match(accept_encoding(), x) ;
}
const int CGI::accept_language(const char* const x) {
  return word_match(accept_language(), x) ;
}
const int CGI::content_language(const char* const x) {
  return word_match(content_language(), x) ;
}
const int CGI::if_match(const char* const x) {
  return word_match(if_match(), x) ;
}
const int CGI::if_none_match(const char* const x) {
  return word_match(if_none_match(), x) ;
}
String& CGI::cookie(const charp x) {
  return key_val(cookie(),x) ;
}
/* Issue an authentication challenge for this document */

void CGI::authenticate(
	const char* authtype,
	const char* realm,
	void callback (const int)
  ) const {
  cout	<< "Status: 401 Authentication Required\n"
	<< "WWW-Authenticate: " << authtype
	<<"; realm=" << realm  << "\n" ;
  if ( callback )
    callback(401) ;
  else
    cout
	<< "Content-type: text/plain\n"
	<< "\nPlease enter your username and password to access this document."
 ;
  exit(0) ;
}
#ifdef OLD
void CGI::read_mime_body(String& boundary) {
  boundary.prepend("--") ;

  String tmp ;
  String name ;

  const Regex colon(":[ \t]*", 1) ;
  const Regex newline("[\r\n]",1) ;
  const Regex nonblank("[^ \t\r\n]",1) ;

  cin.unsetf(ios::skipws) ;

  while ( readline(cin, tmp), !cin.eof() ) {
    if ( tmp.contains(newline) ) tmp.del(newline,-1) ;
    if ( tmp.index(boundary) == 0 ) {
      if ( tmp == boundary ) {			// start new part
	while ( readline (cin, tmp) ) {
          tmp.del(newline,-1) ;
	  if ( !tmp.contains(nonblank) ) {
	    break ;
	  } else if ( tmp.contains("Content-Disposition", 0)) {
	    name = tmp.after("name=\"") ;
	    name = name.before('"') ;
	    String filename = tmp.after("filename=\"") ;
	    if (filename != NULL_String) {
	      filename = filename.before('"') ;
	      (*this)[name].filename(filename) ;
	    }
	    (*this)[name].set(NULL_String) ;
	  } else {
	    String pair[2] ;
	    split(tmp,pair,2,colon) ;
	    (*this)[name].add_header(pair[0],pair[1]) ;
	  }
	}
      } else {
	break ;					// was final bdy
      }
    } else if ( (*this)[name].is_dflt() ) {
	(*this)[name] = new form_unknown(tmp) ;
    } else {

      if ( (*this)[name].as_text().length() )
	tmp.prepend("\n") ;
 

      (*this)[name].add( tmp) ;
    }
  }
// Ostream ("/tmp/dump") << (*this)["file"].as_longtext() ;
}
#else
void CGI::read_mime_body(String& boundary) {

//cerr << "read_mime_body  - " << _bodylen << " bytes\n" ;

// read whole body into a buffer
//  int buflen ;
//  String& zzz(content_length()) ;
//  istrstream(zzz, content_length().length()) >> buflen ;
//  char* buf = new char[buflen+1] ;

//cerr << " reading " << buflen << " bytes"  << endl ;
//  cin.read(buf, buflen) ;
//   buf[buflen]=0 ;
//   Ostream("/tmp/DEBUG") << buf ;
// cerr << "bdy " << boundary << endl ;
// cerr << "got " << buf << endl ;

  boundary = "\r?\n?--" + boundary  + "\r?\n?" ;
  const Regex rxbdy(boundary) ;
  const Regex colon(":[ \t]*", 1) ;
  const Regex newline("[\r\n]",1) ;
  const Regex nonblank("[^ \t\r\n]",1) ;

  int mlen ;
/*
  Find first MIME boundary
  LOOP
    check for end
    move to end of mime bdy
    find next mime bdy
    parse inbetween
*/
  int startpart = 0 ;
  int endpart = rxbdy.search(_body, _bodylen-startpart, mlen, startpart ) ;
  startpart = endpart + mlen ;
// cerr << "part from " << startpart << " to " << endpart << endl ;
  while (startpart > 0) {
    if ( ! strncmp("--", _body+startpart, 2) )
	break ;					// end mark
    endpart = rxbdy.search(_body+startpart, _bodylen-startpart, mlen, 0 ) ;
// cerr << "part from " << startpart << " to " << endpart << endl ;
    if (endpart < 4)
	break ;

//    char* partbuf = new char[endpart-startpart] ;
//    strncpy(partbuf, buf+startpart, endpart-startpart) ;

// char zzz[1111] ;
// strncpy(zzz,buf+startpart,endpart/*-startpart*/) ;
// cerr << "part is " << zzz << endl ;
    istrstream partstr(_body+startpart, endpart/*-startpart*/) ;
    partstr.unsetf(ios::skipws) ;

    String hdrline, name ;
    int part_offs = 0 ;
    while ( readline(partstr, hdrline) , !partstr.eof() ) {
      part_offs += hdrline.length()+1 ;
// cerr << "header " << hdrline << "\nlen  " << part_offs << endl;
      hdrline.del(newline,-1) ;
      if ( ! hdrline.contains(nonblank) )
	break ;
      else if ( hdrline.contains("Content-Disposition", 0)) {
	name = hdrline.after("name=\"") ;
	name = name.before('"') ;
	String filename = hdrline.after("filename=\"") ;
	if (filename != NULL_String) {
	  filename = filename.before('"') ;
	  (*this)[name].filename(filename) ;
	}
	(*this)[name].set(NULL_String) ;
      } else {
	String pair[2] ;
	split(hdrline,pair,2,colon) ;
	(*this)[name].add_header(pair[0],pair[1]) ;
      }
    }		// part header read .. phew

    char* data = new char[endpart-part_offs+1] ;
    partstr.read(data,endpart-part_offs) ;
    data[endpart-part_offs] = 0 ;
// cerr << "contents " << endpart-part_offs << "bytes\n" ;
// Ostream("/tmp/DEBUG2").write(data,endpart-part_offs) ;
    if ( (*this)[name].is_dflt() )
	(*this)[name] = new form_unknown(NULL_String) ;

    (*this)[name].set( data,endpart-part_offs) ;

    delete data ;

    startpart += endpart + mlen ;
  }
}
#endif
