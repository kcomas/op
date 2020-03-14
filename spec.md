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

### Internal Types

- Unknown
- Null Returned by void functions and operations cannot be assigned
- Error Returned by invalid calls, external failures

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
"s Split

#### Array

Dynamic Array

[1, 2.0, "Asdf"]

@+ Push
@- Pop
@\$ Len
@^ Reverse
@[int] Index
@[int]: Assign
@m Map
@f Filter
@r Reduce
@s Sort

#### Hash

Hashmap String to value

{"test": 1, "x": 2.0 }

%k keys
%v values
%[string] Index
%[string]: Assign
%- Delete

#### File

File Descriptor

'1' STDOUT
'./test' file
'tcp://...' Socket
'http://...' Http

'l Load String
'> Write
'>> Append
'< Read
'd Directory Listing
'- Unlink

#### Thread

Function run as a thread. All args are copied by value

handle: ~fn(args)

~ Split/Join
~@ Join Array of threads
~ Join Var

#### Function

Does not have scope cannot see parent or child

(arg1,arg2...) {} Def
name(args) Call

#### Module

Code File, can be imported anywhere

m: 'op://filename' Direct Import
m: 'l "op://filename" String import

## Operators

### If

```
? (cond) {

} (elif) {

} {
else
}
```

### While

```
?? (cond) {

}
```
