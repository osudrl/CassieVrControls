#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintest.h"

#include "binary.h"


int main(int argc, char *argv[])
{
	//char *stringEnd;
	//double num = strtod(argv[1], &stringEnd);
	//printf("lmoa %s\n",argv[1]);
	//printf("hai %f \n" , num);
	//printf("hai %d \n" , (int) num);
	//printf("hai %d \n" , round(num));

	int index=12;

	if(argc > 1)
	{
		char *stringEnd;
		double dindex = strtod(argv[1], &stringEnd);
		index = (int) dindex;
	}

	unsigned char letter = letters[index];
	printf("Binary representation to decimal: %d\n", letter);
	printf("letter representation: %c \n", matchToMorse(letter));
	printf("length of morse:%d\n", lengthOfMorse(letter));
	//printBits(letter);
	return 0;
}






/*
void addToWhileOn(int intTime)
{
    float now = intTime;
    float unit = now / unitLength;
    if (unit < THRESH_DASH)
        dot();
    else
        dash();
}
void addToWhileOff(int intTime)
{
    float now = intTime;
    float unitt = now / unitLength;
    if (unitt > THRESH_SPACE) {
        currMorseIndex++;
        currMorseIndex++;
    }
    else if (unitt > THRESH_NEWLETTER) {
        currMorseIndex++;
    }
}
void addDashOrDot(byte value)
{
    int howLong = lengthOfMorse(currMorse[currMorseIndex]);
    howLong++;
    byte bitToChange = 7 - (howLong + 2);
    currMorse[currMorseIndex] ^= (-value ^ currMorse[currMorseIndex]) & (1 << bitToChange);
    for (int i = 0; i < 3; i++) {
        byte exponent = 2 - i;
        value = 0;
        byte binNum = round(pow(2, exponent));
        if (howLong >= binNum) {
            howLong -= binNum;
            value = 1;
        }
        bitToChange = (7 - i);
        currMorse[currMorseIndex] ^= (-value ^ currMorse[currMorseIndex]) & (1 << bitToChange);
    }
    for (int i = 0; i < 8; i++) {
        int bitt = (currMorse[currMorseIndex] >> (7 - i)) & 1;
    }
}
void dash()
{
    addDashOrDot(1);
}
void dot()
{
    addDashOrDot(0);
}
*/
