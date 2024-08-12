class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
    int fun(vector<int>&nums,int k){
         int count = 0;
         int start = 0; int end = 0; 
         unordered_map<int,int>mp;

         while(end < nums.size()){
            mp[nums[end]]++;       //map update

            while(mp.size() > k){   //condition (shrink)
                mp[nums[start]]--;
                if(mp[nums[start]] == 0) mp.erase(nums[start]);
                start++;
            }
            //either the map size is less or equal
            count = count + (end - start + 1);   //count update
            end++;
         }
         return count;
    }
};
