CC = riscv64-unknown-elf-gcc
LINKER = riscv64-unknown-elf-gcc
ASM = riscv64-unknown-elf-as
TFTP_DIR=~/srv/tfp/


SBI_INCLUDE = ./libs/sbi/include/
INCLUDES = ../ $(SBI_INCLUDE)

INCLUDE_STRING = $(foreach include, $(INCLUDES), -I $(include))
U_BOOT_PATH = /home/howorang/uboot/u-boot/u-boot.bin

package: compile kernel.elf
	mkdir -p build
	cp ./kernel.elf ${TFTP_DIR}

run: package
	qemu-system-riscv64 -machine virt -kernel $(U_BOOT_PATH) -serial mon:stdio -netdev user,id=n0,tftp=./,bootfile=kernel.elf -device virtio-net-device,netdev=n0
compile: entry kernel memory string stdlib
	${LINKER} $(INCLUDE_STRING) -T linker.ld -lgcc -nostdlib kernel.o entry.o memory.o string.o stdlib.o -o kernel.elf
entry: entry.asm
	${ASM} -c entry.asm -o entry.o
kernel: kernel.c
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
memory: memory.c memory.h
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany memory.c -o memory.o -ffreestanding
string: string.c string.h 
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany string.c -o string.o -ffreestanding
stdlib: stdlib.c stdlib.h
	${CC} $(INCLUDE_STRING) -Wall -Wextra -c -mcmodel=medany stdlib.c -o stdlib.o -ffreestanding