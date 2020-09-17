#!/bin/bash

# Jacob Duncan
# Lab 02
# task9.sh

echo -n "Enter the directory the file lives in: "
read directory

# If the first character in the directory entered is the tilda sign
# then it means the user is giving an absolute directory from the home dir
# we must handle this by replacing the ~ with /Users/jake as that is the path from the root
# to the home directory for jake

# then we must add (append) what the user entered to /Users/jake/
if [ ${directory:0:1} = '~' ]; then
  directory="/Users/jake/${directory:2:${#directory}-2}"
fi

if [ -d $directory ]; then
  echo -n "Enter the name of the file: "
  read file_name

  file_location="$directory/$file_name"
  attempt=1

  # User only has 3 chances to enter a correct file name.
  # cannot just do -e because the file has to be readable because 
  # we are going to need to check if a word exists in it, so we need to be 
  # able to read from the file, so that must be our second condition. 
  until [ $attempt -eq 3 -o -r $file_name ] ; do 
    echo -n "No file found with that name. Enter the name of the file: "
    read file_name

    file_location="$directory/$file_name"

    attempt=$((attempt + 1))
  done

  # Prompt user to enter a word to find in that file if it is readable
  if [ -r $file_location ]; then
    echo -n "Enter a word to search in the file: "
    read word
    
    # grep gets the entire line if the word is found in the file
    exec_command=$(grep $word $file_location)

    # if the grep command length is 0, then it did not find a word 
    if [ -z "$exec_command" ]; then
      echo "$word NOT FOUND"
      exit 4
    # else the grep command did find a word
    else 
      echo "$word FOUND!"
      exit 0
    fi

  # else the file was not readable and we need to tell the user
  elif [ -e $file_location ]; then
    echo "$file_name exists however, it is not readable"
    exit 3
  # or the file did not exist
  else 
    echo "$file_name does not exist or is not valid"
  fi

else 
  echo "$directory does not exists or is not valid"
  exit
fi
