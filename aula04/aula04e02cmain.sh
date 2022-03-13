#!/bin/bash

. aula04e02c.sh


echo 'Introduza dois números, um de cada vez.'
read n1
read n2

compare_numbers $n1 $n2

case $? in
	1)
		echo "Os números são iguais."
		;;
	2)
		echo "$n1 é o maior numero"
		;;
	3)
		echo "$n2 é o maior numero"
		;;
	*)
		echo "algo correu mal"
esac

