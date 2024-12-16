Problem Statement -:

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

Example 1 -:

Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2 -:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3 -:

Input: s = ")("
Output: [""]

Problem Constraints -:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.

Topic Tags -: String, Backtracking, Breadth-First Search

Approach -:

The problem is simple we have to generate all the possible valid parenthesis after removing the characters that make an invalid set. To generate the valid set of parentheses we will first calculate the number
of invalid parenthesis then we will remove all the invalid brackets to get the answer. Now every character comes with two choices either we can remove it or keep it. So we will recursively generate every set
using the above two cases. Note that we will only remove invalid number of characters. After removing the set of characters we will check whether the resulting set is valid or not.This is how we will generate
all the parentheses.
