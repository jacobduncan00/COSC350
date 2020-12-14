# Write a bash script which takes a sequence of integers as arguments
# and calculates the multiplication of integers and displays the results
# Ex. ./mult.sh 1 2 3 4

#!/bin/bash

output=1

if [ $# -eq 0 ]; then
  echo "No arguments passed, cannot run!"
  exit 0;
fi

for i in "$@"
do
  output=$(($output * $i))
done

echo "multiplication of $@ = $output"

exit 0;
