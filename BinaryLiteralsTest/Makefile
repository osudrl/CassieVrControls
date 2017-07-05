LC := /home/kellark/Documents/CassieVrControls/BinaryLibCreator/ 

bintest.lexe: bintest.c
	gcc -L$(LC) -I$(LC) -Wl,-rpath=$(LC) -Wall -Wextra -o bintest.lexe bintest.c -lbinary

