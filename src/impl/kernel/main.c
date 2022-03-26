#include "print.h"
void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_GREEN);// First declare the background of the text, then the color of the text itself.
    print_str("OK");
}