#!/bin/bash
#wait for host as argument to come back online

host=$1
until ping -c 1 "$host" >& /dev/null; do
	echo "$host still unavailable lol"
	sleep 5
done;
echo -e "$host is available again. \a"

