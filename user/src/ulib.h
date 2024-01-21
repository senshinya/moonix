#ifndef _ULIB_H
#define _ULIB_H

#include "types.h"
#include "syscall.h"

/*  io.c    */
uint8 getc();
void printf(char *, ...);
void panic(char*);
void putchar(int c);

inline usize yield() {
    return sys_yield();
}
inline usize getTime() {
    return sys_gettime();
}

#endif