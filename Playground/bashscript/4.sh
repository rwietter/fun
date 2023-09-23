#!/bin/bash

: <<'COMMENT'
  The World of Numbers
COMMENT

read -p "X: " X
read -p "Y: " Y

X=$(($X))
Y=$(($Y))

if [[ $X -ge -100 ]] && [[ $Y -le 100 ]] && [[ $Y -ne 0 ]]; then
  echo $(($X + $Y))
  echo $(($X - $Y))
  echo $(($X * $Y))
  echo $(($X / $Y))
fi
