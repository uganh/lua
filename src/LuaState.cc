#include "LuaState.h"

#define lock() 0
#define unlock() 0

// #define LUA_

// #define LUA_REGISTRYINDEX 

// #define ispseudo(idx) ((idx) <= LUA_REGISTRYINDEX)

namespace lua {
int LuaState::absindex(int idx) const {
  return idx >= 0 ? idx : idx + stack.size();
}

int LuaState::gettop(void) const {
  return stack.size();
}

void LuaState::pushvalue(int idx) {
  lock();

  
}
}