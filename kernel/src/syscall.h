#ifndef SYSCALL_H
#define SYSCALL_H

typedef enum {
    Shutdown = 13,
    LsDir = 20,
    CdDir = 21,
    Pwd = 22,
    Open = 56,
    Close = 57,
    Read = 63,
    Write = 64,
    Exit = 93,
    Exec = 221,
} SyscallId;

const usize FD_STDOUT = 1;

#endif
