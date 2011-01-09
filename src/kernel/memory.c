#include "system.h"

// Copys num bytes of memory src to dest
void *memcpy( void *dest, const void *src, int num )
{
	char *dp = (char *)dest;
	const char *sp = (const char *)src;
	for( ; num != 0; num-- )
		*dp++ = *sp++;
	return dp;
}

// Sets the first num bytes of the block of memory ptr to specified value
void *memset( void *ptr, char val, int num )
{
	char *temp = (char *)ptr;
	for( ; num != 0; num-- )
		*temp++ = val;
	return ptr;
}
