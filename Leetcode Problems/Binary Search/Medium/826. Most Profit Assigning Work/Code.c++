class Solution {
public:
     vector<int>prefix;
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        
        int n = diff.size();
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++)
        {
            int difficulty = diff[i];
            int prof = profit[i];
            v.push_back(make_pair(difficulty,prof));
        }
        sort(v.begin(),v.end());

        prefix.push_back(v[0].second);
        for(int i=1;i<v.size();i++)
        {
            int val = max(prefix[i-1],v[i].second);
            prefix.push_back(val);
        }
        
        int ans = 0;
        for(int i=0;i<worker.size();i++)
        {
            int target = worker[i];
            binary_search_(v,0,v.size()-1,target,ans);
        }
        return ans;
    }
    void binary_search_(vector<pair<int,int>>&v,int start,int end,int targetdiff,int &ans)
    {
        int val = 0;
        while(start<=end)
        {
            int mid = (start + ((end - start)/2));

            if(targetdiff == v[mid].first)
            {
               val = max(val,prefix[mid]);
               start = mid+1;        
            }
            else if(targetdiff > v[mid].first)
            {
                val = max(val,prefix[mid]);
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        if(start>=0 and start<v.size() and v[start].first <= targetdiff)
        val = max(val,prefix[start]);

        if(end>=0 and end<v.size() and v[end].first <= targetdiff)
        val = max(val,prefix[end]);

        ans = ans + val;
    }
};
