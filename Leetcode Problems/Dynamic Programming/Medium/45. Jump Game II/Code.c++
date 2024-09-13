class Solution {
public:
    vector<int>dp;
int jump(vector<int>& nums) 
{
    int idx=0;
    dp.resize(nums.size(),-1);
	return fun(nums,idx);        
}
int fun(vector<int>&nums,int idx)
{
	if(idx >= nums.size())
    {
       return 1e5;
    }
    
	if(idx==nums.size()-1)
	{
	  return 0;	
	}
	
	if(dp[idx]!=-1)
	{
		return dp[idx];
	}
	
	int k = nums[idx];
	
	int ans=1e5;
	
	for(int i=1;i<=k;i++)
	{
	   int temp = 1 + fun(nums,idx+i);
	   if(temp < ans)
	   {
	       ans=temp;	
	   }	
	}
	return dp[idx]=ans;
}
};
