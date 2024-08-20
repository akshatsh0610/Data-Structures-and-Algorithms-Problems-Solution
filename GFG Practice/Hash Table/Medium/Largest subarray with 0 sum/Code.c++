/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        //return approach1(arr,n);
        return approach2(arr,n);
    }
    int approach1(vector<int>&arr,int &n)
    {
        int len=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                if(sum==0)
                {
                    // subarray -->ans
                    len=max(len,j-i+1);
                }
            }
        }
        return len;
    }
    int approach2(vector<int>&arr,int &n)
    {
        vector<int>v(n);
        v[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            v[i]=v[i-1]+arr[i];
        }
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(v[i])!=mp.end())
            {
                ans=max(ans,i-mp[v[i]]);
            }
            else
            {
                mp[v[i]]=i;
            }
        }
        return ans;
    }
};
