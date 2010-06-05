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
#ifndef FEP_H
#define FEP_H

#include <iostream.h>
#include <strstream.h>

#define FORM_ELEMENT		1
#define FORM_STRING		0x2
#define FORM_MC			0x4
#define FORM_SIZED		0x8
#define FORM_CHECKBOX		0x10
#define FORM_SELECT_MULTIPLE	0x20
#define FORM_HIDDEN		0x40
#define FORM_PASSWORD		0x80
#define FORM_INPUT		0x100
#define FORM_TEXTAREA		0x200
#define FORM_RADIO		0x400
#define FORM_SELECT		0x800
#define FORM_SUBMIT		0x1000
#define FORM_IMAGEMAP_COORD	0x2000
#define FORM_IMAGEMAP		0x4000
#define FORM_FILE		0x8000
#define FORM_OPTIONS		0x10000
#define FORM_LONGFILE		0x20000
#define FORM_STREAM		0x40000
#define FORM_SIZED_STREAM	0x80000

// hack to know the default element
#define FORM_UNSET		0x10000

typedef char* charp ;


// container classes created using GNU "genclass"
#include "String.String.AVLMap.h"
#include "String.SLBag.h"

/* decent error management reserved for future enhancement.   Taint is
   usually the most critical trouble in CGI.   Maybe this should be a
   class that complains on cerr about extracting tainted elements.
*/

typedef String CDATA ;
typedef class FORM ;

// Base class for export

typedef StringStringAVLMap Map ;
typedef StringSLBag Bag ;

extern String NULL_String ;
extern Map NULL_Map ;
extern Bag NULL_Bag ;

/* base class for all form elements.   The standalone version needs
   to contain the NAME field, but this one is for use in StringFEPMap
   FORM needs to set() and print() an arbitrary element.
*/
class form_element {
  friend class FEP ;
protected:
  virtual const char* as_base64(const char* buf, int sz) ;
  unsigned long flags ;
  form_element(FEP& e) ;
  form_element(form_element* e) { flags=e->flags; verify(e, FORM_ELEMENT) ; }
  const int verify(const form_element* p, const unsigned long bit) {
	flags = p->flags ;
	return verify(bit) ;
  }
  const int verify( const FEP&, const unsigned long) ;
/*
  const int verify(const unsigned long bit) {}
	if ( (flags & bit) != bit ) {
		cerr << "Invalid type conversion " << flags << " " << bit << endl ;
		exit(1) ;
	}
	return 1 ;
  }
*/
  const int verify(const unsigned long bit) { return bit ; }
  
  form_element() { flags = FORM_ELEMENT ; }
  virtual ~form_element() { }
public:
  virtual void set(String&) =0 ;
  virtual void set(const String& c) { String s(c) ; set(s) ; }
  virtual void set(const char* p) { String s(p) ; set(s) ; }
  virtual void set(const char* p, const int sz) { set(p-sz+sz) ; }
  virtual void set(int i, int nplaces =0) ;
  virtual void print(const String& name, ostream& o =cout)
	{ o << render(name) ; }
  virtual String& as_text() =0 ;
  virtual const char* as_longtext() { return as_text() ; }
  virtual const char* as_base64()
	{ return as_base64(as_longtext(), strlen(as_longtext())) ; }
  virtual void dump_bytes(ostream& o =cout) { o << as_longtext() ; }
  virtual String& encode(const String& name) =0;
  virtual CDATA& as_html() ;
  virtual CDATA& render(const String& name) =0 ;
  virtual form_element& operator=(charp const x)
	{ String s(x); set(s) ; return *this ; }

  virtual void add_header(String& h, String& v)
	{cerr << "Unexpected header " << h << " = " << v << endl ;}
  virtual const String& filename(const String& s =NULL_String) { return s ; }
  virtual Map& headers() { return NULL_Map ; }
  virtual const int checked() const { return 0 ; }
  virtual void add(String& s) { set(s) ; }
  virtual void add(const char* p) { String s(p) ; add(s) ; }

  virtual Bag& multi() { return NULL_Bag ; }	// select_multiple ops
  virtual void unset(String& s) { s=s; }
  virtual void clear() { }

  virtual const int x() const { return 0 ; }
  virtual const int y() const { return 0 ; }		// imagemap coords
//  virtual void print_html() { cout << as_html() ; }
  virtual const int operator!() { return ( as_text() == NULL_String ) ; }
  friend ostream& operator<<(ostream& o, form_element& f)
	{ o << f.as_text() ; return o ; }
} ;
class form_stream : public form_element {
  int bytes ;
protected:
  ostrstream _buf ;
  form_stream() { bytes = 0 ; flags |= FORM_STREAM ; }
  form_stream(form_element* x) : form_element(x)
	{ bytes = ((form_stream*)x)->bytes ; verify(x,FORM_STREAM) ; }
  ~form_stream(){}
public:
  void set(String& v) { if ( bytes > 0 ) { _buf << '\n' ; ++bytes ; }
				_buf << v ; bytes += v.length() ; }
//  void set(const char* v) { _buf << v << "\n" ; }
//  void set(const String& v) { _buf << v << "\n" ; }
  const char* as_longtext() { _buf << ends ; return _buf.str() ; }
  const char* as_base64() { return form_element::as_base64(as_longtext(), bytes) ; }
  void dump_bytes(ostream& o =cout) { o.write(as_longtext(), bytes) ; }
  String& as_text() { return NULL_String ; } // can't do more 'cos appending
					     // ends is one-way
	// { static String s ; s = as_longtext() ; return s ; }
  friend ostream& operator<<(ostream& o, form_stream& x)
	{ o.write(x.as_longtext(), x.bytes) ; return o ; }
  void set(const char* buf, const int sz)
	{ _buf.write(buf,sz) ; bytes=sz ; }
} ;
class FEP {	// wraps form_element*
  inline friend ostream& operator<< (ostream& o, FEP& f)
	{ return operator<<(o, *f._) ; }
private:
  form_element* _ ;
public:
  FEP() ; 
  FEP(form_element* x) : _(x) {}
  FEP(const FEP& x) : _(x._) {}
  ~FEP() {}
  const int is_dflt() const { return (_->flags & FORM_UNSET) ; }
  const int operator!() { return ( is_dflt() || ! *_ ) ; }

  void set (String& s) { _->set(s) ; }
  void set (const String& s) { _->set(s) ; }
  void set (const char* p) { _->set(p) ; }
  void set (const char* p, const int sz) { _->set(p, sz) ; }
  void set(int i, int nplaces =0) { _->set(i,nplaces) ; }
  void print(const String& name, ostream& o) { _->print(name,o) ; }
  String& as_text() { return _->as_text() ; }
  int as_int(const int =0) ;
  String& encode(const String& name) { return _->encode(name) ; }
  CDATA& as_html() { return _->as_html() ; }
  CDATA& render(const String& name) { return _->render(name) ; }
  form_element& operator=(form_element& x) { return _->operator=(x) ; }
  void add_header(String& h, String& v) { _->add_header(h, v) ; }
  const String& filename ( const String& s =NULL_String)
		{ return _->filename(s) ; }
  Map& headers() { return _->headers() ; }
  const int checked() const { return _->checked() ; }
  void add(String& s) { _->add(s) ; }
  void add(const char* p) { _->add(p) ; }
  void destruct() ;

  const form_element* operator()() const { return _;}
  form_element* operator()() { return _;}

  Bag& multi() { return _->multi() ; }
  void unset(String& s) { _->unset(s) ; }
  void clear() { _->clear() ; }

  const int x() { return _->x() ; }
  const int y() { return _->y() ; }

  String& operator[](String& x) ;
  String& operator[](const char* x) ;
  const char* as_longtext() { return _->as_longtext() ; }
  const char* as_base64() { return _->as_base64() ; }
  void dump_bytes(ostream& o =cout) { _->dump_bytes(o) ; }
						// binary upload data:
						// the only way to deal with NUL
//  void print_html() { _->print_html() ; }

} ;
inline const int form_element::verify(const FEP& f, const unsigned long l) {
	return verify(f(),l) ;
}
inline form_element::form_element(FEP& p)
	{ flags=p()->flags; verify(p, FORM_ELEMENT) ; }

// base class for all form elements whose VALUE is a string
class form_string : public form_element {
protected:
  String _val ;
  form_string(String& v) { set(v) ; flags |= FORM_STRING ; }
  form_string(form_element* x) : form_element(x)
	{ verify(x,FORM_STRING) ; _val = ((form_string*)x)->_val ; }
  virtual ~form_string(){}
public:
  virtual void set(String& v) { _val = v ; }
  virtual void add(String& v) { _val += v ; }
  virtual String& as_text() { return _val ; }
  virtual String& encode(const String&) ;
} ;

/* give a MAP a name and an unobtrusive constructor.   Serves as
   base class for everything with different internal and external
   STRING representations
   Use charp (=char*) rather than String to make things like
	options["name 1"] = "value 1" ;
   work without an extra copy to convert to String
*/
class form_options : public Map {
protected:
  form_options(form_element* v) : Map(NULL_String)
	{
	  form_options* z = (form_options*)v ;
		for (Pix x = z->first(); x; z->next(x))
		(*this)[z->key(x)] = z->contents(x) ; }
  form_options(String& m) : Map(m) { }
  virtual ~form_options() {}
public:
  String& operator[](char const* x)
	{ static String s; s=x; return Map::operator[](s) ; }
} ;


// Base class for multiple-choice form inputs (SELECT and RADIO buttons)
class form_mc : public form_string, public form_options {
protected:
  form_mc(String& v) : form_string(v) , form_options(NULL_String)
	{ flags |= FORM_MC ; }
  form_mc(form_element* v) : form_string(v) , form_options(v)
	{ verify(v, FORM_MC) ; }
/*
	{ verify(v, FORM_MC) ; form_mc* z = (form_mc*)v ;
		for (Pix x = z->first(); x; z->next(x))
		(*this)[z->key(x)] = z->contents(x) ; }
*/
  virtual ~form_mc() {}
} ;

class form_sized : public form_string {
protected:
  String _d1,_d2 ;		// if null you get browser defaults
  form_sized(String& v, const String& l =NULL_String, const String& m =NULL_String)
	: form_string(v)
	{ _d1 = l ; _d2 = m ; flags |= FORM_SIZED ; }
  form_sized(form_element* x) : form_string(x) {
	verify(x,FORM_SIZED) ;
	_d2 = ((form_sized*)x)->_d2 ;
	_d1 = ((form_sized*)x)->_d1 ;
  }
  virtual ~form_sized() {}
} ;
class form_sized_stream : public form_stream {
protected:
  String _d1,_d2 ;		// if null you get browser defaults
  form_sized_stream(const String& l =NULL_String, const String& m =NULL_String)
	{ _d1 = l ; _d2 = m ; flags |= FORM_SIZED_STREAM ; }
  form_sized_stream(form_element* x) : form_stream(x) {
	verify(x,FORM_SIZED_STREAM) ;
	_d2 = ((form_sized_stream*)x)->_d2 ;
	_d1 = ((form_sized_stream*)x)->_d1 ;
  }
  ~form_sized_stream() {}
} ;

/* An "unknown" class is required when reading a form element that the
   user hasn't defined in a template.   Assume the VALUE to be a plain
   string, and we can't render it in HTML.   To get some passable
   behaviour, use form_input or form_hidden.
#ifdef DEBUG
#define form_unknown form_input
#else
#define form_unknown form_hidden
#endif
*/
#define form_unknown form_input

/* ==========================================================
		FORM ELEMENTS
   ==========================================================
*/
class form_checkbox : public form_element {
private:
  int onoff ;
public:
  form_checkbox(String& s) {set (s) ; flags |= FORM_CHECKBOX ; }
  form_checkbox(form_element* v) : form_element(v)
	{ verify(v, FORM_CHECKBOX) ; onoff = ((form_checkbox*)v)->onoff ; }
  ~form_checkbox() {}
  void set(String& s)
	{ onoff = s.length() ; }
  const int checked() const { return onoff ; }
  String& as_text() ;
  CDATA& render(const String&) ;
  String& encode(const String&) ;
} ;

class form_select_multiple : public form_element, public form_options {
private:
  Bag selected ;	// less overhead than a Set
public:
  form_select_multiple(String& s) : form_options(s)
	 {set(s) ; flags |= FORM_SELECT_MULTIPLE ; }
  ~form_select_multiple(){}
  void set(const char* p) { String s(p) ; set(s) ; }
  void set(String& s)
	{ selected.add(s) ; }
  form_select_multiple(form_element* v) : form_element(v), form_options(v) {
	verify(v, FORM_SELECT_MULTIPLE) ;
	selected = ((form_select_multiple*)v)->selected ;
  }
/* ?? allow manipulation of value() - return non-const LValue */
  Bag& value() { return selected ; }	// back-compatibility only
  Bag& multi() { return selected ; }
  void unset(String& s) { selected.remove(s) ; }
  void clear() { selected.clear() ; }
  String& as_text() ;
  CDATA& as_html() ;
  CDATA& render(const String&) ;
  String& encode(const String&) ;
} ;

class form_hidden : public form_string {
public:
  form_hidden(String& v) : form_string(v) { flags |= FORM_HIDDEN ; }
  form_hidden(form_element* v) : form_string(v) { verify(v,FORM_HIDDEN) ; }
  ~form_hidden(){}
  CDATA& render(const String&) ;
} ;
class form_password : public form_sized {
public:
  form_password(String& v, const String& l =NULL_String, const String& m =NULL_String)
	: form_sized(v,l,m)
	{ flags |= FORM_PASSWORD ; }
  form_password(form_element* v) : form_sized(v)
	{ verify(v,FORM_PASSWORD) ; }
  ~form_password(){}
  CDATA& render(const String&) ;
} ;
class form_input : public form_sized {
public:
  form_input(String& v, const String& l =NULL_String, const String& m =NULL_String)
	: form_sized(v,l,m)
	{ flags |= FORM_INPUT ;  }
  form_input(form_element* v) : form_sized(v) { verify(v,FORM_INPUT) ; }
  ~form_input(){}
  CDATA& render(const String&) ;
} ;
class form_textarea : public form_sized {
public:
  form_textarea(String& v, const String& l, const String& m)
	: form_sized(v,l,m)
	{ flags |= FORM_TEXTAREA ;  }
  form_textarea(form_element* v) : form_sized(v)
	{ verify(v,FORM_TEXTAREA) ; }
  ~form_textarea(){}
  CDATA& render(const String&) ;
  void add(const String& s) { _val += s ; }
} ;
class form_radio : public form_mc {
  String _sep ;
public:
  form_radio(String& v, const String& sep ="<br>")
	: form_mc(v) , _sep(sep) { flags |= FORM_RADIO ;  }
  form_radio(form_element* v) : form_mc(v)
	{ verify(v,FORM_RADIO) ; _sep = ((form_radio*)v)->_sep ; }
  ~form_radio(){}
  void separator(String& sep) { _sep = sep ; }
  CDATA& render(const String&) ;
} ;
class form_select : public form_mc {
public:
  form_select(String& v) : form_mc(v) { flags |= FORM_SELECT ; }
  form_select(form_element* v) : form_mc(v) { verify(v,FORM_SELECT) ; }
  ~form_select(){}
  CDATA& render(const String&) ;
} ;
class form_submit : public form_string {
public:
  String& render(const String&) ;
  form_submit(String& v) : form_string(v) { flags |= FORM_SUBMIT ; }
  form_submit(form_element* v) : form_string(v) { verify(v,FORM_SUBMIT) ; }
  ~form_submit(){}
} ;
/* an imagemap "foo" defines form elements "foo.x" and "foo.y".
   We need to set those - else FORM will class them as "unknown".
   Incorporating into this implementation is a botch job
*/
class form_imagemap_coord : public form_string {
  friend class form_imagemap ;
private:
  form_imagemap_coord(String& s) : form_string(s) { ; }
  const int value() const ; // WARNING: CGI++ doesn't check for bad input!
public:
  CDATA& render(const String&) { return NULL_String ; }
  String& encode(const String&) ;
  ~form_imagemap_coord(){}
} ;
class form_imagemap : public form_sized {
private:
  form_imagemap_coord* _x ;
  form_imagemap_coord* _y ;
public:
  form_imagemap(String& name, String& img, FORM* form, const String&,const String&) ;
  form_imagemap(form_element* v) : form_sized(v) {
	verify(v,FORM_IMAGEMAP) ;
	_x = ((form_imagemap*)v)->_x ;
	_y = ((form_imagemap*)v)->_y ;
  }
  ~form_imagemap(){}
  const int x() const { return _x->value() ; }
  const int y() const { return _y->value() ; }
  CDATA& render(const String&) ;
  String& as_text() ;
  String& encode(const String&) { return NULL_String ; }
} ;
class form_file : public form_sized {
private:
  String _filename ;
  Map _headers ;
public:
  const String& filename (const String& n =NULL_String)
	{ if (n != "") _filename = n ; return _filename ; }
  CDATA& render(const String&) ;
  form_file(String& v, const String& l =NULL_String, const String& m =NULL_String)
	: form_sized(v,l,m) , _headers(NULL_String)
	{ _filename = NULL_String ; flags |= FORM_FILE ;  }
  form_file(form_element* v) : form_sized(v) , _headers(NULL_String)
	{ verify(v,FORM_FILE) ; }
  ~form_file(){}
  CDATA& as_html() ;
  
  Map& headers() { return _headers ; }
  void add_header(String& h, String& v)
	{ _headers[h] = v ; }
} ;
class form_longfile : public form_sized_stream {
private:
  String _filename ;
  Map _headers ;
public:
  const String& filename (const String& n =NULL_String)
	{ if (n != "") _filename = n ; return _filename ; }
  form_longfile(const String& l =NULL_String, const String& m =NULL_String)
	: form_sized_stream(l,m) , _headers(NULL_String)
	{ _filename = NULL_String ; flags |= FORM_LONGFILE ;  }
  form_longfile(form_element* v) : form_sized_stream(v) , _headers(NULL_String)
	{ verify(v,FORM_LONGFILE) ; }
  ~form_longfile(){}
  String& encode(const String&) { return NULL_String ; }
  CDATA& render(const String&) ;
//  void print_html() ;
  const int operator!() { return strlen(as_longtext()) <= 2 ; }
  
  Map& headers() { return _headers ; }
  void add_header(String& h, String& v)
	{ _headers[h] = v ; }
} ;

/* class form_unset is for internal use only */
class form_unset : public form_element {
/* functions needed to instantiate it... they are never called, but we
    abuse the NULL_String to shut up compiler warnings
*/
  String& as_text() { return NULL_String ; }
  String& encode(const String& s) { String x(s) ; return NULL_String ; }
  CDATA& render(const String& s) { String x(s) ; return NULL_String ; }
  void set(String& s) { s=s; }
public:
  form_unset() { flags |= FORM_UNSET ; }
  ~form_unset() {}
} ;
extern const FEP DFLT_FEP ;
inline FEP::FEP() { _ = DFLT_FEP._ ; }

/* form_reset will never come from a form, so it doesn't need an object -
   just a reset method in the FORM class.
*/


/* shove this here until we have real error management */
void VERIFY(void* ptr) ;
  
#endif
