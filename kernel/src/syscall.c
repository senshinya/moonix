#include "types.h"
#include "syscall.h"
#include "def.h"

usize sys_write(usize fd, uint8 c) {
    switch (fd) {
        case FD_STDOUT:
            consolePutchar(c);
        break;
        default:
            panic("Unsupported fd in sys_write!");
    }
    return 1;
}

usize sys_exit(uint32 exitCode) {
    printf("[kernel] Application exited with code %d\n", exitCode);
    runNextApp();
    return 0;
}

usize syscall(usize syscallID, usize args[3]) {
    switch (syscallID) {
        case Write:
            return sys_write(args[0], args[1]);
        case Exit:
            return sys_exit(args[0]);
        default:
            printf("Unsupported syscall_id: %x", syscallID);
            panic("");
    }
}