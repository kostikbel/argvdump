all:	argvdump

argvdump:	argvdump.c mysyscall.S
	$(CC) -O -ffreestanding -g -c -o argvdump.o argvdump.c
	$(CC) -c -o mysyscall.o mysyscall.S
	$(LD) -e start -o argvdump argvdump.o mysyscall.o
