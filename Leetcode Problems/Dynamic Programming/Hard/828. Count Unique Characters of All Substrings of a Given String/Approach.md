# Problem Statement

Let's define a function `countUniqueChars(s)` that returns the number of unique characters in s.

For example, calling countUniqueChars(s) if `s = "LEETCODE"` then `"L", "T", "C", "O", "D"` are the **unique characters** since they appear only once in **s**, therefore `countUniqueChars(s) = 5`.
Given a string `s`, return the sum of `countUniqueChars(t)` where `t` is a substring of `s`. The test cases are generated such that the answer fits in a **32-bit integer**.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

# Example 

**Input**: s = "ABC"

**Output**: 10

**Explanation**: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

# Problem Constraints

- `1 <= s.length <= 10^5`
- `s` consists of uppercase English letters only.

# Topic Tags

`Hash Table`, `String`, `Dynamic Programming`

# Approach

In this problem we are given a string `s` and we need to count the number of **unique** characters in every substring of `s` and we need to return the sum of count. 

The **brute-force** approach to solve the problem is to generate every substring and count the unique characters and finally add them to generate answer. But that won't work here because the length of string can
go upto `10^5` . The time taken by this approach is `O(N^2)` so this approach will not work here.

To solve this problem we are going to use **Hash Table** and **Dynamic Programming**. 

Look at every substring of **ABCA** -:

- A
- AB
- ABC
- **ABCA**
- B
- BC
- BCA
- C
- CA
- A

Here in substring **ABCA** you can see that **A** is repeating character and the occurences of this character are `0, 3`, this says that **A** is unique in all the substrings having starting and ending indexes as
`0-2` and `1-2`. So what we are going to do here we will keep track of count of every substring in which a particular character is unique. So **A** is unique in A, AB, ABC, BCA, CA, A.

We are going to store the left-most index of each character in a map and subsequent indices in a queue. The map is used to map each character to its corresponding queue. We will traverse the string from starting
if the current character is not stored in a map containing left indices then the substrings starting from `0 - i` and ending at `i` have `s[i]` as unique character, so we will count them using `i+1` these are 
considered as left substrings. Similarly we will count all the substrings starting from index `i` and have `s[i]` as unique character and for this we will use our map that stores right indices. At last we will
mulitply count of left and right to get total substrings.

If the current character has already encountered then we will do calculations with respect to this current index and will update the left index of character in map.

This is how this problem is solved using hash table and dynamic programming.
