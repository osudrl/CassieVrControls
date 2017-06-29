#ifndef BINARY_H
#define BINARY_H


const unsigned char letters[26];
int getBit(unsigned char letter, int index);
int lengthOfMorse(unsigned char letter);
char matchToMorse(unsigned char morse);
void printBits(unsigned char letter);

#endif