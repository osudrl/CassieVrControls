filereader.o: src/filereader.c src/filereader.h
	gcc -c src/filereader.c
	mv *.o bin
exe: bin/filereader.o
	gcc bin/*.o -o exe