#ifndef _CONTEXT_H
#define _CONTEXT_H

#include "types.h"
#include "riscv.h"

typedef struct {
    usize x[32];
    usize sstatus;
    usize sepc;
} TrapContext;

static TrapContext newAppInitContext(usize entry, usize sp) {
    TrapContext ctx;
    ctx.sstatus = r_sstatus() & ~SSTATUS_SPP;
    ctx.sepc = entry;
    ctx.x[2] = sp;
    return ctx;
}

#endif