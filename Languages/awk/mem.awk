#!/usr/bin/env -S awk -f

{
	printf("%s\t %s\t%s\t%s\t%s\n", $2, $3, $4, $10, $11)
}
