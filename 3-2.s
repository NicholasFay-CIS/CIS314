	.file	"3-2.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB11:
	.cfi_startproc
	addq	%rsi, %rdx
	imulq	%rdx, %rdi
	salq	$63, %rdx
	sarq	$63, %rdx
	movq	%rdi, %rax
	xorq	%rdx, %rax
	ret
	.cfi_endproc
.LFE11:
	.size	f, .-f
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$4, %edx
	movl	$2, %esi
	movl	$1, %edi
	call	f
	movq	%rax, %r12
	movl	$7, %edx
	movl	$5, %esi
	movl	$3, %edi
	call	f
	movq	%rax, %rbp
	movl	$30, %edx
	movl	$20, %esi
	movl	$10, %edi
	call	f
	movq	%rax, %rbx
	movl	%r12d, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	%ebp, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	%ebx, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.1 20180831"
	.section	.note.GNU-stack,"",@progbits
