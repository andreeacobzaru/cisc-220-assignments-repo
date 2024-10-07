#!/usr/bin/env bash

source ./Q3.sh

calc() {
    awk "BEGIN { print $* }";
}

if [[ $# -eq 0 ]]; then
    filename="grades"
else
    filename="$1"
fi

letter_grades=($( cut -f 3 "${filename}"))

float_string="("
total=$(( 0 ))
for letter in "${letter_grades[@]}"; do
    number=$( letter2gp "${letter}" )
    if [[ ${number} != -1 ]]; then
        float_string="${float_string}$number + "
        (( total += 1))
    fi
done
float_string="${float_string}0.0) / $total"
calc "$float_string"