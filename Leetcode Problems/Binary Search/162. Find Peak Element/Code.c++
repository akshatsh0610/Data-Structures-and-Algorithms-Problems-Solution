class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()==1)
        {
            return 0;
        }
        
        int n=nums.size();
        
        int start=0;
        int end=nums.size()-1;
        
        int idx=-1;
        
        fun(idx,start,end,n,nums);
        
        return idx;
    }
    void fun(int &idx,int start,int end,int n,vector<int>&arr)
    {
       
        
        if(start>end)
        {
            return;
        }
         int mid=(start+(end-start)/2);
        
        if(mid==0)
        {
            if(arr[mid]>=arr[mid+1] and arr[mid]>=arr[n-1])
            {
                idx=mid;
                return;
            }
            else
            {
               fun(idx,mid+1,end,n,arr);    
            }
            
            
        }
        else if(mid==n-1)
        {
            if(arr[mid]>=arr[mid-1] and arr[mid]>=arr[0])
            {
                idx=mid;
                return;
            }   
            else
            {
              fun(idx,start,mid-1,n,arr);    
            }
            
        }
        else if(mid>0 and mid<n-1)
        {
            if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1])
            {
                idx=mid;
            }
            else
            {
                if((arr[mid+1]>arr[mid] and arr[mid-1]>arr[mid]) or (arr[mid+1]==arr[mid-1]))
                {
                    fun(idx,start,mid-1,n,arr);
                    fun(idx,mid+1,end,n,arr);
                }
                else if(arr[mid+1]>arr[mid])
                {
                    fun(idx,mid+1,end,n,arr);
                }
                else if(arr[mid-1]>arr[mid])
                {
                    fun(idx,start,mid-1,n,arr);
                }
            }
        }
    }
};
