class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int count=0;
        int ans=INT_MIN;

        for(int i=0;i<s.length();i++)
        {
           if(i<k)
           {
              if(fun(s[i])==true)
              {
                 count++;	
              }
              if(i==(k-1))
              {
                ans=max(ans,count);
              }
           }
           else
           {
              if(fun(s[i])==true)  //vowel
              {
                count++;	
              }
              if(fun(s[i-k])==true)  //vowel
              {
                count--;
              }
              ans=max(ans,count);
           }
        }  

        if(ans==INT_MIN) return 0;
        return ans;    
    }
    bool fun(char ch)
    {
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
        return true;

        return false;
    }
};
