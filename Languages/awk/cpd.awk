#!/usr/bin/env -S awk -f

# [PURPOSE]
# This script is used to copy files to the corresponding directories.
# e.g. if you have a file named "test.md" in your home directory,
# then this script will create a directory named "test" in the current directory,
# and copy "test.md" to the directory "test".

# [DESCRIPTION]
# This will to convert file names to directory names and copy files to the
# corresponding directories.

# [USAGE]
# 1. copy this script to the directory where you want to copy files
# 2. run this script: ls -1 ~/*.md | ./test.awk
# 3. check the output

# [NOTE]
# This script will not work if file names contain spaces.
# If you want to copy files with spaces in their names, use the following command:
# ls -1 ~/*.md | sed 's/ /\\ /g' | ./test.awk

# [REFERENCE]
# author: @rwietter - https://github.com/rwietter

BEGIN {
	FS = "/"
}

{
	# This will convert file names to directory names.
	# if file_name is "test.md", local_dir will be "test".
	local_dir = gensub(/\.[^.]+$/, "", 1, $NF)

	# This will create local_dir in pwd/dir [where this script is located]/[file_name].
	# e.g. if this script is located in ~/bin, and file_name is "test.md",
	# then local_dir will be created in ~/bin/test.
	printf("%s %s %s\n", "mkdir -p", "$(pwd)/", local_dir) | "/bin/sh"

	# This will copy files to the corresponding directories.
	# e.g. if this script is located in ~/bin, and file_name is "test.md",
	# then test.md will be copied to ~/bin/test/test.md.
	printf("%s %s %s\n", "cp -r", $0, "$(pwd)/"local_dir) | "/bin/sh"
}
