#!/usr/bin/env bash

files=$@

if [[ -z $files ]]; then
	echo "Usage: avglcn.sh FILE1 [FILE]..." 1>&2
	exit 1
fi

total_lines=$(wc -l ${files} | tail -n 1 | ./triml.sh | cut -d " " -f 1)

avg_lines=$(( (total_lines) / $# ))

echo ${avg_lines}