class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>>dp;
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       dp.resize(n+1,vector<int>(W+1,-1));
       int idx = 0;
       return fun(idx,W,n,val,wt);
    }
    int fun(int idx , int W,int &n,int val[],int wt[]){
        if(idx >= n){
            return 0;
        }
        int choise1 = 0;
        int choise2 = 0;
        
        if(dp[idx][W] != -1){
            return dp[idx][W];
        }
        
        if(wt[idx] <= W){
            choise1 = val[idx] + fun(idx+1,W-wt[idx],n,val,wt);
            choise2 = 0        + fun(idx+1,W,n,val,wt);
            return dp[idx][W] = max(choise1,choise2);
        }
        else if(wt[idx] > W){
            choise2 = 0 + fun(idx+1,W,n,val,wt);
            return dp[idx][W] = choise2;
        }
    }
};
