include toolchain.mk

SUB_DIR = user kernel

default: image

image:
	@for n in $(SUB_DIR); do $(MAKE) -C $$n; done

clean:
	@for n in $(SUB_DIR); do $(MAKE) -C $$n clean; done

# QEMU 虚拟机
QEMU = qemu-system-riscv64

# QEMU 启动选项
QEMUOPTS = -machine virt -bios ext/fw_jump.bin -device loader,file=kernel/target/Image,addr=0x80200000 --nographic

qemu: image
	$(QEMU) $(QEMUOPTS)

gdb: image
	$(QEMU) $(QEMUOPTS) -s -S

.PHONY: default image clean qemu gdb