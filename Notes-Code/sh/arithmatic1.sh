#!/bin/sh

echo "give two integers"
read a b
if [ $a -eq $b ]; then
echo " $a is equal to $b"
elif [ $a -gt $b ]; then
echo " $a is greater than to $b"
else
echo " $a is less than $b"
fi
exit 0
