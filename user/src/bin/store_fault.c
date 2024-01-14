#include "../ulib.h"

uint32 main() {
    printf("Into Test store_fault, we will insert an invalid store operation...\n");
    printf("Kernel should kill this application!\n");
    *(uint8 *)0 = 0;
    return 0;
}