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
#ifndef FORM_H
#define FORM_H

#include "String.FEP.VHMap.h"
#include "FEP.h"

class FORM : public StringFEPVHMap {
  char _delimiter ;	// for define() and set_template()
public:
  FORM() : StringFEPVHMap(DFLT_FEP){ _delimiter=':';}
  ~FORM() ;
  void set_template(const String&) ;
  void define(int, ...) ;

  void set_delimiter(const char d) { _delimiter = d ; }
  FEP& operator[](char const*x)
	{ String s(x) ; return StringFEPVHMap::operator[](s) ; }

  const CDATA& start(const char * const,
		const char* const ="POST",
		const char* const =0) const ;
  const CDATA& submit(const char* const ="OK") const ;
  const CDATA& reset(const char* const ="Cancel") const ;
  const CDATA& end() const ;

  const CDATA& render(char* element)
	{ return ((*this)[element]).render(element) ; }

  const String& dump_as_text() ;
  const CDATA& dump_as_html(charp const, charp const ="POST",
	charp const =0) ;
} ;

#endif
