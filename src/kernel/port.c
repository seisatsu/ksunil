#include "system.h"

unsigned char in( unsigned short _port )
{
	unsigned char ret;
	__asm__ __volatile__ ( "inb %1, %0" : "=a" (ret) : "dN" (_port) );
	return ret;
}

void out( unsigned short _port, unsigned char _data )
{
    __asm__ __volatile__ ( "outb %1, %0" : : "dN" (_port), "a" (_data) );
}

// Reboot the computer
void reboot()
{
	set_text_attr( RED, BLACK );
	prints( "\nSystem is restarting!" );
	out( 0x64, 0xFE );
}
