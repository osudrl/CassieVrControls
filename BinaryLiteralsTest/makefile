bin/binary.o: src/binary.c src/binary.h src/kmath.h src/kmath.c
	gcc -c src/binary.c
	mv *.o bin
bin/kmath.o: src/kmath.h src/kmath.c
	gcc -c src/kmath.c
	mv *.o bin
bin/bintest.o: src/binary.c src/binary.h src/kmath.h src/kmath.c src/bintest.c src/bintest.h
	gcc -c src/bintest.c
	mv *.o bin
binary.lexe: bin/binary.o bin/bintest.o bin/kmath.o
	gcc bin/*.o -o binary.lexe