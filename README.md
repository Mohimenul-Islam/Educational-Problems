# Educational Problems

A collection of competitive programming problems I’ve solved, along with any new takeaways or lessons learned, and reasons I might want to revisit each problem later.

## Problem Collection

| # | Problem | Tag/Category | Difficulty | Takeaway | Revisit Note / Error Log | Code Link |
|---|-------------|--------------|------------|----------|--------------------------|-----------|
| 1 | [Link](https://codeforces.com/contest/2102/problem/D) | Data Structure | Div2D |  | <details><summary>View</summary>Parity dependency with inversion count</details> | [Solution](./codes/solution1.cpp) |
| 2 | [Link](https://atcoder.jp/contests/arc087/tasks/arc087_b) | Dynamic Programming | Div2C-ish | <details><summary>View</summary>Multi Dimensional problems can be reduced to single dimensions if they or the operations on them are independent.</details> | <details><summary>View</summary>recall the negative value shift</details> | [Solution](./codes/solution2.cpp) |
| 3 | [Link](https://atcoder.jp/contests/arc092/tasks/arc092_a) | adhoc | Div2C-ish | <details><summary>View</summary>In set<int, greater<int>>, the upper bound and lower bound functions act reverse. For example, lower bound returns the largest element less that or equal</details> | <details><summary>View</summary>recall the sorting based on x and left to right sweep with set maintainances</details> | [Solution](./codes/solution3.cpp) |
| 4 | [Link](https://cses.fi/problemset/task/2192/) | Geometry | Div2D-ish | <details><summary>View</summary>The Ray Casting algorithm is used for Point-in-Polygon. The key is the 'General Position' principle: use a slightly tilted ray (e.g., to a point like {x+1, large_y}) to avoid ambiguous edge cases like hitting a vertex or a perfectly vertical/horizontal edge.</details> | <details><summary>View</summary>Recall the two main bugs: 1) A vertical ray is fragile and fails on vertex cases. 2) Checking for collinear segment intersection requires an *overlap* check, not a *containment* check. Also, always use long long for cross products.</details> | [Solution](./codes/solution4.cpp) |
| 5 | [Link](https://example.com/test) | Test | Easy |  |  | [Solution](./codes/solution5.cpp) |
<!-- PROBLEMS_TABLE_CONTENT -->

**Note:** Click on "View" in the Takeaway or Revisit Note columns to expand the content.
