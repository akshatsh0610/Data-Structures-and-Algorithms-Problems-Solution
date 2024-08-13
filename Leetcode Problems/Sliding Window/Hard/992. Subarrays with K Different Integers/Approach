Problem Statement -:

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1 -:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2 -:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

Problem Constraints -:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

Difficulty Level -: Hard

Topics -: Array, Hash Table, Sliding Window, Counting

Intuition -:

In this problem we have to find the number of subarrays that have exactly k integers. So let's apply brute force approach first.

Brute Force Approach -:

The simplest solution of this problem is to make subarrays of the given array and count number of different integers in each subarray if count==k then it is included
in answer. 
The time taken by this approach is O(N^2), so the maximum time that can be taken is O(10^4*10^8) and this is equivalent to O(10^8). Clearly this approach is going to take a
lot time. So let's find an optimized solution.

Optimized Approach -:

Here we are talking about subarrays and count of different integers in every subarray, this line clarifies the use of hash table and sliding window. But the problem arises
here that we have find those subarrays that have exactly k different integers. So applying just sliding window and hash table to find subarrays having exactly k different
integers will not work, as it will not give us correct answer. Look at this example -:
Ex -: arr = [1,2,1,2,3] , k = 2
So here we will maintain the size of map equal to k and will move our window accordingly. The subarrays we will get doing this are -: 
[1,2], [1,2,1], [1,2,1,2], [2,1,2], [1,2], [2,3] 
Here we are getting 6 subarrys, we have missed the subarray [2,1] here. This seems a problem here. Let's think of some solution.
Let's find all the subarrays having different integers less than equal to k. So the total answer will be equal to -:
ans1= number of subarrays having 1 different integer + number of subarrays having 2 different integers + ......+ number of subarrays having k-1 different integer + number of 
subarrays having k different integers
Now let's find all the subarrays having different integers equal to less than to k-1. So the total answer will be equal to -:
ans2= number of subarrays having 1 different integer + number of subarrays having 2 different integers + ......+ number of subarrays having k-2 different integer + number of 
subarrays having k-1 different integers
Now if you calculate ans1 - ans2, you will get all the subarrays having exactly k different integers.
ans=(number of subarrays having 1 different integer + number of subarrays having 2 different integers + ......+ number of subarrays having k-1 different integer + number of 
subarrays having k different integers) - (number of subarrays having 1 different integer + number of subarrays having 2 different integers + ......+ number of subarrays having
k-2 different integer + number of subarrays having k-1 different integers)
So what we are doing here is finding all the subarrays having different integers less than equal to k and k-1, and then subtracting the count of both to get final answer.
To find subarrays we will use sliding window and to get the count of only those subarrays having different integers less than equal to k and k-1 we will use hash table.
The time taken by this approach is O(N). So the maximum time that it can take is O(10^4).
