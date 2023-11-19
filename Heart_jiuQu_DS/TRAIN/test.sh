=================================================================
==21==ERROR: AddressSanitizer: heap-use-after-free on address 0x602000000350 at pc 0x56417a7c0fcf bp 0x7ffdbb8e1e90 sp 0x7ffdbb8e1e80
READ of size 4 at 0x602000000350 thread T0
    #2 0x7fca29671082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
0x602000000350 is located 0 bytes inside of 16-byte region [0x602000000350,0x602000000360)
freed by thread T0 here:
    #0 0x7fca2a07f537 in __interceptor_free ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:127
    #2 0x7fca29671082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
previously allocated by thread T0 here:
    #0 0x7fca2a07fa57 in __interceptor_calloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:154
    #4 0x7fca29671082 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x24082)
Shadow bytes around the buggy address:
  0x0c047fff8010: fa fa fd fd fa fa 00 00 fa fa 00 00 fa fa 00 00
  0x0c047fff8020: fa fa 00 00 fa fa fd fa fa fa fd fa fa fa 00 00
  0x0c047fff8030: fa fa fd fd fa fa 00 00 fa fa 00 00 fa fa fd fd
  0x0c047fff8040: fa fa 00 00 fa fa 00 00 fa fa fd fa fa fa 00 fa
  0x0c047fff8050: fa fa fd fa fa fa 00 00 fa fa fd fd fa fa 00 00
=>0x0c047fff8060: fa fa 04 fa fa fa fd fa fa fa[fd]fd fa fa 00 00
  0x0c047fff8070: fa fa 04 fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8090: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff80a0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff80b0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
	Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
	==21==ABORTING
