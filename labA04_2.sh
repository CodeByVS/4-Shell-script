#!/bin/bash

MAX_SIZE=1000  # 1000 bytes limit

dir_count=1

dir_size=0

mkdir "x_$dir_count"

# Loop through all files in the specified directory
for file in *; do
    if [ -f "$file" ]; then

        file_size=$(ls -l "$file" | awk '{print $5}')

        # Check if adding the file to the current directory exceeds the maximum size
        if (( dir_size + file_size > MAX_SIZE )); then
            # If the maximum size is exceeded, increment the directory counter and create a new directory
            ((dir_count++))
            mkdir "x_$dir_count"
            # Reset directory size counter
            dir_size=0
        fi

        # Move the file to the appropriate directory
        mv "$file" "x_$dir_count/"
        
        # Update the directory size
        dir_size=$((dir_size + file_size))
    fi
done
