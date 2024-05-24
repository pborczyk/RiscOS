compile: entry.o kernel.o memory.o string.o stdlib.o
	riscv64-unknown-elf-gcc -T linker.ld -lgcc -nostdlib kernel.o entry.o memory.o string.o stdlib.o -o kernel.elf
entry.o:
	riscv64-unknown-elf-as -c entry.asm -o entry.o
kernel.o:
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany kernel.c -o kernel.o -ffreestanding
memory.o:
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany memory.c -o memory.o -ffreestanding
string.o:
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany string.c -o string.o -ffreestanding
stdlib.o:
	riscv64-unknown-elf-gcc -Wall -Wextra -c -mcmodel=medany stdlib.c -o stdlib.o -ffreestanding