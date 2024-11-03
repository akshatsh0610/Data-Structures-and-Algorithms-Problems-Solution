class Solution {
public:
    unordered_map<int,int>mp;
    bool checkSubarraySum(vector<int>& nums, int k) {
        mp[0] = -1;
        int sum = 0;
        int len = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum = sum + nums[i];
            int remainder = sum % k;
            if(remainder < 0) remainder+=k;

            if(mp.find(remainder) != mp.end())
            {
                len = max(len , i - mp[remainder]);   
            }

            if(mp.find(remainder) == mp.end()) mp[remainder] = i;            
        }
        if(len < 2) return false;
        return true;
    }
};
