compile: entry.o kernel.o memory.o
	riscv64-unknown-elf-gcc -T linker.ld -lgcc -nostdlib kernel.o entry.o memory.o -o kernel.elf
entry.o:
	riscv64-unknown-elf-as -c entry.asm -o entry.o
kernel.o:
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
memory.o:
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany memory.c -o memory.o -ffreestanding
