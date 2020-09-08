#!/bin/sh

echo "you pass $# arguments"
for ARG in $@; do 
	echo $ARG
done
exit 0
