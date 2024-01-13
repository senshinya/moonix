include ../toolchain.mk

SOURCE_DIR := src
APP_SOURCE_DIR := ${SOURCE_DIR}/bin
TARGET_DIR := target
APP_TARGET_DIR := ${TARGET_DIR}/bin

BASE_C_SRCS := $(wildcard $(SOURCE_DIR)/*.c)
BASE_S_SRCS := $(wildcard $(SOURCE_DIR)/*.S)
APP_SRCS := $(wildcard $(APP_SOURCE_DIR)/*.c)

BASE_OBJS := $(patsubst $(SOURCE_DIR)/%.c,$(TARGET_DIR)/%.o,$(BASE_C_SRCS)) \
			$(patsubst $(SOURCE_DIR)/%.S,$(TARGET_DIR)/%.o,$(BASE_S_SRCS))
BINS := $(patsubst $(APP_SOURCE_DIR)/%.c,$(APP_TARGET_DIR)/%.bin,$(APP_SRCS))

default: $(BINS)

${APP_TARGET_DIR}/%.bin: ${APP_TARGET_DIR}/%.elf
	$(OBJCOPY) $< --strip-all -O binary $@

${APP_TARGET_DIR}/%.elf: ${APP_TARGET_DIR}/%.o $(BASE_OBJS)
	$(LD) $(LDFLAGS) -T ${SOURCE_DIR}/user.ld -o $@ $< $(BASE_OBJS)

${APP_TARGET_DIR}/%.o: ${APP_SOURCE_DIR}/%.c
	@mkdir -p $(APP_TARGET_DIR)
	${CC} ${CFLAGS} -c $< -o $@

$(TARGET_DIR)/%.o : $(SOURCE_DIR)/%.c
	@mkdir -p $(TARGET_DIR)
	${CC} ${CFLAGS} -c $< -o $@

$(TARGET_DIR)/%.o : $(SOURCE_DIR)/%.S
	@mkdir -p $(TARGET_DIR)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${TARGET_DIR}

.PHONY: default clean