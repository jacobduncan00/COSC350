#!/bin/bash

# Jacob Duncan
# Lab 02
# task6c.sh

prompt="Enter a number between 5 and 9: "
echo -n "$prompt"
read input

# Check if the number entered is between 5 and 9
while [ $input -lt 5 -o $input -gt 9 ]; do
  echo "Invalid entry [5-9 only]!"
  echo -n "$prompt"
  read input
done

# If we got past the while loop, we have a number between 5 and 9 (inclusive)
# Then we print out the value triangle by printing spaces and numerical values
for i in $(seq 1 $input); do
  for j in $(seq $i $input); do
    echo -n " "
  done
  for j in $(seq 1 $i); do
    echo -n "$i "
  done
  echo
done

exit 0 
