# Problem Statement

Given an array of integers arr of even length `n` and an integer `k`.

We want to divide the array into exactly `n / 2` pairs such that the sum of each pair is divisible by `k`.

Return **true** If you can find a way to do that or **false** otherwise.

# Example 

Input: arr = `[1,2,3,4,5,10,6,7,8,9]`, k = `5`

Output: **true**

Explanation: Pairs are `(1,9),(2,8),(3,7),(4,6)` and `(5,10)`.

# Problem Constraints 

- `arr.length == n`
- `1 <= n <= 10^5`
- `n is even.`
- `-10^9 <= arr[i] <= 10^9`
- `1 <= k <= 10^5`

# Topic Tags

`Array` , `Hash Table` , `Counting`

# Approach

We have to find `n/2` pairs in array `arr` such sum of each pair is divisible by `k`. We can find each pair and check their sum by using brute force appraoch but
looking at constraints that won't work here. We will use hash table here. According to problem `(arr[i]+arr[j])%k==0`. Simplifying the expression -:
`((arr[i]%k) + (arr[j]%k))%k==0`. Now we know that `arr[i]%k` will be between `[-(k-1) - k-1]` and so will be `arr[j]%k`. But their sum `((arr[i]%k) + (arr[j]%k))` 
can still be greater than k. We will store remainder of each number in hashtable and for negative remainders we will store `remainder + k`. And then we will check
each value in map say `x` has `k-x` present or not. If present we will continue otherwise return **false**.
