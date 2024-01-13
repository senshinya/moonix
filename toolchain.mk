# 设置交叉编译工具链
TOOLPREFIX := riscv64-linux-gnu-
ifeq ($(shell uname),Darwin)
	TOOLPREFIX=riscv64-unknown-elf-
endif

CC = $(TOOLPREFIX)gcc
AS = $(TOOLPREFIX)gas
LD = $(TOOLPREFIX)ld
GDB = $(TOOLPREFIX)gdb
OBJCOPY = $(TOOLPREFIX)objcopy
OBJDUMP = $(TOOLPREFIX)objdump

# gcc 编译选项
CFLAGS = -Wall -Werror -O -fno-omit-frame-pointer -ggdb
CFLAGS += -MD
CFLAGS += -mcmodel=medany
CFLAGS += -ffreestanding -fno-common -nostdlib -mno-relax
CFLAGS += -I.

CFLAGS += $(shell $(CC) -fno-stack-protector -E -x c /dev/null >/dev/null 2>&1 && echo -fno-stack-protector)

# ld 链接选项
LDFLAGS = -z max-page-size=4096