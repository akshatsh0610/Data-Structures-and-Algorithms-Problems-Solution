## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if `nums` has a **good subarray** or `false` otherwise.

A **good subarray** is a subarray where:
- its length is **at least two**, and
- the sum of the elements of the subarray is a **multiple** of `k`.
  
**Note** that:
- A **subarray** is a contiguous part of the array.
- An integer `x` is a multiple of `k` if there exists an integer `n` such that `x = n * k`. `0` is always a multiple of `k`.

## Example

**Input**: nums = [23,2,4,6,7], k = 6

**Output**: true

**Explanation**: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

## Problem Constraints

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`
- `0 <= sum(nums[i]) <= 2^31 - 1`
- `1 <= k <= 2^31 - 1`

## Topic Tags

`Array`, `Hash Table`, `Math`, `Prefix Sum`

## Intuition

We are given an array `nums` and an integer `k` and we need to find the subarray having length greater than or equal to 2 and `(sum of subarray)%k==0`. The brute force approach says that we can generate every
subarray and check their sum. But this is going to take more time. Also we can't use sliding window here as we have no defined sliding window condtion here. So we have last option here is to prefix sum and hash
table. We will use prefix sum, which is also called running sum of array, to keep track of the sum of subarrays starting from 0 and we will use hashtable that will keep track the prefix sums at index  `i`.
We are going to use concept of prefix sum to calculate sum of particular subarray `prefix[i] - prefix[j] = sum(subarray(j-i))` here `i>j`. Now `sum(subarray(j-i))%k==0` for a good subarray, alternatively
`sum(subarray(j-i))==k*x` or `prefix[i] - prefix[j]==k*x` taking mod k on both side.

=> `prefix[i]%k - prefix[j]%k==0`

=> `prefix[i]%k == prefix[j]%k`

We will use this terminology to find our answer. We will calculate the prefix sum of array and each time we will apply mod k on it. If the sum is present in map then we have found the good subarray otherwise
we will store the sum in map. This is how the problem is solved.
