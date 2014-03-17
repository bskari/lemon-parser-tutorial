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

command ::= ARGUMENT argumentList .
{
}
command ::= ARGUMENT .
{
}
command ::= COMMAND_SUBSTITUTION_START commandList COMMAND_SUBSTITUTION_END .
{
}

argumentList ::= argument argumentList .
{
}
argumentList ::= argument .
{
}

argument ::= ARGUMENT .
{
}
argument ::= COMMAND_SUBSTITUTION_START commandList COMMAND_SUBSTITUTION_END .
{
}
