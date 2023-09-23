#!/bin/bash

: <<'COMMENT'
  Getting started with conditionals
COMMENT

read -p "W: " W

if [[ $W =~ ^[nN]$ ]]; then
    echo "NO"
fi

if [[ $W =~ ^[yY]$ ]]; then
    echo "YES"
fi
