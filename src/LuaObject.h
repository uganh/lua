#pragma once

namespace lua {
class LuaObject {
  enum {
    
  } t;

  union {
    
    void *p;  /* Light userdata */
    long i;   /* Integer */
    double n; /* Float */
  };
};
}