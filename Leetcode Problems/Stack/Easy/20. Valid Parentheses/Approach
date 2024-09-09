Problem Statement -:

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1 -:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([])"
Output: true

Problem Constraints -: 

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Topic Tags -: String, Stack

Intuition -:

In this question we are given a string that contains the opening and closing bracket of type '(', '{', '['. We need to check whether the given string is valid or 
not. The valid string is the string that has open brackets followed by their corresponding closing brackets. 
The brute force approach says that we can use two loops one loop for opening bracket and second loop to find corresponding closing bracket. But looking at problem
constraints this approach is not going to work. So what do we do now, is there a possible method to find closing bracket corresponding to opening bracket.
We will use stack in which we will keep opening brackets and whenver we encounter a closing bracket of corresponding opening bracket present at top of stack we will
pop it out otherwise the combination is not valid. Look here the stack is a container which keeps track of already seen opening brackets. 
If we get all the valid brackets the stack will become empty otherwise the string is not valid.
