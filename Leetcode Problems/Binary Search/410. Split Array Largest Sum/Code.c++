class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
         long long int start=0;
         long long int end=INT_MAX;
         long long int ans=-1;
         int result;
         while(start<=end)
         {
             long long int mid=(start+end)/2;
             result=isposs(nums,m,mid);
             
             if(result==1)  
             {
                 ans=mid;
                 end=mid-1;
             }
             else if(result==0)   
             {
                 start=mid+1;
             }
             else if(result==-1)
             {ans=mid;
                 end=mid-1;
             }
         }
        return ans;
    }
    int isposs(vector<int>&nums,long long int m,long long int max)
    {
        long long int sub_count=1;
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max)
            {
                return false;
            }
            else if((sum+nums[i])>max)
            {
                sub_count++;
                sum=nums[i];
                
                if(sub_count>m)
                {
                    return false;
                }
            }
            else
            {
                sum=sum+nums[i];
            }
            
        }
       
        if(sub_count==m)
        {
            return 1;
        }
        else if(sub_count<m)
        {
            return -1;
        }
        else if(sub_count>m)
        {
            return 0;
        }
        return 99;
    }
};
