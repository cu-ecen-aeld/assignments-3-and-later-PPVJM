# Assignmnent 1 - Ricardo Ramos (PPVJM)

# Get arguments from command line
writefile=$1
writestr=$2

# If either arguments is null warn user and abort
if [ -z "$writefile" ] || [ -z $writestr ]; then
    echo "Missing arguments. Aborting."
    echo "Usage: $0 <file_name> <string_to_write>"
    exit 1
fi

# Creates path if not found
write_path=$(dirname "$writefile")
mkdir -p "$write_path"
if [ $? -ne 0 ]; then
    echo "Could not create directory $write_path."
    exit 1
fi


# Print piping to file
echo "$writestr" > "$writefile"

# Check if the previous error code is not zero
if [ $? -ne 0 ]; then
    echo "Error writing to $writefile."
    exit 1
fi

exit 0