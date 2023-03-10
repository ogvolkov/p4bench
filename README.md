# Benchmarking powers of 4 check
What is the fastest way to check if a number is a power of 4?

(for purely recreational purposes because https://leetcode.com/problems/power-of-four/)

## Build and run
Needs cmake and [benchmark](https://github.com/google/benchmark) (installed in  a subdirectory).
```
cmake ..
cmake --build .
./benchp4
```
## Results
```
Run on (32 X 2995.2 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x16)
  L1 Instruction 32 KiB (x16)
  L2 Unified 2048 KiB (x16)
  L3 Unified 36864 KiB (x1)
Load Average: 0.00, 0.04, 0.10
***WARNING*** Library was built as DEBUG. Timings may be affected.
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_While      2182572982 ns   2182562100 ns            1
BM_Bit        1157890940 ns   1157889200 ns            1
BM_BitNegMask  958022176 ns    958023300 ns            1
BM_BitMath     953153775 ns    953155000 ns            1
BM_Log        9286177087 ns   9286134500 ns            1
BM_Switch     3217969320 ns   3217970600 ns            1
BM_Rec        1410726022 ns   1410727300 ns            1
BM_PopCount   2842222163 ns   2842222800 ns            1
```

## Disassembly
```
000000000000b680 <_Z7p4Whilei>:
    b680:	f3 0f 1e fa          	endbr64 
    b684:	31 c0                	xor    %eax,%eax
    b686:	85 ff                	test   %edi,%edi
    b688:	7e 30                	jle    b6ba <_Z7p4Whilei+0x3a>
    b68a:	83 ff 01             	cmp    $0x1,%edi
    b68d:	74 1f                	je     b6ae <_Z7p4Whilei+0x2e>
    b68f:	40 f6 c7 03          	test   $0x3,%dil
    b693:	74 11                	je     b6a6 <_Z7p4Whilei+0x26>
    b695:	eb 24                	jmp    b6bb <_Z7p4Whilei+0x3b>
    b697:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    b69e:	00 00 
    b6a0:	40 f6 c7 03          	test   $0x3,%dil
    b6a4:	75 12                	jne    b6b8 <_Z7p4Whilei+0x38>
    b6a6:	c1 ff 02             	sar    $0x2,%edi
    b6a9:	83 ff 01             	cmp    $0x1,%edi
    b6ac:	7f f2                	jg     b6a0 <_Z7p4Whilei+0x20>
    b6ae:	b8 01 00 00 00       	mov    $0x1,%eax
    b6b3:	c3                   	ret    
    b6b4:	0f 1f 40 00          	nopl   0x0(%rax)
    b6b8:	31 c0                	xor    %eax,%eax
    b6ba:	c3                   	ret    
    b6bb:	c3                   	ret    
    b6bc:	0f 1f 40 00          	nopl   0x0(%rax)

000000000000b6c0 <_Z5p4Biti>:
    b6c0:	f3 0f 1e fa          	endbr64 
    b6c4:	31 c0                	xor    %eax,%eax
    b6c6:	85 ff                	test   %edi,%edi
    b6c8:	7e 08                	jle    b6d2 <_Z5p4Biti+0x12>
    b6ca:	f7 c7 aa aa aa aa    	test   $0xaaaaaaaa,%edi
    b6d0:	74 06                	je     b6d8 <_Z5p4Biti+0x18>
    b6d2:	c3                   	ret    
    b6d3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    b6d8:	8d 47 ff             	lea    -0x1(%rdi),%eax
    b6db:	85 f8                	test   %edi,%eax
    b6dd:	0f 94 c0             	sete   %al
    b6e0:	c3                   	ret    
    b6e1:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    b6e8:	00 00 00 00 
    b6ec:	0f 1f 40 00          	nopl   0x0(%rax)

000000000000b6f0 <_Z12p4BitNegMaski>:
    b6f0:	f3 0f 1e fa          	endbr64 
    b6f4:	31 c0                	xor    %eax,%eax
    b6f6:	85 ff                	test   %edi,%edi
    b6f8:	7e 0d                	jle    b707 <_Z12p4BitNegMaski+0x17>
    b6fa:	8d 47 ff             	lea    -0x1(%rdi),%eax
    b6fd:	0d aa aa aa 2a       	or     $0x2aaaaaaa,%eax
    b702:	85 f8                	test   %edi,%eax
    b704:	0f 94 c0             	sete   %al
    b707:	c3                   	ret    
    b708:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    b70f:	00 

000000000000b710 <_Z9p4BitMathi>:
    b710:	f3 0f 1e fa          	endbr64 
    b714:	31 c0                	xor    %eax,%eax
    b716:	85 ff                	test   %edi,%edi
    b718:	7e 27                	jle    b741 <_Z9p4BitMathi+0x31>
    b71a:	8d 57 ff             	lea    -0x1(%rdi),%edx
    b71d:	85 fa                	test   %edi,%edx
    b71f:	75 20                	jne    b741 <_Z9p4BitMathi+0x31>
    b721:	48 63 c7             	movslq %edi,%rax
    b724:	89 fa                	mov    %edi,%edx
    b726:	48 69 c0 56 55 55 55 	imul   $0x55555556,%rax,%rax
    b72d:	c1 fa 1f             	sar    $0x1f,%edx
    b730:	48 c1 e8 20          	shr    $0x20,%rax
    b734:	29 d0                	sub    %edx,%eax
    b736:	8d 04 40             	lea    (%rax,%rax,2),%eax
    b739:	29 c7                	sub    %eax,%edi
    b73b:	83 ff 01             	cmp    $0x1,%edi
    b73e:	0f 94 c0             	sete   %al
    b741:	c3                   	ret    
    b742:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    b749:	00 00 00 00 
    b74d:	0f 1f 00             	nopl   (%rax)

000000000000b750 <_Z5p4Logi>:
    b750:	f3 0f 1e fa          	endbr64 
    b754:	41 54                	push   %r12
    b756:	45 31 e4             	xor    %r12d,%r12d
    b759:	85 ff                	test   %edi,%edi
    b75b:	7e 34                	jle    b791 <_Z5p4Logi+0x41>
    b75d:	66 0f ef c0          	pxor   %xmm0,%xmm0
    b761:	f2 0f 2a c7          	cvtsi2sd %edi,%xmm0
    b765:	e8 66 b9 ff ff       	call   70d0 <log2@plt>
    b76a:	f2 0f 59 05 86 09 05 	mulsd  0x50986(%rip),%xmm0        # 5c0f8 <_IO_stdin_used+0xf8>
    b771:	00 
    b772:	66 0f ef c9          	pxor   %xmm1,%xmm1
    b776:	f2 0f 2c c0          	cvttsd2si %xmm0,%eax
    b77a:	f2 0f 2a c8          	cvtsi2sd %eax,%xmm1
    b77e:	f2 0f 5c c1          	subsd  %xmm1,%xmm0
    b782:	66 0f 2e 05 76 09 05 	ucomisd 0x50976(%rip),%xmm0        # 5c100 <_IO_stdin_used+0x100>
    b789:	00 
    b78a:	0f 9b c0             	setnp  %al
    b78d:	44 0f 44 e0          	cmove  %eax,%r12d
    b791:	44 89 e0             	mov    %r12d,%eax
    b794:	41 5c                	pop    %r12
    b796:	c3                   	ret    
    b797:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    b79e:	00 00 

000000000000b7a0 <_Z8p4Switchi>:
    b7a0:	f3 0f 1e fa          	endbr64 
    b7a4:	81 ff 00 00 01 00    	cmp    $0x10000,%edi
    b7aa:	0f 84 b8 00 00 00    	je     b868 <_Z8p4Switchi+0xc8>
    b7b0:	7f 3e                	jg     b7f0 <_Z8p4Switchi+0x50>
    b7b2:	81 ff 00 01 00 00    	cmp    $0x100,%edi
    b7b8:	0f 84 aa 00 00 00    	je     b868 <_Z8p4Switchi+0xc8>
    b7be:	7f 60                	jg     b820 <_Z8p4Switchi+0x80>
    b7c0:	83 ff 01             	cmp    $0x1,%edi
    b7c3:	0f 84 9f 00 00 00    	je     b868 <_Z8p4Switchi+0xc8>
    b7c9:	8d 4f fc             	lea    -0x4(%rdi),%ecx
    b7cc:	83 f9 3c             	cmp    $0x3c,%ecx
    b7cf:	0f 87 9b 00 00 00    	ja     b870 <_Z8p4Switchi+0xd0>
    b7d5:	48 b8 01 10 00 00 00 	movabs $0x1000000000001001,%rax
    b7dc:	00 00 10 
    b7df:	48 d3 e8             	shr    %cl,%rax
    b7e2:	83 e0 01             	and    $0x1,%eax
    b7e5:	c3                   	ret    
    b7e6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    b7ed:	00 00 00 
    b7f0:	81 ff 00 00 00 01    	cmp    $0x1000000,%edi
    b7f6:	74 70                	je     b868 <_Z8p4Switchi+0xc8>
    b7f8:	b8 01 00 00 00       	mov    $0x1,%eax
    b7fd:	7e 49                	jle    b848 <_Z8p4Switchi+0xa8>
    b7ff:	81 ff 00 00 00 10    	cmp    $0x10000000,%edi
    b805:	74 39                	je     b840 <_Z8p4Switchi+0xa0>
    b807:	81 ff 00 00 00 40    	cmp    $0x40000000,%edi
    b80d:	74 31                	je     b840 <_Z8p4Switchi+0xa0>
    b80f:	81 ff 00 00 00 04    	cmp    $0x4000000,%edi
    b815:	0f 94 c0             	sete   %al
    b818:	c3                   	ret    
    b819:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    b820:	b8 01 00 00 00       	mov    $0x1,%eax
    b825:	81 ff 00 10 00 00    	cmp    $0x1000,%edi
    b82b:	74 53                	je     b880 <_Z8p4Switchi+0xe0>
    b82d:	81 ff 00 40 00 00    	cmp    $0x4000,%edi
    b833:	74 0b                	je     b840 <_Z8p4Switchi+0xa0>
    b835:	81 ff 00 04 00 00    	cmp    $0x400,%edi
    b83b:	0f 94 c0             	sete   %al
    b83e:	c3                   	ret    
    b83f:	90                   	nop
    b840:	c3                   	ret    
    b841:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    b848:	81 ff 00 00 10 00    	cmp    $0x100000,%edi
    b84e:	74 28                	je     b878 <_Z8p4Switchi+0xd8>
    b850:	81 ff 00 00 40 00    	cmp    $0x400000,%edi
    b856:	74 e8                	je     b840 <_Z8p4Switchi+0xa0>
    b858:	81 ff 00 00 04 00    	cmp    $0x40000,%edi
    b85e:	0f 94 c0             	sete   %al
    b861:	c3                   	ret    
    b862:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    b868:	b8 01 00 00 00       	mov    $0x1,%eax
    b86d:	c3                   	ret    
    b86e:	66 90                	xchg   %ax,%ax
    b870:	31 c0                	xor    %eax,%eax
    b872:	c3                   	ret    
    b873:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    b878:	c3                   	ret    
    b879:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    b880:	c3                   	ret    
    b881:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    b888:	00 00 00 00 
    b88c:	0f 1f 40 00          	nopl   0x0(%rax)

000000000000b890 <_Z5p4Reci>:
    b890:	f3 0f 1e fa          	endbr64 
    b894:	31 c0                	xor    %eax,%eax
    b896:	85 ff                	test   %edi,%edi
    b898:	7e 12                	jle    b8ac <_Z5p4Reci+0x1c>
    b89a:	b8 01 00 00 00       	mov    $0x1,%eax
    b89f:	83 ff 01             	cmp    $0x1,%edi
    b8a2:	74 08                	je     b8ac <_Z5p4Reci+0x1c>
    b8a4:	31 c0                	xor    %eax,%eax
    b8a6:	40 f6 c7 03          	test   $0x3,%dil
    b8aa:	74 04                	je     b8b0 <_Z5p4Reci+0x20>
    b8ac:	c3                   	ret    
    b8ad:	0f 1f 00             	nopl   (%rax)
    b8b0:	89 fa                	mov    %edi,%edx
    b8b2:	c1 fa 02             	sar    $0x2,%edx
    b8b5:	74 f5                	je     b8ac <_Z5p4Reci+0x1c>
    b8b7:	b8 01 00 00 00       	mov    $0x1,%eax
    b8bc:	83 fa 01             	cmp    $0x1,%edx
    b8bf:	74 eb                	je     b8ac <_Z5p4Reci+0x1c>
    b8c1:	83 e2 03             	and    $0x3,%edx
    b8c4:	74 0a                	je     b8d0 <_Z5p4Reci+0x40>
    b8c6:	31 c0                	xor    %eax,%eax
    b8c8:	c3                   	ret    
    b8c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    b8d0:	89 f8                	mov    %edi,%eax
    b8d2:	c1 f8 04             	sar    $0x4,%eax
    b8d5:	74 ef                	je     b8c6 <_Z5p4Reci+0x36>
    b8d7:	83 f8 01             	cmp    $0x1,%eax
    b8da:	74 24                	je     b900 <_Z5p4Reci+0x70>
    b8dc:	a8 03                	test   $0x3,%al
    b8de:	75 e6                	jne    b8c6 <_Z5p4Reci+0x36>
    b8e0:	c1 ff 06             	sar    $0x6,%edi
    b8e3:	74 e1                	je     b8c6 <_Z5p4Reci+0x36>
    b8e5:	83 ff 01             	cmp    $0x1,%edi
    b8e8:	74 16                	je     b900 <_Z5p4Reci+0x70>
    b8ea:	83 e7 03             	and    $0x3,%edi
    b8ed:	75 d7                	jne    b8c6 <_Z5p4Reci+0x36>
    b8ef:	89 c7                	mov    %eax,%edi
    b8f1:	89 f8                	mov    %edi,%eax
    b8f3:	c1 f8 04             	sar    $0x4,%eax
    b8f6:	75 df                	jne    b8d7 <_Z5p4Reci+0x47>
    b8f8:	31 c0                	xor    %eax,%eax
    b8fa:	eb cc                	jmp    b8c8 <_Z5p4Reci+0x38>
    b8fc:	0f 1f 40 00          	nopl   0x0(%rax)
    b900:	b8 01 00 00 00       	mov    $0x1,%eax
    b905:	c3                   	ret    
    b906:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    b90d:	00 00 00 
```

## -march=skylake

```
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
BM_While      2176589598 ns   2176574900 ns            1
BM_Bit        1442913562 ns   1442901100 ns            1
BM_BitNegMask 1441099755 ns   1441101100 ns            1
BM_BitMath    1632675015 ns   1632676300 ns            1
BM_Log        9526241451 ns   9526237100 ns            1
BM_Switch     3086262510 ns   3086263900 ns            1
BM_Rec        1461226654 ns   1461226900 ns            1
BM_PopCount   1126120787 ns   1126121000 ns            1
BM_Alexey     1069434627 ns   1069435000 ns            1
```

```
000000000000c070 <_Z7p4Whilei>:
    c070:	f3 0f 1e fa          	endbr64 
    c074:	31 c0                	xor    %eax,%eax
    c076:	85 ff                	test   %edi,%edi
    c078:	7e 30                	jle    c0aa <_Z7p4Whilei+0x3a>
    c07a:	83 ff 01             	cmp    $0x1,%edi
    c07d:	74 1f                	je     c09e <_Z7p4Whilei+0x2e>
    c07f:	40 f6 c7 03          	test   $0x3,%dil
    c083:	74 11                	je     c096 <_Z7p4Whilei+0x26>
    c085:	eb 24                	jmp    c0ab <_Z7p4Whilei+0x3b>
    c087:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    c08e:	00 00 
    c090:	40 f6 c7 03          	test   $0x3,%dil
    c094:	75 12                	jne    c0a8 <_Z7p4Whilei+0x38>
    c096:	c1 ff 02             	sar    $0x2,%edi
    c099:	83 ff 01             	cmp    $0x1,%edi
    c09c:	7f f2                	jg     c090 <_Z7p4Whilei+0x20>
    c09e:	b8 01 00 00 00       	mov    $0x1,%eax
    c0a3:	c3                   	ret    
    c0a4:	0f 1f 40 00          	nopl   0x0(%rax)
    c0a8:	31 c0                	xor    %eax,%eax
    c0aa:	c3                   	ret    
    c0ab:	c3                   	ret    
    c0ac:	0f 1f 40 00          	nopl   0x0(%rax)
    
000000000000bfb0 <_Z5p4Biti>:
    bfb0:	f3 0f 1e fa          	endbr64 
    bfb4:	31 c0                	xor    %eax,%eax
    bfb6:	85 ff                	test   %edi,%edi
    bfb8:	7e 08                	jle    bfc2 <_Z5p4Biti+0x12>
    bfba:	f7 c7 aa aa aa aa    	test   $0xaaaaaaaa,%edi
    bfc0:	74 06                	je     bfc8 <_Z5p4Biti+0x18>
    bfc2:	c3                   	ret    
    bfc3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    bfc8:	c4 e2 40 f3 cf       	blsr   %edi,%edi
    bfcd:	0f 94 c0             	sete   %al
    bfd0:	c3                   	ret    
    bfd1:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    bfd8:	00 00 00 00 
    bfdc:	0f 1f 40 00          	nopl   0x0(%rax)

000000000000bfe0 <_Z12p4BitNegMaski>:
    bfe0:	f3 0f 1e fa          	endbr64 
    bfe4:	31 c0                	xor    %eax,%eax
    bfe6:	85 ff                	test   %edi,%edi
    bfe8:	7e 0d                	jle    bff7 <_Z12p4BitNegMaski+0x17>
    bfea:	8d 47 ff             	lea    -0x1(%rdi),%eax
    bfed:	0d aa aa aa 2a       	or     $0x2aaaaaaa,%eax
    bff2:	85 f8                	test   %edi,%eax
    bff4:	0f 94 c0             	sete   %al
    bff7:	c3                   	ret    
    bff8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    bfff:	00 

000000000000c000 <_Z9p4BitMathi>:
    c000:	f3 0f 1e fa          	endbr64 
    c004:	31 c0                	xor    %eax,%eax
    c006:	85 ff                	test   %edi,%edi
    c008:	7e 27                	jle    c031 <_Z9p4BitMathi+0x31>
    c00a:	c4 e2 68 f3 cf       	blsr   %edi,%edx
    c00f:	75 20                	jne    c031 <_Z9p4BitMathi+0x31>
    c011:	48 63 c7             	movslq %edi,%rax
    c014:	48 69 c0 56 55 55 55 	imul   $0x55555556,%rax,%rax
    c01b:	89 fa                	mov    %edi,%edx
    c01d:	c1 fa 1f             	sar    $0x1f,%edx
    c020:	48 c1 e8 20          	shr    $0x20,%rax
    c024:	29 d0                	sub    %edx,%eax
    c026:	8d 04 40             	lea    (%rax,%rax,2),%eax
    c029:	29 c7                	sub    %eax,%edi
    c02b:	83 ff 01             	cmp    $0x1,%edi
    c02e:	0f 94 c0             	sete   %al
    c031:	c3                   	ret    
    c032:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    c039:	00 00 00 00 
    c03d:	0f 1f 00             	nopl   (%rax)

000000000000c040 <_Z5p4Logi>:
    c040:	f3 0f 1e fa          	endbr64 
    c044:	41 54                	push   %r12
    c046:	45 31 e4             	xor    %r12d,%r12d
    c049:	85 ff                	test   %edi,%edi
    c04b:	7e 34                	jle    c081 <_Z5p4Logi+0x41>
    c04d:	c5 f0 57 c9          	vxorps %xmm1,%xmm1,%xmm1
    c051:	c5 f3 2a c7          	vcvtsi2sd %edi,%xmm1,%xmm0
    c055:	e8 56 b0 ff ff       	call   70b0 <log2@plt>
    c05a:	c5 fb 59 05 96 20 05 	vmulsd 0x52096(%rip),%xmm0,%xmm0        # 5e0f8 <_IO_stdin_used+0xf8>
    c061:	00 
    c062:	c5 f0 57 c9          	vxorps %xmm1,%xmm1,%xmm1
    c066:	c5 fb 2c c0          	vcvttsd2si %xmm0,%eax
    c06a:	c5 f3 2a c8          	vcvtsi2sd %eax,%xmm1,%xmm1
    c06e:	c5 fb 5c c1          	vsubsd %xmm1,%xmm0,%xmm0
    c072:	c5 f9 2e 05 86 20 05 	vucomisd 0x52086(%rip),%xmm0        # 5e100 <_IO_stdin_used+0x100>
    c079:	00 
    c07a:	0f 9b c0             	setnp  %al
    c07d:	44 0f 44 e0          	cmove  %eax,%r12d
    c081:	44 89 e0             	mov    %r12d,%eax
    c084:	41 5c                	pop    %r12
    c086:	c3                   	ret    
    c087:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    c08e:	00 00 

000000000000c090 <_Z8p4Switchi>:
    c090:	f3 0f 1e fa          	endbr64 
    c094:	81 ff 00 00 01 00    	cmp    $0x10000,%edi
    c09a:	0f 84 b8 00 00 00    	je     c158 <_Z8p4Switchi+0xc8>
    c0a0:	7f 3e                	jg     c0e0 <_Z8p4Switchi+0x50>
    c0a2:	81 ff 00 01 00 00    	cmp    $0x100,%edi
    c0a8:	0f 84 aa 00 00 00    	je     c158 <_Z8p4Switchi+0xc8>
    c0ae:	7f 60                	jg     c110 <_Z8p4Switchi+0x80>
    c0b0:	83 ff 01             	cmp    $0x1,%edi
    c0b3:	0f 84 9f 00 00 00    	je     c158 <_Z8p4Switchi+0xc8>
    c0b9:	83 ef 04             	sub    $0x4,%edi
    c0bc:	83 ff 3c             	cmp    $0x3c,%edi
    c0bf:	0f 87 9b 00 00 00    	ja     c160 <_Z8p4Switchi+0xd0>
    c0c5:	48 b8 01 10 00 00 00 	movabs $0x1000000000001001,%rax
    c0cc:	00 00 10 
    c0cf:	c4 e2 c3 f7 c0       	shrx   %rdi,%rax,%rax
    c0d4:	83 e0 01             	and    $0x1,%eax
    c0d7:	c3                   	ret    
    c0d8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    c0df:	00 
    c0e0:	81 ff 00 00 00 01    	cmp    $0x1000000,%edi
    c0e6:	74 70                	je     c158 <_Z8p4Switchi+0xc8>
    c0e8:	b8 01 00 00 00       	mov    $0x1,%eax
    c0ed:	7e 49                	jle    c138 <_Z8p4Switchi+0xa8>
    c0ef:	81 ff 00 00 00 10    	cmp    $0x10000000,%edi
    c0f5:	74 39                	je     c130 <_Z8p4Switchi+0xa0>
    c0f7:	81 ff 00 00 00 40    	cmp    $0x40000000,%edi
    c0fd:	74 31                	je     c130 <_Z8p4Switchi+0xa0>
    c0ff:	81 ff 00 00 00 04    	cmp    $0x4000000,%edi
    c105:	0f 94 c0             	sete   %al
    c108:	c3                   	ret    
    c109:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    c110:	b8 01 00 00 00       	mov    $0x1,%eax
    c115:	81 ff 00 10 00 00    	cmp    $0x1000,%edi
    c11b:	74 53                	je     c170 <_Z8p4Switchi+0xe0>
    c11d:	81 ff 00 40 00 00    	cmp    $0x4000,%edi
    c123:	74 0b                	je     c130 <_Z8p4Switchi+0xa0>
    c125:	81 ff 00 04 00 00    	cmp    $0x400,%edi
    c12b:	0f 94 c0             	sete   %al
    c12e:	c3                   	ret    
    c12f:	90                   	nop
    c130:	c3                   	ret    
    c131:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    c138:	81 ff 00 00 10 00    	cmp    $0x100000,%edi
    c13e:	74 28                	je     c168 <_Z8p4Switchi+0xd8>
    c140:	81 ff 00 00 40 00    	cmp    $0x400000,%edi
    c146:	74 e8                	je     c130 <_Z8p4Switchi+0xa0>
    c148:	81 ff 00 00 04 00    	cmp    $0x40000,%edi
    c14e:	0f 94 c0             	sete   %al
    c151:	c3                   	ret    
    c152:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    c158:	b8 01 00 00 00       	mov    $0x1,%eax
    c15d:	c3                   	ret    
    c15e:	66 90                	xchg   %ax,%ax
    c160:	31 c0                	xor    %eax,%eax
    c162:	c3                   	ret    
    c163:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    c168:	c3                   	ret    
    c169:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    c170:	c3                   	ret    
    c171:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    c178:	00 00 00 00 
    c17c:	0f 1f 40 00          	nopl   0x0(%rax)

000000000000c180 <_Z5p4Reci>:
    c180:	f3 0f 1e fa          	endbr64 
    c184:	31 c0                	xor    %eax,%eax
    c186:	85 ff                	test   %edi,%edi
    c188:	7e 12                	jle    c19c <_Z5p4Reci+0x1c>
    c18a:	b8 01 00 00 00       	mov    $0x1,%eax
    c18f:	83 ff 01             	cmp    $0x1,%edi
    c192:	74 08                	je     c19c <_Z5p4Reci+0x1c>
    c194:	31 c0                	xor    %eax,%eax
    c196:	40 f6 c7 03          	test   $0x3,%dil
    c19a:	74 04                	je     c1a0 <_Z5p4Reci+0x20>
    c19c:	c3                   	ret    
    c19d:	0f 1f 00             	nopl   (%rax)
    c1a0:	89 fa                	mov    %edi,%edx
    c1a2:	c1 fa 02             	sar    $0x2,%edx
    c1a5:	74 f5                	je     c19c <_Z5p4Reci+0x1c>
    c1a7:	b8 01 00 00 00       	mov    $0x1,%eax
    c1ac:	83 fa 01             	cmp    $0x1,%edx
    c1af:	74 eb                	je     c19c <_Z5p4Reci+0x1c>
    c1b1:	83 e2 03             	and    $0x3,%edx
    c1b4:	74 0a                	je     c1c0 <_Z5p4Reci+0x40>
    c1b6:	31 c0                	xor    %eax,%eax
    c1b8:	c3                   	ret    
    c1b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    c1c0:	89 f8                	mov    %edi,%eax
    c1c2:	c1 f8 04             	sar    $0x4,%eax
    c1c5:	74 ef                	je     c1b6 <_Z5p4Reci+0x36>
    c1c7:	83 f8 01             	cmp    $0x1,%eax
    c1ca:	74 24                	je     c1f0 <_Z5p4Reci+0x70>
    c1cc:	a8 03                	test   $0x3,%al
    c1ce:	75 e6                	jne    c1b6 <_Z5p4Reci+0x36>
    c1d0:	c1 ff 06             	sar    $0x6,%edi
    c1d3:	74 e1                	je     c1b6 <_Z5p4Reci+0x36>
    c1d5:	83 ff 01             	cmp    $0x1,%edi
    c1d8:	74 16                	je     c1f0 <_Z5p4Reci+0x70>
    c1da:	83 e7 03             	and    $0x3,%edi
    c1dd:	75 d7                	jne    c1b6 <_Z5p4Reci+0x36>
    c1df:	89 c7                	mov    %eax,%edi
    c1e1:	89 f8                	mov    %edi,%eax
    c1e3:	c1 f8 04             	sar    $0x4,%eax
    c1e6:	75 df                	jne    c1c7 <_Z5p4Reci+0x47>
    c1e8:	31 c0                	xor    %eax,%eax
    c1ea:	eb cc                	jmp    c1b8 <_Z5p4Reci+0x38>
    c1ec:	0f 1f 40 00          	nopl   0x0(%rax)
    c1f0:	b8 01 00 00 00       	mov    $0x1,%eax
    c1f5:	c3                   	ret    
    c1f6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    c1fd:	00 00 00

    000000000000c3b0 <_Z10p4PopCounti>:
    c3b0:	f3 0f 1e fa          	endbr64 
    c3b4:	31 c0                	xor    %eax,%eax
    c3b6:	85 ff                	test   %edi,%edi
    c3b8:	7e 0b                	jle    c3c5 <_Z10p4PopCounti+0x15>
    c3ba:	31 d2                	xor    %edx,%edx
    c3bc:	f3 0f b8 d7          	popcnt %edi,%edx
    c3c0:	83 fa 01             	cmp    $0x1,%edx
    c3c3:	74 0b                	je     c3d0 <_Z10p4PopCounti+0x20>
    c3c5:	c3                   	ret    
    c3c6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    c3cd:	00 00 00 
    c3d0:	ff cf                	dec    %edi
    c3d2:	f3 0f b8 ff          	popcnt %edi,%edi
    c3d6:	29 fa                	sub    %edi,%edx
    c3d8:	89 d0                	mov    %edx,%eax
    c3da:	83 e0 01             	and    $0x1,%eax
    c3dd:	c3                   	ret    
    c3de:	66 90                	xchg   %ax,%ax

    000000000000c4e0 <_Z8p4Alexeyi>:
    c4e0:	f3 0f 1e fa          	endbr64 
    c4e4:	31 c0                	xor    %eax,%eax
    c4e6:	85 ff                	test   %edi,%edi
    c4e8:	7e 0d                	jle    c4f7 <_Z8p4Alexeyi+0x17>
    c4ea:	8d 47 ff             	lea    -0x1(%rdi),%eax
    c4ed:	0d aa aa aa aa       	or     $0xaaaaaaaa,%eax
    c4f2:	85 f8                	test   %edi,%eax
    c4f4:	0f 94 c0             	sete   %al
    c4f7:	c3                   	ret    
    c4f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    c4ff:	00  
    ```