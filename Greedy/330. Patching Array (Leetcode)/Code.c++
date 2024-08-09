class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
           long long int x = 0;     
           int idx = 0;
           long long int count = 0;
           while(idx < nums.size()){
              if(nums[idx] == (x+1)){
                  x = 0LL + (2*x)+1;
                  idx++;
              }else if(nums[idx] > (x+1)){
                  //need to add the element to the array
                  count++;
                  x = 0LL + (2*x)+1;
              }else if(nums[idx] < (x+1)){
                  x = 0LL + x + nums[idx];
                  idx++;
              }
              if(x >= n) return count;
           } 
           if(x >= n) return count;
           while(x < n){
              //we have currently highest achivable till x
              //we need to add the value of x+1
              //that will provide the value till (2*x)+1
              count = 0LL + count + 1;
              x = 0LL + (2*x)+1;
           }
           return count;
    }
};
