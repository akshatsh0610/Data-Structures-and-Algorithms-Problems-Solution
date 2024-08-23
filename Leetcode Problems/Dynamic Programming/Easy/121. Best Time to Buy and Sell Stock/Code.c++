class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int currmin=INT_MAX;
        int profit=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<currmin)
            {
                currmin=arr[i];
            }
            if(profit<(arr[i]-currmin))
            {
                profit=arr[i]-currmin;
            }
        }
        return profit;
        
    }
};
