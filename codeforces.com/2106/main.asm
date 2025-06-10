	.file	"main.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	$2, -16(%rbp)
	jmp	.L2
.L7:
	movb	$0, -17(%rbp)
	movq	$2, -8(%rbp)
	jmp	.L3
.L6:
	movq	-16(%rbp), %rax
	cqto
	idivq	-8(%rbp)
	movq	%rdx, %rax
	testq	%rax, %rax
	jne	.L4
	movb	$1, -17(%rbp)
	jmp	.L9
.L4:
	addq	$1, -8(%rbp)
.L3:
	movq	-8(%rbp), %rax
	imulq	%rax, %rax
	cmpq	%rax, -16(%rbp)
	jge	.L6
.L9:
	addq	$1, -16(%rbp)
.L2:
	cmpq	$99, -16(%rbp)
	jle	.L7
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
