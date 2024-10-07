#!/usr/bin/env bash

f1=$1
f2=$2

f1_lines=$(wc -l "${f1}" | ./triml.sh | cut -d " " -f 1)
f2_lines=$(wc -l "${f2}" | ./triml.sh | cut -d " " -f 1)

avg_lines=$(( (f1_lines + f2_lines) / 2))

echo ${avg_lines}