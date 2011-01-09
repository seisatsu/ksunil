#include "system.h"

int cursX = 0, cursY = 0;

// Set cursor position to x,y
void gotoxy( int x, int y )
{
	// Get position using this simple equation
	int position = ( y * screen_width + x );
	
	out( 0x3D4, 14 );
	out( 0x3D5, position >> 8 );
	out( 0x3D4, 15 );
	out( 0x3D5, position );
}

// Basically just calls gotoxy() with the current cusor position (cursX,cursY)
void update_cursor()
{
	gotoxy( cursX, cursY );
}
