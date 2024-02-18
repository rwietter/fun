#!/usr/bin/env -S awk -f

BEGIN {
		FS = ","
    while (("cat ~/data" | getline line) > 0) {
        gsub(/[{}]/, "", line)
				sub(/([ \t]+)/, "", line)
				gsub(/("|")/, "", line)
    }
    close("cat ~/data")
}
