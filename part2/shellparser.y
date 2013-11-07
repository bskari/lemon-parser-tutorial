%include
{
 #include <cassert>
 #include <iostream>
}

%syntax_error
{
  *valid = false;
}

%token_type {const char*}
%extra_argument {bool* valid}

start ::= commandList .
commandList ::= command PIPE commandList .
{
}
commandList ::= command .
{
}

command ::= FILENAME argumentList .
{
}
command ::= FILENAME .
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
argument ::= FILENAME .
{
}
