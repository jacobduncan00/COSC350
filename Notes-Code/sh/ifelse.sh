#!/bin/sh

echo "Is it morning? Please answer yes or no"
read yesorno
if [ $yesorno = "yes" ]; then
	echo "Good morning!"
elif [ $yesorno = "no"]; then
	echo "Good afternoon!"
else
	echo "Sorry $yesorno not recognized. Enter yes or no"
exit 1
fi
exit 0;
