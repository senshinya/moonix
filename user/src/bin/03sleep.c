#include "../ulib.h"

uint32 main() {
    usize currentTimer = getTime();
    usize waitFor = currentTimer + 3000;
    while (getTime() < waitFor) {
        yield();
    }
    printf("Test sleep OK!\n");
    return 0;
}