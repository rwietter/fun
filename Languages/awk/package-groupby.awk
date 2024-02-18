#!/usr/bin/env -S awk -f

BEGIN { FS="[:<]" }
/^Empacotador/ {
	 	gsub(/>$/, "", $NF)
    emails[$NF]++ # email = email + 1
    names[$NF] = $2 # name[email] = name
}
END {
		printf("\n%-32s %-30s %s\n","Nome", "Email", "Pacotes")
    for (email in emails) {
			name = gensub(/^[ \t]+|[ \t]+$/,"","g",names[email]) # trim
      printf("%-32s %-30s %d\r\n", name, email, emails[email])
     }
		printf("\n")
}
