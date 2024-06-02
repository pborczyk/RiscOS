.section .init
 
.option norvc
 
.type start, @function
.global start
start:

 
	la t0, kmain
	/* Jump to kernel! */
	tail kmain
 
.end
