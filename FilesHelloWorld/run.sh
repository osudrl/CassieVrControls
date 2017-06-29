#!/bin/sh

make filereader.lexe

echo "\n"

./filereader.lexe

echo "\nHere is the outputfile:\n"

cat myoutput.txt