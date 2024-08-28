Problem Statement -:

You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the proper divisors of x.
A number is called special if it has exactly 2 proper divisors. For example:
The number 4 is special because it has proper divisors 1 and 2.
The number 6 is not special because it has proper divisors 1, 2, and 3.
Return the count of numbers in the range [l, r] that are not special.

Example 1 -:

Input: l = 5, r = 7
Output: 3
Explanation:
There are no special numbers in the range [5, 7].

Example 2 -:

Input: l = 4, r = 16
Output: 11
Explanation:
The special numbers in the range [4, 16] are 4 and 9.

Problem Constraints -:

1 <= l <= r <= 10^9

Topic Tags -: Array, Math, Number Theory

Intuition -:

The problem says that we have to count the non-special numbers in range [l,r]. Special numbers are numbers having exaclty 2 proper divisors (apart from itself). 
Let's talk about prime numbers first. Prime numbers are the numbers having two divisors, 1 and number itself. Now let's consider the squares of prime number, the
divisors of the number is 1, prime number and number itself. 
Example -: 
4 -> {1,2,4}
9 -> {1,3,9}
25 -> {1,5,25}
49 -> {1,7,49} etc.
So we can see that squares of prime number are special numbers. Now we have to find special number in range [l,r]. This implies,
l<= (prime number)^2 <=r
=> sqrt(l) <= prime number <= sqrt(r)
So it is clear that we have to find the total number of prime number between [sqrt(l), sqrt(r)].
Now we need to find total number of non-special number.
Non-special numbers = (r-l+1) - (number of prime number in range [sqrt(l), sqrt(r)].
Looking at constraints we will use seive of erasthoneses to calculate the prime numbers between [1,sqrt(r)]. The seive says that we will consider each number as 
prime number then we will cancel every number that is a multiple of prime number. In this way we get all the prime numbers between [1,sqrt(r)]. Then we will 
calculate the numbers between [sqrt(l),sqrt(r)] and finally we will get our answer.
