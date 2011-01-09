#define WHITE_ON_BLACK	0x07
#define	BLACK		0
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define RED			4
#define MAGENTA		5
#define BROWN		6
#define WHITE		7

// port.c
extern unsigned char in( unsigned short _port );
extern void out( unsigned short _port, unsigned char _data );
extern void reboot();

// cursor.c
extern void gotoxy( int x, int y );
extern void update_cursor();
extern int cursX;
extern int cursY;

// memory.c
extern void *memcpy( void *dest, const void *src, int num );
extern void *memset( void *ptr, char val, int num );

// string.c
extern int strlen(const char *str);
extern void strcpy( char *dest, const char *src );
extern int strcmp( const char *str1, const char *str2 );

// screen.c
extern void clrscr();
extern void putch( char c );
extern void prints( char *string );
extern void set_text_attr( int FG, int BG );
extern unsigned char *vidmem;
extern unsigned int screen_width;
extern unsigned int screen_height;
