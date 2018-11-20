/* read_cmos: reads CMOS register value from location
** Copyright (C) Barracuda Networks 
** Author: hpotaraju@barracuda.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

unsigned char ctl_port = 0x70;	
unsigned char data_port = 0x71;

int cmos_read(unsigned char reg)
{
	outb(reg, ctl_port);
	usleep(100000); 	/* Sleep for (100 ms) */ 
	return inb(data_port);
}


int main(int argc, char *argv[])
{
	unsigned char byte_pos = 0;
	if (argc > 1) {
		byte_pos = (unsigned char) atoi(argv[1]);
	}
	else {
		printf("Usage: %s <byte to read>\n", argv[0]);
		return 1;
	}

	/* Get access to the CMOS I/O ports */
	if (ioperm(ctl_port, 3, 1)) {
  		perror("failed getting port access"); 
		return 1;
	}
  
	printf("byte %d: %x\n", byte_pos, cmos_read(byte_pos));
		

	/* Close access */
	if (ioperm(ctl_port, 3, 0)) {
		perror("failed closing port access"); 
		return 1;
	}

	return 0;
}

