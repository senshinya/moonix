#include "../ulib.h"

const usize LEN = 100;

uint32 main() {
    usize p = 5;
    usize m = 998244353;
    usize iter = 140000;
    usize s[LEN];
    for (int i = 0; i < LEN; i ++) {
        s[i] = 0;
    }
    usize cur = 0;
    s[cur] = 1;
    for (int i = 1; i <= iter; i ++) {
        usize next = cur + 1;
        if (cur + 1 == LEN) next = 0;
        s[next] = s[cur] * p % m;
        cur = next;
        if (i % 10000 == 0) {
            printf("power_5 [%d/%d]\n", i, iter);
        }
    }
    printf("%d^%d = %d(MOD %d)\n", p, iter, s[cur], m);
    printf("Test power_5 OK!\n");
    return 0;
}