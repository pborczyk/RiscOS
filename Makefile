CROSS_COMPILE = riscv64-unknown-elf
CC = ${CROSS_COMPILE}-gcc
LINKER = ${CROSS_COMPILE}-gcc
ASM = ${CROSS_COMPILE}-as
OBJCOPY=${CROSS_COMPILE}-objcopy
TFTP_DIR=~/srv/tfp/
BUILD_DIR=build


SBI_INCLUDE = ../opensbi/include/
INCLUDES = ../ $(SBI_INCLUDE)

INCLUDE_STRING = $(foreach include, $(INCLUDES), -I $(include))
U_BOOT_PATH = bin/u-boot.bin

run: compile ./build/kernel.elf
	qemu-system-riscv64 -M virt \
    -display none -serial stdio \
    -bios bin/u-boot-spl.bin \
    -device loader,file=bin/u-boot.itb,addr=0x80200000 \
	-netdev user,id=n0,tftp=./${BUILD_DIR},bootfile=kernel.bin -device virtio-net-device,netdev=n0

compile: entry kernel memory string stdlib
	cd ${BUILD_DIR} && \
	${LINKER} $(INCLUDE_STRING) -T ../linker.ld -lgcc -nostdlib kernel.o entry.o memory.o string.o stdlib.o -o kernel.elf && \
	${OBJCOPY} -O binary kernel.elf kernel.bin
entry: entry.asm
	${ASM} -c entry.asm -o ${BUILD_DIR}/entry.o
kernel: kernel.c
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany kernel.c -o ${BUILD_DIR}/kernel.o -ffreestanding
memory: memory.c memory.h
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany memory.c -o ${BUILD_DIR}/memory.o -ffreestanding
string: string.c string.h 
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany string.c -o ${BUILD_DIR}/string.o -ffreestanding
stdlib: stdlib.c stdlib.h
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany stdlib.c -o ${BUILD_DIR}/stdlib.o -ffreestanding
clean:
	rm -rf ./build/**