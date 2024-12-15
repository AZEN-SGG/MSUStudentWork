#!/bin/bash

find . -type f -name "Makefile" | while read -r file; do
    echo "Processing file: $file"

    tmp_file=$(mktemp)

    sed -e 's/a\.exe/\.\/a\.out/g' \
        -e 's/\<del\>/rm/g' \
        -e 's/\-lssp//g' "$file" > "$tmp_file"

    mv "$tmp_file" "$file"
    echo "File $file processed."
done

echo "All Makefiles processed."
