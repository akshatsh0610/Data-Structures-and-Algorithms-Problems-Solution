class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         unordered_map<int,int>mp;
         for(int i = 0 ; i < arr.size() ; i++)
         {
              int remainder = arr[i] % k;
              if(remainder < 0) remainder = remainder + k;
              mp[remainder]++;
         }

         for(auto it = mp.begin() ; it != mp.end() ; it++)
         {
              if(it->first == 0 and ((it->second%2) != 0)) return false;
              else if(it->first == 0 and ((it->second%2) == 0)) continue;

              if(mp[it->first] != mp[k - it->first]) return false;
         }
         return true;
    }
};
