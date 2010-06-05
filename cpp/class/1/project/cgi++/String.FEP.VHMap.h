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


#ifndef _StringFEPVHMap_h
#ifdef __GNUG__
#pragma interface
#endif
#define _StringFEPVHMap_h 1

#include "String.FEP.Map.h"


class StringFEPVHMap : public StringFEPMap
{
protected:
  String*           tab;
  FEP*           cont;
  char*          status;
  unsigned int   size;

public:
                StringFEPVHMap(FEP  dflt,unsigned int sz=DEFAULT_INITIAL_CAPACITY);
                StringFEPVHMap(StringFEPVHMap& a);
  inline               ~StringFEPVHMap();

  FEP&          operator [] (String& key);

  void          del(String& key);

  Pix           first();
  void          next(Pix& i);
  inline String&          key(Pix i);
  inline FEP&          contents(Pix i);

  Pix           seek(String& key);
  inline int           contains(String& key);

  void          clear(); 
  void          resize(unsigned int newsize = 0);

  int           OK();
};

inline StringFEPVHMap::~StringFEPVHMap()
{
  delete [] tab;
  delete [] cont;
  delete [] status;
}

inline int StringFEPVHMap::contains(String& key)
{
  return seek(key) != 0;
}

inline String& StringFEPVHMap::key(Pix i)
{
  if (i == 0) error("null Pix");
  return *((String*)i);
}

inline FEP& StringFEPVHMap::contents(Pix i)
{
  if (i == 0) error("null Pix");
  return cont[((unsigned)(i) - (unsigned)(tab)) / sizeof(String)];
}

#endif
