class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int idx = 0;
       return fun(idx,W,n,val,wt);
    }
    int fun(int idx , int W,int &n,int val[],int wt[]){
        if(idx >= n){
            return 0;
        }
        int choise1 = 0;
        int choise2 = 0;
        
        if(wt[idx] <= W){
            choise1 = val[idx] + fun(idx+1,W-wt[idx],n,val,wt);
            choise2 = 0        + fun(idx+1,W,n,val,wt);
            return max(choise1,choise2);
        }
        else if(wt[idx] > W){
            choise2 = 0 + fun(idx+1,W,n,val,wt);
            return choise2;
        }
    }
};
