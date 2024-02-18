#!/bin/bash

# Define a function that returns a value
function add() {
    local result=$(( $1 + $2 ))
    return $result
}

# Call the function and capture the return value
add 5 3
sum=$?
echo "The sum is: $sum"
