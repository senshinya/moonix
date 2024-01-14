#include "def.h"

void clearBSS() {
    extern void *sbss;
    extern void *ebss;

    for(char *i = sbss; i < (char *)ebss; i ++) {
        *i = 0;
    }
}

int main() {
    clearBSS();
    initTrap();
    initBatch();
    runNextApp();
}