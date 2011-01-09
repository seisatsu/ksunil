nasm -f elf src/boot/bootsect.asm -o obj/bootsect.o

# Compile all the files
gcc -m32 -o obj/main.o -c src/kernel/main.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -m32 -o obj/port.o -c src/kernel/port.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -m32 -o obj/cursor.o -c src/kernel/cursor.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -m32 -o obj/memory.o -c src/kernel/memory.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -m32 -o obj/string.o -c src/kernel/string.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector
gcc -m32 -o obj/screen.o -c src/kernel/screen.c -Wall -Wextra -Werror -I src/include/ -nostdlib -nostartfiles -nodefaultlibs -ffreestanding -fno-stack-protector

# Link all object files into kernel.bin
ld -melf_i386 -T linker.ld -o bin/kernel.bin obj/bootsect.o obj/main.o obj/port.o obj/cursor.o obj/memory.o obj/string.o obj/screen.o

# Create a floppy image
rm floppy.img
cat stage1 stage2 pad bin/kernel.bin > floppy.img
