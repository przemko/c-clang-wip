	.text
	.file	"f1.c"
	.globl	f
	.p2align	4, 0x90
	.type	f,@function
f:                                      # @f
	.cfi_startproc
# BB#0:
                                        # kill: %EDI<def> %EDI<kill> %RDI<def>
	leal	(%rdi,%rdi), %eax
	retq
.Lfunc_end0:
	.size	f, .Lfunc_end0-f
	.cfi_endproc


	.ident	"clang version 3.9.0 (tags/RELEASE_390/final)"
	.section	".note.GNU-stack","",@progbits
