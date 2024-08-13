Problem Statement -:

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1 -: 

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2 -:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Problem Constraints -:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

Brute Force Approach -:

In this problem we have to find greatest element which we can find by traversing the array from starting to end eventually updating our answer which is initially set to INT_MIN. This will have time complexity of
O(N) where N is size of array.

Optimized Approach -:

To find peak element in time less than O(N) we can use Binary Search. Binary search is a searching technique used to search an element in a sorted list in O(logN) time. 
In the problem they have given us rotated sorted array that means before a particular element the array is decreasing (right to left) and after that the array is increasing (left to right).
Example -: 4 5 6 1 2 3, so here the array is rotated at point 6. 6 is peak element here and you can see that element before 6 and after 6 are less than 6, and this is our condition of getting answer.
So whenever we encounter an element having small adjacent elements is our peak element.
We will take start pointer pointing to first element of array and end element pointing to last element of array, our mid element will be pointing at (start+end)/2.
If mid==0 then we will check mid+1 element, if arr[mid+1]<arr[mid] then 0th element is our peak element, otherwise we will go to right side.
If mid==arr.size()-1 then we will check mid-1 element, if arr[mid-1]<arr[mid] then 0th element is our peak element, otherwise we will go to left side.
If our mid>0 and mid<arr.size()-1 then we will check mid-1 and mid+1 element, if arr[mid-1]<arr[mid] and arr[mid+1]<arr[mid], then this element is our peak element, otherwise we will go in both directions right
and left. We are going in both directions because our array is rotated sorted so we have increasing elements to the left of peak element and to the right of peak element.
