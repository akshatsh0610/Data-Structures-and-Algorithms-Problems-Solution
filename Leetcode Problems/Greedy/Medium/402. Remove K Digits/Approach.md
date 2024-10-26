# Problem Statement

Given string num representing a non-negative integer `num`, and an integer `k`, return the **smallest*** possible integer after removing `k` digits from `num`.

# Example

**Input**: `num = "1432219"`, `k = 3`

**Output**: `"1219"`

**Explanation**: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

# Problem Constraints

- `1 <= k <= num.length <= 10^5`
- `num` consists of only digits.
- `num` does not have any leading zeros except for the zero itself.

# Topic Tags

`String`, `Stack`, `Greedy`, `Monotonic Stack`

# Approach

The problem here says that we are given a string `num` and `k` (number of digits to be removed from `num`). We need to remove `k` digits such that the resulting string is numerically smallest. The brute force 
approach is to remove every combination of `k` digits and find the answer but looking at problem constraints this is not going to work here. What do we do now? 🤔

Look at the example carefully in order to make `num` smaller we are trying to remove larger digits from right and this is whole solution of this problem. We will traverse the string from right to left and will 
maintain a stack that will keep track of smaller digits to right, now while traversing if we encounter a digit smaller than the one kept at top of stack then we will remove the top digit from stack and will push
the current digit in stack. But what about equal digits, we will keep them intact as they are not going to make any change. Note that we will do this operation till `k>0`. Also we don't want any leading zeros here
so we need to handle them at last. 

And this is how this problem will be solved. 🤩
