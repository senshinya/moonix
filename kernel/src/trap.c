#include "types.h"
#include "riscv.h"
#include "context.h"
#include "trap.h"
#include "def.h"

void initTrap() {
    extern void __alltraps();
    w_stvec((usize)__alltraps | MODE_DIRECT);
}

TrapContext* trapHandler(TrapContext *ctx) {
    usize scause = r_scause();
    usize stval = r_stval();
    switch (scause) {
        case USER_ENV_CALL:
            ctx->sepc += 4;
            usize args[3] = {ctx->x[10], ctx->x[11], ctx->x[12]};
            ctx->x[10] = syscall(ctx->x[17], args);
        break;
        case STORE_ACCESS_FAULT:
        case STORE_PAGE_FAULT:
            printf("[kernel] PageFault in application, kernel killed it.\n");
            runNextApp();
        break;
        case ILLEGAL_INSTRUCTION:
            printf("[kernel] IllegalInstruction in application, kernel killed it.\n");
            runNextApp();
        break;
        default:
            printf("Unsupported trap %x, stval = %x!\n", scause, stval);
            panic("");
    }
    return ctx;
}