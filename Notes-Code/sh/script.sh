#!/bin/sh
# Shell script that basically does the "ls" command, 
# this script prints out the name of all files in the directory this
# script is in

for file in *
do
  if grep -q main $file
  then
    echo $file
  fi
done 
exit 0