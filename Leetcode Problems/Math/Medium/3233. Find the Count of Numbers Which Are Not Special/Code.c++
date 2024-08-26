class Solution {
public:
    vector<bool>prime;
    int nonSpecialCount(int l, int r) {
        int size=sqrt(r)+1;
        prime.resize(size,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<size;i++)
        {
            if(prime[i]==true)
            {
                for(int j=i+i;j<=sqrt(r);j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=sqrt(l);i<=sqrt(r);i++)
        {
            if(prime[i] and (i*i>=l and i*i<=r))
            {
                count++;
            }
        }
        return (r-l+1)-count;
    }
};
