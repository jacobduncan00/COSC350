#!/bin/sh

echo "file name to check?"
read fname
if [ -e $fname ]; then
echo "the file $fname exist in the current directory"
else
echo "There is no sush a $fname file exist in the current directory"
exit 1;
fi
if [ -f $fname ]; then
echo " the file $fname is regular file"
else
echo " the file $fname is not regular file"
fi
exit 0;
