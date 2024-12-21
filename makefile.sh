#!/bin/bash

find . -type f -name "makefile" | while read -r file; do
    echo "Processing file: $file"

    tmp_file=$(mktemp)

    if [ "$1" == "delete" ]; then
        # Удаление строк с a.exe
        sed -e '/a\.exe/d' \
            -e 's/\<del\>/rm/g' \
            -e 's/\-lssp//g' "$file" > "$tmp_file"
    else
        # Замена a.exe на ./a.out
        sed -e 's/a\.exe/\.\/a\.out/g' \
            -e 's/\<del\>/rm/g' \
            -e 's/\-lssp//g' "$file" > "$tmp_file"
    fi

    mv "$tmp_file" "$file"
    echo "File $file processed."
done

echo "All Makefiles processed."
