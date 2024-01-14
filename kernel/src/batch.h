#ifndef _BATCH_H
#define _BATCH_H

#include "types.h"

#define MAX_APP_NUM 16
const usize APP_BASE_ADDRESS = 0x80400000;
const usize APP_SIZE_LIMIT = 0x20000;

#define USER_STACK_SIZE 4096*2
#define KERNEL_STACK_SIZE 4096*2

typedef struct {
    uint8 data[KERNEL_STACK_SIZE];
}__attribute__((aligned(4096))) KernelStack;

typedef struct {
    uint8 data[USER_STACK_SIZE];
}__attribute__((aligned(4096))) UserStack;

KernelStack KERNEL_STACK;
inline usize getKernelStackSp() {
    return (usize)&KERNEL_STACK.data + KERNEL_STACK_SIZE;
}

UserStack USER_STACK;
inline usize getUserStackSp() {
    return (usize)&USER_STACK.data + USER_STACK_SIZE;
}

typedef struct {
    usize numApp;
    usize currentApp;
    usize appStart[MAX_APP_NUM+1];
} AppManager;

AppManager APP_MANAGER;

#endif