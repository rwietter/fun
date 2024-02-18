#!/bin/bash

: <<'COMMENT'
  Arithmetic Operations
COMMENT

read -p "X: " X

    echo $X | bc -l | xargs printf "%.3f"
