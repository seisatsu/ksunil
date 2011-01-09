#include "system.h"

unsigned char *vidmem;
unsigned int screen_width = 80, screen_height = 25;
unsigned int text_attr = WHITE_ON_BLACK;				// Set default text attribute to white on black
unsigned int default_text = WHITE_ON_BLACK;				// The default font color is white on black, and is unchanged (unlike text_attr)

void clrscr()
{
	vidmem = (unsigned char *)0xB8000;
	const long size = screen_width * screen_height;
	long loop;
	
	for( loop = 0; loop < size; loop++ )
	{
		*vidmem++ = 0;
		*vidmem++ = text_attr;
	}
	
	// Set cursor position to 0,0
	gotoxy( 0, 0 );
}

void putch( char c )
{
	vidmem = (unsigned char *)0xb8000;
	unsigned short offset;
	//unsigned long i;
	
	// Get the position of where the character should be (cusors's X position * the screen width + cursor's Y position)
	offset = (cursY * screen_width + cursX);

	// Backspace ('\b') is handled by moving the cursor one character back, and setting that character to 0 (erasing it, basically)
	if( c == 0x08 )
	{
		cursX -= 2;
		offset = (cursY * screen_width + cursX );
		vidmem[offset] = 0;
		vidmem[offset+1] = default_text;	// Use default text color so that there won't be a blank space with a different background color
	}

	// New line
	if( c == '\n' )
	{	
		// Add line and go to the start of that line
		cursY += 2;
		cursX = 0;
	}
	
	// Any character that is greater than or equal to a space is printed
	else if( c >= ' ' )
	{
		vidmem[offset] = c;
		vidmem[offset+1] = text_attr;
		cursX += 2;
	}
	
	// Check if the cursor reached the edge of the screen. If so, insert a new line
	if( cursX >= 80 )
	{
		cursX = 0;
		cursY += 2;
	}
	
	// Set the new cursor position
	update_cursor();
}

void prints( char *string )	
{
	int i;
	for( i = 0; i < strlen(string); i++ )
		putch( string[i] );
}

// Sets the text color. First argument is foreground, second argument is background.
void set_text_attr( int FG, int BG )
{
	// The top 4 bytes are the background, and the bottom 4 are foreground.
	text_attr = (BG << 4) | (FG & 0x0F);
}
