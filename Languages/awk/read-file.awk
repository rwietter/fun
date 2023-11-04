#!/usr/bin/env -S awk -f

BEGIN {
	FS = ","
	PROCINFO["sorted_in"] = "@ind_num_asc"  # Ordena o array por índice numérico

	while ((getline < "catalog.csv") > 0) {
		lines++
		for (i = 1; i <= NF; i++) {
			dados[lines, i] = $i
		}
		fields[lines] = NF
	}

	process_data()
}

function process_data() {
	for (line = 1; line <= lines; line++) {
		printf("\nLine %d has %d words\n", line, fields[line])
		for (field = 1; field <= fields[line]; field++) {
			printf("%s | ", dados[line, field])
		}
		printf("\n")
	}
}
