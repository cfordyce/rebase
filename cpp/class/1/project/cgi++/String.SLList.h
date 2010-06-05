// This may look like C code, but it is really -*- C++ -*-
// WARNING: This file is obsolete.  Use ../SLList.h, if you can.
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


#ifndef _StringSLList_h
#ifdef __GNUG__
#pragma interface
#endif
#define _StringSLList_h 1

#include <Pix.h>
#include "String.defs.h"

#ifndef _StringSLListNode_h
#define _StringSLListNode_h 1

struct StringSLListNode
{
  StringSLListNode*         tl;
  String                    hd;
                         StringSLListNode() { }
                         StringSLListNode(const String& h, StringSLListNode* t = 0);
                         ~StringSLListNode() { }
};


inline StringSLListNode::StringSLListNode(const String& h, StringSLListNode* t)
:tl(t), hd(h) {}

typedef StringSLListNode* StringSLListNodePtr;

#endif


class StringSLList
{
protected:
  StringSLListNode*        last;

public:
                        StringSLList();
                        StringSLList(const StringSLList& a);
                        ~StringSLList();

  StringSLList&            operator = (const StringSLList& a);

  int                   empty();
  int                   length();

  void                  clear();

  Pix                   prepend(String& item);
  Pix                   append(String& item);

  void                  join(StringSLList&);

  Pix                   prepend(StringSLListNode*);
  Pix                   append(StringSLListNode*);

  String&                  operator () (Pix p);
  Pix                   first();
  void                  next(Pix& p);
  int                   owns(Pix p);
  Pix                   ins_after(Pix p, String& item);
  void                  del_after(Pix p);

  String&                  front();
  String&                  rear();
  String                   remove_front();
  int                   remove_front(String& x);
  void                  del_front();

  void                  error(const char* msg);
  int                   OK();
};

inline StringSLList::~StringSLList()
{
  clear();
}

inline StringSLList::StringSLList()
{
  last = 0;
}

inline int StringSLList::empty()
{
  return last == 0;
}


inline Pix StringSLList::first()
{
  return (last == 0)? 0 : Pix(last->tl);
}

inline void StringSLList::next(Pix& p)
{
  p = (p == 0 || p == last)? 0 : Pix(((StringSLListNode*)(p))->tl);
}

inline String& StringSLList::operator () (Pix p)
{
  if (p == 0) error("null Pix");
  return ((StringSLListNode*)(p))->hd;
}

inline String& StringSLList::front()
{
  if (last == 0) error("front: empty list");
  return last->tl->hd;
}

inline String& StringSLList::rear()
{
  if (last == 0) error("rear: empty list");
  return last->hd;
}

#endif
