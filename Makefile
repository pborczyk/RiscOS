compile: entry kernel memory string stdlib
	riscv64-unknown-elf-gcc -T linker.ld -lgcc -nostdlib kernel.o entry.o memory.o string.o stdlib.o -o kernel.elf
entry: entry.asm
	riscv64-unknown-elf-as -c entry.asm -o entry.o
kernel: kernel.c
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
memory: memory.c memory.h
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany memory.c -o memory.o -ffreestanding
string: string.c string.h 
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany string.c -o string.o -ffreestanding
stdlib: stdlib.c stdlib.h
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany stdlib.c -o stdlib.o -ffreestanding