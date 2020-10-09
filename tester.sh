#!/bin/bash

if [ $# -lt 1 ]; then
	echo "Pass at least 1 numerical argument"
  exit 1
else
  sum=0
	for i in $*
	do
		if [ `expr $i % 2` -eq 0 ]; then
			let sum=sum+$i
		fi
	done
fi
echo "The sum of even argument is $sum"
exit 0

