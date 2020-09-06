#!/bin/sh

echo Hello World

cat ~/golang/3301/cicada.go | grep "main"

# This is slightly faster than the command above
grep "main" ~/golang/3301/cicada.go
