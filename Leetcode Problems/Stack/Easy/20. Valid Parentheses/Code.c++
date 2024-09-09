class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(int idx  = 0 ; idx <= s.length()-1 ; idx++){
             if(s[idx] == '('  or s[idx] == '['  or s[idx] == '{')
             {
                   stk.push(s[idx]);
             }
             else if(s[idx] == ')'  or s[idx] == '}'  or s[idx] == ']')
             {
                   if(stk.size() > 0 and stk.top() == '(' and s[idx] == ')') stk.pop();
                   else if(stk.size() > 0 and  stk.top() == '{' and s[idx] == '}') stk.pop(); 
                   else if(stk.size() > 0 and stk.top() == '[' and s[idx] == ']') stk.pop(); 
                   else return false;
             }
        }
        if(stk.size() == 0) return true;
        return false;
    }
};
