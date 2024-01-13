#include "types.h"
#include "syscall.h"
#include "ulib.h"

__attribute__((weak)) uint32 main()
{
    panic("No main linked!\n");
    return 1;
}

void clearBSS() {
    extern void *sbss;
    extern void *ebss;

    for(char *i = sbss; i < (char *)ebss; i ++) {
        *i = 0;
    }
}

usize exit(uint32 exitCode) {
    return sys_exit(exitCode);
}

__attribute__ ((section (".text.entry"))) void _start() {
    clearBSS();
    exit(main());
    panic("unreachable code!");
}