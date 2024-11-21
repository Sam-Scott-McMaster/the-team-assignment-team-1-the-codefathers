# Check if the username argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <username>"
    exit 1
fi

username="$1"
folder="./history_logs"
filepath="$folder/${username}.txt"

# Create the history file (or overwrite if it already exists)
touch "$filepath"