#!/bin/sh

for m in Samsung LG Nokia Apple "Hewlett Packard"
do
	echo "Manufacturer is:" $m
done

for i in $(seq 1 10);
do
	echo "$i Hello World $i ";
done

for ((i=1; i<11; i++));
do
	echo "$i Hello World $i ";
done
