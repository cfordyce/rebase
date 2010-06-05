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


#ifndef _StringStringAVLMap_h
#ifdef __GNUG__
#pragma interface
#endif
#define _StringStringAVLMap_h 1

#include "String.String.Map.h"

struct StringStringAVLNode
{
  StringStringAVLNode*      lt;
  StringStringAVLNode*      rt;
  String                 item;
  String                 cont;
  char                stat;
                      StringStringAVLNode(String& h, String& c, 
                                    StringStringAVLNode* l=0, StringStringAVLNode* r=0);
                      ~StringStringAVLNode();
};

inline StringStringAVLNode::StringStringAVLNode(String& h, String& c, 
                                    StringStringAVLNode* l, StringStringAVLNode* r)
     :lt(l), rt(r), item(h), cont(c), stat(0) {}

inline StringStringAVLNode::~StringStringAVLNode() {}

typedef StringStringAVLNode* StringStringAVLNodePtr;


class StringStringAVLMap : public StringStringMap
{
protected:
  StringStringAVLNode*   root;

  StringStringAVLNode*   leftmost();
  StringStringAVLNode*   rightmost();
  StringStringAVLNode*   pred(StringStringAVLNode* t);
  StringStringAVLNode*   succ(StringStringAVLNode* t);
  void            _kill(StringStringAVLNode* t);
  void            _add(StringStringAVLNode*& t);
  void            _del(StringStringAVLNode* p, StringStringAVLNode*& t);

public:
                StringStringAVLMap(String& dflt);
                StringStringAVLMap(StringStringAVLMap& a);
  inline               ~StringStringAVLMap();

  String&          operator [] (String& key);

  void          del(String& key);

  inline Pix           first();
  inline void          next(Pix& i);
  inline String&          key(Pix i);
  inline String&          contents(Pix i);

  Pix           seek(String& key);
  inline int           contains(String& key);

  inline void          clear(); 

  Pix           last();
  void          prev(Pix& i);

  int           OK();
};

inline StringStringAVLMap::~StringStringAVLMap()
{
  _kill(root);
}

inline StringStringAVLMap::StringStringAVLMap(String& dflt) :StringStringMap(dflt)
{
  root = 0;
}

inline Pix StringStringAVLMap::first()
{
  return Pix(leftmost());
}

inline Pix StringStringAVLMap::last()
{
  return Pix(rightmost());
}

inline void StringStringAVLMap::next(Pix& i)
{
  if (i != 0) i = Pix(succ((StringStringAVLNode*)i));
}

inline void StringStringAVLMap::prev(Pix& i)
{
  if (i != 0) i = Pix(pred((StringStringAVLNode*)i));
}

inline String& StringStringAVLMap::key(Pix i)
{
  if (i == 0) error("null Pix");
  return ((StringStringAVLNode*)i)->item;
}

inline String& StringStringAVLMap::contents(Pix i)
{
  if (i == 0) error("null Pix");
  return ((StringStringAVLNode*)i)->cont;
}

inline void StringStringAVLMap::clear()
{
  _kill(root);
  count = 0;
  root = 0;
}

inline int StringStringAVLMap::contains(String& key)
{
  return seek(key) != 0;
}

#endif
