class Solution {
public:
    string removeKdigits(string nums, int k) {
        
          stack<int>stk;
          for(int i = 0 ; i < nums.size() ; i++){
            int num = nums[i] - '0';
            if(stk.size() == 0) stk.push(num);
            else if(stk.size() > 0){
                if(num >= stk.top()){
                    stk.push(num);
                }
                else if(num < stk.top()){
                    while(!stk.empty() and k > 0 and num < stk.top()){
                        stk.pop(); k--;
                    }
                    stk.push(num);
                }
            }
          }
          while(!stk.empty() and k > 0){
            stk.pop(); k--;
          }
          if(stk.size() == 0) return "0";
          string ans = "";
          while(!stk.empty()){
             char ch = stk.top() + '0'; stk.pop();
             ans.push_back(ch);
          }
          reverse(ans.begin(),ans.end());
          if(ans.length() == 1 and ans == "0") return ans;
          for(int i = 0 ; i < ans.length() ; i++) if(ans[i] != '0') return ans.substr(i);
          return "0";
    }
};
