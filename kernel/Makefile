include ../toolchain.mk

SOURCE_DIR := src
TARGET_DIR := target

C_SRCS := $(wildcard $(SOURCE_DIR)/*.c)
S_SRCS := $(wildcard $(SOURCE_DIR)/*.S)

OBJS := $(patsubst $(SOURCE_DIR)/%.c,$(TARGET_DIR)/%.o,$(C_SRCS)) \
        $(patsubst $(SOURCE_DIR)/%.S,$(TARGET_DIR)/%.o,$(S_SRCS))

default: kernel

kernel: ${TARGET_DIR}/Kernel
	$(OBJCOPY) ${TARGET_DIR}/Kernel -O binary ${TARGET_DIR}/Image

${TARGET_DIR}/Kernel: $(OBJS)
	$(LD) $(LDFLAGS) -T ${SOURCE_DIR}/kernel.ld -o ${TARGET_DIR}/Kernel $(OBJS)

$(TARGET_DIR)/%.o : $(SOURCE_DIR)/%.c
	@mkdir -p $(TARGET_DIR)
	${CC} ${CFLAGS} -c $< -o $@

$(TARGET_DIR)/%.o : $(SOURCE_DIR)/%.S
	@mkdir -p $(TARGET_DIR)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${TARGET_DIR}

.PHONY: default kernel clean
