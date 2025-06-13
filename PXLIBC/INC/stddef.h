#ifndef stddef_h
#define stddef_h
#define ptrdiff_t long
#define size_t unsigned long
#define wchar_t unsigned short
#define NULL ((void *)0)
#define offsetof(type,member) ((size_t) & ((type *)0)->member)
#endif