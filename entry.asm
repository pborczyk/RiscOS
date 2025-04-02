.section .init

.option norvc

.type start, @function
.global start
start:
	.cfi_startproc
	/* Clear the BSS section */
	la t5, bss_start
	la t6, bss_end
bss_clear:
	sd zero, (t5)
	addi t5, t5, 8
	bltu t5, t6, bss_clear
	
	la t0, kmain
	
	/* Jump to kernel! */
	tail kmain
	
	.cfi_endproc

.end