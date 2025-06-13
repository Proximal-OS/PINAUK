#ifndef stdio_h
#define stdio_h
#define FILE void*
#define fpos_t long
#define size_t unsigned long

#define NULL ((void*)0)
#define _IOFBF 0x0000
#define _IOLBF 0x0040
#define _IONBF 0x0004
#define BUFSIZ 1024
#define EOF (-1)
#define FOPEN_MAX 32
#define FILENAME_MAX 256
#define L_tmpnam 256
#define SEEK_CUR 0
#define SEEK_END 1
#define SEEK_SET 2
#define TMP_MAX 256256

#define stdin ((FILE*)0x00000000)
#define stdout ((FILE*)0x00000001)
#define stderr ((FILE*)0x00000002)

#define _PRINTF_NAN_LEN_MAX 256

int remove(const char* filename);
int rename(const char* oldname, const char* newname);
FILE* tmpfile(void);
char* tmpnam(char* s);
int fclose(FILE* stream);
int fflush(FILE* stream);
FILE* fopen(const char* restrict filename, const char* restrict mode);
FILE* freopen(const char* restrict filename, const char* restrict mode,
	FILE* restrict stream);
void setbuf(FILE* restrict stream, char* restrict buf);
int setvbuf(FILE* restrict stream, char* restrict buf, int mode, size_t size);
int printf(const char* restrict format, ...);
int scanf(const char* restrict format, ...);
int snprintf(char* restrict s, size_t n, const char* restrict format, ...);
int sprintf(char* restrict s, const char* restrict format, ...);
int sscanf(const char* restrict s, const char* restrict format, ...);
int vfprintf(FILE* restrict stream, const char* restrict format, va_list arg);
int vfscanf(FILE* restrict stream, const char* restrict format, va_list arg);
int vprintf(const char* restrict format, va_list arg);
int vscanf(const char* restrict format, va_list arg);
int vsnprintf(char* restrict s, size_t n, const char* restrict format, va_list arg);
int vsprintf(char* restrict s, const char* restrict format, va_list arg);
int vsscanf(const char* restrict s, const char* restrict format, va_list arg);
int fgetc(FILE* stream);
char* fgets(char* restrict s, int n, FILE* restrict stream);
int fputc(int c, FILE* stream);
int fputs(const char* restrict s, FILE* restrict stream);
int getc(FILE* stream);
int getchar(void);
int putc(int c, FILE* stream);
int putchar(int c);
int puts(const char* s);
int ungetc(int c, FILE* stream);
size_t fread(void* restrict ptr, size_t size, size_t nmemb,
	FILE* restrict stream);
size_t fwrite(const void* restrict ptr, size_t size, size_t nmemb,
	FILE* restrict stream);
int fgetpos(FILE* restrict stream, fpos_t* restrict pos);
int fseek(FILE* stream, long int offset, int whence);
int fsetpos(FILE* stream, const fpos_t* pos);
long int ftell(FILE* stream);
void rewind(FILE* stream);
void clearerr(FILE* stream);
int feof(FILE* stream);
int ferror(FILE* stream);
void perror(const char* s);
int fprintf(FILE* restrict stream, const char* restrict format, ...);
int fscanf(FILE* restrict stream, const char* restrict format, ...);

#if defined(__STDC_WANT_LIB_EXT1__)

#define L-tmpnam_s(s, smax) tmpnam_s(s, smax, NULL)
#define TMP_MAX_S 25565

typedef int errno_t;
typedef int rsize_t;

errno_t tmpfile_s(FILE* restrict* restrict streamptr);
errno_t tmpnam_s(char* s, rsize_t maxsize);
errno_t fopen_s(FILE* restrict* restrict streamptr,
	const char* restrict filename, const char* restrict mode);
errno_t freopen_s(FILE* restrict* restrict newstreamptr,
	const char* restrict filename, const char* restrict mode,
	FILE* restrict stream);
int fprintf_s(FILE* restrict stream, const char* restrict format, ...);
int fscanf_s(FILE* restrict stream, const char* restrict format, ...);
int printf_s(const char* restrict format, ...);
int scanf_s(const char* restrict format, ...);
int snprintf_s(char* restrict s, rsize_t n, const char* restrict format, ...);
int sprintf_s(char* restrict s, rsize_t n, const char* restrict format, ...);
int sscanf_s(const char* restrict s, const char* restrict format, ...);
int vfprintf_s(FILE* restrict stream, const char* restrict format, va_list arg);
int vfscanf_s(FILE* restrict stream, const char* restrict format, va_list arg);
int vprintf_s(const char* restrict format, va_list arg);
int vscanf_s(const char* restrict format, va_list arg);
int vsnprintf_s(char* restrict s, rsize_t n, const char* restrict format, va_list arg);
int vsprintf_s(char* restrict s, rsize_t n, const char* restrict format, va_list arg);
int vsscanf_s(const char* restrict s, const char* restrict format, va_list arg);
char* gets_s(char* s, rsize_t n);
#endif
#endif	// stdio_h — standard input/output header file
