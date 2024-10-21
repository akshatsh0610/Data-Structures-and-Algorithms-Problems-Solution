# Problem Statement

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the **median** of the two sorted arrays.
The overall run time complexity should be `O(log (m+n))`.

# Example

**Input**: `nums1 = [1,3], nums2 = [2]`
**Output**: `2.00000`
**Explanation**: merged `array = [1,2,3]` and median is **2**.

# Problem Constraints

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

# Topic Tags

`Array`, `Binary Search`, `Divide and Conquer`

# Solution

In this problem we are given two **sorted** arrays `nums1` and `nums2` and we need to find the **median** of two sorted arrays. Note that median is the **middle 
element** of a sorted array. So the easiest solution of this problem is to merge these sorted arrays and find the middle element. The middle element depends on
the size of resultant array. If the size is even the middle element would be `(size/2)-1` (0-indexed) otherwise middle element would be `((size/2)-1) + ((size/2)-1-1))/2` (average of middle and element before middle element). So this is the brute force approach which will take time of O(m+n). But we need to solve the problem
in `O(log(m+n))` time. 

Seeing the time complexity it is clear that it is a **Binary Search** problem. 
