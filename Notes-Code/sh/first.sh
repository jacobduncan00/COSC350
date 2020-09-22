#!/bin/sh

# This file looks through all the files in the current
# directory for the string “main”, and then print the name
# of those files to the standard output.

for file in *
do
if grep -q main $file
then
	echo $file
fi
done
exit 0
