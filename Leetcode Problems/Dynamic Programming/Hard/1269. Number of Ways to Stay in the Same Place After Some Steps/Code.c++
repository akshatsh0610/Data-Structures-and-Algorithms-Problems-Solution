class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>>dp;
    int numWays(int steps, int arrLen) {
        dp.resize(steps+1,vector<int>(steps+1,-1));
        return fun(steps,0,arrLen)%mod;
    }
    int fun(int steps,int pos,int &arrLen)
    {
        if(steps==0 and pos==0)
        {
            return 1;
        }
        if(steps==0)
        {
            return 0;
        }
        if(dp[steps][pos]!=-1)
        {
            return dp[steps][pos]%mod;
        }
        int right=0,left=0,stay=0;
        if(pos<arrLen-1)
            right=fun(steps-1,pos+1,arrLen)%mod;
        if(pos>0)
            left=fun(steps-1,pos-1,arrLen)%mod;
        stay=fun(steps-1,pos,arrLen)%mod;
        return dp[steps][pos]=(0LL+(right%mod)+(left%mod)+(stay%mod))%mod;
    }
};
