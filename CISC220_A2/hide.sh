#!/usr/bin/env bash

if (( $# != 1 )); then
	echo "Usage: hide.sh FILE"  1>&2
	exit 1
fi

filename=$1
base_filename=$( basename "$filename" )
dir_filename=$( dirname "$filename" )

if [[ -e "${dir_filename}/.${base_filename}" ]]; then
	mv -i "$filename" "${dir_filename}/.${base_filename}"
else
	mv "$filename" "${dir_filename}/.${base_filename}"
fi
