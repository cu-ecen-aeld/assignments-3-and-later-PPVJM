# Assignmnent 1 - Ricardo Ramos (PPVJM)

#!/bin/sh

# Get arguments from command line
filesdir=$1
searchstr=$2

# If either arguments is null warn user and abort
if [ -z "$filesdir" ] || [ -z $searchstr ]; then
    echo "Missing arguments. Aborting."
    echo "Usage: $0 <files_dir> <search_str>"
    exit 1
fi

# If the first argument is not a directory warn user and abort
if [ ! -d "$filesdir" ]; then
    echo "$filesdir is not a directory. Aborting."
    exit 1
fi

# Store the number of files into the num_files varialble
num_files=$(find "$filesdir" -type f 2>/dev/null | wc -l)

# Compare
matches=$(grep -r --text --line-number -- "$searchstr" "$filesdir" 2>/dev/null | wc -l)

# Print the result and exit
echo "The number of files are $num_files and the number of matching lines are $matches"
exit 0