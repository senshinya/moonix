#ifndef _RISCV_H
#define _RISCV_H

#include "types.h"

#define MODE_DIRECT 0x0
#define MODE_VECTOR 0x1
/* stvec 寄存器设置中断处理函数和处理模式 */
static void w_stvec(usize x) {
    asm volatile("csrw stvec, %0" : : "r" (x));
}


#define SIE_SEIE (1L << 9)  /* 外部中断 */
#define SIE_STIE (1L << 5)  /* 时钟中断 */
#define SIE_SSIE (1L << 1)  /* 软件中断 */
/* SIE 寄存器设置一些中断使能 */
static usize r_sie() {
    usize x;
    asm volatile("csrr %0, sie" : "=r" (x) );
    return x;
}

static void w_sie(usize x) {
    asm volatile("csrw sie, %0" : : "r" (x));
}

#define SSTATUS_SUM (1L << 18)
#define SSTATUS_SPP (1L << 8)
#define SSTATUS_SPIE (1L << 5)
#define SSTATUS_SIE (1L << 1)   /* 监管者模式中断使能 */
#define SSTATUS_UIE (1L << 0)   /* 用户模式中断使能 */
/* 监管者模式状态寄存器 */
static usize r_sstatus() {
    usize x;
    asm volatile("csrr %0, sstatus" : "=r" (x) );
    return x;
}

static void w_sstatus(usize x) {
    asm volatile("csrw sstatus, %0" : : "r" (x));
}

/* 读取硬件时钟 */
static usize r_time() {
    usize x;
    asm volatile("csrr %0, time" : "=r" (x) );
    return x;
}

static usize r_satp() {
    usize x;
    asm volatile("csrr %0, satp" : "=r" (x) );
    return x;
}

/* 打开异步中断，并等待中断 */
static void enable_and_wfi() {
    asm volatile("csrsi sstatus, 1 << 1; wfi");
}

/* 关闭异步中断并保存原先的 sstatus */
static usize disable_and_store() {
    usize x;
    asm volatile("csrrci %0, sstatus, 1 << 1" : "=r" (x) );
    return x;
}

/* 恢复 sstatus */
static void restore_sstatus(usize flags) {
    asm volatile("csrs sstatus, %0" :: "r"(flags) );
}

static usize r_scause() {
    usize x;
    asm volatile("csrr %0, scause" : "=r" (x) );
    return x;
}

static usize r_stval() {
    usize x;
    asm volatile("csrr %0, stval" : "=r" (x) );
    return x;
}

#endif