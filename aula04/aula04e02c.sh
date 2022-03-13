#!/bin/bash

function compare_numbers()
{
	if [[ $1 -eq $2 ]];then
		return 1
	elif [[ $1 -gt $2 ]]; then
		return 2
	else
		return 3
	fi
}
compare_numbers $1 $2
