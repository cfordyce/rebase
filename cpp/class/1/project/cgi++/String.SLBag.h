// This may look like C code, but it is really -*- C++ -*-
/* 
Copyright (C) 1988 Free Software Foundation
    written by Doug Lea (dl@rocky.oswego.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/


#ifndef _StringSLBag_h
#ifdef __GNUG__
#pragma interface
#endif
#define _StringSLBag_h 1

#include "String.Bag.h"
#include "String.SLList.h"

class StringSLBag : public StringBag
{
protected:
  StringSLList     p;

public:
                StringSLBag();
                StringSLBag(const StringSLBag&);

  inline Pix           add(String& item);
  void          del(String& item);
  void          remove(String&item);
  inline int           contains(String& item);
  int           nof(String& item);

  inline void          clear();

  inline Pix           first();
  inline void          next(Pix& i);
  inline String&          operator () (Pix i);
  inline int           owns(Pix i);
  Pix           seek(String& item, Pix from = 0);

  int           OK();
};


inline StringSLBag::StringSLBag() : p() { count = 0; }

inline StringSLBag::StringSLBag(const StringSLBag& s) : p(s.p) { count = s.count; }

inline Pix StringSLBag::first()
{
  return p.first();
}

inline void StringSLBag::next(Pix  & idx)
{
  p.next(idx);
}

inline String& StringSLBag::operator ()(Pix   idx)
{
  return p(idx);
}

inline void StringSLBag::clear()
{
  count = 0;  p.clear();
}

inline int StringSLBag::owns (Pix   idx)
{
  return p.owns(idx);
}

inline Pix StringSLBag::add(String& item)
{
  ++count;
  return p.append(item);
}

inline int StringSLBag::contains(String& item)
{
  return seek(item) != 0;
}

#endif
