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
#include "Text.h"

void Text::localtext(String& s) {
/* convert _something_ to <em>something</em>, etc */
  int pos, xpos ;
  const Regex em("[ \t\n]_[^_ \t\n]") ;
  const Regex xem("[^_ \t\n]_[ \t\n]") ;
  for (pos = s.index(em) ; pos >= 0 ; pos = s.index(em, ++pos))
    if ( xpos = s.index(xem, pos) , xpos > pos ) {
      s.at(pos+1,1) = "<em>" ;
      xpos = s.index('_',xpos) ;
      s.at(xpos,1) = "</em>" ;
      pos = xpos ;
    }

  const Regex strong("[ \t\n]\\*[^* \t\n]") ;
  const Regex xstrong("[^* \t\n]\\*[ \t\n]") ;
  for (pos = s.index(strong) ; pos >= 0 ; pos = s.index(strong, ++pos))
    if ( xpos = s.index(xstrong, pos) , xpos > pos ) {
      s.at(pos+1,1) = "<strong>" ;
      xpos = s.index('*',xpos) ;
      s.at(xpos,1) = "</strong>" ;
      pos = xpos ;
    }
}
String& Text::smart() {
  String tmp ;
  gsub("\r","") ;
  const Regex url("<[Uu][Rr][Ll]:[^<>]+>",1) ;
  int lastpos = -1 ;
  int pos ;
  for (pos = index(url); pos >= 0; pos = index(url,lastpos)) {
    if ( lastpos >= 0 )
      before(pos) = before(lastpos)
	+ html_escape((tmp=before(pos),tmp=tmp.from(lastpos),tmp)) ;
    else
      before(pos) = html_escape((tmp=before(pos),tmp)) ;
    tmp = after((pos=index(url,pos),pos+4)) ;
    tmp = tmp.before(">") ;
    int oldlen = tmp.length()+6 ;
    tmp.gsub(RXwhite,"") ;
    String repl("&lt;URL:<a href=\"" + tmp + "\">" + tmp + "</a>&gt;") ;
    at(pos,oldlen) = repl ;
    lastpos = pos + repl.length() ;
  }
  if ( lastpos < (int)length() )
    after(lastpos) = html_escape((tmp=after(lastpos),tmp)) ;

  const Regex blankline("\n\n+") ;
  int npara = freq("\n\n")+1 ;		// too many isn't a problem
  String* para = new String[npara] ;
  npara = split(*this, para, npara, blankline) ;

  const Regex format("\n[^A-Za-z0-9<(]\\|\t", 1) ;

  tmp = "" ;
  for (int i=0; i<npara; ++i) {
    localtext(para[i]) ;
    if ( para[i].contains(format) )
	tmp += "<pre>" + para[i] + "</pre>" ;
    else {
      Regex br("[:?!,;.-]\n") ;
      for (pos = para[i].index(br) ; pos >= 0 ;
		pos = para[i].index(br,pos+5))
	para[i].at(pos+1,1) = "<br>" ;
	tmp += "<p>" + para[i] + "</p>" ;
    }
  }
  delete[] para ;
  *this = tmp ;
  gsub("-- ", "-- <br>") ;
  return *this ;
}
