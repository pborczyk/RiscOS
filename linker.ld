ENTRY(_start)
SECTIONS {
    /* U-Boot's booti relocates the kernel image to this address, so we link here to keep ELF symbols aligned with runtime addresses for GDB debugging */
    . = 0x40280000;
    .startup . : { *entry.asm.obj(.text) }
    .text : { *(.text) }
    .data : { *(.data) }
    .bss : { *(.bss COMMON) }
    . = ALIGN(16); /* two times pointer size */
    . += 0x1000; /* 4kB of stack memory */ 
    stack_top = .;
}