#!/bin/sh

# shows for loop example
#loop through a set of stings:
for m in Samsung Sony Panasonic LG
do
	echo "Manufactuer of LED TV is: $m"
done
# Loop 10 times
echo "You want me say I love you? yes or no"
read answer
if [ "$answer" = "yes" ]; then
for i in $(seq 1 10);
do
	echo "I love you $1"
done
else
	echo "Bye"
fi
exit 0;
