#!/bin/bash

# Jacob Duncan
# Lab 02
# task8.sh

# If number of arguments passed is not equal to 1, we display an error message
if [ $# -ne 1 ]; then
  echo "You need to pass one numerical argument"
  exit 1
else
  # Assign first positional parameter to num, we use $1 because we know there is
  # only 1 parameter passed to this function
  num=$1
  sum=0
  while [ $num -gt 0 ]; do
    rem=`expr $num % 10` # Get remainder
    sum=`expr $sum + $rem` # Add to sum
    num=`expr $num / 10` # Get next digit in number
  done
  echo "Sum of digits for number is $sum"
fi

exit 0
