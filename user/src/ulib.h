#ifndef _ULIB_H
#define _ULIB_H

#include "types.h"

/*  io.c    */
uint8 getc();
void printf(char *, ...);
void panic(char*);
void putchar(int c);

#endif