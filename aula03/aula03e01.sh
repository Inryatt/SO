#!/bin/bash
#Agrupamento de comandos na bash

{
	i=0
	while read teste; do
		echo $i: $teste
		i=$(($i+1))
	done
}<$1
