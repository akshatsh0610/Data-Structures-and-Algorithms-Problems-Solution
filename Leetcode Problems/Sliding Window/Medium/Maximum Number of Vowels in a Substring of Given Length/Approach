Problem Statement -:

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1 -:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2 -:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3 -:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

Problem Constraints -:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length

Topic Tags -:

String, Sliding Window

Intuition -:

In this problem we are given a string and length of substring equal to k. We need to find maximum vowels in the substring of size of k. Two solutions are possible
for this problem.

Brute Force Approach -:
This approach says that we can make every substring of size k and count vowels in each substring and get maximum count. This approach has time complexity of O(n^2)
where n is length of string.

Optimized Approach -:
The another approach suggests the use of sliding window. As we are given the length of substring this says that we can create a window of exactly k size and then 
calculate the count of vowels by sliding window. We will set a starting pointer on the 0th index and ending pointer on 0th index as well. The starting and ending
pointers marks the starting and ending points of window. We will keep updating our end pointer (end++) till our window size (end-start+1) is not equal to k and if
we encounter any vowel we will increase our count. When window size is equal to k we will keep track of maximum count. And when window size exceeds k we will move
start pointer so that our window size is maintained to k, here if we encounter any vowel at start we decrease our count as this vowel will become part of previous 
window and this is how we can calculate vowels of all substrings of size k. This approach take time of O(n) as we are simultaneously moving start and end pointers.
