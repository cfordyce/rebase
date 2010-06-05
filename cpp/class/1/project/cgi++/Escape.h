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
#ifndef WWWESCAPE_H
#define WWWESCAPE_H
#include <String.h>

// edit strings in-place
String& www_escape(String&) ;
String& www_unescape(String&) ;
String& html_escape(String&) ;

// make and return a copy if called with const argument
const String& www_escape(const String& s) ;
const String& www_unescape(const String& s) ;
const String& html_escape(const String& s) ;

// allow calling with char*
const char* html_escape(char const*) ;
String& www_escape(char const*) ;
String& www_unescape(char const*) ;

#endif

