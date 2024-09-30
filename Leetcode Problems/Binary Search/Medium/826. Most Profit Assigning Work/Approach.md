# Problem Statement

You have `n` jobs and `m` workers. You are given three arrays: **difficulty**, **profit**, and **worker** where:

- `difficulty[i]` and `profit[i]` are the difficulty and the profit of the `ith` job, and
- `worker[j]` is the ability of `jth` worker (i.e., the `jth` worker can only complete a job with difficulty at most `worker[j]`).

Every worker can be assigned at most one job, but one job can be **completed multiple times**.

For example, if three workers attempt the same job that pays `$1`, then the total profit will be `$3`. If a worker cannot complete any job, their profit is `$0`.
Return the maximum profit we can achieve after assigning the workers to the jobs.

# Example 1

Input: difficulty = `[2,4,6,8,10]`, profit = `[10,20,30,40,50]`, worker = `[4,5,6,7]`
Output: 100
Explanation: Workers are assigned jobs of difficulty `[4,4,6,6]` and they get a profit of `[20,20,30,30]` separately.

# Example 2

Input: difficulty = `[85,47,57]`, profit = `[24,66,99]`, worker = `[40,25,25]`
Output: 0

# Problem Constraints

`n == difficulty.length`

`n == profit.length`

`m == worker.length`

`1 <= n, m <= 10^4`

`1 <= difficulty[i], profit[i], worker[i] <= 10^5`

# Topic Tags

`Array`, `Two Pointers`, `Binary Search`, `Greedy`, `Sorting`

# Approach

In the problem we are given three arrays namely -:
- `difficulty` : tells about the difficulty in doing job.
- `profit` : tells about profit associated with each job.
- `worker` : tells the maximum difficulty job that can be done by a worker.

We have to assign jobs to workers such that total **profit is maximized**.

Now the jobs are assigned to `ith` worker such that `worker[i]>=difficulty assigned` and also we need to assign a job that maximizes total profit. 
And this is the most important part of problem. 

To ensure this we will group difficulty and corresponding profit of jobs and sort the grouped array according to difficulty. And then we will find the prefix 
maximum based on profit of this grouped array. This will help us to assign task with maximum profit. Also a job can be assigned maximum times so we got no problem
here.

Then we will iterate over `workers` array and for each worker `worker[i]` we will find a job whose `difficulty<=worker[i]` and whose `profit` is maximum. For this
we apply **binary search** on the grouped array. As we are always trying to maximize profit so whenever we find possible `difficulty` we will assign the profit
to `answer` and will go to right `start=mid+1`. Otherwise we will lower `difficulty` by `end=mid-1`. And this is how we will get our answer.
