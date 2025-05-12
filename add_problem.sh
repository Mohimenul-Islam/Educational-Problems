#!/bin/bash

# Script to add a new problem to the Educational-Problems repository
# By: Mohimenul

#=================================================
# EDIT THESE PARAMETERS BEFORE RUNNING THE SCRIPT
#=================================================

# Path to the solution file (required)
FILE=""  # Example: "/home/mohimenul/solution.cpp" or "./solution.cpp"

# Problem link (required)
LINK=""  # Example: "https://codeforces.com/problemset/problem/123/A"

# Problem category/tag (required)
TAG=""   # Example: "Greedy" or "Dynamic Programming"

# Difficulty level (e.g., Easy, Medium, Hard) (required)
DIFFICULTY=""  # Example: "Medium"

# Key takeaway or learning (optional)
TAKEAWAY=""    # Example: "Use priority queue for optimization"

# Note for revisiting (optional)
REVISIT=""     # Example: "Review time complexity"

#=================================================
# DO NOT EDIT BELOW THIS LINE
#=================================================

# Validate required parameters
if [[ -z "$FILE" || -z "$LINK" || -z "$TAG" || -z "$DIFFICULTY" ]]; then
    echo "Error: Missing required parameters"
    echo "Please edit the script and fill in the required parameters at the top of the file."
    echo "FILE, LINK, TAG, and DIFFICULTY are required. TAKEAWAY and REVISIT are optional."
    exit 1
fi

# Check if file exists
if [[ ! -f "$FILE" ]]; then
    echo "Error: File '$FILE' not found"
    exit 1
fi

# Extract filename
FILENAME=$(basename "$FILE")

# Create the codes directory if it doesn't exist
CODES_DIR="codes"
mkdir -p "$CODES_DIR"

# Copy the solution file to the codes directory
cp "$FILE" "$CODES_DIR/$FILENAME"
echo "Copied $FILE to $CODES_DIR/$FILENAME"

# Generate a unique identifier for the problem (timestamp)
TIMESTAMP=$(date +%Y%m%d%H%M%S)

# Create a markdown entry for the README
TAKEAWAY_FIELD=""
REVISIT_FIELD=""

# Add takeaway field only if provided
if [[ ! -z "$TAKEAWAY" ]]; then
    TAKEAWAY_FIELD="<details><summary>View</summary>$TAKEAWAY</details>"
fi

# Add revisit note field only if provided
if [[ ! -z "$REVISIT" ]]; then
    REVISIT_FIELD="<details><summary>View</summary>$REVISIT</details>"
fi

ENTRY="| [$LINK]($LINK) | $TAG | $DIFFICULTY | $TAKEAWAY_FIELD | $REVISIT_FIELD | [Solution](./codes/$FILENAME) |"

# Update the README
README_FILE="README.md"
sed -i "/<!-- PROBLEMS_TABLE_CONTENT -->/i\\$ENTRY" "$README_FILE"

echo "Successfully added problem to the repository!"
echo "Updated README with new problem entry"
