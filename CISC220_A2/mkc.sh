#!/usr/bin/env bash

str=$1

if [[ -z $str ]]; then
	exit 1
fi

touch "${str}.h"
touch "${str}.c"

echo -e "#ifndef ${str^^}_H\n#define ${str^^}_H\n\n#endif" 1> "${str}.h"

echo "#include \"${str}.h\"" 1> "${str}.c"
