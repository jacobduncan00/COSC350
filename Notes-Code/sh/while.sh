#!/bin/sh

# while.sh: to test while loop. let command, which treats its

count=1
while [ "$count" -le 20 ]; do
	echo "Here we go again count = $count"
	let count++
done
exit 0
