#!/usr/bin/env bash

if (( $# == 0 )); then
	exit 0
fi

file=$1

if [[ ! (-f $file) ]]; then
	echo "trash.sh: cannot remove a non-regular file" 1>&2
	exit 1
fi

abs_path=$( realpath "$file" )
parent_dir=$( dirname "$abs_path" )
parent_dir_relative=${parent_dir#"$HOME"}

if [[ "$parent_dir_relative" == "$parent_dir" ]]; then # if equal, home dir isn't in path
	echo "trash.sh: cannot remove a file not found below $HOME" 1>&2
	exit 2
elif [[ ! (-w $parent_dir && -x $parent_dir) ]]; then
	echo "trash.sh: directory missing write and/or execute permission" 1>&2
	echo $parent_dir
	exit 3
fi

if [[ ! ( -e "$HOME/.trash/${parent_dir_relative}" ) ]]; then
	mkdir -p "$HOME/.trash/${parent_dir_relative}"
fi

mv $abs_path "$HOME/.trash/${parent_dir_relative}"
	

