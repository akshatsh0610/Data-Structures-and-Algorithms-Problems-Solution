Problem Statement -:

Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1 -: 

Input: arr[] = {15,-2,2,-8,1,7,10,23}, n = 8
Output: 5
Explanation: The largest subarray with sum 0 is -2 2 -8 1 7.

Example 2 -:

Input: arr[] = {1, 0, -4, 3, 1, 0}, n = 6
Output: 5
Explanation: The subarray is 0 -4 3 1 0.

Problem Constraints -:

1 <= n <= 10^5
-1000 <= arr[i] <= 1000, for each valid i

Topics -: Arrays, Hash

Company Tags -: Amazon, Microsoft, MakeMyTrip

Brute Force Approach -:

In this problem we have find the length of the largest subarray whose sum is equal to 0. The question is straight forward we will find the sum of all the subarrays. The subarray whose sum is 0 can give an answer 
to us. We will find maximum length out of all valid subarrays. To find all the subarrays we know that we need nested loops. So the time complexity of this approach will be O(N^2). This is pretty much time, this 
approach will not work here. Let's optimize the solution.

Optimized Approach -:

We know what Prefix sum is, it is the running sum of array. Suppose you have an array of size=8
arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
prefix[] = {15, 15+(-2), 15+(-2)+2, 15+(-2)+2+(-8), 15+(-2)+2+(-8)+1, 15+(-2)+2+(-8)+1+7, 15+(-2)+2+(-8)+1+7+10, 15+(-2)+2+(-8)+1+7+10+23]
         => {15, 13, 15, 7, 8, 18, 41}
We can say that prefix[] array contains the sum of all the subarrays starting from 0th index.
Let's consider two subarrays starting from 0 ending at x and y respectively where x<y.
Prefix sum of subarray starting at 0 and ending at x = p(x)
Prefix sum of subarray starting at 0 and ending at y = p(y)
Now p(y) - p(x) = a, here 'a' is the sum of subarray starting at x and ending at y.
Now according to the problem we have to find the largest subarray having sum = 0. This implies that a = 0 i.e. p(x) - p(y) = 0 => p(x) = p(y).
This breakdown is complete logic of problem. The logic says that first we have to find prefix sum of array then we have to find the prefix sums that comes more than one time. To keep track of duplicate prefix sums
I will use map here. The map will store the sum as key and index of the prefix sum. Initially our sum is 0 so mp[0] = -1. Whenever we encounter a duplicated prefix sum we will consider it in our answer as 
ans = max(ans, i - mp[sum]). 
Seeing the array if any of our sum repeats itself it suggests that the elements between the latest sum and previous sum are cancelling each other.
The time taken by this solution is O(N).
