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
// GDT stuff
void create_gdt_entry(uint16_t *target, struct GDT source)
{
    if (source.limit > 0xFFFFF) {kerror("Can not encode GDT over 0xFFFFF")}
    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] = (source.limit >> 16) & 0x0F;

    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;

    target[5] = source.access_byte;

    target[6] |= (source.flags << 4)
 
}

// Starts the kernel
void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_GREEN);// First declare the background of the text, then the color of the text itself.
    print_str("OK");
}
