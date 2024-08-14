class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
{
   int count=0;
   int maxele = INT_MIN;
   for(int i=0;i<arr.size();i++)
   {
      	maxele = max(maxele,arr[i]);
      	
      	if(maxele == i)
      	count++;
   }    
   return count;    
}
};
