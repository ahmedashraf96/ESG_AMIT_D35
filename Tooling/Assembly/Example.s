	.file	"Example.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	print_my_name
	call	print_my_age
	call	print_my_college
	call	print_my_faculty
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 6.2.0"
	.def	print_my_name;	.scl	2;	.type	32;	.endef
	.def	print_my_age;	.scl	2;	.type	32;	.endef
	.def	print_my_college;	.scl	2;	.type	32;	.endef
	.def	print_my_faculty;	.scl	2;	.type	32;	.endef
