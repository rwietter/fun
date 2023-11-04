#!/usr/bin/env -S awk -f

BEGIN {

}

function printenv(var) {
	command = "printenv " var | getline result
	close(command)
	return result
}

{
	printf("%s\n", printenv($0)); exit
}
