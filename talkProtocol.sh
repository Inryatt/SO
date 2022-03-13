#!/bin/bash

if [ "$1" == "Olá" ];
then
	echo "Olá"
else
	if [ "$1" == "Que horas são?" ];
	then	
		echo "10:47"
	else	echo "Something went wrong"
	fi
fi

