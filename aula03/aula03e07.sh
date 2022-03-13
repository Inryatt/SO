#!/bin/bash
#calculate the sum of a series of numbers

SCORE="0"
SUM="0"
ENTERED="0"
    while true; do
    echo -n "Enter your score [0-10] ('q' to quit) (r to restart): "
    read SCORE;
    if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
        echo "Try again: "
    elif [[ "$SCORE" == "q" ]]; then
        MEDIA=$((SUM / ENTERED))
        echo "Sum: $SUM. Values entered: $ENTERED. Média: $MEDIA"

        break
    elif [[ "$SCORE" == "r" ]]; then
        echo "Sum reset"
        SUM=0
    else
        SUM=$((SUM + SCORE))
        ENTERED=$((ENTERED + 1))
    fi
done
echo "Exiting."