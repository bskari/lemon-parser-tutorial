%include
{
 #include <cassert>
 #include <iostream>
}

%syntax_error
{
  std::cerr << "Error parsing command\n";
}

%token_type {const char*}

start ::= commandList .
commandList ::= command PIPE commandList .
{
}
commandList ::= command .
{
}

command ::= PROGRAM argumentList .
{
}
command ::= PROGRAM .
{
}

argumentList ::= ARGUMENT argumentList .
{
}
argumentList ::= ARGUMENT .
{
}

