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
#ifndef CGI_H
#define CGI_H

#include "FORM.h"

class CGI : public FORM {
  static Map _env ;
  friend ostream& operator<< (ostream&, CGI&) ;
  friend istream& operator>> (istream&, CGI&) ;
  static int max_length ;
private:
  char* _body ;	// raw document body, if content-type isn't known
  int _bodylen ;

  void setenv() ; // for dump() functions only
  void decode(charp) ;
  void decode(const String&) ;
  void debug_mode() ;
  void errordoc(const int, const char*) const ;

// for reading multipart/form (Netscape file-upload)
  void read_mime_body(String&) ;
  void mime_error(const char*) const ;

public:
// Keep the constructor minimal to
// allow programmers to set template before initialising data
  CGI() { _body = 0 ;}
  ~CGI() { if (_body) delete [] _body ; }

// flag for whether there's any data to process
  const int has_form_data()
	{ return ( ( request_method() == "POST" ) ||
			( query_string() != NULL_String ) ) ; }

// Unset values
  void clean() ;
// handle to the raw body
  char const* const body() const { return _body ; }

// debug functions
  const String& dump_as_text() ;
  const CDATA& dump_as_html(charp const, charp const ="POST",
	charp const =0) ;

// FORM functions
  bool readfrom(char const * const from) ;	// read from file
  bool saveto(char const * const to) ;		// save to file
  void form() ;					// read whats' been submitted

// Parsing of env vars
  String& key_val(String&, const char* const,
	char const ='=', char const =';') const;
  String& key_val(const String& s, const char* const k,
	char const eq='=', char const end=';') const
	{ String S(s) ; return key_val(S,k,eq,end) ; }
  const int word_match(const String&, const char* const) const ;

// Raw CGI environment vars 
  String& auth_type() { return env("AUTH_TYPE") ; }
  String& content_length() { return env("CONTENT_LENGTH") ; }
  String& content_type() { return env("CONTENT_TYPE") ; }
  String& gateway_interface() { return env("GATEWAY_INTERFACE") ; }
  String& path_info() { return env("PATH_INFO") ; }
  String& path_translated() { return env("PATH_TRANSLATED") ; }
  String& query_string() { return env("QUERY_STRING") ; }
  String& remote_addr() { return env("REMOTE_ADDR") ; }
  String& remote_host() { return env("REMOTE_HOST") ; }
  String& remote_ident() { return env("REMOTE_IDENT") ; }
// remote_port() is an Apache-specific extension
  String& remote_port() { return env("REMOTE_PORT") ; }
  String& remote_user() { return env("REMOTE_USER") ; }
  String& request_method() { return env("REQUEST_METHOD") ; }
// script_filename ain't in the spec but seems to be implemented
  String& script_filename() { return env("SCRIPT_FILENAME") ; }
  String& script_name() { return env("SCRIPT_NAME") ; }
  String& server_admin() { return env("SERVER_ADMIN") ; }
  String& server_name() { return env("SERVER_NAME") ; }
  String& server_port() { return env("SERVER_PORT") ; }
  String& server_protocol() { return env("SERVER_PROTOCOL") ; }
  String& server_software() { return env("SERVER_SOFTWARE") ; }

/* =================================================================
Everything below here belongs in class HTTP_REQUEST, which will be a
parent of CGI as soon as I've fixed it up!
==================================================================== */
  const char*const cenv(charp const) ;
  String& env(charp const) ;

/*NOTE: authorization should NOT be passed to CGI unless the server is hacked
  CGI/1.1 is too old to know about proxy authorization, but I guess a server
  probably will keep the 'spirit' of it and NOT return it ...
*/
  String& authorization() { return env("HTTP_AUTHORIZATION") ; }
  String& proxy_authorization() { return env("HTTP_PROXY_AUTHORIZATION") ; }

/* The rest of the headers will probably be available to CGI whenever set
   (but I really don't know where to draw the line for authentication
   stuff - like MD5 - does anyone?   The CGI/1.1 spec simply isn't
   adequate for programming with HTTP/1.1).
*/

// GENERAL HEADERS
  String& cache_control() { return env("HTTP_CACHE_CONTROL") ; }
  String& connection() { return env("HTTP_CONNECTION") ; }
  String& date() { return env("HTTP_DATE") ; }
  String& pragma() { return env("HTTP_PRAGMA") ; }
  String& transfer_encoding() { return env("HTTP_TRANSFER_ENCODING") ; }
  String& upgrade() { return env("HTTP_UPGRADE") ; }
  String& via() { return env("HTTP_VIA") ; }

// REQUEST HEADERS
  String& accept() { return env("HTTP_ACCEPT") ; }
  String& accept_charset() { return env("HTTP_ACCEPT_CHARSET") ; }
  String& accept_encoding() { return env("HTTP_ACCEPT_ENCODING") ; }
  String& accept_language() { return env("HTTP_ACCEPT_LANGUAGE") ; }
  String& cookie() { return env("HTTP_COOKIE") ; }
  String& from() { return env("HTTP_FROM") ; }
  String& host() { return env("HTTP_HOST") ; }
  String& if_modified_since() { return env("HTTP_IF_MODIFIED_SINCE") ; }
  String& if_match() { return env("HTTP_IF_MATCH") ; }
  String& if_none_match() { return env("HTTP_IF_NONE_MATCH") ; }
  String& if_range() { return env("HTTP_IF_RANGE") ; }
  String& if_unmodified_since() { return env("HTTP_IF_UNMODIFIED_SINCE") ; }
  String& max_forwards() { return env("HTTP_MAX_FORWARDS") ; }
  String& range() { return env("HTTP_RANGE") ; }
  String& referer() { return env("HTTP_REFERER") ; }
  String& user_agent() { return env("HTTP_USER_AGENT") ; }

// ENTITY HEADERS (the spec is rather awkward: content-type and length
//	are both CGI headers and Entity headers.   Can fix this with
//	the HTTP class hierarchy in a future release).
//
// Not that we expect to get most of these very often...
  String& allow() { return env("HTTP_ALLOW") ; }
  String& content_base() { return env("HTTP_CONTENT_BASE") ; }
  String& content_encoding() { return env("HTTP_CONTENT_ENCODING") ; }
  String& content_language() { return env("HTTP_CONTENT_LANGUAGE") ; }
  String& http_content_length() { return env("HTTP_CONTENT_LENGTH") ; }
  String& content_location() { return env("HTTP_CONTENT_LOCATION") ; }
  String& content_md5() { return env("HTTP_CONTENT_MD5") ; }
  String& content_range() { return env("HTTP_CONTENT_RANGE") ; }
  String& http_content_type() { return env("HTTP_CONTENT_TYPE") ; }
  String& etag() { return env("HTTP_ETAG") ; }
  String& expires() { return env("HTTP_EXPIRES") ; }
  String& last_modified() { return env("HTTP_LAST_MODIFIED") ; }

  

/* Smart implementation of the HTTP Request wants its own class, which will
   have to wait for a future release of CGI++.   Here's a token gesture...
   headers which either do or don't include a word (boolean), and
   a version of cookie to process KEY=VALUE pairs.
   Of course, the smart version of QUERY_STRING is already dealt with by FORM :-)
*/
  const int content_language(const char*const) ;
  const int if_match(const char*const) ;
  const int if_none_match(const char*const) ;
  const int accept(const char*const) ;
  const int accept_charset(const char*const) ;
  const int accept_encoding(const char*const) ;
  const int accept_language(const char*const) ;
  String& cookie(const charp) ;

/* Issue an authentication challenge for this document */
  void authenticate( const char* authtype, const char* realm,
	void errorfunc(const int status) =0 ) const ;

} ;

#endif
