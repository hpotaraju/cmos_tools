all: write_cmos read_cmos

read_cmos: read_cmos.c

write_cmos:write_cmos.c


clean:
	rm -f read_cmos write_cmos
