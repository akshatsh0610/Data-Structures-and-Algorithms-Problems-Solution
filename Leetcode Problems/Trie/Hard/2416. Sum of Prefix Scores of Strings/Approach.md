## Problem statement

You are given an array `words` of size `n` consisting of non-empty strings.

We define the **score** of a string term as the number of strings `words[i]` such that term is a **prefix** of `words[i]`.

For example, if `words = ["a", "ab", "abc", "cab"]`, then the score of `"ab"` is `2`, since `"ab"` is a prefix of both `"ab"` and `"abc"`.
Return an array answer of size `n` where `answer[i]` is the **sum of scores** of every non-empty **prefix** of `words[i]`.

Note that a string is considered as a prefix of itself.

## Example

**Input**: words = ["abc","ab","bc","b"]

**Output**: [5,4,3,2]

**Explanation**: The answer for each string is the following:
- "abc" has 3 prefixes: "a", "ab", and "abc".
- There are 2 strings with the prefix "a", 2 strings with the prefix "ab", and 1 string with the prefix "abc".
The total is answer[0] = 2 + 2 + 1 = 5.
- "ab" has 2 prefixes: "a" and "ab".
- There are 2 strings with the prefix "a", and 2 strings with the prefix "ab".
The total is answer[1] = 2 + 2 = 4.
- "bc" has 2 prefixes: "b" and "bc".
- There are 2 strings with the prefix "b", and 1 string with the prefix "bc".
The total is answer[2] = 2 + 1 = 3.
- "b" has 1 prefix: "b".
- There are 2 strings with the prefix "b".
The total is answer[3] = 2.

## Problem Constraints

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 1000`
- `words[i]` consists of lowercase English letters.

## Topic Tags

`Array`, `String`, `Trie`, `Counting`

## Approach

The **brute-force approach** says that we can store all possible prefixes of every string along with their frequency in a map and at last we can calculate `answer[i]` by calculating the sum of frequencies of all possible prefixes of that string. But looking at the constraints the approach won't work here becuase the
maximum time by this approach is O(size(array)*len(array[i])).

The another approach to solve this problem is use **Prefix Tree** or **Trie**. We will store every word in trie. The node of trie will consist of an array of size 26 (letters from 'a' to 'z'), the elements are pointer to next node of trie (initialized by NULL), `count` which is initialized as 0  and a boolean flag `isend` initialized by false that will keep track of end of string. 

We will insert every word in trie for this we will define a `root` pointing to beginning of trie and will traverse complete word string storing each element of string in trie if not already stored and we will also increment count of each word. Next we will iterate over `words` array and will calculate the sum of `count` of every character present in the prefix tree. Now here when we are taking the sum of counts actually we are calculating the frequency of every possible prefix of word. And this is how we will get our answer.
