## Problem Statement

You are given a 0-indexed 2D integer array grid of size `m x n`. Each cell has one of two values:

- `0` represents an empty cell,
- `1` represents an obstacle that may be removed.
- You can move **up**, **down**, **left**, or **right** from and to an **empty** cell.

Return the **minimum number** of obstacles to remove so you can move from the upper left corner `(0, 0)` to the lower right corner `(m - 1, n - 1)`.

## Example

![image](https://github.com/user-attachments/assets/1b9355d7-94d1-4d7f-b789-9fc683111ddf)

**Input** -: grid = [[0,1,1],[1,1,0],[1,1,0]]

**Output** -: 2

**Explanation** -: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.

## Problem Constraints 

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10^5`
- `2 <= m * n <= 10^5`
- `grid[i][j] is either 0 or 1.`
- `grid[0][0] == grid[m - 1][n - 1] == 0`

## Topic Tags

`Array`, `Breadth-First Search`, `Graph`, `Heap (Priority Queue)`, `Matrix`, `Shortest Path`

## Approach

In this problem we are given a grid that consists of **0** and **1**. 0 represents an **empty cell** whereas 1 represents an **obstacle**. We need to start from `(0,0)` and reach `(m-1,n-1)` such that we need to find the path removing minimum number of obstacles. The brute force approach recommends the use **DFS or BFS** checking every possible path and calculating answer, but this won't work here as it will lead to time complexity. 

The another approach to solve the problem is using **Shortest Path** algorithms i.e. **Djkstra's Algorithm** in which we move to that cell which has smallest weight in this case minimum obstacle removals. We will use an **ordered set** here instead of **priority queue**. The set will contain `(number of obstacles removed, row, column)`. We will use **BFS** to find answer. We will also maintain a **visited** array so that we don't loop around same state again and again here the state will be `(row, column)`. We have not included `number of obstacles removed` in `visited` array because we are using **ordered set** here so we are always working with the path that has minimum obstacles. Once we reach last corner we will get our answer.
