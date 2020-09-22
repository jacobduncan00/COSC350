#!/bin/sh

myname="Jacob Duncan"
echo "What is your name?"
read yourname
if [ -z $yourname ]; then
echo "no input from keyboard"
exit 1
elif [ $myname = $yourname ]; then
echo "We have the same name $myname"
else
echo "My name is $myname. Your name is $yourname"
fi
exit 0;
