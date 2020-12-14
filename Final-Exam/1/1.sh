# Write a script which test each file name in current directory
# and display subdirectory names

#!/bin/bash

for file in *;
do
  if [ -d "$file" ]; then
    echo "$file"
  fi
done


exit 0;



