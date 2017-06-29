bin/filereader.o: src/filereader.c src/filereader.h
	gcc -c src/filereader.c
	mv *.o bin
filereader.lexe: bin/filereader.o
	gcc bin/*.o -o filereader.lexe