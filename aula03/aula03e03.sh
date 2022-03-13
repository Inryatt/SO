#!/bin/bash
#This script checks the existence of a file

#echo $#
if [[  $# == 1 ]] ; then
	
	echo "Checking..."
	if [[ -f $1 ]] ; then
		echo "$1 existe."
		out=$(ls -l $1)
		echo $out
	else
		echo "$1 não existe."
	fi
	echo "...Done."
else
	echo "Por favor passe um e só um argumento."
fi

