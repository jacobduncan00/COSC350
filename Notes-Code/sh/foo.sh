#!/bin/sh

# Loop through the arguments passed to a function

foo() {
for ARG in "$@"; do
	echo $ARG;
done
}
foo $@
exit 0
