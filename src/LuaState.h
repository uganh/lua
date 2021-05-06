#pragma once

#include "LuaObject.h"

#include <vector>

namespace lua {


class LuaState {
  std::vector<LuaObject> stack;

public:
  static LuaState *create(void);

  /* Basic stack manipulation */

  /*
  ** Convert an acceptable stack index into an absolute index
  */
  int absindex(int idx) const;


  int gettop(void) const;
  void settop(int idx);
  void pushvalue(int idx);
  void rotate(int idx, int n);
  void copy(int fromidx, int toidx);
  int checkstack(int n);
  
  void xmove(LuaState *to, int n);
};
}