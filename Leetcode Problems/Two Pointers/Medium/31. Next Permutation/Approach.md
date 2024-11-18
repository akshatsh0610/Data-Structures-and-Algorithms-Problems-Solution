## Problem Statement

A **permutation** of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = `[1,2,3]`, the following are all the permutations of arr: `[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]`.
The **next permutation** of an array of integers is the **next lexicographically greater permutation** of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = `[1,2,3] is [1,3,2]`.

Similarly, the next permutation of arr = `[2,3,1] is [3,1,2]`.

While the next permutation of `arr = [3,2,1] is [1,2,3]` because `[3,2,1]` does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be **in place** and use only **constant extra memory**.

## Example 

**Input**: nums = `[1,2,3]`

**Output**: `[1,3,2]`

## Problem Constraints

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

## Topic Tags

`Array`, `Two Pointers`

## Approach

The problem saya that we have to lexicographic next arrangement of given array or more specifically we can say that we have find just greater number of the number represented by array. So when we look closely
at the given array we will not find any next arrangement if the array is decreasing. To make just next greater arrangement we have to arrange rightmost elements first. As you can see in above example the last 
numbers were arranged to get next permutation. So in order to find next permutation we will iterate our array from last and will keep track of maximum element. While traversing if we encounter any element greater
than `max_ele` then we will do nothing because rearranging them will make our arrangement smaller. But if encounter any element smaller than `max_ele` then we will swap this element with another element which is
just greater than current element and whose index is greater than index of current of current element and then we will sort the subarray ranging from `(current_index+1, nums.size())`. 

You might be thinking that why are we sorting and swapping here. The reason is simple we are swapping our current element with its just greater number this will help us to create next sequence of givem sequence
amd sorting will maintain the lexicographical order. 

This is how we will solve this problem.
