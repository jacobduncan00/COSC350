#!/bin/bash

# Jacob Duncan
# Lab 02
# task7.sh

prompt="Enter a number to calculate the factorial of (must be positive): "
echo -n "$prompt"
read input

temp=$input
factorial=1

while [ $input -lt 0 ]; do
  echo "Invalid entry, you must enter a positive integer"
  echo -n "$prompt"
  read input
done

while [ $input -gt 0 ]; do
  factorial=$(($factorial * $input))
  input=$(($input -1))
done

echo "$temp! = $factorial"

exit 0
