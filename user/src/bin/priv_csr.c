#include "../ulib.h"

uint32 main() {
    printf("Try to access privileged CSR in U Mode\n");
    printf("Kernel should kill this application!\n");
    usize x;
    asm volatile("csrr %0, sstatus" : "=r" (x) );
    return 0;
}