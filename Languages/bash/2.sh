#!/bin/bash

: <<'COMMENT'
  A Personalized Echo
COMMENT

read -p "Your name: " name

echo -e "Welcome $name"
