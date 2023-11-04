#!/usr/bin/env -S awk -f

BEGIN {
  FS=","
}

{
  len = NR
}

END {
 print NR==len ? $1 : null
}
