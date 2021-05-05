#ifndef LUA_VALUE_H
#define LUA_VALUE_H

namespace lua {

class LuaValue {
public:
  virtual ~LuaValue(void) noexcept = default;
};

} // namespace lua

#endif