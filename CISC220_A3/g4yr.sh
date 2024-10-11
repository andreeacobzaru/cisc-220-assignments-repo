#!/usr/bin/env bash

source ./Q3.sh

calc() { 
    awk "BEGIN { print $*}"; 
}

if [[ $# -eq 0 ]]; then
    echo "USAGE: g4yr.sh yr [gradefile]" 2>&1
    exit 1
elif [[ $# -gt 2 ]]; then
    echo "g4yr.sh: expecting one or two arguments, ignoring extra arguments" 2>&1
fi

if [[ $# -eq 1 ]]; then
    filename="grades"
elif [[ $# -ge 2 ]]; then
    filename="$2"
fi

if [[ !(-f $filename) ]]; then
    echo "g4yr.sh: ${filename} is not a regular file" 2>&1
    exit 2
elif [[ !(-r $filename) ]]; then
    g4yr.sh: ${filename} is not readable
    exit 2
fi

year="$1"
next_year=$(( year + 1 ))
mapfile -t letter_grades < <(cut -f 3 "${filename}")
mapfile -t terms < <(cut -f 2 "${filename}")

float_string="("
total=$(( 0 ))
for (( i=0; i < "${#terms[@]}"; i++ )); do
    term="${terms[i]}"
    if [[ "${term}" == "${year} F" || "${term}" == "${next_year} W" || "${term}" == "${next_year} S" ]]; then
        letter=${letter_grades[i]}
        number=$( letter2gp "${letter}" )
        if [[ ${number} != -1 ]]; then
            float_string="${float_string}$number + "
            (( total += 1))
        fi
    fi
done

if [[ $total -ne 0 ]]; then
    float_string="${float_string}0.0) / $total"
    calc "$float_string"
fi