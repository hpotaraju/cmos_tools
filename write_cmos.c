/* write_cmos: writes value to CMOS register 
** Copyright (C) Barracuda Networks 
** Author: hpotaraju@barracuda.com
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

int ctl_port = 0x70;	
int data_port = 0x71;

int cmos_write (unsigned char reg, unsigned char val)
{
	outb(reg, ctl_port);
	usleep(100000); 	/* Sleep for (100 ms) */ 
	outb(val, data_port);
}


int main(int argc, char *argv[])
{
	unsigned char reg = 0;
	unsigned char val = 0;
	if (argc > 2) {
		reg = (unsigned char) atoi(argv[1]);
		val = (unsigned char) strtol(argv[2], NULL, 16);
		if ((atoi(argv[2]) != 0) && (val == 0)) {
			printf("hex value error\n");
			return 1;
		}
	}
	else {
		printf("Usage: %s <byte position to write> <hex value to write>\n", argv[0]);
		return 1;
	}

	/* Get access to the CMOS I/O ports */
	if (ioperm(ctl_port, 3, 1)) {
  		perror("failed getting port access"); 
		return 1;
	}
  
	cmos_write(reg,val);

	/* Close access */
	if (ioperm(ctl_port, 3, 0)) {
		perror("failed closing port access"); 
		return 1;
	}

	return 0;
}

