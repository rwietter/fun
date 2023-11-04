#!/bin/bash

: <<'COMMENT'
  More on Conditionals
COMMENT

read -p "X: " X
read -p "Y: " Y
read -p "Z: " Z

X=$((X))
Y=$((Y))
Z=$((Z))

if [[ $X -eq $Y ]] && [[ $X -eq $Z ]]; then
  echo "EQUILATERAL"
elif [[ $X -eq $Y ]] || [[ $X -eq $Z ]] || [[ $Y -eq $Z ]]; then
  echo "ISOSCELES"
elif [[ $X -ne $Y ]] && [[ $X -ne $Z ]] && [[ $Y -ne $Z ]]; then
  echo "SCALENE"
fi
