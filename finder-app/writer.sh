# Assignmnent 2 - Ricardo Ramos (PPVJM)

# Clean and check for errors
make clean

if [ $? -ne 0 ]; then
    echo "Error cleaning writer. Exiting."
    exit 1
fi

# Compile writer for x86 and check for errors
make

if [ $? -ne 0 ]; then
    echo "Error making to writer. Exiting."
    exit 1
fi

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

# Invoke writer
./write "$writefile" "$writestr" 

# Check if the previous error code is not zero
if [ $? -ne 0 ]; then
    echo "Error writing to $writefile."
    exit 1
fi

exit 0