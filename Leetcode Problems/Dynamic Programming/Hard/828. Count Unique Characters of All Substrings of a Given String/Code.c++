class Solution {
public:
    // in this question the approach is very simple instead of checking for unique 
    // characters in each substring we are going to check for contribution of a particular
    // character in substrings so we will keep track of indices here and will calculate
    // the contribution of every single character
    int uniqueLetterString(string s) {
        int n=s.length();
        unordered_map<char,int>mp1; // going to store left index
        unordered_map<char,queue<int>>mp2; // going to store right indices
        for(int i=0;i<s.length();i++)
        {
            mp2[s[i]].push(i);
        }
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(mp1.find(s[i])==mp1.end())
            {
                if(mp2[s[i]].size()==1)
                {
                    mp2[s[i]].pop();
                    ans=ans+(i+1)*(n-i);
                }
                else
                {
                    mp2[s[i]].pop();
                    ans=ans+(i+1)*(mp2[s[i]].front()-i);
                }
            }
            else
            {
                mp2[s[i]].pop();
                if(mp2[s[i]].size()>0)
                {
                    ans=ans+(i-mp1[s[i]])*(mp2[s[i]].front()-i);
                }
                else
                {
                    ans=ans+(i-mp1[s[i]])*(n-i);
                }
            }
            mp1[s[i]]=i;
        }
        return ans;
    }
};
