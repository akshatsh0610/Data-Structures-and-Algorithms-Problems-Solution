// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) 
    {
       sort(arr.begin(),arr.end());
       
       int start = 0;
       int end   = arr.size()-1;
       
       int diff     = INT_MAX;
       int ansStart = -1;
       int ansEnd   = -1;
       
       while(start < end)
       {
           int sum = arr[start] + arr[end];
           
           if(abs(sum - target) < diff){
              diff = abs(sum - target);
              ansStart = arr[start];
              ansEnd   = arr[end];
           }
           
           if(sum < target) start++;
           else if(sum > target) end--;
           else if(sum == target) return {arr[start],arr[end]};
       }
       if(ansStart == -1 and ansEnd == -1) return {};
       return {ansStart,ansEnd};
    }
};
