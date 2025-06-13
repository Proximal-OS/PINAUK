// Implementation of functions defined in stdio.h
#include "stdio.h"
#include <efi.h>
#include <efilib.h>
#include <libsmbios.h>
#include <stdbool.h>
#include <stdlib.h>

int remove(const char* filename)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
int rename(const char* oldname, const char* newname)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
FILE* tmpfile(void)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
char* tmpnam(char* s)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
int fclose(FILE* stream)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
int fflush(FILE* stream)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
int fgetc(FILE* stream)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
int fputc(int c, FILE* stream)
{
	return -1; // Heck, this OS doesn't even support file accessing yet
}
// Let's just continue with what we can implement now
int printf(const char* format, ...) 
{
	// We're still in UEFI's boot services, let's just convert the string to CHAR16 and use the UEFI's Print function
	CHAR16 buffer[256];
	int i;
	for (i = 0; format[i] != '\0' && i < 255; i++;) 
	{
		buffer[i] = (CHAR16)format[i];
	}
	buffer[i] = 0; // Null-terminate the string
}