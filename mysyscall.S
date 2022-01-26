#include <sys/syscall.h>

	.text
	.globl	mywrite
	.type	mywrite,@function
mywrite:
	movl	$SYS_write,%eax
	movq	%rcx,%r10
	syscall
	retq
	.size	mywrite, . - mywrite

	.globl	myexit
	.type	myexit,@function
myexit:
	movl	$SYS_exit,%eax
	movq	%rcx,%r10
	syscall
	retq
	.size	myexit, . - myexit
