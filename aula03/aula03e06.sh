#!/bin/bash
#this script opens 4 terminal windows

i="0"
until [[ $i -gt 3 ]]; do
	gnome-terminal  &

	i=$(($i+1))
done
