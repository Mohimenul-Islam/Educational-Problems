#!/bin/bash

# Script to add a new problem to the Educational-Problems repository
# By: Mohimenul

#=================================================
# EDIT THESE PARAMETERS BEFORE RUNNING THE SCRIPT
#=================================================

# Path to the solution file (required)
FILE="/home/mohimenul/educational/Educational-Problems/solution.cpp"
  # Example: "/home/educational/Educational-Problems/solution.cpp" or "./solution.cpp"

# Problem link (required)
LINK="https://atcoder.jp/contests/arc092/tasks/arc092_a"  # Example: "https://codeforces.com/problemset/problem/123/A"

# Problem category/tag (required)
TAG="adhoc"   # Example: "Greedy" or "Dynamic Programming"

# Difficulty level (e.g., Easy, Medium, Hard) (required)
DIFFICULTY="Div2C-ish"  # Example: "Medium"

# Key takeaway or learning (optional)
TAKEAWAY="In set<int, greater<int>>, the upper bound and lower bound functions act reverse. For example, lower bound returns the largest element less that or equal"    # Example: "Use priority queue for optimization"

# Note for revisiting (optional)
REVISIT="recall the sorting based on x and left to right sweep with set maintainances"     # Example: "Review time complexity"

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

# Extract base filename
FILENAME=$(basename "$FILE")

# Determine the extension of the current file
if [[ "$FILENAME" != *"."* ]]; then
    # Detect file type and add appropriate extension
    FILE_TYPE=$(file -b --mime-type "$FILE")
    EXT="cpp" # Default extension
    if [[ "$FILE_TYPE" == *"text/x-c"* ]]; then
        EXT="cpp"
    elif [[ "$FILE_TYPE" == *"text/x-python"* ]]; then
        EXT="py"
    elif [[ "$FILE_TYPE" == *"text/x-java"* ]]; then
        EXT="java"
    fi
else
    # Extract extension from original file
    EXT="${FILENAME##*.}"
fi

# Find the highest solution number in the codes directory
CODES_DIR="codes"
mkdir -p "$CODES_DIR"

# Get the highest number from existing solution files
HIGHEST_NUM=0
for f in "$CODES_DIR"/solution*.${EXT}; do
    if [ -f "$f" ]; then
        # Extract the number from filename (solution<NUM>.ext)
        NUM=$(basename "$f" | sed -E "s/solution([0-9]*)\.$EXT/\1/")
        # If no number (just solution.ext), treat as 0
        if [ -z "$NUM" ]; then
            NUM=0
        fi
        # Update highest number if this one is higher
        if [ "$NUM" -gt "$HIGHEST_NUM" ]; then
            HIGHEST_NUM=$NUM
        fi
    fi
done

# Increment the number for the new file
NEXT_NUM=$((HIGHEST_NUM + 1))

# Create the new filename
FILENAME="solution${NEXT_NUM}.${EXT}"

# Copy the solution file to the codes directory with numbered name
cp "$FILE" "$CODES_DIR/$FILENAME"
echo "Copied $FILE to $CODES_DIR/$FILENAME"

# Generate the problem number (simply use the same number as the solution)
PROBLEM_NUM=$NEXT_NUM

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

ENTRY="| $PROBLEM_NUM | [Link]($LINK) | $TAG | $DIFFICULTY | $TAKEAWAY_FIELD | $REVISIT_FIELD | [Solution](./codes/$FILENAME) |"

# Update the README
README_FILE="README.md"

# Check if problem link already exists in README to prevent duplicates
if grep -q "$LINK" "$README_FILE"; then
    echo "Warning: This problem link already exists in the README!"
    read -p "Do you want to add it anyway? (y/n): " ADD_ANYWAY
    if [[ "$ADD_ANYWAY" != "y" && "$ADD_ANYWAY" != "Y" ]]; then
        echo "Operation cancelled. Problem not added."
        exit 0
    fi
fi

# Add new entry to README
sed -i "/<!-- PROBLEMS_TABLE_CONTENT -->/i\\$ENTRY" "$README_FILE"

echo "Successfully added problem to the repository!"
echo "Updated README with new problem entry"

# Git commit and push
if command -v git &> /dev/null; then
    echo "Pulling latest changes from GitHub..."
    git pull
    
    echo "Committing changes to Git repository..."
    git add "$CODES_DIR/$FILENAME" "$README_FILE"
    git commit -m "Add new problem solution: $TAG - $DIFFICULTY"
    
    echo "Pushing changes to GitHub..."
    # Check if credentials are already cached, if not, suggest ways to authenticate
    if ! git push origin HEAD; then
        echo -e "\nPush failed. GitHub requires a secure authentication method."
        echo "Options to fix this:"
        echo "1. Set up a Personal Access Token (recommended for HTTPS):"
        echo "   a. Visit https://github.com/settings/tokens to create a token"
        echo "   b. Use git credential helper to store it:"
        echo "      git config --global credential.helper cache  # Cache for 15 minutes"
        echo "      # OR store permanently (replace with your GitHub username):"
        echo "      git config --global credential.helper store"
        echo "      # Then try pushing again and enter your token when prompted for password"
        echo ""
        echo "2. Set up SSH authentication:"
        echo "   a. Generate SSH key: ssh-keygen -t ed25519 -C \"your_email@example.com\""
        echo "   b. Add to GitHub: https://github.com/settings/keys"
        echo "   c. Change remote URL: git remote set-url origin git@github.com:Mohimenul-Islam/Educational-Problems.git"
        echo ""
        exit 1
    fi
    
    echo "Changes successfully pushed to GitHub!"
else
    echo "Warning: Git is not installed. Changes were not committed to GitHub."
    echo "To manually commit and push, run: git add $CODES_DIR/$FILENAME $README_FILE && git commit -m \"Add problem\" && git push"
fi
