#!/usr/bin/env -S awk -f

# count number of words per line

# FS: Field Separator (default: space) e.g. FS = ","
# RS: Record Separator (default: newline) e.g. RS = "\n\n"
# NF: Number of Fields (columns) e.g. NF = 3
# NR: Number of Records (lines) e.g. NR = 1
# OFS: Output Field Separator (default: space) e.g. OFS = ","
# ORS: Output Record Separator (default: newline) e.g. ORS = "\n\n"
# $0: whole line (record) e.g. $0 = "foo bar baz"
# $1: first field (column) e.g. $1 = "foo"
# $2: second field (column) e.g. $2 = "bar"
# $NF: last field (column) e.g. $NF = "baz"
# $NR: current line number e.g. $NR = 1

# Awk é orientado a colunas, mas é possível iterar sobre as linhas com o
# comando for (i = 1; i <= NF; i++) {}

BEGIN {
	FS = ","
}

{
	if (NR > 1 && NR < 5) {
		printf("\nLine %d has %d words\n", NR, NF)
		for (i = 1; i <= NF; i++) {
			printf("%s | ", $i)
			if (i == NF) {
				printf("\n")
			}
		}
	}
}
