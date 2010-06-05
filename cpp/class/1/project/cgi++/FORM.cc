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
#include "FORM.h"
#include "FileStream.h"

FORM::~FORM() {
  for (Pix x=first(); x; next(x))
    contents(x).destruct() ;
}

void FORM::define(int n, ...) {
  if ( n <= 0) return ;
  va_list templ ;
  va_start (templ, n) ;
  for (charp s = va_arg(templ, charp); n-- ; s = va_arg(templ,charp) )
    set_template(s) ;
  va_end(templ) ;
}
void FORM::set_template(const String& templ) {
  String parse[5] ;
  split(templ, parse, 5, _delimiter) ;
  String& name = parse[0] ;
  String& type = parse[1] ;
  String& value = parse[2] ;
  String& n1 = parse[3] ;
  String& n2 = parse[4] ;

  if ( type == "input" )
	(*this)[name] = new form_input(value,n1,n2) ;
  else if ( type == "hidden" )
	(*this)[name] = new form_hidden(value) ;
  else if ( type == "password" )
	(*this)[name] = new form_password(value,n1,n2) ;
  else if ( type == "select" )
	(*this)[name] = new form_select(value) ;
  else if ( type == "radio" )
	(*this)[name] = new form_radio(value,n1) ;
  else if ( type == "textarea" )
	(*this)[name] = new form_textarea(value,n1,n2) ;
  else if ( type == "submit" )
	(*this)[name] = new form_submit(value) ;
  else if ( type == "checkbox" )
	(*this)[name] = new form_checkbox(value) ;
  else if ( type == "select_multiple" )
	(*this)[name] = new form_select_multiple(value) ;
  else if ( type == "imagemap" )
	(*this)[name] = new form_imagemap(name, value, this, n1, n2) ;
  else if ( type == "file" )
	(*this)[name] = new form_file(NULL_String, n1, n2) ;
  else if ( type == "longfile" )
	(*this)[name] = new form_longfile(n1, n2) ;
  else {
	(*this)[name] = new form_unknown(value) ;
#ifdef DEBUG
	cerr << templ << ": Error at " << name << ": type "
		<< type << " unknown\n" ;
#endif
  }
  VERIFY((*this)[name]()) ;
}
const String& FORM::dump_as_text() {
  static String dump ;
  dump = "" ;
  for (Pix x = first() ; x ; next(x) )
    dump = dump + key(x) + " = "
	+ contents(x).as_text() + "\n" ;
  return dump ;
}
const CDATA& FORM::dump_as_html(charp const name,
	charp const meth, charp const enc) {
  static CDATA dump ;
  dump = start(name, meth, enc)
	+ "<table border=1><caption><big><b>Elements of your Form</b></big></caption>"
	+ "<tr><th>Name</th><th>Value</th><th>Rendition<br></th></tr>" ;
  for (Pix x = first() ; x ; next(x) ) {
    FEP& p = contents(x) ;
    dump = dump + "<tr><th>" + key(x) + "</th><td>"
	+ p.as_html() + "</td><td>"
	+ p.render(key(x)) + "<br></td></tr>" ;
  }
  dump += "</table>" + end() ;
  return dump ;
}
const CDATA& FORM::start(const char* const action,
	const char* const method, const char* const enctype) const {
  static CDATA s ;
  s = "<form action=\"" ;
  s = s + action + "\" method=\"" + method ;
  if (enctype)
    s = s + "\" enctype=\"" + enctype ;
  s = s+"\">" ;
  return s ;
}
const CDATA& FORM::end() const {
  static CDATA s("</form>") ;
  return s ;
}
const CDATA& FORM::submit(const char* const s) const {
  static CDATA o ;
  o = "<input type=submit value=\"" ;
  o = o + s + "\">" ;
  return o ;
}
const CDATA& FORM::reset(const char* const s) const {
  static CDATA o ;
  o = "<input type=reset value=\"" ;
  o = o + s + "\">" ;
  return o ;
}
