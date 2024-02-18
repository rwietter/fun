#!/usr/bin/env -S awk -f

BEGIN {
  FS = "(, *)|(- *)"
}

{
  print $1, $2c
}

END {
  print "\nDone"
}