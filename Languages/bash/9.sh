#!/bin/bash

: <<'COMMENT'
  Compute the Average
COMMENT

sum=0

read -p "N: " loop

elements=$((loop))

while [[ $loop -gt 0 ]]; do
  read -p "X: " X
  sum=$((sum + X))
  loop=$((loop - 1))
done

media="$(echo "$sum / $elements" | bc -l)"

echo $media | xargs printf "%.3f"
