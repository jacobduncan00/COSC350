#!/bin/bash

for file in *; do
	if [ -d "$file" ]; then
		echo "$file"
	fi
done
exit 0
