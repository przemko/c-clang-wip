	.text
	.file	"f4.c"
	.globl	f
	.p2align	4, 0x90
	.type	f,@function
f:                                      # @f
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
	pushq	%rbx
.Ltmp1:
	.cfi_def_cfa_offset 24
	pushq	%rax
.Ltmp2:
	.cfi_def_cfa_offset 32
.Ltmp3:
	.cfi_offset %rbx, -24
.Ltmp4:
	.cfi_offset %rbp, -16
	movl	%edi, %ebx
	xorl	%ebp, %ebp
	testl	%ebx, %ebx
	je	.LBB0_3
# BB#1:
	xorl	%ebp, %ebp
	.p2align	4, 0x90
.LBB0_2:                                # =>This Inner Loop Header: Depth=1
	movl	%ebx, %edi
	callq	g
	addl	%eax, %ebp
	decl	%ebx
	jne	.LBB0_2
.LBB0_3:
	movl	%ebp, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f
	.cfi_endproc


	.ident	"clang version 3.9.0 (tags/RELEASE_390/final)"
	.section	".note.GNU-stack","",@progbits
