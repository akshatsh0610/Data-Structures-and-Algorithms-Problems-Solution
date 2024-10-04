# Problem Statement

You are given an `n x n` integer matrix grid where each value `grid[i][j]` represents the elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are 
at most `t`. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square `(n - 1, n - 1)` if you start at the top left square `(0, 0)`.

# Example 

**Input**: grid = `[[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]`
**Output**: 16

# Problem Constraints

- `n == grid.length`
- `1 <= n <= 50`
- `0 <= grid[i][j] < n^2`
- Each value grid[i][j] is **unique**.

# Topic Tags

`Array`, `Binary Search`, `Depth-First Search`, `Breadth-First Search`, `Union Find`, `Heap (Priority Queue)`, `Matrix`

# Approach

In this problem we are given a 2-D array that consists of elevation at a particular point. The problem says that at time `t` the depth of water everywhere is `t` and a person can swim in 4 directions (up,left,
right, down) such that the elevation at every point is at most `t`. The person needs to swim from `0,0` to `(n-1,n-1)` in least time `t`. 

Now the problem specifies two things number 1 is the time `t` is maximum elevation and second point is the time `t` is minimum time taken to move from `0,0` to `(n-1,n-1)`. These type of problems are generally
solved using **Binary search**. And for shortest path having maximum elevation equal to `t` we will use **Breadth First Search**.

We will make a direction matrix of size `(4,2)` that will contain movement to all four directions. We will apply **Binary Search** from `start=0` to `end=m*n` wwhere `m` is number of rows in grid and `n` is 
number of columns in grid. Our goal is to minimize the **maximum elevation**. So we will check every possible elevation using **BFS**. If the elevation is valid we will try to minimize it using `end=mid-1`, 
otherwise we will look for valid elevation using `start=mid+1`.

In **BFS** we will store the `{start point}` in queue i.e. `(0,0)` and we will also make visited array so that we can't go again and again on cells visited before. We will check in all four direction and will
push the new position in queue if it not visited before and elevation at this point is less or equal to maximum elevation we will do this till we reach `(n-1,n-1)`. 
