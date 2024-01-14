#ifndef TRAP_H
#define TRAP_H

/* RV64 中断发生时，机器根据中断类型自动设置 scause 寄存器 */
#define ILLEGAL_INSTRUCTION 2L
#define BREAKPOINT          3L                  /* 断点中断 */
#define STORE_ACCESS_FAULT  7L
#define USER_ENV_CALL       8L                  /* 来自 U-Mode 的系统调用 */
#define SUPERVISOR_TIMER    5L | (1L << 63)     /* S-Mode 的时钟中断 */
#define SUPERVISOR_EXTERNAL 9L | (1L << 63)     /* S-Mode 的外部中断 */
#define STORE_PAGE_FAULT    15L

#endif
