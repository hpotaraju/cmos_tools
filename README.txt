read_cmos.c: 
	reads value from byte location in CMOS, and prints it out in hex format
	usage: ./read_cmos <byte location in CMOS (dec)>

write_cmos.c: 
	writes a hex value to byte location in CMOS
	usage: ./write_cmos <byte location in CMOS (dec)> <value to write (hex)>


To compile:
	gcc -O read_cmos.c -o read_cmos
	gcc -O write_cmos.c -o write_cmos


Reference: 
	http://www.bioscentral.com/misc/cmosmap.htm



To reset RTC Clock: 
#	./write_cmos 10 26 
	./write_cmos 11 6 
