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
  Parse(shellParser, FILENAME, "cat");
  Parse(shellParser, FILENAME, "main.cpp");
  Parse(shellParser, PIPE, 0);
  Parse(shellParser, FILENAME, "wc");
  Parse(shellParser, 0, 0);
  ParseFree(shellParser, free);
  return 0;
}

