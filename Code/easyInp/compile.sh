#! /bin/bash

if [ -z "$1" ] # if argv[1] is not an empty string
then
	gcc sampleUsage.c easyinp.c
else
	gcc sampleUsage.c easyinp.c -o $1
fi
