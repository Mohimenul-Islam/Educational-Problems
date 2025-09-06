# Educational Problems Workflow

This document explains how to work with this repository effectively.

## How to Add a New Problem

1. **Solve the problem** in `solution.cpp` file in the root directory.

2. **Run the script** and follow the interactive prompts:
   ```bash
   ./add_problem.sh
   ```
   
   The script will ask you for:
   - **Problem URL** (required) - Link to the problem
   - **Category/Tag** (required) - Like "Greedy", "DP", "Graph", etc.
   - **Difficulty** (required) - Like "Div2C", "Easy", "Hard", etc.
   - **Takeaway** (optional) - Key learning or insight
   - **Revisit Note** (optional) - Future review note or error log
   
   After entering all details, it will show a summary and ask for confirmation.

   **Example session:**
   ```
   Enter problem URL: https://codeforces.com/contest/123/problem/A
   Enter problem category/tag: Greedy
   Enter difficulty level: Div2C
   Enter key takeaway/learning (optional): Use sorting for optimization
   Enter revisit note/error log (optional): Remember edge case with n=1
   Add this problem to the repository? (y/n): y
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
- The script provides guided prompts - just run `./add_problem.sh` and follow along
- URL validation ensures you enter a proper web link
- Optional fields can be skipped by pressing Enter
- Review the summary before confirming to avoid mistakes
- The script will handle file numbering automatically
- The script automatically pulls the latest changes before committing to avoid conflicts
- Git credentials are stored to avoid entering username/password repeatedly
