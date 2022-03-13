#!/bin/bash



if [[ "$2" == "-r" ]]; then
	if [[ $# == 2  ]]; then
		if [[ -d  $1 ]]; then 
			for f in $1/*; do
				filename=${f##*/}
				filename=${filename##*_} 
				echo $filename
				mv $f $1"/"$filename
		       	echo ${f}	
			done
		fi
	fi
else
	if [[ $# == 1  ]]; then
		if [[ -d  $1 ]]; then 
			for f in $1/*; do
				mv -- $f $1"/new_"${f##*/}
		       	echo ${f##*/}	
			done
		fi
	fi
fi
