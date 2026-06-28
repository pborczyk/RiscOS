.global _start

// ARM64 Image header — bootm validates this after unwrapping the uImage.
// Without it: "Bad Linux ARM64 Image magic!"
_start:
    b _entry            // 0x00: branch over header
    .word 0             // 0x04: reserved
    .quad 0             // 0x08: text_offset
    .quad 0             // 0x10: image_size
    .quad 0x0a          // 0x18: flags (LE, 4K pages, any load addr)
    .quad 0             // 0x20: reserved
    .quad 0             // 0x28: reserved
    .quad 0             // 0x30: reserved
    .word 0x644d5241    // 0x38: magic "ARM\x64"
    .word 0             // 0x3c: reserved

_entry:
    ldr x30, =stack_top
    mov sp, x30
    bl kmain
    b .

