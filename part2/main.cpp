#include <cstdlib>
#include <iostream>
#include <string>
#include "shellparser.hpp"
#include "shellscanner.yy.hpp"
using namespace std;
 
void* ParseAlloc(void* (*allocProc)(size_t));
void Parse(void*, int, const char*);
void ParseFree(void*, void(*freeProc)(void*));
 
void parse(const string& commandLine) {
    // Set up the scanner
    yyscan_t scanner;
    yylex_init(&scanner);
    YY_BUFFER_STATE bufferState = yy_scan_string(commandLine.c_str(), scanner);
 
    // Set up the parser
    void* shellParser = ParseAlloc(malloc);
 
    int lexCode;
    do {
        lexCode = yylex(scanner);
        Parse(shellParser, lexCode, NULL);
    }
    while (lexCode > 0);
 
    if (-1 == lexCode) {
        cerr << "The scanner encountered an error.\n";
    }
 
    // Cleanup the scanner and parser
    yy_delete_buffer(bufferState, scanner);
    yylex_destroy(scanner);
    ParseFree(shellParser, free);
}
 
int main() {
    string commandLine;
    while (getline(cin, commandLine)) {
        parse(commandLine);
    }
    return 0;
}
