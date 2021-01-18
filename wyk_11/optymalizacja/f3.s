	.text
	.file	"f3.c"
	.globl	f
	.p2align	4, 0x90
	.type	f,@function
f:                                      # @f
	.cfi_startproc
# BB#0:
                                        # kill: %EDI<def> %EDI<kill> %RDI<def>
	xorl	%eax, %eax
	testl	%edi, %edi
	je	.LBB0_2
# BB#1:
	leal	-1(%rdi), %eax
	leal	-2(%rdi), %ecx
	imulq	%rax, %rcx
                                        # kill: %EAX<def> %EAX<kill> %RAX<kill>
	imull	%eax, %eax
	shrq	%rcx
	addl	%edi, %eax
	subl	%ecx, %eax
.LBB0_2:
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f
	.cfi_endproc


	.ident	"clang version 3.9.0 (tags/RELEASE_390/final)"
	.section	".note.GNU-stack","",@progbits
