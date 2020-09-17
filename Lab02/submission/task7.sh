#!/bin/bash

# Jacob Duncan
# Lab 02
# task7.sh

prompt="Enter a number to calculate the factorial of (must be positive): "
echo -n "$prompt"
read input

factorial=1

while [ $input -lt 0 ]; do
  echo "Invalid entry, you must enter a positive integer"
  echo -n "$prompt"
  read input
done

temp=$input

while [ $input -gt 0 ]; do
  factorial=$(($factorial * $input))
  input=$(($input -1))
done

echo "$temp! = $factorial"

exit 0

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
OUTPUT

./task7.sh 
Enter a number to calculate the factorial of (must be positive): -8
Invalid entry, you must enter a positive integer
Enter a number to calculate the factorial of (must be positive): 5
5! = 120
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
