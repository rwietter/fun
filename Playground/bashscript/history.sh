zsh_history=~/.zsh_history
zsh_history_tmp=~/.zsh_history_tmp

if [[ ! -f $zsh_history ]]; then
	echo "zsh_history not found. Are you using zsh ? Please check it out."
	exit 1
fi

if [[ ! -f $zsh_history_tmp ]]; then
	# touch $zsh_history_tmp
fi

diff=$(diff $zsh_history $zsh_history_tmp)

diff_commands=$(echo $diff | sed 's/[\<\:0-9\;]//g')

echo $diff_commands

if [[ -n $diff ]]; then
	for line in $diff_commands; do
		echo $line
		# echo $line >>$zsh_history_tmp
	done
fi
