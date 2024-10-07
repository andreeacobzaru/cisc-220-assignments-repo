#!/usr/bin/env bash

for file in "$@"; do
    mapfile -t lines < "$file"
    current_index=$(( ${#lines[@]} - 1 ))
    while [[ $current_index -ge 0 ]]; do
        echo "${lines[$current_index]}"
        (( current_index-- ))
    done
done