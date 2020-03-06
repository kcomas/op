# OP SCRIPT

## Scripting language where all built in operators are typed

eg:

- 1 + 2 Int Addition
- 1.0 .+ 2.0 Float Addition

## Built in Types

### Type -- Representation

- Int
- Float .
- String/Char "
- Array @
- Hash %
- File '
- Thread ~
- Function
- Module

#### Int

A 64 bit signed number

1 10 100000 1e10

\+ Add
\- Sub
\\\* Mul
/ Div
% Mod
^ Pow

#### Float

A 64 bit IEEE floating point number

1.0 10.1 1.1e10

.+ Add
.- Sub
.\* Mul
./ Div
.^ Pow

#### String/Char

A utf-8 string

"Hello World\n"

Single Character Strings are chars and are placed on the stack not heap

"+ Concat
"\$ Len
"[int] Index

#### Array

Dynamic Array

[1, 2.0, "Asdf"]

@+ Push
@- Pop
@\$ Len
@[int] Index
@m Map
@f Filter
@r Reduce
@s Sort
