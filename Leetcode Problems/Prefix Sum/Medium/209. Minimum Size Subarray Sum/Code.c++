class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int size=INT_MAX;
    
        int start=0;
        int end=0;

        int sum=0;

        while(end<nums.size())
        {
            while(end<nums.size() and sum<target)
            {
                sum=sum+nums[end];
                end++;
            }
            //break out because of sum>=target
            while(sum>=target)
            {
                size=min(size,end-start);
                sum=sum-nums[start];
                start++;
            }
        }
        if(size==INT_MAX) return 0;
        return size;
    }
};
