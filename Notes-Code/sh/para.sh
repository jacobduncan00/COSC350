#!/bin/sh

#para.sh testing parameter variables
salutation=Hello
echo $salutation
echo "The program $0 is now running"
echo "The first parameter was $1"
echo "The second parameter was $2 "
echo "The number of parameters passed $#"
echo "The list of parameters were $*"
echo "The user's home directory is $HOME"
echo "The user's current working directory is $PWD "
echo "Your initial greeting is $salutation"
echo "You can change your greeting now."
echo "Please enter a new greeting"
read salutation
echo "Your new salutation is \" $salutation \" "

exit 0
