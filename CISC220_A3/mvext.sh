#!/usr/bin/env bash

if [[ $# -eq 1 ]]; then
    src_ext=$1
    dest_ext=""
elif [[ $# -eq 2 ]]; then
    src_ext="$1"
    dest_ext=".$2"
else
    exit 1
fi

for file in *.${src_ext}; do
    mv "${file}" "${file/.${src_ext}/$dest_ext}"
done