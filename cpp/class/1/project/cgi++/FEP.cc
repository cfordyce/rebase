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
#include <string.h>
#include <ctype.h>
#include "Escape.h"
#include "FEP.h"
#include "FORM.h"
#include <strstream.h>

/* strdup chokes on POSIX, so we'll use our own */
inline const char* STRDUP(const char* str) {
  char* ret = new char[strlen(str)+1] ;
  strcpy(ret, str) ;
  return ret ;
}

void FEP::destruct() {
  if (_)
    if ( ! is_dflt() )
	{ delete _ ; _ = 0 ; }
}
void form_element::set(int i, int n) {
  String s ;
  while ((--n >= 0) || i) {
    s.prepend(i%10+'0') ;
    i /= 10 ;
  }
  set(s) ;
}
CDATA& form_element::as_html() {
  return html_escape(as_text()) ;
}
CDATA& form_file::as_html() {
  static CDATA ret ;
  ret = "<pre>" ;
  ret += html_escape(as_text()) + "</pre>" ;
  return ret ;
}
int FEP::as_int(int dflt) {
  int ret = dflt ;
  istrstream i(as_text()) ;
  i >> ret ;
  return ret ;
}
String& form_string::encode(const String& name) {
  static String s ;
//  s = www_escape(name) + '=' + www_escape(_val) ;
  s = www_escape(name) ;
  s +=  '=' ;
  s +=  www_escape(_val) ;
  return s ;
}
String& form_imagemap_coord::encode(const String& name) {
  static String s ;
  s = www_escape(name) + '=' + _val ;
  return s ;
}
String& form_select_multiple::encode(const String& name) {
  static String s ;
  s = "" ;
  const String& escapedname = www_escape(name) ;
  Pix x = selected.first();
  while (x) {
    s += escapedname + '=' + www_escape(selected(x)) ;
    selected.next(x) ;
    if (x) s += '&' ;
  }
  return s ;
}
String& form_checkbox::encode(const String& name) {
  static String s ;
  if ( onoff )
    s = www_escape(name) + "=on" ;
  else
    s = "" ;
  return s ;
}
String& form_checkbox::as_text() {
  static String s ;
  s = onoff ? "on" : "off" ;
  return s ;
}
String& form_select_multiple::as_text() {
  static String s ;
  s = "" ;
  for (Pix x = selected.first(); x; selected.next(x))
    s += "\n\t" + selected(x) ;
  return s ;
}
CDATA& form_select_multiple::as_html() {
  static CDATA s ;
  s = "<ul>" ;
  for (Pix x = selected.first(); x; selected.next(x))
    s += "<li>" + html_escape(selected(x)) ;
  s += "</ul>" ;
  return s ;
}
String& form_imagemap::as_text() {
  static String s ;
  s = "x = " ;
  s += _x->_val + "; y = " + _y->_val ;
  return s ;
}
CDATA& form_imagemap::render(const String& name) {
  static CDATA s ;
  s = "<input type=image src=\"" ;
  s += _val + "\" name=\"" + name + "\"" ;
  if (_d1 != NULL_String ) 
	s = s + " width=" + _d1 ;
  if (_d2 != NULL_String ) 
	s = s + " height=" + _d2 ;
  s += ">" ;
  return s ;
}

CDATA& form_checkbox::render(const String& name) {
  static CDATA s ;
  s =  "<input type=checkbox name=\""
	+ name + "\"" ;
  if ( onoff ) s += " checked>" ;
  else s += ">" ;
  return s ;
}
CDATA& form_input::render(const String& name) {
  static CDATA o ;
  o = "<input name=\""  + name + "\"" ;
  if ( _d1 != NULL_String )
	o += " size=" + _d1 ;
  if ( _d2 != NULL_String )
	o += " maxlength=" + _d2 ;
  if ( _val.length() )
	o += " value=\"" + _val + "\"" ;
  o += ">" ;
  return o ;
}
CDATA& form_password::render(const String& name) {
  static CDATA o ;
  o = "<input type=password name=\""  + name + "\"" ;
  if ( _d1 != NULL_String )
	o += " size=" + _d1 ;
  if ( _d2 != NULL_String )
	o += " maxlength=" + _d2 ;
  if ( _val.length() )
	o += " value=\"" + _val + "\"" ;
  o += ">" ;
  return o ;
}
CDATA& form_file::render(const String& name) {
  static CDATA o ;
  o = "<input type=file name=\""  + name + "\"" ;
  if ( _d1 != NULL_String )
	o += " size=" + _d1 ;
  if ( _d2 != NULL_String )
	o += " maxlength=" + _d2 ;
  o += ">" ;
  return o ;
}
CDATA& form_longfile::render(const String& name) {
  static CDATA o ;
  o = "<input type=file name=\""  + name + "\"" ;
  if ( _d1 != NULL_String )
	o += " size=" + _d1 ;
  if ( _d2 != NULL_String )
	o += " maxlength=" + _d2 ;
  o += ">" ;
  return o ;
}

CDATA& form_hidden::render(const String& name) {
  static CDATA o ;
  o = "<input type=hidden name=\""  + name + "\"" ;
  if ( _val.length() )
	o += " value=\"" + _val + "\"" ;
  o += ">" ;
  return o ;
}
CDATA& form_textarea::render(const String& name) {
  static CDATA o ;
  o = "<textarea name=\"" + name
    + "\" rows=" + _d1 + " cols=" + _d2
    + ">" + _val + "</textarea>" ;
  return o ;
}
CDATA& form_radio::render(const String& name) {
  static CDATA o ;
  o ="" ;
  for (Pix v = first() ; v ; next(v) ) {
    String& k = key(v) ;
    o += "<input type=radio name=\"" + name + "\" value=\"" + k ;
    if ( _val == k )
	o += "\" checked> " ;
    else
	o += "\"> " ;
    o += contents(v) + _sep ;
  }
  return o ;
}
CDATA& form_select::render(const String& name) {
  static CDATA o ;
  o = "<select name=\"" + name + "\">" ;
  for (Pix v = first() ; v ; next(v) ) {
    String& k = key(v) ;
    o = o + "<option value=\"" + k ;
    if ( _val == k )
	o += "\" selected>" ;
    else
	o += "\">" ;
    o += contents(v) ;
  }
  o += "</select>" ;
  return o ;
}
CDATA& form_submit::render(const String& name) {
  static CDATA o ;
  o = "<input type=submit" ;
  if (name.length())
	o += " name=\"" + name + "\"" ;
  if ( _val.length() )
	o += " value=\"" + _val + "\"" ;
  o += ">" ;
  return o ;
}
CDATA& form_select_multiple::render(const String& name) {
  static CDATA o ;
  o = "<select multiple name=\"" + name + "\">" ;
  for (Pix v = first() ; v ; next(v) ) {
    String k = key(v) ;
    o = o + "<option value=\"" + k ;
    if ( selected.contains(k) )
	o += "\" selected>" ;
    else
	o += "\">" ;
    o += contents(v) ;
  }
  o += "</select>" ;
  return o ;
}
form_imagemap::form_imagemap(String& name, String& img, FORM* form,
	const String& width, const String& height)
	: form_sized(img, width, height) {
/* these new's are tagged directly on the FORM, so we don't
   want a separate destructor for form_imagemap
*/
  flags |= FORM_IMAGEMAP ;
  (*form)[name + ".x"] = _x = new form_imagemap_coord(NULL_String) ;
  VERIFY(_x) ;
  (*form)[name + ".y"] = _y = new form_imagemap_coord(NULL_String) ;
  VERIFY(_y) ;
}
const int form_imagemap_coord::value() const {
  return (_val == NULL_String) ? -1 : atoi(_val) ;
}
int checkbox2i(charp in) {
  return (strlen(in) > 1) ;
}
String& checkbox(String in, const int on) {
  if (on)
	in += "=on" ;
  else
	in = "" ;
  return in ;
}
String& FEP::operator[](String& x)
	{ _->verify(FORM_OPTIONS) ; return (*(form_mc*)_)[x] ; }
String& FEP::operator[](const char* c)
	{ String x(c) ; return operator[](x) ; }


/* shove this here until we have real error management ... */
void VERIFY(void* ptr) {
  if (!ptr) {
    cerr << "Bad pointer - memory allocation failed!!!\n" ;
    exit(-1) ;
  }
}
const char* form_element::as_base64(const char* buf, int buflen) {
  const char encoding[] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  ostrstream buf64 ;
  unsigned long ul = 0 ;
  int n = 0 ;
  int lptr = 0 ;
  while ( --buflen >= 0 ) {
    unsigned char c = *buf++ ;
    ul = ( ul << 8 ) | c ;

    if ( ++n > 2 ) {
      for (n=18; n >= 0; n -= 6)
	buf64 << encoding[(ul>>n)&0x3f] ;
      lptr += 4 ;
      if ( lptr > 60 ) {
	buf64 << '\n' ;
	lptr = 0 ;
      }
      n = 0 ;
    }
  }
  switch (n) {
    case 1:
      buf64
	<< encoding[(ul>>2)&0x3f]
	<< encoding[(ul<<4)&0x30]
	<< "==" ;
      lptr += 4 ;
      break ;
    case 2:
      buf64
	<< encoding[(ul>>10)&0x3f]
	<< encoding[(ul>>4)&0x3f]
	<< encoding[(ul<<2)&0x3c]
	<< "=" ;
      lptr += 4 ;
      break ;
    default: break ;
  }
  if ( lptr )
    buf64 << '\n' ;
  buf64 << ends ;
  return STRDUP(buf64.str()) ; //	strdup not POSIX
  
}
