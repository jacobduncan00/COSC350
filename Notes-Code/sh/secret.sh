#!/bin/sh

# testing while loop

echo "Enter password"
read password
while [ "$password" != "secret" ];
do
	echo "Wrong password Try again"
read password
done
	echo "You got it!"
exit 0
