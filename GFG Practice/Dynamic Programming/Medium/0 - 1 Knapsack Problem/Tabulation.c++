
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(w+1));
       
       for(int i=0;i<(w+1);i++)
       {
           dp[0][i]=0;
       }
       for(int i=0;i<(n+1);i++)
       {
           dp[i][0]=0;
       }
       for(int i=1;i<(n+1);i++)
       {
           for(int j=1;j<(w+1);j++)
           {
               if(wt[i-1]>j)
               {
                   dp[i][j]=dp[i-1][j];
               }
               else 
               {
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               }
           }
       }
       return dp[n][w];
    }
};
