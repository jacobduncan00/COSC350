#!/bin/sh

# or if test 4 –eq 4; then
if [ 4 -eq 4 ]; then
echo " 4 is equal to 4"
else
echo " 4 is not equal to 4"
fi
a=4
b=4
if [ $a -eq $b ]; then
echo " a is equal to b"
else
echo " a is not equal to b"
fi
exit 0
