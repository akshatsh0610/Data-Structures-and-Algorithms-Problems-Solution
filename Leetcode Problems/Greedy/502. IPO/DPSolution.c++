class Solution {
public:
    int n;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         int idx = 0;
         n = profits.size();
         return fun(idx,profits,capital,k,w);
    }
    int fun(int idx , vector<int>&profit , vector<int>&capital, int k , int w){
         if(idx >= n){
            return w;
         }

         int choise1 = 0;
         int choise2 = 0;
         int choise3 = 0;

         if((k > 0) and w >= capital[idx]){
             choise1 = fun(idx+1,profit,capital,k-1,w+profit[idx]);
             choise2 = fun(idx+1,profit,capital,k,w);
             return max(choise1,choise2);
         }
         else if(w <= capital[idx]){
            choise3 = fun(idx+1,profit,capital,k,w);
            return choise3;
         }
         return -1;
    }
};
