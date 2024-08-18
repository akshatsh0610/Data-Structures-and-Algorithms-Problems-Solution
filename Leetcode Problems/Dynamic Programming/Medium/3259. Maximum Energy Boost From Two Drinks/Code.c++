class Solution {
public:
    vector<vector<long long>>dp;
    long long maxEnergyBoost(vector<int>& drink1, vector<int>& drink2) {
        dp.resize(drink1.size(),vector<long long>(3,-1));
       return getMaxEnergy(drink1,drink2,0,0); 
    }
    long long getMaxEnergy(vector<int>&d1,vector<int>&d2,int d,int idx)
    {
        if(idx>=d1.size())
        {
            return 0;
        }
        if(dp[idx][d]!=-1)
        {
            return dp[idx][d];
        }
        long long choise1=0;
        long long choise2=0;
        if(idx==0)
        { 
            choise1=d1[idx]+max(getMaxEnergy(d1,d2,1,idx+1),getMaxEnergy(d1,d2,2,idx+2));
            choise2=d2[idx]+max(getMaxEnergy(d1,d2,2,idx+1),getMaxEnergy(d1,d2,1,idx+2));
        }
        else
        {
            if(d==1)
            {
                choise1=d1[idx]+getMaxEnergy(d1,d2,1,idx+1);
                choise2=d1[idx]+getMaxEnergy(d1,d2,2,idx+2);
            }
            else 
            {
                choise1=d2[idx]+getMaxEnergy(d1,d2,2,idx+1);
                choise2=d2[idx]+getMaxEnergy(d1,d2,1,idx+2);
            }
        }
        return dp[idx][d]=max(choise1,choise2);
    }
};
