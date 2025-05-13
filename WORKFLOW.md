# Educational Problems Workflow

This document explains how to work with this repository effectively.

## How to Add a New Problem

1. **Solve the problem** in `solution.cpp` file in the root directory.

2. **Update parameters** in `add_problem.sh`:
   ```bash
   # Edit these parameters
   FILE="/home/mohimenul/educational/Educational-Problems/solution.cpp"
   LINK="https://problem-link-here.com"
   TAG="Your Tag Here"
   DIFFICULTY="Your Difficulty Here" 
   TAKEAWAY="Optional takeaway"
   REVISIT="Optional revisit note"
   ```

3. **Run the script** to add your solution:
   ```bash
   ./add_problem.sh
   ```

## What the Script Does

1. Checks for existing solutions and automatically creates a new numbered solution file
   - Example: solution1.cpp, solution2.cpp, solution3.cpp, etc.

2. Updates the README.md with a new entry including:
   - Problem number (matching the solution file number)
   - Link to the problem
   - Tag/Category
   - Difficulty level
   - Optional takeaways and revisit notes
   - Link to your solution file

3. Commits and pushes the changes to GitHub (if configured)

## Tips

- Always work in the `solution.cpp` file in the root directory
- Run the script when you're ready to save the solution
- The script will handle file numbering automatically
- The script now automatically pulls the latest changes before committing to avoid conflicts
- Git credentials are stored to avoid entering username/password repeatedly
