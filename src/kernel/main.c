#include "system.h"

void kmain()
{
	char string[] = "This is a test string!\nAin't it pretty??\b";
	clrscr();
	memset( string, '-', 4 );

	// Set the text to white on blue
	set_text_attr( WHITE, BLUE );
	prints( string );
	
	set_text_attr( RED, BLACK );
	prints( "\nW" );
	
	set_text_attr( BLUE, BLACK );
	prints( "o" );
	
	set_text_attr( GREEN, BLACK );
	prints( "a" );
	
	set_text_attr( CYAN, BLACK );
	prints( "h" );
	
	set_text_attr( MAGENTA, GREEN );
	prints( "!" );
	//reboot();
	
	// Kernel should be in a continuous loop
	for(;;);
}
