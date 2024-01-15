#!/bin/bash

# Example of a while loop that prints numbers from 1 to 5
counter=1
while [ $counter -le 5 ]
do
    echo "Number: $counter"
    ((counter++))
done

# Example of a while loop that reads user input until 'quit' is entered
input=""
while [ "$input" != "quit" ]
do
    echo "Enter 'quit' to exit:"
    read input
done
