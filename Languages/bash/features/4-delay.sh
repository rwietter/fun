#!/bin/bash
#Filename: sleep.sh

echo Count: tput sc # Loop for 40 seconds

for count in `seq 0 5`
do
    echo -e $count
    sleep 1
done