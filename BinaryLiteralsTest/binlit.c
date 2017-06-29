#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binlit.h"

const unsigned char letters[] = {
    /*A*/ 0b01001000,
    /*B*/ 0b10010000,
    /*C*/ 0b10010100,
    /*D*/ 0b01110000,
    /*E*/ 0b00100000,
    /*F*/ 0b10000100,
    /*G*/ 0b01111000,
    /*H*/ 0b10000000,
    /*I*/ 0b01000000,
    /*J*/ 0b10001110,
    /*K*/ 0b01110100,
    /*L*/ 0b10001000,
    /*M*/ 0b01011000,
    /*N*/ 0b01010000,
    /*O*/ 0b01111100,
    /*P*/ 0b10001100,
    /*Q*/ 0b10011010,
    /*R*/ 0b01101000,
    /*S*/ 0b01100000,
    /*T*/ 0b00110000,
    /*U*/ 0b01100100,
    /*V*/ 0b10000010,
    /*W*/ 0b01101100,
    /*X*/ 0b10010010,
    /*Y*/ 0b10010110,
    /*Z*/ 0b10011000
};

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

void printBits(unsigned char letter)
{
	for(int i = 0; i < 8; i++)
	{
		printf("Bit %d of %c is %d\n", i, matchToMorse(letter), getBit(letter,i));
	}
}

int getBit(unsigned char letter, int index)
{
	return (letter >> (7 - index)) & 1;
}

int lengthOfMorse(unsigned char letter)
{
    int howLong = 0;
    for (int i = 0; i < 3; i++) 
    {
        int bit = (letter >> (7 - i)) & 1;
        int exponent = 2 - i;
        int powResult = kpow(2, exponent);
        int toAdd = (powResult * bit);
        howLong += toAdd;
        //printf("Debug... i=%d, exponent=%d, bit=%d, howlong=%d, powResult=%d, toAdd=%d \n",i,exponent,bit,howLong,powResult,toAdd);
    }
    return howLong;
}


int kpow(int base, int power)
{
	int ret = 1;
	for (int i = 0; i < power; i++)
	{
		ret = base * ret;
	}
	return ret;
}

char matchToMorse(unsigned char morse)
{
    for (int i = 0; i < sizeof(letters); i++) {
        if (morse == letters[i])
            return 65 + i;
    }
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