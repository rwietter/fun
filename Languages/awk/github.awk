#!/usr/bin/env -S awk -f

BEGIN {
		FS = ","
		printf("%s\n", "--------------------------")
		printf("%s\n", "----- GitHub Profile -----")
		printf("%s\n", "--------------------------")
}

/login|name|public_repos|blog|followers|following/ {
    if (!/(followers_url|following_url|twitter_username)/) {
				FS = ":"
        sub(/[ \t]+/, "")
        gsub(/("|")/, "")
				gsub(/login/, "Username")
				gsub(/\033\[[0-9;]*m/, "")

				key = toupper(substr($1, 0, 1))substr($1, 2)
				printf("%s:%s\n", key, $2)
    }
}
