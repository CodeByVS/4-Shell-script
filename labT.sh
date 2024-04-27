#!/bin/bash
echo "Contents of $dir1 and $dir2 have been swapped."
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 directory1 directory2"
    exit 1
fi
dir1="$1"
dir2="$2"
if [ ! -d "$dir1" ] || [ ! -d "$dir2" ]; then
    echo "Error: Both arguments must be directories"
    exit 1
fi
tmpdir=$(mktemp -d)
mv "$dir1"/* "$tmpdir"
mv "$dir2"/* "$dir1"
mv "$tmpdir"/* "$dir2"
rmdir "$tmpdir"
echo "Contents of $dir1 and $dir2 have been swapped."
