Problem Statement -:

You are given an integer array nums of length n.
Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
The score for a jump from index i to index j is calculated as (j - i) * nums[i].
Return the maximum possible total score by the time you reach the last index.

Example 1 -:

Input: nums = [1,3,1,5]
Output: 7
Explanation:
First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.

Example 2 -:

Input: nums = [4,3,1,3,2]
Output: 16
Explanation:
Jump directly to the last index. The final score is 4 * 4 = 16.

Problem Constraints -:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

Intuition -:

The problem says that we can take steps from 0th position till we reach end. The steps are taken such that total score is maximized. The score associated with 
each step is "(j-i)*nums[i]" (j>i). Looking at the score it is clear that if we step on index whose value is greater than or equal to the value of previous 
index, the score will be maximized. But how do we find the index that will have greater or equal value than its previous step. 
We will use stack for this purpose or I can say that the approach is going to use Monotonic stack. The stack will store only the elements that are greater or
equal to previous element. 
We need to find the greater or equal element right to the previous element. We will use an array to store the possible index. This array will basically stores
the index of next greater element to the right of particular element. We will start from right most index that is last index as the last element doesn't have
any valid index to the right its ngr index will be -1. Pushing the last element index in stack and iterating `nums` from second last index. We will check the seen
element that is the elements stored in stack and check whether there is any possible ngr amongst the elements seen so far or not. If present we will store it in 
our array (ngr[i]=st.top()), otherwise we will store -1.
Now we will start iterating from 0th index to calculate the maximum score as we have already found the next greater or equal element to the right of particular
index, we will only jump to that index till possible. If any index has ngr[i]=-1 we will directly take jump to last index as no ngr exists and this is how our 
score is maximized.
