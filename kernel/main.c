#include "types.h"
#include "def.h"

void clearBSS() {
    extern void *sbss;
    extern void *ebss;

    for(char *i = (char *)sbss; i < (char *)ebss; i ++) {
        *i = 0;
    }
}

int main() {
    clearBSS();
    printf("Hello, moonix!\n");
    panic("Shutdown machine!");
}