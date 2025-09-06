# Educational Problems Workflow

This document explains how to work with this repository effectively.

## How to Add a New Problem

1. **Solve the problem** in `solution.cpp` file in the root directory.

2. **Run the script** with problem details:
   ```bash
   ./add_problem.sh "https://problem-link-here.com" "Your Tag" "Difficulty" ["Optional takeaway"] ["Optional revisit note"]
   ```
   
   **Parameters:**
   - `link` - URL to the problem (required)
   - `tag` - Category/tag like "Greedy", "DP", "Graph" (required)
   - `difficulty` - Difficulty level like "Div2C", "Easy", "Hard" (required)
   - `takeaway` - Key learning or insight (optional)
   - `revisit` - Future review note or error log (optional)

   **Examples:**
   ```bash
   # Minimum required parameters
   ./add_problem.sh "https://codeforces.com/contest/123/problem/A" "Greedy" "Div2C"
   
   # With optional takeaway and revisit note
   ./add_problem.sh "https://atcoder.jp/contests/abc123/tasks/abc123_d" "Dynamic Programming" "Div2D" "Use 2D DP for optimization" "Remember the base case when n=1"
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
- Use quotes around parameters that contain spaces
- The script will handle file numbering automatically
- The script now automatically pulls the latest changes before committing to avoid conflicts
- Git credentials are stored to avoid entering username/password repeatedly
- To see usage help: `./add_problem.sh` (without parameters)
