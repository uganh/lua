#include <istream>

namespace lua {
enum Token {
  T_EQ,
  T_LE,
  T_GE,
  T_NE,
  T_SHL,
  T_SHR,
  T_IDIV,
  T_STRING,
};

class Lexer {
  std::istream &in;
  int peek;
  unsigned lineno;

public:
  Lexer(std::istream &in) : in(in), peek(in.get()), lineno(1) {}

  int scan(void);
};

int Lexer::scan(void) {
  while (true) {
    switch (peek) {
      case '\n':
      case '\r':
      /* Spaces */
      case ' ':
      case '\f':
      case '\t':
      case '\v':
        peek = in.get();
        break;
      case '-':
        peek = in.get();
        if (peek != '-') {
          return '-';
        }
        /* '--' comment */
        // peek = in.get();
        // if (peek == '[') {
        //   /* Long comment */
        // }
      case '[':
      case '=':
        peek = in.get();
        if (peek == '=') {
          return T_EQ;
        }
        return '=';
      case '<':
        peek = in.get();
        if (peek == '=') {
          return T_LE;
        }
        else if (peek == '<') {
          return T_SHL;
        }
        return '<';
      case '>':
        peek = in.get();
        if (peek == '=') {
          return T_GE;
        }
        else if (peek == '>') {
          return T_SHR;
        }
        return '>';
      case '/':
        peek = in.get();
        if (peek == '/') {
          return T_IDIV;
        }
        return '/';
      case '~':
        peek = in.get();
        if (peek == '=') {
          return T_NE;
        }
        return '~';
      case ':':
        break;
      case '"':
      case '\'':
        return T_STRING;
      case '.':
        break;
      case EOF:
        break;
    }
  }
}
}