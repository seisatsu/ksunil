#include "system.h"

int strlen(const char *str)
{
    int retval;
    for(retval = 0; *str != '\0'; str++) 
    	retval++;
    return retval;
}

// Copy string src to dest
// Example: strcpy( string1, "test" );	- string1 now contains "test"
// 			strcpy( string1, string2 );	- string1 now contains contents of string2
void strcpy( char *dest, const char *src )
{
	void *dp = (void *)dest;
	const void *sp = (const void *)src;
	int nbytes = strlen(src)+1;
	
	// Basically this calls memcpy on the arguments
	memcpy( dp, sp, nbytes );
}

// Compares two strings.
// Returns 0 if they are equal, 1 if the first string is longer, and -1 if the second string is longer.
// A value greater than 1 indicates that the first character taht does not match has a greater value in str1 than in str2.
// A value less than -1 indicates the opposite.
int strcmp( const char *str1, const char *str2 )
{
	int length1 = strlen( str1 );
	int length2 = strlen( str2 );
	
	// If the first string is longer than the second one, return 1
	if( length1 > length2 )
		return 1;
		
	// If the second string is longer than the first one, return -1
	else if( length2 > length1 )
		return -1;
	
	int i;
	for( i = 0; i < length1; i++ )
	{
		// If the current character in str1 is greater than that of str2, return 2
		if( str1[i] > str2[i] )
			return 2;
			
		// If the current character in str1 is less than that of str2, return -2
		else if( str1[i] < str2[i] )
			return -2;
		
		// Else, they are equal, so do nothing and keep looping
	}
	
	return 0;
}
