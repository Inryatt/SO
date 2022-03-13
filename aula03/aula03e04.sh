#!/bin/bash
#This script does a very simple test for checking disk space.
space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | tail -1 | cut -d"%" -f1 -)
spaciest=$(df -h | awk '{print $4 $1}' | grep -v Use | sort -n )
echo $spaciest
echo "largest occupied space = $space%"
case $space in
	[1-6]*)
		Message="All OK."
		;;
	[7-8]*)
		Message="Cleaning out. There is a partition that is $space % full."
		;;
	9[0-8]*)
		Message="Better buy a new disk... One partition is $space % full."
		;;
	99)
		Message="Im drowning here! Theres a partition at $space %! "
		;;
	*)
		Message="I seem to be running with an nonexistent disk..."
		;;
esac
echo $Message
