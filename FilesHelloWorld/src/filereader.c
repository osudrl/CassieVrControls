#include "filereader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	printf("%s\n", "Hello World");

	FILE *in = fopen("data.txt" , "r");
	FILE *out = fopen("myoutput.txt", "w");

	char line[80];

	while(fscanf(in,"%79[^\n]\n", line) == 1)
	{
		if(line[1] == '1')
			fprintf(out, "%s\n", line);
		fprintf(stdout, "Readline:  %s\n", line);
	}

	fclose(in);
	fclose(out);

	return 0;
}

