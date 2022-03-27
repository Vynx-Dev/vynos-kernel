#include <stdint.h>
#include "print.h"

#if UINT32_MAX == UINTPTR_MAX
#define STACK_CHK_GUARD 0xe2dae263
#else
#define STACK_CHK_GUARD 0x599e9fbd94fdf737
#endif
 
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;
 
 // Stack Smahing Check Failure Handler
__attribute__((noreturn))
void __stack_chk_fail(void)
{
#if __STDC_HOSTED__
	abort();
#elif __is_myos_kernel
	panic("Panic #0");
#endif
}
// Start Main Kernel
void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_GREEN);// First declare the background of the text, then the color of the text itself.
    print_str("OK");
}
