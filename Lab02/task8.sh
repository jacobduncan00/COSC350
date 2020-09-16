#!/bin/bash

# Jacob Duncan
# Lab 02
# task8.sh

# If number of arguments passed is not equal to 1, we display an error message
if [ $# -ne 1 ]; then
  echo "You need to pass one numerical argument"
  exit 1
else
  # Turn out argument into base 10 form
  num=$((10#$1))
  sum=0
  # Sum all the numbers together
  while [ $num -gt 0 ]; do
    sum=$((sum + num % 10))
    num=$((num / 10))
  done
  echo "Sum of digits for number is $sum"
fi

exit 0
