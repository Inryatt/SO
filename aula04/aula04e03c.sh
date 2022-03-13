#!/bin/bash

function int_selection_sort()
{
    j=0
    inicial=$1
    while [[ ${#final[@]} != ${#inicial[@]}  ]]; do
        for((i = 0; i<${#inicial[@]};i++)); do
            if [[ inicial[i] -lt $smol ]]; then
                smol=$inicial[i]
                tmp_i=$i
            fi


        done
        ((j++))
        final+=($smol)
        unset inicial[$tmp_i]

    done
}


file="numeros.txt"
echo "$file"
read -a lista -d ' ' < "$file"
echo vals ${lista[@]}    

int_selection_sort $lista
