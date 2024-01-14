#include "../ulib.h"

const usize SIZE = 10;
const uint32 P = 3;
const usize STEP = 100000;
const uint32 MOD = 10007;

uint32 main() {
    uint32 pow[SIZE];
    for (int i = 0; i < 10; i ++) {
        pow[i] = 0;
    }
    int index = 0;
    pow[index] = 1;
    for (int i = 1; i <= STEP; i ++) {
        uint32 last = pow[index];
        index = (index + 1) % SIZE;
        pow[index] = last * P % MOD;
        if (i % 10000 == 0) {
            printf("%d^%d=%d(MOD %d)\n", P, i, pow[index], MOD);
        }
    }
    printf("Test power OK!\n");
    return 0;
}