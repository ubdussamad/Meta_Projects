
#include <asm/unistd.h>
#include <syscall.h>   /* For SYS_xxx definitions */
#define SYS_write 0x1
	
	.file	"test2.cpp"
	.section	.rodata
hello:
	.string	"HELLO WORLD\n"
	.text
	.globl	_start
	.type	_start, @function
_start:
	## Writing
	movl	$12, %edx
	movl	$hello, %esi
	movl	$1, %edi
	movl	$0x1, %eax
	syscall

	## exit the program and handle the control to parent
	movl	$0, %edi
	movl	$0x3c, %eax
	syscall
