#include <cstdlib>
#include <iostream>
#include "shellparser.h"
using namespace std;

void* ParseAlloc(void* (*allocProc)(size_t));
void* Parse(void*, int, const char*);
void* ParseFree(void*, void(*freeProc)(void*));

int main()
{
  void* shellParser = ParseAlloc(malloc);
  // Simulate a command line such as "cat main.cpp | wc"
  Parse(shellParser, PROGRAM, "cat");
  Parse(shellParser, ARGUMENT, "main.cpp");
  Parse(shellParser, PIPE, 0);
  Parse(shellParser, PIPE, 0);
  Parse(shellParser, PROGRAM, "wc");
  ParseFree(shellParser, free);
  return 0;
}

