binary.o: binary.c binary.h
	gcc -c -Wall -Wextra -Werror -fpic binary.c

libbinary.so: binary.o
	gcc -shared -o libbinary.so binary.o
	rm *.o