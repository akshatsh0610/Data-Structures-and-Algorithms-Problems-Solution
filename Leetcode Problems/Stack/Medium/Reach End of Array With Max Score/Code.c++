class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        stack<int>st;
        int n=nums.size()-1;
        st.push(nums.size()-1);
        //ngr
        vector<int>ngl(nums.size(),-1);
        for(int i=nums.size()-2;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()]<nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ngl[i]=st.top();
            }
            st.push(i);
        }
        int i=0;
        while(i<nums.size())
        {
            if(ngl[i]==-1)
            {
                ans=ans+0LL+((n-i)*1LL*nums[i]*1LL);
                break;
            }
            else
            {
                ans=ans+0LL+((ngl[i]-i)*1LL*nums[i]*1LL); 
                if(ngl[i]==n)
                    break;
                i=ngl[i];
            }
        }
        return ans;
    }
};
