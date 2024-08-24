class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int K) 
    {
        int N = arr.size();
        long long int sum = 0;
	    long long int count = 0;
	    unordered_map<long long , long long>mp;  //rem vs count
	    mp[0]++;
	    int idx = 0;
	    while(idx < N)
	    {
	        sum = sum + 0LL + arr[idx];
	        long long rem = sum % K;
	        if(rem < 0)
	        {
	            rem = rem + 0LL + K;
	        }
	        count = count + 0LL + mp[rem];
	        mp[rem]++;
	        idx++;
	    }
	    return count;
	}   
};
