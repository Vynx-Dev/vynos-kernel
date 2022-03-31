# Kernel Development Guide
Thanks for reading this guide and connsidering to contribute the Vynos kernel!
## What this guide will and will not cover
This guide *WILL* cover some basic guidelines for project specific development and also some project specific C functions.

This guide *WILL NOT* cover kernel programming concepts or general programming.
## Recommened Knowledge
Programming in C without a standard library and kernel level Assembly

Basic computer science
## Printing to Standard Output
To print text to standard output you *MUST* include the library `print.h`. This library includes a printf like function along with some useful text formating functions. Here is a list of all the functions along with their purpose. First of all there is `print_clear()` this function clears the standard output buffer . Next there is `clear_row(NUMBER_OF_ROWS)` this function clears a specifed number of rows from standard output. Then there is `print_newline()` this function adds a new row to standard output. Then there is `print_char(CHAR)` this prints a specifed character on the current row of output. Then we have `print_str()` this is effectively printf. Finally there is `print_set_color(BACKGROUND, TEXT)` this sets the color of the background and the text color, this is very recommended as you don't wanna have boring black and white text! You ***must*** put it before `print_str()` The available colors are 
```

PRINT_COLOR_BLACK

PRINT_COLOR_BLUE

PRINT_COLOR_GREEN

PRINT_COLOR_CYAN 

PRINT_COLOR_RED

PRINT_COLOR_MAGENTA

PRINT_COLOR_BROWN 

PRINT_COLOR_LIGHT_GRAY 

PRINT_COLOR_DARK_GRAY

PRINT_COLOR_LIGHT_BLUE

PRINT_COLOR_LIGHT_GREEN

PRINT_COLOR_LIGHT_CYAN 

PRINT_COLOR_LIGHT_RED

PRINT_COLOR_PINK

PRINT_COLOR_YELLOW

PRINT_COLOR_WHITE
```
.
