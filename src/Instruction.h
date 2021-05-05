#pragma once

namespace lua {
enum Opcode {
  MOVE,
  LOADI,
  LOADF,
  LOADK,
  LOADKX,
  LOADFALSE,
  LFALSESKIP,
};
}