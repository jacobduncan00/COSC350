#!/bin/bash
echo "What is your name?"
read USER_NAME
echo "Hello $USER_NAME"
touch "{$USER_NAME}_file"
echo "I have created you a filed called ${USER_NAME}_file"

