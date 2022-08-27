	.file	"Func.c"
	.section .rdata,"dr"
.LC0:
	.ascii "My name is Yasser\0"
	.text
	.globl	print_my_name
	.def	print_my_name;	.scl	2;	.type	32;	.endef
	.seh_proc	print_my_name
print_my_name:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC0(%rip), %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "My age is 30\0"
	.text
	.globl	print_my_age
	.def	print_my_age;	.scl	2;	.type	32;	.endef
	.seh_proc	print_my_age
print_my_age:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC1(%rip), %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "My college is Menoufia\0"
	.text
	.globl	print_my_college
	.def	print_my_college;	.scl	2;	.type	32;	.endef
	.seh_proc	print_my_college
print_my_college:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC2(%rip), %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "My faculty is Engineering\0"
	.text
	.globl	print_my_faculty
	.def	print_my_faculty;	.scl	2;	.type	32;	.endef
	.seh_proc	print_my_faculty
print_my_faculty:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC3(%rip), %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 6.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
