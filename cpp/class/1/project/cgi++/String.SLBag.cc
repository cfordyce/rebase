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

#ifdef __GNUG__
#pragma implementation
#endif
#include "String.SLBag.h"

int StringSLBag::OK()
{
  int v = p.OK();
  v &= count == p.length();
  if (!v) error("invariant failure");
  return v;
}

Pix StringSLBag::seek(String& item, Pix i)
{
  if (i == 0) i = first(); else next(i);
  for (; i != 0 && (!(StringEQ(p(i), item))); p.next(i));
  return i;
}

int StringSLBag::nof(String& item)
{
  int n = 0;
  for (Pix p = first(); p; next(p)) if (StringEQ((*this)(p), item)) ++n;
  return n;
}


void StringSLBag::del(String& item)
{
  Pix i = p.first();
  if (i == 0) 
    return;
  else if (StringEQ(p(i), item))
  {
    --count;
    p.del_front();
  }
  else
  {
    Pix trail = i;
    p.next(i);
    while (i != 0)
    {
      if (StringEQ(p(i), item))
      {
        --count;
        p.del_after(trail);
        return;
      }
      trail = i;
      p.next(i);
    }
  }
}    

void StringSLBag::remove(String& item)
{
  Pix i = p.first();
  while (i != 0 && StringEQ(p(i), item))
  {
    --count;
    p.del_front();
    i = p.first();
  }
  if (i != 0)
  {
    Pix trail = i;
    p.next(i);
    while (i != 0)
    {
      if (StringEQ(p(i), item))
      {
        --count;
        p.del_after(trail);
        i = trail;
        p.next(i);
      }
      else
      {
        trail = i;
        p.next(i);
      }
    }
  }
}    

