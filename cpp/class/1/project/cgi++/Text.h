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
#ifndef TEXT_H
#define TEXT_H
#include "Escape.h"

class Text : public String {
private:
  void localtext(String& s) ;
public:
  Text(const String& s) : String(s) {}
  Text(const char* s) : String(s) {}
  String& html() { return *this ; }
  String& plain() {
	*this = "<pre>" + html_escape((String&)*this) + "</pre>" ;
	return *this ;
  }
  String& smart() ;
  String& as(const String& type) {
    if ( type == "plain")
	return plain() ;
    else if ( type == "smart")
	return smart() ;
    else
	return html() ;
  }
} ;
#endif
