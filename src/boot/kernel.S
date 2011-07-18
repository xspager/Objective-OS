	.file	"kernel.c"
	.section	.rodata
.LC0:
	.string	"\nObjective-OS\n\n"
.LC1:
	.string	"CPUid:\n"
.LC2:
	.string	"AMD"
.LC3:
	.string	"Intel"
.LC4:
	.string	"Unknown"
.LC5:
	.string	" vendor = %s\n"
	.align 4
.LC6:
	.string	" maximum supported standard level = 0x%x\n"
.LC7:
	.string	" vendor string = %s\n"
.LC8:
	.string	" processor signature = 0x%x\n"
.LC9:
	.string	" stepping id = 0x%x\n"
.LC10:
	.string	" model number = 0x%x\n"
.LC11:
	.string	" family code = 0x%x\n"
.LC12:
	.string	" processor type = 0x%x\n"
	.align 4
.LC13:
	.string	" max extended information = 0x%x\n"
.LC14:
	.string	" cpu name = %s\n"
.LC15:
	.string	"\n registers values:\n"
	.align 4
.LC16:
	.string	"\t    EAX    |     EBX   |     ECX   |     EDX\n"
.LC17:
	.string	"%X\t0x%X| 0x%X| 0x%X| 0x%X\n"
.LC18:
	.string	"Beeep!"
.LC19:
	.string	"%c"
	.text
	.p2align 4,,15
.globl cmain
	.type	cmain, @function
cmain:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$400, %esp
	call	init
	call	cls
	movl	$.LC0, (%esp)
	call	printf
	movl	$.LC1, (%esp)
	call	printf
	leal	-376(%ebp), %eax
	movl	%eax, (%esp)
	call	cpuid
	movzbl	-376(%ebp), %eax
	movzbl	%al, %eax
	movl	%eax, -380(%ebp)
	cmpl	$2, -380(%ebp)
	je	.L3
	cmpl	$3, -380(%ebp)
	je	.L4
	jmp	.L2
.L3:
	movl	$.LC2, -20(%ebp)
	jmp	.L5
.L4:
	movl	$.LC3, -20(%ebp)
	jmp	.L5
.L2:
	movl	$.LC4, -20(%ebp)
.L5:
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	movl	-372(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	leal	-376(%ebp), %eax
	addl	$8, %eax
	movl	%eax, 4(%esp)
	movl	$.LC7, (%esp)
	call	printf
	movl	-352(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC8, (%esp)
	call	printf
	movzbl	-348(%ebp), %eax
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$.LC9, (%esp)
	call	printf
	movzbl	-347(%ebp), %eax
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$.LC10, (%esp)
	call	printf
	movzbl	-346(%ebp), %eax
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$.LC11, (%esp)
	call	printf
	movzbl	-345(%ebp), %eax
	movzbl	%al, %eax
	movl	%eax, 4(%esp)
	movl	$.LC12, (%esp)
	call	printf
	movl	-340(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC13, (%esp)
	call	printf
	movzbl	-336(%ebp), %eax
	testb	%al, %al
	je	.L6
	leal	-376(%ebp), %eax
	addl	$40, %eax
	movl	%eax, 4(%esp)
	movl	$.LC14, (%esp)
	call	printf
.L6:
	movl	$.LC15, (%esp)
	call	printf
	movl	$.LC16, (%esp)
	call	printf
	movl	$0, -16(%ebp)
	jmp	.L8
.L9:
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %edx
	addl	%edx, %eax
	subl	$264, %eax
	movl	(%eax), %ecx
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %esi
	addl	%esi, %eax
	subl	$268, %eax
	movl	(%eax), %ebx
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %edx
	addl	%edx, %eax
	subl	$272, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %esi
	addl	%esi, %eax
	subl	$276, %eax
	movl	(%eax), %eax
	movl	%ecx, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC17, (%esp)
	call	printf
	addl	$1, -16(%ebp)
.L8:
	movl	-372(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jae	.L9
	movl	$-2147483648, -16(%ebp)
	jmp	.L11
.L12:
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %edx
	addl	%edx, %eax
	subl	$264, %eax
	movl	(%eax), %ecx
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %esi
	addl	%esi, %eax
	subl	$268, %eax
	movl	(%eax), %ebx
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %edx
	addl	%edx, %eax
	subl	$272, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	sall	$4, %eax
	leal	-8(%ebp), %esi
	addl	%esi, %eax
	subl	$276, %eax
	movl	(%eax), %eax
	movl	%ecx, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC17, (%esp)
	call	printf
	addl	$1, -16(%ebp)
.L11:
	movl	-340(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jae	.L12
	movb	$0, -9(%ebp)
	jmp	.L14
.L15:
	call	getc
	movb	%al, -9(%ebp)
	cmpb	$103, -9(%ebp)
	jne	.L16
#APP
	movb $0xB6, %al                     outb %al, $0x43                     movb $0x0D, %al                     outb %al, $0x43                     movb $0x11, %al                     outb %al, $0x42                     inb $0x61, %al                     orb $3, %al                     outb %al, $0x61
#NO_APP
	movl	$.LC18, (%esp)
	call	printf
.L16:
	movzbl	-9(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC19, (%esp)
	call	printf
.L14:
	cmpb	$19, -9(%ebp)
	jne	.L15
	addl	$400, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.size	cmain, .-cmain
.globl make_bake_code_char_map
	.data
	.align 32
	.type	make_bake_code_char_map, @object
	.size	make_bake_code_char_map, 148
make_bake_code_char_map:
	.zero	2
	.byte	-127
	.byte	19
	.byte	-126
	.byte	49
	.byte	-125
	.byte	50
	.byte	-124
	.byte	51
	.byte	-123
	.byte	52
	.byte	-122
	.byte	53
	.byte	-121
	.byte	54
	.byte	-120
	.byte	55
	.byte	-119
	.byte	56
	.byte	-118
	.byte	57
	.byte	-117
	.byte	48
	.byte	-116
	.byte	45
	.byte	-115
	.byte	61
	.byte	-114
	.byte	8
	.byte	-113
	.byte	9
	.byte	-112
	.byte	81
	.byte	-111
	.byte	119
	.byte	-110
	.byte	101
	.byte	-109
	.byte	114
	.byte	-108
	.byte	116
	.byte	-107
	.byte	121
	.byte	-106
	.byte	117
	.byte	-105
	.byte	105
	.byte	-104
	.byte	111
	.byte	-103
	.byte	112
	.byte	-102
	.byte	91
	.byte	-101
	.byte	93
	.byte	-100
	.byte	10
	.byte	-99
	.byte	32
	.byte	-98
	.byte	97
	.byte	-97
	.byte	115
	.byte	-128
	.byte	100
	.byte	-127
	.byte	102
	.byte	-126
	.byte	103
	.byte	-125
	.byte	104
	.byte	-124
	.byte	106
	.byte	-123
	.byte	107
	.byte	-122
	.byte	108
	.byte	-121
	.byte	32
	.byte	-120
	.byte	39
	.byte	-119
	.byte	96
	.byte	-118
	.byte	32
	.byte	-117
	.byte	92
	.byte	-116
	.byte	122
	.byte	-115
	.byte	120
	.byte	-114
	.byte	99
	.byte	-113
	.byte	118
	.byte	-112
	.byte	98
	.byte	-111
	.byte	110
	.byte	-110
	.byte	109
	.byte	-109
	.byte	44
	.byte	-108
	.byte	46
	.byte	-107
	.byte	47
	.byte	-106
	.byte	32
	.byte	-105
	.byte	42
	.byte	-104
	.byte	32
	.byte	-103
	.byte	32
	.byte	-102
	.byte	32
	.byte	-101
	.byte	32
	.byte	-100
	.byte	32
	.byte	-99
	.byte	32
	.byte	-98
	.byte	32
	.byte	-97
	.byte	32
	.byte	-112
	.byte	32
	.byte	-112
	.byte	32
	.byte	-112
	.byte	32
	.byte	-112
	.byte	32
	.byte	-112
	.byte	32
	.byte	-112
	.byte	32
	.zero	2
	.byte	-112
	.byte	55
	.byte	-112
	.byte	56
	.byte	-112
	.byte	57
	.text
	.p2align 4,,15
.globl getc
	.type	getc, @function
getc:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
.L21:
	movzbl	-2(%ebp), %eax
	movb	%al, -1(%ebp)
#APP
	inb $96, %al
#NO_APP
	movb	%al, -2(%ebp)
	movzbl	-2(%ebp), %eax
	cmpb	-1(%ebp), %al
	je	.L21
	movzbl	-2(%ebp), %eax
	movzbl	-1(%ebp), %edx
	subl	$-128, %edx
	cmpl	%edx, %eax
	jne	.L21
	movzbl	-1(%ebp), %eax
	movzbl	make_bake_code_char_map+1(%eax,%eax), %eax
	movb	%al, -2(%ebp)
	movzbl	-2(%ebp), %eax
	leave
	ret
	.size	getc, .-getc
	.p2align 4,,15
.globl itoa
	.type	itoa, @function
itoa:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$36, %esp
	movl	8(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	$10, -16(%ebp)
	cmpl	$100, 12(%ebp)
	je	.L27
	cmpl	$105, 12(%ebp)
	jne	.L29
.L27:
	cmpl	$0, 16(%ebp)
	jns	.L29
	movl	-32(%ebp), %eax
	movb	$45, (%eax)
	addl	$1, -32(%ebp)
	addl	$1, 8(%ebp)
	movl	16(%ebp), %eax
	negl	%eax
	movl	%eax, -20(%ebp)
	jmp	.L31
.L29:
	cmpl	$120, 12(%ebp)
	je	.L32
	cmpl	$88, 12(%ebp)
	jne	.L34
.L32:
	movl	$16, -16(%ebp)
	jmp	.L31
.L34:
	cmpl	$98, 12(%ebp)
	jne	.L31
	movl	$2, -16(%ebp)
.L31:
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	movl	%edx, %ecx
	movl	$0, %edx
	divl	%ecx
	movl	%edx, %eax
	movl	%eax, -8(%ebp)
	cmpl	$9, -8(%ebp)
	jg	.L36
	movl	-8(%ebp), %eax
	addl	$48, %eax
	movb	%al, -34(%ebp)
	jmp	.L38
.L36:
	cmpl	$120, 12(%ebp)
	jne	.L39
	movb	$97, -33(%ebp)
	jmp	.L41
.L39:
	movb	$65, -33(%ebp)
.L41:
	movl	-8(%ebp), %eax
	addb	-33(%ebp), %al
	subl	$10, %eax
	movb	%al, -34(%ebp)
.L38:
	movl	-32(%ebp), %eax
	movzbl	-34(%ebp), %edx
	movb	%dl, (%eax)
	addl	$1, -32(%ebp)
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	movl	%edx, %ecx
	movl	$0, %edx
	divl	%ecx
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	jne	.L31
	cmpl	$16, -16(%ebp)
	jne	.L43
	movl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	subl	%edx, %eax
	cmpl	$7, %eax
	jg	.L43
	jmp	.L46
.L47:
	movl	-32(%ebp), %eax
	movb	$48, (%eax)
	addl	$1, -32(%ebp)
.L46:
	movl	-32(%ebp), %eax
	movl	8(%ebp), %edx
	subl	%edx, %eax
	cmpl	$7, %eax
	jle	.L47
.L43:
	movl	-32(%ebp), %eax
	movb	$0, (%eax)
	movl	8(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	-32(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -24(%ebp)
	jmp	.L48
.L49:
	movl	-28(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, -1(%ebp)
	movl	-24(%ebp), %eax
	movzbl	(%eax), %edx
	movl	-28(%ebp), %eax
	movb	%dl, (%eax)
	movl	-24(%ebp), %edx
	movzbl	-1(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -28(%ebp)
	subl	$1, -24(%ebp)
.L48:
	movl	-28(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jb	.L49
	leave
	ret
	.size	itoa, .-itoa
	.ident	"GCC: (GNU) 4.2.1 20070719  [FreeBSD]"
