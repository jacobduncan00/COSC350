#!/bin/sh

echo "file name to check?"
read fname
if [ -e $fname ]; then
echo "the file $fname exist in the current directory"
else
echo "There is no such a $fname file exist in the
current directory"
exit 1;
fi
exit 0;
