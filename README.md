THE MONTY LANGUAGE

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

REQUIREMENTS:

Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You allowed to use a maximum of one global variable
No more than 5 functions per file
You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called monty.h
Don’t forget to push your header file
All your header files should be include guarded
You are expected to do the tasks in the order shown in the project

Some of the Opcodes to be implemented

push
pall
pint
pop
swap
add
nop

Example:

cat -e bytecodes/00.m
push 1
push 2
push 3
pall

./monty bytecodes/00.m
3
2
1

COMPILATIONS AND OUTPUTS:

Your code will be compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
Any output must be printed on stdout
Any error message must be printed on stderr

Authors
Akinlade Rebecca - akinladerebecca04@gmail.com
Olowosuyi Temitope - temitopeabiodun685@gmail.com
