class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
         int minstart = INT_MAX;
         int maxend = INT_MIN;

         for(int i=0;i<(trips.size());i++)
         {
             minstart = min(minstart,min(trips[i][1],trips[i][2]));
             maxend = max(maxend,max(trips[i][1],trips[i][2]));
         }    
         
         vector<int>pref(maxend+2,0);
         for(int i=0;i<trips.size();i++)
         {
             int pass = trips[i][0];
             int start = trips[i][1];
             int end = trips[i][2];

             //taking pass passengers at the starting point
             pref[start] = pref[start] + pass;

             //droping off the passnmgers at the end
             pref[end] = pref[end] - pass;

             

         }

         for(int i=0;i<pref.size();i++)
         {
             if(i==0)
             {
                if(pref[i] > capacity)
                return false;

                continue;
             }

             pref[i] = pref[i] + pref[i-1];

             if(pref[i] > capacity)
             return false;
         }
         return true;
    }
};
