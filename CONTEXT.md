# Educational-Problems Repository Context

## Project Overview
**Repository Name:** Educational-Problems  
**Owner:** Mohimenul-Islam  
**GitHub URL:** https://github.com/Mohimenul-Islam/Educational-Problems  
**Primary Language:** C++ (Competitive Programming)  
**Last Updated:** September 6, 2025  

## Project Purpose
This is a personal competitive programming repository designed to:
- Store solved competitive programming problems with detailed documentation
- Track learning takeaways and lessons from each problem
- Maintain notes for future revisiting and review
- Organize solutions in a structured, searchable format
- Automate the process of adding new problems with proper documentation

## Repository Structure

### Root Directory Files
```
/home/mohimenul/Educational-Problems/
├── README.md              # Main documentation with problem table
├── WORKFLOW.md            # Step-by-step usage instructions
├── CONTEXT.md             # This file - project context (NEW)
├── add_problem.sh         # Automation script for adding new problems
├── solution.cpp           # Working file for solving current problem
└── codes/                 # Directory containing all finalized solutions
    ├── solution1.cpp      # Problem #1 solution
    ├── solution2.cpp      # Problem #2 solution
    └── solution3.cpp      # Problem #3 solution
```

### Key Components

#### 1. README.md
- Contains a markdown table with all solved problems
- **Structure:** Problem #, Link, Tag/Category, Difficulty, Takeaway, Revisit Note, Code Link
- Uses collapsible `<details>` tags for takeaways and revisit notes
- Automatically updated by the `add_problem.sh` script
- Contains marker comment `<!-- PROBLEMS_TABLE_CONTENT -->` for script insertion

#### 2. add_problem.sh (Automation Script)
**Location:** `/home/mohimenul/Educational-Problems/add_problem.sh`
**Function:** Fully automated problem addition workflow

**Key Features:**
- **File Management:** Automatically copies `solution.cpp` to `codes/solutionN.cpp`
- **Numbering:** Auto-increments solution numbers (finds highest existing number + 1)
- **Multi-language Support:** Detects file extensions (.cpp, .py, .java, etc.)
- **Duplicate Prevention:** Warns if problem link already exists
- **Git Integration:** Automatically pulls, commits, and pushes to GitHub
- **README Update:** Inserts new problem entry in the table

**Required Parameters (Edit before running):**
```bash
FILE="/home/mohimenul/educational/Educational-Problems/solution.cpp"
LINK="https://problem-link-here.com"
TAG="Problem Category"
DIFFICULTY="Difficulty Level"
TAKEAWAY="Key learning (optional)"
REVISIT="Future review note (optional)"
```

#### 3. solution.cpp (Working File)
- **Purpose:** Active workspace for solving current problem
- **Location:** Root directory
- **Usage:** Always work in this file, script will copy it to codes/ when done
- **Current Content:** Contains solution for an AtCoder problem (ARC092-A)

#### 4. codes/ Directory
**Purpose:** Archive of all finalized solutions
**Naming Convention:** `solutionN.cpp` where N is the problem number
**Current Contents:**
- `solution1.cpp` - Data Structure problem (Codeforces 2102D) - Parity dependency with inversion count
- `solution2.cpp` - Dynamic Programming (AtCoder ARC087B) - Multi-dimensional to single dimension reduction  
- `solution3.cpp` - Adhoc problem (AtCoder ARC092A) - Set operations with custom comparator

## Current Problem Status

### Problems Solved: 4

| # | Platform | Problem | Category | Difficulty | Key Takeaway |
|---|----------|---------|----------|------------|--------------|
| 1 | Codeforces | [2102D](https://codeforces.com/contest/2102/problem/D) | Data Structure | Div2D | Parity dependency with inversion count |
| 2 | AtCoder | [ARC087B](https://atcoder.jp/contests/arc087/tasks/arc087_b) | Dynamic Programming | Div2C-ish | Multi-dimensional problems can be reduced to single dimensions |
| 3 | AtCoder | [ARC092A](https://atcoder.jp/contests/arc092/tasks/arc092_a) | Adhoc | Div2C-ish | Set<int, greater<int>> reverse behavior of bounds |
| 4 | CSES | [2192](https://cses.fi/problemset/task/2192/) | Geometry | Div2D-ish | Geometric problem solution |

### Next Solution Number: 5
- The script will automatically create `solution4.cpp` for the next problem

## Workflow Process

### Standard Problem-Solving Workflow:
1. **Solve** the problem in `solution.cpp` (root directory)
2. **Edit parameters** in `add_problem.sh`:
   - Update LINK, TAG, DIFFICULTY (required)
   - Add TAKEAWAY and REVISIT notes (optional)
3. **Run script:** `./add_problem.sh`
4. **Automatic processing:**
   - Copies solution to `codes/solutionN.cpp`
   - Updates README.md with new table entry
   - Commits and pushes to GitHub

### Git Integration
- **Remote:** https://github.com/Mohimenul-Islam/Educational-Problems.git
- **Branch:** main
- **Auto-sync:** Script pulls before committing to avoid conflicts
- **Authentication:** Uses HTTPS with credential caching

## Technical Implementation Details

### Script Logic:
- **File Detection:** Automatically detects file type and extension
- **Number Management:** Scans codes/ directory for highest solution number
- **Markdown Generation:** Creates properly formatted table entries with collapsible sections
- **Error Handling:** Validates required parameters and file existence
- **Git Safety:** Pulls latest changes before pushing to prevent conflicts

### Code Style:
- **Language:** C++ with competitive programming template
- **Headers:** Uses `#include <bits/stdc++.h>`
- **Aliases:** `using ll = long long`
- **Contests:** Primarily AtCoder and Codeforces problems

## Learning Focus Areas

### Problem Categories Covered:
1. **Data Structures** - Segment trees, complex data manipulation
2. **Dynamic Programming** - Multi-dimensional optimization
3. **Adhoc/Implementation** - Set operations, sorting algorithms

### Difficulty Progression:
- Div2C to Div2D level problems
- Focus on educational value and technique learning
- Emphasis on problems with reusable patterns

## Future Enhancement Ideas
- Add difficulty tagging system (Easy/Medium/Hard)
- Implement problem search functionality
- Add performance metrics (time/space complexity notes)
- Create topic-based problem grouping
- Add solution explanation templates

## Usage Notes for AI Assistant
- **Working File:** Always use `solution.cpp` in root for new problems
- **Script Path:** `/home/mohimenul/Educational-Problems/add_problem.sh`
- **Edit Script:** Modify parameters section before running
- **Git Status:** Repository is actively maintained and synced with GitHub
- **File Structure:** Never directly edit files in `codes/` directory
- **Table Updates:** Only modify README.md through the automated script

## Last Context Update
**Date:** September 6, 2025  
**Status:** Project is active and well-organized  
**Next Steps:** Ready for new problem addition using established workflow
